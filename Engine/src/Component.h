#ifndef     __COMPONENT_H__
# define    __COMPONENT_H__

namespace   Component
{
	static int uniqueId()
	{
		static int id = 0;
		return id++;
	}

	struct Base
	{
		Base(){}
		virtual ~Base(){}
		virtual Base &operator=(const Base &other)
		{
			return *this;
		}
	};

	template <class T>
	struct ComponentBase : public Base
	{
		static unsigned int getTypeId()
		{
			static unsigned int id = uniqueId();
			return id;
		}
	};
};

#endif      //__COMPONENT_H__