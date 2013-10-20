#ifndef   __BITMAP_H__
# define  __BITMAP_H__


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_opengl.h>
#include <GL/GL.h>
#include "ARessource.h"

class Bitmap : public ARessource
{
public:
	Bitmap()
		: bmp(nullptr),
		tex(0)
	{}

	virtual ~Bitmap()
	{}

	ALLEGRO_BITMAP *bmp;
	GLuint tex;
private:
	virtual bool loadingFunction(const Utils::File &file)
	{
		bmp = al_load_bitmap(file.getFullName().c_str());
		if (!bmp)
			return false;
		tex = al_get_opengl_texture(bmp);
		if (tex == 0)
		{
			al_destroy_bitmap(bmp);
			return false;
		}
		return true;
	}
};

#endif    //__BITMAP_H__