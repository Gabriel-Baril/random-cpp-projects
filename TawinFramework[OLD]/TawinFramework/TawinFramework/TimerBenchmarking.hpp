#pragma once
#include <iostream>
#include <chrono>

class TimerBenchmarking
{
	std::chrono::time_point<std::chrono::steady_clock> m_start_time_point;
public:
	TimerBenchmarking();
	~TimerBenchmarking();
};