#include "Entity.h"
#include "Barcode.h"
#include "SystemManager.h"
#include "StringId.hpp"

using namespace Game;

// TODO RESET() !

Entity::Entity(unsigned int id, const std::string &tag, const std::string &layer)
	: id_(id),	
{
// todo abort if (tag.size() > TAG_LENGTH)
// todo abort if (layer.size() > TAG_LENGTH)
	tag_ = Utils::StringId::getInstance().getId(tag);
	layer_ = Utils::StringId::getInstance().getId(layer);
}

Entity::~Entity()
{
// todo delete components	
}

Entity::Entity(const Entity &other)
{
	id_ = other.id_;
	code_ = other.code_;
	// todo delete components
	components_ = other.components_;
	tag_ = o.tag_;
	layer_ = o.layer_;
}

Entity &Entity::operator=(const Entity &other)
{
	id_ = other.id_;
	code_ = other.code_;
	// todo delete components
	components_ = other.components_;
	tag_ = o.tag_;
	layer_ = o.layer_;
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


template <typename T>
bool Entity::hasComponent() const
{
	return code_.isSet<T>();
}

template <typename T>
Component::Base *Entity::addComponent()
{
	unsigned int id = T::getTypeId();
	if (hasComponent(id))
	{
		return static_cast<T*>(components_[id]);
	}
	T *tmp = new T;
	// todo assert if new T fail
	code_.add(id);
	components_[id] = tmp;
	System::Manager().entityModified(getId());
	return tmp;
}

template <typename T>
Component::Base *Entity::getComponent() const
{
	unsigned int id = T::getTypeId();
	if (!hasComponent(id))
		return std::nullptr;
	return static_cast<T*>(components_[id]);
}

template <typename T>
void Entity::removeComponent()
{
	unsigned int id = T::getTypeId();
	if (!hasComponent(id))
		return;
	code_.remove(id);
	delete components_[id];
	components_[id]	= nullptr;
	System::Manager().entityModified(getId());
}

static Game::EntityManager &Entity::Manager()
{
	static manager = Manager::getInstance();
	return manager;
}
