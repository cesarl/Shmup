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
			: generation(500),
			age(500)
		{}

		virtual ~cPopsicle(){}

		int generation;
		int age;
	};
};

#endif     //__POPSICLE_COMPONENT_H__
