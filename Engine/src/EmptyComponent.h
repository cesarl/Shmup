#ifndef    __EMPTY_COMPONENT_H__
# define   __EMPTY_COMPONENT_H__

#include   "Component.h"

namespace  Component
{
	struct cEmpty : public ComponentBase<cEmpty>
	{
		cEmpty(){}
		virtual ~cEmpty(){}
	};
};

#endif     //__EMPTY_COMPONENT_H__