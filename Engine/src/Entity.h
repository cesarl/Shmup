#ifndef		__ENTITY_H__
# define	__ENTITY_H__

#include <vector>
#include "Barcode.h"
#include "StringId.hpp"

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

		Entity(unsigned int id = 0, const std::string &tag = DEFAULT_TAG, const std::string &layer = DEFAULT_LAYER);
		~Entity();
		Entity(const Entity &other);
		Entity &operator=(const Entity &other);
		const Game::Barcode &getCode() const;
		unsigned int getId() const;
		bool hasComponent(unsigned int id) const;
		void reset();
		//const unsigned int getTagId() const;
		//const unsigned int getLayerId() const;
		//const std::string &getTagString() const;
		//const std::string &getLayerString() const;

		template <typename T>
		bool hasComponent() const;

		template <typename T>
		T *addComponent();

		template <typename T>
		T *getComponent() const;

		template <typename T>
		void removeComponent();

		static Game::EntityManager &getManager();
	private:
		unsigned int id_;
		Utils::Tag tag_;
		Utils::Tag layer_;
		Barcode code_;
		std::vector<Component::Base*> components_;
	};
};

#endif		//__ENTITY_H__