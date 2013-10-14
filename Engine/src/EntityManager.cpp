#include "EntityManager.h"

using namespace Game;

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

Entity &EntityManager::newEntity()
{
	if (freeIds_.empty())
	{
		// todo abord idCounter > MAX ENTITY
		collection_[idCounter_] = Entity(idCounter_);
		Entity &res = collection_[idCounter_];
		++idCounter_;
		return res;
	}
	Entity &res = collection_[freeIds_.back()];
	res = Entity(freeIds_.back());
	freeIds_.pop_back();
	return res;
}

void EntityManager::deleteEntity(const Entity &entity)
{
	unsigned int id = entity.getId();

	collection_[id].reset();
	freeIds_.push_back(id);
	System::getManager().entityModified(id);
}

void EntityManager::deleteEntity(unsigned int entityId)
{
	collection_[entityId].reset();
	freeIds_.push_back(entityId);
	System::getManager().entityModified(entityId);
}
