#ifndef  __CORE_WINDOW_H__
# define __CORE_WINDOW_H__

#include <allegro5/allegro.h>
#include "Singleton.h"
#include "Assert.h"

	class Window : public Utils::Singleton<Window>
	{
		friend class Utils::Singleton<Window>;
	public:
		unsigned int getWidth()
		{
			return width_;
		}

		unsigned int getHeight()
		{
			return height_;
		}

		void createWindow(unsigned int w = 1024, unsigned int h = 640)
		{
			ALLEGRO_DISPLAY *display;

			display = al_get_current_display();
			if (display)
				al_destroy_display(display);
			ASSERT(al_create_display(w, h) == NULL, "Creating display error");
			width_ = w;
			height_ = h;
		}
	private:
		Window()
			: width_(0),
			height_(0)
		{}

		~Window()
		{}

		unsigned int width_;
		unsigned int height_;
	};


#endif   //__CORE_WINDOW_H__