#ifndef    __ENTITY_MANAGER_H__
# define   __ENTITY_MANAGER_H__

#include   <vector>
#include   "Singleton.h"
#include   "Entity.h"

class Entity;

class  EntityManager : public Utils::Singleton<EntityManager>
{
public:
	friend class Utils::Singleton<EntityManager>;
	Entity &getEntity(unsigned int entityId);
	Entity &newEntity();
	void deleteEntity(const Entity &entity);
	void deleteEntity(unsigned int entityId);
	void logNumber();
	std::vector<Entity> &getList();
	unsigned int getEnd();
private:
	EntityManager();
	virtual ~EntityManager();
private:
	unsigned int idCounter_;
	std::vector<Entity> collection_;
	std::vector<unsigned int> freeIds_;
};

#endif     //__ENTITY_MANAGER_H__