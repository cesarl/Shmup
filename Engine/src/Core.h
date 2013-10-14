#ifndef  __CORE_H__
# define __CORE_H__

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Window.h"
#include "Event.h"
#include "SystemManager.h"

class Core : public Utils::Singleton<Core>
{
private:
	friend class Utils::Singleton<Core>;
	virtual ~Core(){}
public:
	static Window &getWindow()
	{
		static Window &window = Window::getInstance();

		return window;
	}

	static EventManager &getEvent()
	{
		static EventManager &event = EventManager::getInstance();

		return event;
	}

	bool init()
	{
		if (!al_init())
			return false;
		if (!al_init_image_addon())
			return false;
		//Window::getInstance().init();
		EventManager::getInstance().init();

		System::getManager().init();
		return true;
	}

	void uninit() // important ! TODO and clear here all Allegro dependancies
	{}

};

#endif   //__CORE_H__