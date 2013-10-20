#pragma once

#include   <string>
#include   <map>
//#include   "StringId.hpp"

template   <class DataType>
class      Resource
{
public:
	Resource(const std::string &id)
		: _id(id)
		, _isReady(false) {
			if (_map.find(_id) != _map.end())
			{
				_isReady = true;
				_data = *_map[_id];
			}
	}


	Resource(const Resource &other)
	: _id(other._id)
	, _data(other._data)
	, _isReady(other._isReady)
{}



	Resource &operator=(const Resource &other)
{
	if (this != &other) {
		_id = other._id;
		_data = other._data;
		_isReady = other._isReady;
	}
	return *this;
}

	~Resource()
	{}

	template<typename Function>
	bool load(Function function)
	{
		if (_map.find(_id) == _map.end())
		{
			_map[_id] = &_data;
			if (function(_data))
			{
				_isReady = true;
				return true;
			}
			return false;
		}
		_data = *_map[_id];
		_isReady = true;
		return true;
	}



	bool fromFile(const std::string &path)
	{
		return load([&path] (DataType &data) -> bool {
			return data.loadFromFile(path);
		});
	}

	bool isReady() const
	{
		return _isReady;
	}

	operator DataType &()
	{
		return _data_;
	}

private:
	static std::map<std::string, DataType *> _map;
	std::string _id;
	DataType _data;
	bool _isReady;
};
