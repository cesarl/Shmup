#pragma once

#include "Ressource.h"

template <class DataType>
std::map<std::string, DataType *> Resource<DataType>::_map;

template <class DataType>
Resource<DataType>::Resource(const Utils::Tag &id)
	: _id(id.getId())
	, _isReady(false) {
		if (_map.find(_id) != _map.end())
		{
			_isReady = true;
			_data = *_map[_id];
		}
}

template <class DataType>
Resource<DataType>::Resource(Resource const &other)
	: _id(other._id)
	, _data(other._data)
	, _isReady(other._isReady)
{}

template <class DataType>
Resource<DataType> &Resource<DataType>::operator=(Resource const &other)
{
	if (this != &other) {
		_id = other._id;
		_data = other._data;
		_isReady = other._isReady;
	}
	return *this;
}

template <class DataType>
Resource<DataType>::~Resource()
{}

template <class DataType>
Resource<DataType>::operator DataType &()
{
	return _data;
}

template <typename DataType>
template <typename Function>
bool Resource<DataType>::load(Function function) {
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

template <class DataType>
bool Resource<DataType>::fromFile(std::string const &path)
{
	return load([&path] (DataType &data) -> bool {
		return data.loadFromFile(path);
	});
}