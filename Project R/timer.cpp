#include "timer.h"
#include <thread>
thread *Timer::Delay(float time, bool loop, function<void()> x)
{
	thread timer([x,time,loop]() {
		do
		{
			clock_t start = clock();
			for (;;)
			{
				clock_t end = clock();
				float t = (end - start) / CLOCKS_PER_SEC;
				if (t == time)
				{
					break;
				}
			}
			x();
		} while (loop);
		
		});
	timer.detach();
	return &timer;
}
