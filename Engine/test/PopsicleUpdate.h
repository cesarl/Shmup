#ifndef		__POPSICLE_SYSTEM_H__
# define	__POPSICLE_SYSTEM_H__

#include	"../src/System.h"
#include    "Popsicle.h"
#include    "../src/EmptyComponent.h"

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
			for (unsigned int i = 0, mi = Game::Entity::getManager().getEnd(); i < mi; ++i)
			{
				Game::Entity &e = Game::Entity::getManager().getList()[i];

				if (!code_.match(e))
					continue;
				Component::cPopsicle *pop = e.getComponent<Component::cPopsicle>();

				pop->persisttime -= time;
				pop->divideTime -= time;
				pop->removeComponentTime -= time;
				pop->addComponentTime -= time;
				pop->lifetime -= time;

				if (pop->addComponentTime <= 0.0f)
					e.addComponent<Component::cEmpty>();
				if (pop->removeComponentTime <= 0.0f)
					e.removeComponent<Component::cEmpty>();
				if (pop->divideTime <= 0.0f && pop->persisttime > 0.0f)
				{
					Game::Entity &n = Game::Entity::getManager().newEntity();
					n.addComponent<Component::cPopsicle>()->persisttime = pop->persisttime;
					n.addComponent<Component::cEmpty>();
				}
				if (pop->lifetime <= 0.0f)
					Game::Entity::getManager().deleteEntity(e);

			}
		}

		virtual void initialize() override
		{
			require<Component::cPopsicle>();
		}
	};
};

#endif //__POPCICLE_SYSTEM_H__