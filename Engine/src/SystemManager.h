#ifndef     __SYSTEM_MANAGER_H__
# define    __SYSTEM_MANAGER_H__

#include    <map>
#include    <list>
#include    <unordered_map>
#include    <unordered_set>
#include    <allegro5/allegro.h>
#include    "Singleton.h"

class Entity;

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

		template <class T>
		T *addSystem(int priority, bool draw = false)
		{
			auto &it = list_.find(typeid(T).name());

			if (it != std::end(list_))
				return static_cast<T*>(it->second);
			auto sys = new T;
			// todo assert sys is nullptr;
			sys->init();
			list_.insert(std::pair<const char *, Base*>(typeid(T).name(), sys));
			if (draw)
				drawList_.insert(std::pair<int, Base*>(priority, sys));
			else
				updateList_.insert(std::pair<int, Base*>(priority, sys));
			return sys;
		}

		template <class T>
		T *getSystem()
		{
			auto &it = list_.find(typeid(T).name);
			if (it != std::end(list_))
				return static_cast<T*>(it.second);
			return std::nullptr;
		}

		template <class T, class Sys>
		void subscribeToAdd(Sys *sys)
		{
			unsigned int id = T::getTypeId();
			if (addSubscribers_.find(id) != std::end(addSubscribers_))
			{
				if (std::find(std::begin(addSubscribers_[id]), std::end(addSubscribers_[id]), sys) == std::end(addSubscribers_[0]))
					addSubscribers_[id].push_back(sys);
				return;
			}
			addSubscribers_.emplace(id, std::list<System::Base*>());
			addSubscribers_[id].push_back(sys);
		}

		template <class T>
		void componentAdded(Entity &e)
		{
			unsigned int id = T::getTypeId();
			if (addSubscribers_.find(id) == std::end(addSubscribers_))
				return;
			for (auto &i : addSubscribers_[id])
			{
				i->entityUpdated(e);
			}
		}

	private:
		SystemManager();
		virtual ~SystemManager();
	private:
		std::multimap<int, Base*> updateList_;
		std::multimap<int, Base*> drawList_;
		std::map<const char *, Base*> list_;
		std::unordered_map<unsigned int, std::list<System::Base*> > addSubscribers_;
	};

	static SystemManager &getManager()
	{
		static auto &manager = SystemManager::getInstance();
		return manager;
	}
};

#endif      //__SYSTEM_MANAGER_H__