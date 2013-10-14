#ifndef  __CORE_H__
# define __CORE_H__

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Window.h"

class Core : Utils::Singleton<Core>
{
private:
	friend class Utils::Singleton<Core>;
	~Core(){}
public:
	static Window &getWindow()
	{
		static Window &window = Window::getInstance();

		return window;
	}

	bool init()
	{
		if (!al_init())
			return false;
		if (!al_init_image_addon())
			return false;
		return true;
	}

	void uninit() // important ! TODO and clear here all Allegro dependancies
	{}

};

#endif   //__CORE_H__