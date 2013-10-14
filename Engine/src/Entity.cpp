#include "Entity.h"
#include "Barcode.h"
#include "SystemManager.h"
#include "EntityManager.h"
#include "Component.h"

using namespace Game;

// TODO RESET() !

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
}

Entity &Entity::operator=(const Entity &other)
{
	reset();
	id_ = other.id_;
	code_ = other.code_;
	components_ = other.components_;
	tag_ = other.tag_;
	layer_ = other.layer_;
	return *this;
}

const Barcode &Entity::getCode() const
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
	for (auto &e : components_)
	{
		if (e)
			delete e;
		e = nullptr;
	}
	code_.reset();
}

//const unsigned int Entity::getTagId() const
//{
//	return tag_;
//}
//
//const unsigned int getLayerId() const
//{
//	return id_;
//}

//const std::string &getTagString() const;
//const std::string &getLayerString() const;

Game::EntityManager &Entity::getManager()
{
	static auto &manager = Entity::Manager::getInstance();
	return manager;
}
