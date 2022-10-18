#include "gameObject.h"
#include "component.h"
#include "collision.h"

class Example :public GameObject
{
public:
	
private:

};

Example::Example()
{
	char shape[] = "aaaaaa\naaaaaaaaaa\naaaaaa";
	int width=5,height = 3;
	int id = 1;
	transform = new Transform();
	renderer = new Renderer(transform,shape);
	AddComponent(new Collision<Static>(transform,width,height, id));

}

Example::~Example()
{
}
