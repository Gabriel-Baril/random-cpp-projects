#include <iostream>
#include <string>

namespace hedron
{
	namespace log
	{
		namespace trivial
		{
			std::string formatter_name_properties[3] = { "SEVERITY","TIME_STAMP","MESSAGE" };
			enum PROPERTIES
			{
				severity_level,
				time_stamp,
				message
			};

			enum OPTIONS
			{
				message_color,
				format_color,
				extra_end_character
			};
		}


		void override_formatter_name_properties(trivial::PROPERTIES prop, std::string new_name)
		{
			trivial::formatter_name_properties[prop] = new_name;
		}
	}
}

enum SEVERITY_LEVEL
{
	none,
	info,
	warning,
	error,
	fatal
};

std::string SEVERITY_LEVEL_LABELS[5] = { "NONE","INFO","WARNING","ERROR","FATAL" };

class Logger
{
	SEVERITY_LEVEL level_filter;
public:
	Logger(const SEVERITY_LEVEL& sl) : level_filter{sl} {}
	Logger() : level_filter{ none } {}
	void set_filter(SEVERITY_LEVEL level) { level_filter = level; }



	void log(SEVERITY_LEVEL sl,std::string msg)
	{
		if (sl == level_filter || level_filter == none)
		{
			std::cout << "[" << SEVERITY_LEVEL_LABELS[sl] << "] : " << msg << "\n";
		}
	}
};


int main()
{
	Logger lg;

	//hedron::log::override_formatter_name_properties(hedron::log::trivial::, "SEV_LEVEL");

	for (unsigned i = 0;i < 3;i++)
	{
		lg.log(info, hedron::log::trivial::formatter_name_properties[i]);
	}
}