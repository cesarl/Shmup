#ifndef		__SYSTEM_H__
# define	__SYSTEM_H__

#include    <allegro5/allegro.h>
#include    <set>
#include	"Barcode.h"

class Entity;

namespace	Game
{
	class	Barcode;
	class   Entity;
}

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
		void entityUpdated(const Game::Entity &entity);
		void init();
		const Game::Barcode &getCode() const;
		void entityUpdated(const Game::Entity &entity);
		static SystemManager &Manager();

		template <typename T>
		void require();

	protected:
		std::set<unsigned int> collection_;
		Game::Barcode code_;
	private:
		virtual void updateBegin(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void updateEnd(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void mainUpdate(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void initialize() = 0;
	};
};

#endif		//__SYSTEM_H__