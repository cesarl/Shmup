#ifndef		__ENTITY_H__
# define	__ENTITY_H__

#include <vector>
#include "Barcode.h"

namespace	Component
{
	struct	Base;
};


namespace	Game
{
	class EntityManager;

	class Entity
	{		
	public:
		typedef Game::EntityManager Manager;

		Entity(unsigned int id = 0);
		~Entity();
		Entity(const Entity &other);
		Entity &operator=(const Entity &other);
		const Game::Barcode &getCode() const;
		unsigned int getId() const;
	private:
		unsigned int id_;
		Barcode code_;
		std::vector<Component::Base*> components_;
	};
};

#endif		//__ENTITY_H__