#ifndef   __STRING_ID_HPP__
# define  __STRING_ID_HPP__

#include <map>
#include <string>

namespace Utils
{
	class Tag
	{
	private:
		class StringId
		{
		public:
			unsigned int getId(const std::string &tag)
			{
				std::map<std::string, unsigned int>::iterator it = list_.find(tag);
				if (it != std::end(list_))
					return it->second;
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
		};
	public:
		Tag(const std::string &tag = "")
			: str_(tag),
			id_(0)
		{
			id_ = manager_.getId(tag);
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
		std::string str_;
		unsigned int id_;
		static StringId manager_;
	};
};

#endif    //__STRING_ID_HPP__