#ifndef		__BARCODE_H__
# define	__BARCODE_H__

#include	<bitset>
#include    "Assert.h"

namespace   Component
{
	struct  Base;
};

namespace	Game
{
	class	Entity;

	class Barcode
	{
	public:

		Barcode();
		Barcode(const Entity &entity);
		Barcode(const Barcode &other);
		Barcode &operator=(const Barcode &other);
		~Barcode();
		bool match(const std::bitset<COMPONENTS_MAX_NUMBER> &set);
		bool match(const Entity &entity);
		bool match(const Barcode &entity);
		void reset();
		void add(unsigned int componentId);
		void remove(unsigned int componentId);
		bool isEmpty();

		template <class T>
		void add()
		{
			applyChange(T::getTypeId(), true);
		}

		template <class T>
		void remove()
		{
			applyChange(T::getTypeId(), false);
		}

	private:
		void applyChange(unsigned int componentId, bool tof)
		{
			ASSERT(componentId < COMPONENTS_MAX_NUMBER, "Component ID > COMPONENTS_MAX_NUMBER");
			code_[componentId] = tof;
		}

		std::bitset<COMPONENTS_MAX_NUMBER> code_;
	};
};

#endif		//__BARCODE_H__