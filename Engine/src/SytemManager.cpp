#include "SystemManager.h"
#include "System.h"
#include "EntityManager.h"
#include "Entity.h"

using namespace System;

SystemManager::SystemManager()
{}

SystemManager::~SystemManager()
{
	for(auto &e : list_)
	{
		delete e.second;
	}

	updateList_.clear();
	drawList_.clear();
	list_.clear();
}

void SystemManager::updateSystemCollection()
{
// todo
}

void SystemManager::init()
{
	for (auto &e : list_)
	{
		e.init();
	}
}

void SystemManager::update(const ALLEGRO_EVENT &event, double time)
{
	Game::Entity::Manager &entityManager = Game::Entity::Manager::getInstance();

	// clear entity modfied list
	entityModified_.clear();

	for (std::map<int, Base*>::iterator it = std::begin(updateList_);
		it != std::end(updateList_);
		++it)
	{
		// update system
		it->second->update(event, time);

		std::map<int, Base*>::iterator next = it;
		if (++next == std::end(updateList_))
			next = std::begin(updateList_);
		for (auto &i : entityModified_)
		{
			Game::Entity &entity = entityManager.getEntity(i);
			next->second->entityUpdated(entity);
		}
	}
}

void SystemManager::draw(const ALLEGRO_EVENT &event, double time)
{
	for (auto &e : drawList_)
	{
		e.second->update(event, time);
	}	
}

void SystemManager::entityModified(unsigned int entityId)
{
}

template <class T>
T *addSystem(int priority, bool draw)
{
	auto &it = list_.find(typeid(T).name());

	if (it != std::end(list_))
		return static_cast<T*>(it.second);
	auto sys = new T;
	// todo assert sys is nullptr;
	sys.init();
	list_.insert(std::pair<const char *, Base*>(typeid(T).name()));
	if (draw)
		drawList_.insert(std::pair<int, Base*>(priority, sys));
	else
		updateList_.insert(std::pair<int, Base*>(priority, sys));
	return sys;
}

template <class T>
T *getSystem()
{
	auto &it = list_.find(typeid(T).name);
	if (it != std::end(list_))
		return static_cast<T*>(it.second);
	return std::nullptr;
}

using namespace System;