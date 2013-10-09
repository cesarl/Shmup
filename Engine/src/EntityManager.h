#ifndef    __ENTITY_MANAGER_H__
# define   __ENTITY_MANAGER_H__

#include   "Singleton.h"

namespace Game
{
	class  EntityManager : public Utils::Singleton<EntityManager>
	{
	public:
		friend class Utils::Singleton<EntityManager>;
	private:
		EntityManager();
		virtual ~EntityManager();
	};
};

#endif     //__ENTITY_MANAGER_H__