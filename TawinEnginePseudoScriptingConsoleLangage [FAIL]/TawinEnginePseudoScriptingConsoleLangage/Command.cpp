#include <iostream>
#include "Command.h"


Command::Command(const std::string& command) : m_full_command(command)
{
	m_frag_command = std::vector<std::string>();
	unsigned short last_blank = 0;
	Command::normalize_spacing(m_full_command);
	for (unsigned i = 0;i < m_full_command.size();i++)
		if (m_full_command[i] == ' ')
		{
			m_frag_command.push_back(m_full_command.substr(last_blank, i - last_blank) );
			last_blank = i + 1;
		}
	m_frag_command.push_back(m_full_command.substr(last_blank, m_full_command.size() - last_blank) );
}

std::string& Command::normalize_spacing(std::string& str)
{
	while (str[0] == ' ') str.erase(0, 1);
	while (str[str.size() - 1] == ' ') str.pop_back();
	for (unsigned i = 0;i < str.size();i++)
		if (str[i] == ' ')
		{
			int count = i;
			while (str[++count] == ' ');
			str.erase(i + 1, count - i - 1);
		}
	return str;
}

const std::vector<std::string>& Command::get_frag_command() const { return m_frag_command; }
const std::string& Command::get_full_command() const { return m_full_command; }