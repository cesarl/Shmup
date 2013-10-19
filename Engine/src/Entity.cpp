#include "Entity.h"
#include "Barcode.h"
#include "SystemManager.h"
#include "EntityManager.h"
#include "Component.h"
#include "System.h"

System::SystemManager &Entity::systemManager_ = System::getManager();

Entity::Entity(unsigned int id, const std::string &tag, const std::string &layer)
	: id_(id)
{
	// todo abort if (tag.size() > TAG_LENGTH)
	// todo abort if (layer.size() > TAG_LENGTH)
	tag_ = Utils::Tag(tag);
	layer_ = Utils::Tag(layer);
	components_.resize(COMPONENTS_MAX_NUMBER);
}

Entity::~Entity()
{
	reset();
}

Entity::Entity(const Entity &other)
{
	reset();
	id_ = other.id_;
	code_ = other.code_;
	components_ = other.components_;
	tag_ = other.tag_;
	layer_ = other.layer_;
	systems_ = other.systems_;
	informSystemsAboutRemovedCpt_();
}

Entity &Entity::operator=(const Entity &other)
{
	reset();
	id_ = other.id_;
	code_ = other.code_;
	components_ = other.components_;
	tag_ = other.tag_;
	layer_ = other.layer_;
	systems_ = other.systems_;
	informSystemsAboutRemovedCpt_();
	return *this;
}

const Utils::Barcode &Entity::getCode() const
{
	return code_;
}

unsigned int Entity::getId() const
{
	return id_;
}

bool Entity::hasComponent(unsigned int componentId) const
{
	return code_.isSet(componentId);
}

void Entity::reset()
{
	code_.reset();
	informSystemsAboutRemovedCpt_();
	for (auto &e : components_)
	{
		if (e)
			delete e;
		e = nullptr;
	}
	systems_.clear();
}

EntityManager &Entity::getManager()
{
	static auto &manager = EntityManager::getInstance();
	return manager;
}

glm::mat4 &Entity::getLocalTransform()
{
	return localTransform_;
}

const glm::mat4 &Entity::getLocalTransform() const
{
	return localTransform_;
}


glm::mat4 &Entity::getGlobalTransform()
{
	return globalTransform_;
}

const glm::mat4 &Entity::getGlobalTransform() const
{
	return globalTransform_;
}

void Entity::setLocalTranform(const glm::mat4 &trans)
{
	localTransform_ = trans;
}

void Entity::addSystem(System::Base *sys)
{
	if (std::find(std::begin(systems_), std::end(systems_), sys) == std::end(systems_))
		systems_.push_back(sys);
}

void Entity::removeSystem(System::Base *sys)
{
	auto i = std::find(std::begin(systems_), std::end(systems_), sys);
	if (i != std::end(systems_))
		systems_.remove(*i);
}

bool Entity::isPartOfSystem(System::Base *sys) const
{
	return (std::find(std::begin(systems_), std::end(systems_), sys) != std::end(systems_));
}

void Entity::informSystemsAboutRemovedCpt_()
{
	std::list<System::Base*>::iterator it = std::begin(systems_);
	std::list<System::Base*>::iterator current;
	while (it != std::end(systems_))
	{
		current = it++;
		(*current)->entityUpdated(*this);
	}
}