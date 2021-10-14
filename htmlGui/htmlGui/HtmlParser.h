#include <string>
#include <vector>

class HtmlParser
{
public:
	HtmlParser(const std::string&);
	HtmlParser(const HtmlParser&) = delete;
	HtmlParser(const HtmlParser&&) = delete;

	const std::vector<std::string> html_elements;
private:


};