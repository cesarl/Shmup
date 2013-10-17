#ifndef    __RESSOURCE_H__
# define   __RESSOURCE_H__

#include   <string>
#include   <map>
#include   "StringId.hpp"

template   <class DataType>
class      Resource
{
public:
	Resource(const Utils::Tag &id);
	Resource(const Resource &other);
	Resource &operator=(const Resource &other);
	~Resource();

	template<typename Function>
	bool load(Function function);
	bool fromFile(const std::string &path);
	bool isReady() const;
	operator DataType &();

private:
	static std::map<std::string, DataType *> _map;
	std::string _id;
	DataType _data;
	bool _isReady;
};

#endif    //__RESSOURCE_H__

/*

#pragma once

template<class DataType>
std::map<std::string, DataType *> Resource<DataType>::_map;

template<class DataType>
Resource<DataType>::Resource(std::string const &id)
: _id(id)
, _isReady(false) {
if (_map.find(_id) != _map.end()) {
_isReady = true;
_data = *_map[_id];
}
}

template<class DataType>
Resource<DataType>::Resource(Resource const &other)
: _id(other._id)
, _data(other._data)
, _isReady(other._isReady) {}

template<class DataType>
Resource<DataType> &Resource<DataType>::operator=(Resource const &other) {
if (this != &other) {
_id = other._id;
_data = other._data;
_isReady = other._isReady;
}
return *this;
}

template<class DataType>
Resource<DataType>::~Resource() {}

template<class DataType>
Resource<DataType>::operator DataType &() {
return _data;
}

template<typename DataType>
template<typename Function>
bool Resource<DataType>::load(Function function) {
if (_map.find(_id) == _map.end()) {
_map[_id] = &_data;
if (function(_data)) {
_isReady = true;
return true;
}
return false;
}
_data = *_map[_id];
_isReady = true;
return true;
}

template<class DataType>
bool Resource<DataType>::fromFile(std::string const &path) {
return load([&path] (DataType &data) -> bool {
return data.loadFromFile(path);
});
}

*/