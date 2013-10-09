#ifndef    __ENTITY_MANAGER_H__
# define   __ENTITY_MANAGER_H__

#include   <vector>
#include   "Singleton.h"
#include   "Entity.h"

namespace Game
{
	class Entity;

	class  EntityManager : public Utils::Singleton<EntityManager>
	{
	public:
		friend class Utils::Singleton<EntityManager>;
	private:
		EntityManager();
		virtual ~EntityManager();
	private:
		std::vector<Game::Entity> collection_;
	};
};

#endif     //__ENTITY_MANAGER_H__