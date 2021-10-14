#include <iostream>
#include <string>
#include <vector>


struct RouteTree
{
	
};

std::vector<std::string> airports = { "BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN",
									"JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD"};

std::vector<std::pair<std::string, std::string>> routes =
{
	std::make_pair<std::string, std::string>("DSM", "ORD"),
	std::make_pair<std::string, std::string>("ORD", "BGI"),
	std::make_pair<std::string, std::string>("BGI", "LGA"),
	std::make_pair<std::string, std::string>("SIN", "CDG"),
	std::make_pair<std::string, std::string>("CDG", "SIN"),
	std::make_pair<std::string, std::string>("CDG", "BUD"),
	std::make_pair<std::string, std::string>("DEL", "DOH"),
	std::make_pair<std::string, std::string>("DEL", "CDG"),
	std::make_pair<std::string, std::string>("TLV", "DEL"),
	std::make_pair<std::string, std::string>("EWR", "HND"),
	std::make_pair<std::string, std::string>("HND", "ICN"),
	std::make_pair<std::string, std::string>("HND", "JFK"),
	std::make_pair<std::string, std::string>("ICN", "JFK"),
	std::make_pair<std::string, std::string>("JFK", "LGA"),
	std::make_pair<std::string, std::string>("EYW", "LHR"),
	std::make_pair<std::string, std::string>("LHR", "SFO"),
	std::make_pair<std::string, std::string>("SFO", "SAN"),
	std::make_pair<std::string, std::string>("SFO", "DSM"),
	std::make_pair<std::string, std::string>("SAN", "EYW"),
};

std::vector<std::pair<std::string, unsigned>> getMinimumRoutes(std::vector<std::string> airports, std::vector<std::pair<std::string, std::string>> routes, std::string startingAirport)
{

}


int main()
{
	std::string startingAirport = "LGA";
	auto result = getMinimumRoutes(airports, routes, startingAirport);


}