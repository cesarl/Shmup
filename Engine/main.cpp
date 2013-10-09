#include <allegro5/allegro.h>

int main(void)
{
	ALLEGRO_DISPLAY *dis = NULL;

	if (!al_init())
		return EXIT_FAILURE;		
	dis = al_create_display(300, 300);
	if (!dis)
		return EXIT_FAILURE;
	al_rest(1);
	al_destroy_display(dis);
	al_uninstall_system();
	return EXIT_SUCCESS;
}