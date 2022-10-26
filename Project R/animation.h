#pragma once
#include "component.h"
#include "transform.h"
#include "Renderer.h"
#include <vector>

class Animation
{
public:
	Animation(Renderer* r);
	
	void AddFrame(string str);
	void Play();


	static Animation* currentPlaying;
	Renderer* renderer;
	vector<string> frame;
	int count;
	bool isPlaying = false;


private:

};
