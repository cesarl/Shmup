#ifndef   __STRING_ID_HPP__
# define  __STRING_ID_HPP__

#include <map>
#include <string>

namespace Utils
{
	class Tag
	{
	public:
		Tag(const std::string &tag = "")
			: str_(tag),
			id_(0)
		{
			id_ = getId_(tag);
		}

		Tag(const Tag &other)
		{
			str_ = other.str_;
			id_ = other.id_;
		}

		Tag &operator=(const Tag &other)
		{
			str_ = other.str_;
			id_ = other.id_;
			return *this;
		}

		~Tag()
		{}

		const std::string &getString() const
		{
			return str_;
		}

		const unsigned int getId() const
		{
			return id_;
		}

		bool operator==(const Tag &other)
		{
			return (id_ == other.id_);
		}

		bool operator!=(const Tag &other)
		{
			return (id_ != other.id_);
		}
	private:
		unsigned int getId_(const std::string &tag)
		{
			static unsigned int idCounter = 0;
			static std::map<std::string, unsigned int> list;

			std::map<std::string, unsigned int>::iterator it = list.find(tag);
			if (it != std::end(list))
				return it->second;
			list.insert(std::pair<std::string, unsigned int>(tag, idCounter));
			return idCounter++;
		}

		std::string str_;
		unsigned int id_;
	};
};

#endif    //__STRING_ID_HPP__