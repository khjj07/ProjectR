#include "animation.h"


Animation::Animation(Renderer* r)
{
	renderer = r;
}
void Animation::Play()
{
	isPlaying = true;
	renderer->shape=frame[count];
	count= count>frame.size()-1 ? count = 0: count+1;
}

void Animation::AddFrame(string str)
{
	frame.push_back(str);
}