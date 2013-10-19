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
			: persisttime(100), // time remaining for split
			divideTime(10), // time remaining before split
			removeComponentTime(8), // time remaining before cpt remove
			addComponentTime(7), // time remaining before cpt add
			lifetime(10) // lifetime

		{}

		int persisttime;
		int divideTime;
		int removeComponentTime;
		int addComponentTime;
		int lifetime;

		virtual ~cPopsicle(){}
	};
};

#endif     //__POPSICLE_COMPONENT_H__
