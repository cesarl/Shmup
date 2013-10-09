#include "EntityManager.h"

using namespace Game;

EntityManager::EntityManager()
{
// todo
// abort size of vector > ENTITY_MAX_NUMBER
	collection_.resize(ENTITY_MAX_NUMBER);
}

EntityManager::~EntityManager()
{}