#pragma once
#include "collection.h"
#include "singleton.h"
class IngameCollection : public Collection, public Singleton<IngameCollection>
{
public:
	IngameCollection();
private:
	
};
