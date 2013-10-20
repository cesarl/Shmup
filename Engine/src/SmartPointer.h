#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

#include <assert.h>
#include <stdlib.h>

namespace Utils
{
	template<class T>
	class SmartPointer
	{
	public:
		struct SReferenceCount
		{
			T					*pointer;
			unsigned long int 	count;
		};

	private:
		SReferenceCount 			*_reference;

	public:
		inline SmartPointer();
		inline SmartPointer(SmartPointer const &oth);
		inline SmartPointer(T *ptr);
		inline ~SmartPointer();

		inline void 					SetReferencePointer(SReferenceCount *ref);

		template<class U>
		inline operator SmartPointer<U>() const;

		inline SmartPointer 	&operator=(SmartPointer const &oth);
		inline SmartPointer 	&operator=(T *ptr);
		inline T 				&operator*() const;
		inline T 				*operator->() const;
		inline bool 			operator==(SmartPointer const &oth) const;
		inline bool 			operator!=(SmartPointer const &oth) const;
		inline bool 			operator==(T *oth) const;
		inline bool 			operator!=(T *oth) const;
	};
};

#include "SmartPointer.hpp"

#endif //__SMARTPOINTER_H__