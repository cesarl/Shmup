#ifndef		__SYSTEM_H__
# define	__SYSTEM_H__

#include    <allegro5/allegro.h>
#include    <unordered_set>
#include    "SystemManager.h"
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
		void entityUpdated(Entity &entity);
		void init();
		const Utils::Barcode &getCode() const;

		template <typename T>
		void require()
		{
			code_.add<T>();
			manager_.subscribeToAdd<T>(this);
		}


	protected:
		std::unordered_set<unsigned int> collection_;
		std::list<std::pair<bool, unsigned int> > toAddOrTrash_;
		bool isUpdating_;
		Utils::Barcode code_;
		static SystemManager &manager_;
	private:
		virtual void updateBegin(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void updateEnd(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void mainUpdate(const ALLEGRO_EVENT & ev, double time) = 0;
		virtual void initialize() = 0;
		void postUpdateCollection_();
	};
};

#endif		//__SYSTEM_H__