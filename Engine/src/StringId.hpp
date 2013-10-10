#ifndef   __STRING_ID_HPP__
# define  __STRING_ID_HPP__

#include <map>
#include <string>
#include "Singleton.h"

namespace Utils
{
	class StringId : public Singleton<StringId>
	{
	public:
		unsigned int getId(const std::string &tag)
		{
			auto it = list_.find(tag);
			if (it != std::end(list_))
				return it.second;
			list_.insert(std::pair<std::string, unsigned int>(tag, id_));
			return id_++;

		}
	private:
		StringId()
			: id_(0)
		{}

		virtual ~StringId()
		{}
	private:
		unsigned int id_;
		std::map<std::string, unsigned int> list_;
		friend class Singleton<StringId>;
	};
};

#endif    //__STRING_ID_HPP__