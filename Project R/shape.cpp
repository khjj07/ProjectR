#include "shape.h"
Shape::Shape()
{

}
string Shape::Load(string name)
{
	string result;
	char source[1000];
	ifstream readfile;
	readfile.open("" + name);
	if (readfile.is_open())
	{
		while (readfile)
		{
			readfile.getline(source, Screen::Width);
			result.append(source);
			result.append("\n");	
		}
		;
	}
	return result;
}