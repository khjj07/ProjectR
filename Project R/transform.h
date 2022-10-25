#pragma once
#include "component.h"
#include "define.h"
#include <typeinfo>
class Component;
class Transform : public Component 
{
public:
	Transform(Vector2<float> p,Vector2<int>s, GameObject* go, vector<Component*>* c);
	Vector2<float> position;
	Vector2<int> size;
	Vector2<float> center;
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