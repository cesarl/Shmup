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

void SystemManager::init()
{
	for (auto &e : list_)
	{
		e.second->init();
	}
}

void SystemManager::update(const ALLEGRO_EVENT &event, double time)
{
	EntityManager &entityManager = EntityManager::getInstance();

	for (std::map<int, Base*>::iterator it = std::begin(updateList_);
		it != std::end(updateList_);
		++it)
	{
		// update system
		it->second->update(event, time);
	}
}

void SystemManager::draw(const ALLEGRO_EVENT &event, double time)
{
	for (auto &e : drawList_)
	{
		e.second->update(event, time);
	}	
}