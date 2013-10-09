#include "Entity.h"
#include "Barcode.h"

using namespace Game;

Entity::Entity(unsigned int id)
	: id_(id)	
{}

Entity::~Entity()
{}

Entity::Entity(const Entity &other)
{
	id_ = other.id_;
	code_ = other.code_;
	components_ = other.components_;
}

Entity &Entity::operator=(const Entity &other)
{
	id_ = other.id_;
	code_ = other.code_;
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