#ifndef     __SYSTEM_MANAGER_H__
# define    __SYSTEM_MANAGER_H__

#include    <map>
#include    <unordered_set>
#include    <allegro5/allegro.h>
#include    "Singleton.h"

namespace System
{
	class Base;

	class SystemManager : public Utils::Singleton<SystemManager>
	{
	public:
		friend class Utils::Singleton<System::SystemManager>;
		void updateSystemCollection();
		void init();
		void update(const ALLEGRO_EVENT &event, double time);
		void draw(const ALLEGRO_EVENT &event, double time);
		void entityModified(unsigned int entityId);

		template <class T>
		T *addSystem(int priority, bool draw = false);

		template <class T>
		T *getSystem();
	private:
		SystemManager();
		virtual ~SystemManager();
	private:
		std::multimap<int, Base*> updateList_;
		std::multimap<int, Base*> drawList_;
		std::map<const char *, Base*> list_;
		std::unordered_set<unsigned int> entityModified_;
	};

	static SystemManager &getManager()
	{
		static auto &manager = SystemManager::getInstance();
		return manager;
	}
};

#endif      //__SYSTEM_MANAGER_H__