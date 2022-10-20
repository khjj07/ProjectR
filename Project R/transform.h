#pragma once
#include "component.h"
#include "define.h"
#include <typeinfo>

class Transform : public Component 
{
public:
	Transform(Vector2<int> p, Vector2<int>s, vector<Component*>* c);
	Vector2<int> position;
	Vector2<int> size;
	Vector2<int> center;
	vector<Component*> *componentList;
	template<typename T>
	T* GetComponent();
private:
	
}; 

template<typename T>
T* Transform::GetComponent()
{
	vector<Component*>::iterator component =  componentList->begin();
	for (; component < componentList->end(); component++)
	{
		if (typeid(T).name() == typeid(**component).name())
			return (T*)*component;
	}
}