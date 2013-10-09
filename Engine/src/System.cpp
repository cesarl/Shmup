#include "System.h"
#include "Entity.h"

using namespace System;

Base::Base()
{}

Base::~Base()
{}

void Base::update(const ALLEGRO_EVENT & ev, double time)
{
	updateBegin(ev, time);
	mainUpdate(ev, time);
	updateEnd(ev, time);
	// todo
	//System::Manager::updateSystemCollections();
}

void Base::entityUpdated(const Game::Entity &entity)
{
	if (code_.match(entity))
		collection_.insert(entity.getId());
	else
		collection_.erase(entity.getId());
}

void Base::init()
{
	initialize();
	// todo
	//ASSERT(!code_.isEmpty());
}

template <typename T>
void Base::require()
{
	code_.add<T>();
}

const Game::Barcode &Base::getCode() const
{
	return code_;
}
