#include <allegro5/allegro.h>
#include "src/Entity.h"
#include "src/EntityManager.h"
#include "src/EmptySystem.h"
#include "src/EmptyComponent.h"
#include "src/System.h"
#include "src/Core.h"
#include "test/PopsicleUpdate.h"
#include "src/Bitmap.h"
#include "src/Resource.h"

template<class DataType>
std::map<std::string, DataType *> Resource<DataType>::_map;

int main(void)
{
	//
	// Tests
	//

	Core::getInstance().init();

	EntityManager &entityManager = Entity::getManager();
	System::Manager &systemManager = System::getManager();

	systemManager.addSystem<System::sEmpty>(1);
	systemManager.addSystem<System::sPopsicleUpdate>(2);

	Entity &e1 = entityManager.newEntity();
	//e1.addComponent<Component::cEmpty>();
	//e1.removeComponent<Component::cEmpty>();
	//e1.addComponent<Component::cEmpty>();
	//e1.addComponent<Component::cEmpty>();
	//e1.removeComponent<Component::cEmpty>();
	//e1.removeComponent<Component::cEmpty>();
	e1.addComponent<Component::cEmpty>();
	e1.addComponent<Component::cPopsicle>();

	//std::cout << Component::cEmpty::getTypeId() << std::endl;
	//std::cout << Component::cPopsicle::getTypeId() << std::endl;
	//std::cout << Component::cEmpty::getTypeId() << std::endl;

	Resource<Bitmap> lol("prout");
	lol.fromFile("prout.jpg");
	&lol;

	Core::getWindow().createWindow();
	Core::getEvent().play();

	return EXIT_SUCCESS;
}