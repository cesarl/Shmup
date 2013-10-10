#ifndef		__EMPTY_SYSTEM_H__
# define	__EMPTY_SYSTEM_H__

#include	"System.h"

namespace System
{
	class sEmpty : public System::Base
	{
	public:
		sEmpty(){};
		virtual ~sEmpty(){};
		virtual void updateBegin(const ALLEGRO_EVENT & ev, double time) override;
		virtual void updateEnd(const ALLEGRO_EVENT & ev, double time) override;
		virtual void mainUpdate(const ALLEGRO_EVENT & ev, double time) override;
		virtual void initialize() override;
	};
};

#endif		//__EMPTY_SYSTEM_H__