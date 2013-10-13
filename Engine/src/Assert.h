#ifndef    __ASSERT_H__
# define   __ASSERT_H__

#include "Settings.h"
#include <cassert>
#include <string>

inline void ASSERT(bool tof, const std::string &message)
{
	//	std::assert(tof);
	static_cast<void>(message);
}

#endif     //__ASSERT_H__