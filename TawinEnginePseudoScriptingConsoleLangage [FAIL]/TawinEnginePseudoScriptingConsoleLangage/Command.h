#pragma once
#include <vector>
#include <string>

class Command
{
	std::string m_full_command;
	std::vector<std::string> m_frag_command;
public:
	Command(const std::string& command);
	static std::string& normalize_spacing(std::string& str);
	const std::vector<std::string>& get_frag_command() const;
	const std::string& get_full_command() const;
};