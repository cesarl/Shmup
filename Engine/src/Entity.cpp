#include "Entity.h"
#include "Barcode.h"
#include "SystemManager.h"

using namespace Game;

// TODO RESET() !

Entity::Entity(unsigned int id)
	: id_(id)	
{}

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
}

Entity &Entity::operator=(const Entity &other)
{
	id_ = other.id_;
	code_ = other.code_;
	// todo delete components
	components_ = other.components_;
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

template <typename T>
bool Entity::hasComponent()
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
	return tmp;
}

template <typename T>
Component::Base *Entity::getComponent()
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
	System::Manager::getInstance().entityModified(getId());
delete 	
}