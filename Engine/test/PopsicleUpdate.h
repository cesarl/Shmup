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
			for (auto &c : collection_)
			{
				Entity &e = Entity::getManager().getEntity(c);

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
					Entity &n = Entity::getManager().newEntity();
					n.addComponent<Component::cPopsicle>()->persisttime = pop->persisttime;
					n.addComponent<Component::cEmpty>();
				}
				if (pop->lifetime <= 0.0f)
					Entity::getManager().deleteEntity(e);

			}
		}

		virtual void initialize() override
		{
			require<Component::cPopsicle>();
		}
	};
};

#endif //__POPCICLE_SYSTEM_H__