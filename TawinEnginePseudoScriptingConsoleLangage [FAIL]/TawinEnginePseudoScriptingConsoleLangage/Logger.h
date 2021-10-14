#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <mutex>

class Logger
{
	static Logger instance;
	HANDLE m_out_console = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE m_in_console = GetStdHandle(STD_INPUT_HANDLE);
	std::mutex m_log_mutex;
	std::mutex m_warning_mutex;
	std::mutex m_error_mutex;

	Logger();
public:
	static Logger& get_instance();

	void log(const std::string& source, const std::string& msg, const unsigned short& color, bool reset_color);
	void warning(const std::string& source, const std::string& msg);
	void error(const std::string& source, const std::string& msg);

	Logger& operator()() const;
};