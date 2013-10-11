#include <allegro5/allegro.h>
#include "src/Entity.h"
#include "src/EntityManager.h"
#include "src/EmptySystem.h"
#include "src/EmptyComponent.h"
#include "src/System.h"
#include "src/SystemManager.h"

int main(void)
{

	//
	// Tests
	//

	Game::Entity::Manager &entityManager = Game::Entity::getManager();
	System::Manager &systemManager = System::getManager();

	systemManager.addSystem<System::sEmpty>(1);
	systemManager.init();

	Game::Entity &e1 = entityManager.newEntity();

	e1.addComponent<Component::cEmpty>();
	e1.removeComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();

	systemManager.update(ALLEGRO_EVENT(), 1.0f);

	e1.removeComponent<Component::cEmpty>();

	systemManager.update(ALLEGRO_EVENT(), 2.0f);

	e1.removeComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();

	systemManager.update(ALLEGRO_EVENT(), 3.0f);

	//
	// Allegro Test
	//

	//ALLEGRO_DISPLAY *dis = NULL;
	//if (!al_init())
	//	return EXIT_FAILURE;		
	//dis = al_create_display(300, 300);
	//if (!dis)
	//	return EXIT_FAILURE;
	//al_rest(1);
	//al_destroy_display(dis);
	//al_uninstall_system();
	return EXIT_SUCCESS;
}