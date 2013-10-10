#ifndef     __SYSTEM_MANAGER_H__
# define    __SYSTEM_MANAGER_H__

#include    <multimap>
#include    <allegro5/allegro.h>
#include    "Singleton.h"

namespace System
{
	class Base;

	class SystemManager : public Singleton<SystemManager>
	{
	public:
		friend class Singleton<SytemManager>;
		void updateSystemCollection();
		void init();
		void update(const ALLEGRO_EVENT &event, double time);
		void draw(const ALLLEGRO_EVENT &event, double time);

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
	};
};

#endif      //__SYSTEM_MANAGER_H__