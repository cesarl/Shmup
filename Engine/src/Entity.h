#ifndef		__ENTITY_H__
# define	__ENTITY_H__

#include <vector>
#include <glm/glm.hpp>
#include "Barcode.h"
#include "StringId.hpp"
#include "SystemManager.h"

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

		template <typename T>
		bool hasComponent() const
		{
			return code_.isSet<T>();
		}

		template <typename T>
		T *addComponent()
		{
			unsigned int id = T::getTypeId();
			if (hasComponent(id))
			{
				return static_cast<T*>(components_[id]);
			}
			T *tmp = new T;
			// todo assert if new T fail
			code_.add(id);
			components_[id] = tmp;
			return tmp;
		}

		template <typename T>
		T *getComponent() const
		{
			unsigned int id = T::getTypeId();
			if (!hasComponent(id))
				return nullptr;
			return static_cast<T*>(components_[id]);
		}

		template <typename T>
		void removeComponent()
		{
			unsigned int id = T::getTypeId();
			if (!hasComponent(id))
				return;
			code_.remove(id);
			delete components_[id];
			components_[id]	= nullptr;
		}

		static Game::EntityManager &getManager();
	private:
		unsigned int id_;
		Utils::Tag tag_;
		Utils::Tag layer_;
		glm::vec3 position_;
		glm::vec3 rotation_;
		glm::vec3 scale_;
		Barcode code_;
		std::vector<Component::Base*> components_;
	};
};

#endif		//__ENTITY_H__