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

class EntityManager;

class Entity
{		
public:
	Entity(unsigned int id = 0, const std::string &tag = DEFAULT_TAG, const std::string &layer = DEFAULT_LAYER);
	~Entity();
	Entity(const Entity &other);
	Entity &operator=(const Entity &other);
	const Utils::Barcode &getCode() const;
	unsigned int getId() const;
	bool hasComponent(unsigned int id) const;
	void reset();
	const glm::mat4 &getLocalTransform() const;
	glm::mat4 &getLocalTransform();
	const glm::mat4 &getGlobalTransform() const;
	glm::mat4 &getGlobalTransform();
	void setLocalTranform(const glm::mat4 &trans);

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
		System::getManager().entityModified(getId());
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
		System::getManager().entityModified(getId());
	}

	static EntityManager &getManager();
private:
	unsigned int id_;
	Utils::Tag tag_;
	Utils::Tag layer_;
	glm::mat4 localTransform_;
	glm::mat4 globalTransform_;
	Utils::Barcode code_;
	std::vector<Component::Base*> components_;
};

#endif		//__ENTITY_H__