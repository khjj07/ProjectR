#include<time.h>
#include <functional>
#include <thread>
#include "define.h"

using std::thread;

class Timer
{
public:
	static thread * Delay(float time, bool loop, function<void()>);
	static vector<thread*> timerlist;
protected:
private:
};
