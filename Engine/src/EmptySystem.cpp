#include "EmptySystem.h"
#include "EmptyComponent.h"

using namespace System;

void sEmpty::updateBegin(const ALLEGRO_EVENT &, double)
{

}

void sEmpty::updateEnd(const ALLEGRO_EVENT &, double)
{

}

void sEmpty::mainUpdate(const ALLEGRO_EVENT &, double)
{

}

void sEmpty::initialize()
{
	require<Component::cEmpty>();
}
