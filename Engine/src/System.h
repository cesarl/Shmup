#ifndef		__SYSTEM_H__
# define	__SYSTEM_H__

#include    <allegro5/allegro.h>
#include    <set>
#include	"Barcode.h"

class Entity;

namespace	Utils
{
	class	Barcode;
}

class       Entity;
class       EntityManager;

namespace	System
{
	class   SystemManager;
	typedef SystemManager Manager;

	class	Base
	{
	public:
		Base();
		virtual ~Base();
		void update(const ALLEGRO_EVENT & ev, double time);
		void entityUpdated(const Entity &entity);
		void init();
		const Utils::Barcode &getCode() const;

		template <typename T>
		void require()
		{
			code_.add<T>();
		}


	protected:
		std::set<unsigned int> collection_;
		Utils::Barcode code_;
	private:
		virtual void updateBegin(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void updateEnd(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void mainUpdate(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void initialize() = 0;
	};
};

#endif		//__SYSTEM_H__