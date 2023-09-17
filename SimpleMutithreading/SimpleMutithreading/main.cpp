#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#define HDR_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

class Timer
{
public:
	Timer()
	{
		reset();
	}

	void reset()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	float elapsed()
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_start).count() * 0.001f * 0.001f * 0.001f;
	}

	float elapsed_milliseconds()
	{
		return elapsed() * 1000.0f;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};

void rendering()
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(2000ms);
}

void physics()
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1000ms);
}

int main()
{

	while (true)
	{
		Timer timer;

		std::thread t1(rendering);
		std::thread t2(physics);

		t1.join();
		t2.join();
		std::cout << timer.elapsed_milliseconds() << std::endl;
	}


	return 0;
}