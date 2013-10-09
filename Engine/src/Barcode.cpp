#include "Barcode.h"
#include "Entity.h"
#include "Component.h"

using namespace Game;

Barcode::Barcode()
{}

Barcode::Barcode(const Entity &entity)
{
	code_ = entity.getCode().code_;
}

Barcode::Barcode(const Barcode &other)
{
	code_ = other.code_;
}

Barcode &Barcode::operator=(const Barcode &other)
{
	code_ = other.code_;
	return *this;
}

Barcode::~Barcode()
{}

bool Barcode::match(const std::bitset<COMPONENTS_MAX_NUMBER> &set)
{
	return((set & code_) == code_);
}

bool Barcode::match(const Entity &entity)
{
	return((entity.getCode().code_ & code_) == code_);
}

bool Barcode::match(const Barcode &other)
{
	return((other.code_ & code_) == code_);
}

void Barcode::reset()
{
	code_.reset();
}

void Barcode::add(unsigned int componentId)
{
	applyChange(componentId, true);
}

void Barcode::remove(unsigned int componentId)
{
	applyChange(componentId, true);
}

bool Barcode::isEmpty()
{
	return (code_.none());
}