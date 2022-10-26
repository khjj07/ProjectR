#pragma once
#include "collection.h"
#include "singleton.h"

class Empty : public Collection,public Singleton<Empty>
{
public:
	Empty();
private:

};
