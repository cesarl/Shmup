#ifndef  __ARESSOURCE_H__
# define __ARESSOURCE_H__

#include "File.h"

class ARessource
{
public:
	ARessource(){}
	virtual ~ARessource(){}
	bool loadFromFile(const std::string &path)
	{
		Utils::File file(path);
		if (!file.exists())
			return false;
		return loadingFunction(file);
	}
private:
	virtual bool loadingFunction(const Utils::File &path) = 0;
};

#endif  //__ARESSOURCE_H__