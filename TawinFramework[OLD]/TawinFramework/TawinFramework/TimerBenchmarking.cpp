#include "TimerBenchmarking.hpp"

TimerBenchmarking::TimerBenchmarking() : m_start_time_point(std::chrono::steady_clock::now()) {}

TimerBenchmarking::~TimerBenchmarking()
{
	auto end_time_point = std::chrono::steady_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_start_time_point).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(end_time_point).time_since_epoch().count();

	double duration = end - start;

	std::cout << "Time pass : " << "\n\t" << (duration / 1000000000) << " seconds\n";
	std::cout << "\t" << (duration / 1000000) << " milliseconds\n";
	std::cout << "\t" << (duration / 1000) << " microseconds\n";
	std::cout << "\t" << duration << " nanoseconds\n";

}