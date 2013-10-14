#ifndef		__POPSICLE_SYSTEM_H__
# define	__POPSICLE_SYSTEM_H__

#include	"../src/System.h"
#include    "Popsicle.h"

namespace System
{
	class sPopsicleUpdate : public System::Base
	{
	public:
		sPopsicleUpdate(){};
		virtual ~sPopsicleUpdate(){};

		virtual void updateBegin(const ALLEGRO_EVENT & ev, double time) override
		{
		}

		virtual void updateEnd(const ALLEGRO_EVENT & ev, double time) override
		{
		}

		virtual void mainUpdate(const ALLEGRO_EVENT & ev, double time) override
		{
			for (auto c : collection_)
			{
				Game::Entity &e = Game::Entity::getManager().getEntity(c);

				Component::cPopsicle *pop = e.getComponent<Component::cPopsicle>();

				--pop->generation;

				if (pop->generation <= 0)
				{
					pop->age--;
					if (pop->age > 0)
					{
						Game::Entity &e2 = Game::Entity::getManager().newEntity();
						e2.addComponent<Component::cPopsicle>()->generation = pop->age;
						e2.getComponent<Component::cPopsicle>()->age = pop->age;
						Game::Entity &e3 = Game::Entity::getManager().newEntity();
						e3.addComponent<Component::cPopsicle>()->generation = pop->age;
						e3.getComponent<Component::cPopsicle>()->age = pop->age;
						Game::Entity::getManager().deleteEntity(e);
						std::cout << e3.getId() << std::endl;
					}
					return;
					(void)time;
				}
			}
		}

		virtual void initialize() override
		{
			require<Component::cPopsicle>();
		}
	};
};

#endif //__POPCICLE_SYSTEM_H__