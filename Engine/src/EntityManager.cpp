#include <iostream>
#include <cassert>
#include "EntityManager.h"

EntityManager::EntityManager()
	: idCounter_(0)
{
// todo
// abort size of vector > ENTITY_MAX_NUMBER
	collection_.resize(ENTITY_MAX_NUMBER);
}

EntityManager::~EntityManager()
{}

Entity &EntityManager::getEntity(unsigned int entityId)
{
	return collection_[entityId];
}

std::vector<Entity> &EntityManager::getList()
{
	return collection_;
}

unsigned int EntityManager::getEnd()
{
	return idCounter_;
}

Entity &EntityManager::newEntity()
{
	if (freeIds_.empty())
	{
		//assert(idCounter_ < ENTITY_MAX_NUMBER);
		// todo abord 
		collection_[idCounter_] = Entity(idCounter_);
		Entity &res = collection_[idCounter_];
		++idCounter_;
		logNumber();
		return res;
	}
	Entity &res = collection_[freeIds_.back()];
	res = Entity(freeIds_.back());
	freeIds_.pop_back();
	logNumber();
	return res;
}

void EntityManager::deleteEntity(const Entity &entity)
{
	unsigned int id = entity.getId();

	collection_[id].reset();
	freeIds_.push_back(id);
	System::getManager().entityModified(id);
	logNumber();
}

void EntityManager::deleteEntity(unsigned int entityId)
{
	collection_[entityId].reset();
	freeIds_.push_back(entityId);
	System::getManager().entityModified(entityId);
	logNumber();
}

void EntityManager::logNumber()
{
	if (idCounter_ % 50 == 0)
		std::cout << "Active entity " << idCounter_ << std::endl;
}
