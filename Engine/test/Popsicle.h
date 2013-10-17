#ifndef    __POPSICLE_COMPONENT_H__
# define   __POPSICLE_COMPONENT_H__

#include   <glm/glm.hpp>
#include   "../src/Component.h"

namespace  Component
{

	// a component for testing entity creation and deletion at runtime

	struct cPopsicle : public ComponentBase<cPopsicle>
	{
		cPopsicle()
			: persisttime(3.0f), // time remaining for split
			divideTime(0.5f), // time remaining before split
			removeComponentTime(1.5f), // time remaining before cpt remove
			addComponentTime(1.0f), // time remaining before cpt add
			lifetime(2.f) // lifetime

		{}

		float persisttime;
		float divideTime;
		float removeComponentTime;
		float addComponentTime;
		float lifetime;

		virtual ~cPopsicle(){}
	};
};

#endif     //__POPSICLE_COMPONENT_H__
