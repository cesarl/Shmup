#include <allegro5/allegro.h>
#include "src/Entity.h"
#include "src/EntityManager.h"
#include "src/EmptySystem.h"
#include "src/EmptyComponent.h"
#include "src/System.h"
#include "src/Core.h"

int main(void)
{

	//
	// Tests
	//

	Core::getInstance().init();

	Game::Entity::Manager &entityManager = Game::Entity::getManager();
	System::Manager &systemManager = System::getManager();

	systemManager.addSystem<System::sEmpty>(1);

	Game::Entity &e1 = entityManager.newEntity();
	e1.addComponent<Component::cEmpty>();
	e1.removeComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();
	e1.removeComponent<Component::cEmpty>();
	e1.removeComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();

	Core::getWindow().createWindow();
	Core::getEvent().play();

	return EXIT_SUCCESS;
}