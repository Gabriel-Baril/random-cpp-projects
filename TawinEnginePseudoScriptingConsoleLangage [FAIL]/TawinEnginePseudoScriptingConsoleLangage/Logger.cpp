#include "Logger.h"

Logger Logger::instance;

Logger::Logger()
{

}

Logger& Logger::get_instance()
{
	return Logger::instance;
}

void Logger::log(const std::string & source, const std::string & msg, const unsigned short& color, bool reset_color)
{
	std::lock(m_log_mutex, m_warning_mutex, m_error_mutex);
	std::lock_guard<std::mutex> lg_log_mutex(m_log_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_warning_mutex(m_warning_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_error_mutex(m_error_mutex, std::adopt_lock);

	SetConsoleTextAttribute(Logger::m_out_console, color);
	std::cout << "[LOG (" << source << ")]" << " : " << msg << "\n";
	if (reset_color)
		SetConsoleTextAttribute(Logger::m_out_console, 15);
}

void Logger::warning(const std::string& source, const std::string& msg)
{
	std::lock(m_log_mutex, m_warning_mutex, m_error_mutex);
	std::lock_guard<std::mutex> lg_log_mutex(m_log_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_warning_mutex(m_warning_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_error_mutex(m_error_mutex, std::adopt_lock);

	SetConsoleTextAttribute(Logger::m_out_console, 14);
	std::cout << "[WARNING (" << source << ")]" << " : ";
	SetConsoleTextAttribute(Logger::m_out_console, 15);
	std::cout << msg << "\n";
}

void Logger::error(const std::string& source, const std::string& msg)
{
	std::lock(m_log_mutex, m_warning_mutex, m_error_mutex);
	std::lock_guard<std::mutex> lg_log_mutex(m_log_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_warning_mutex(m_warning_mutex, std::adopt_lock);
	std::lock_guard<std::mutex> lg_error_mutex(m_error_mutex, std::adopt_lock);

	SetConsoleTextAttribute(Logger::m_out_console, 12);
	std::cout << "[ERROR (" << source << ")]" << " : ";
	SetConsoleTextAttribute(Logger::m_out_console, 15);
	std::cout << msg << "\n";
}

Logger& Logger::operator()() const
{
	return instance;
}

