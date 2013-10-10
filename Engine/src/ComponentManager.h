#ifndef    __COMPONENT_MANAGER_H__
# define   __COMPONENT_MANAGER_H__

#include "Singleton.hpp"

namespace Component
{
	class Base;

	class Manager : public Utils::Singleton<Manager>
	{
	public:
		friend class Utils::Singleton<Manager>;
	private:
		Manager();
		virtual ~Manager();
	};
};

#endif     //__COMPONENT_MANAGER_H__