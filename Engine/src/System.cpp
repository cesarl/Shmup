#pragma once

#include "System.h"
#include "Entity.h"
#include "SystemManager.h"

using namespace System;

SystemManager &Base::manager_ = System::getManager();

Base::Base()
	: isUpdating_(false)
{}

Base::~Base()
{}

void Base::update(const ALLEGRO_EVENT & ev, double time)
{
	updateBegin(ev, time);
	isUpdating_ = true;
	mainUpdate(ev, time);
	isUpdating_ = false;
	postUpdateCollection_();
	updateEnd(ev, time);
}

void Base::init()
{
	initialize();
	// todo
	//ASSERT(!code_.isEmpty());
}

const Utils::Barcode &Base::getCode() const
{
	return code_;
}

void Base::entityUpdated(Entity &entity)
{
	if (code_.match(entity.getCode()) && !entity.isPartOfSystem(this))
	{
		if (isUpdating_)
		{
			toAddOrTrash_.push_back(std::pair<bool, unsigned int>(true, entity.getId()));
		}
		else
		{
			collection_.insert(entity.getId());
		}
		entity.addSystem(this);
	}
	else if (entity.isPartOfSystem(this) && !code_.match(entity.getCode()))
	{
		if (isUpdating_)
		{
			toAddOrTrash_.push_back(std::pair<bool, unsigned int>(false, entity.getId()));
		}
		else
		{
			collection_.erase(entity.getId());
		}
		entity.removeSystem(this);
	}
}

void Base::postUpdateCollection_()
{
	for (auto &e : toAddOrTrash_)
	{
		if (e.first)
		{
			collection_.insert(e.second);
		}
		else
			collection_.erase(e.second);
	}
	toAddOrTrash_.clear();
}