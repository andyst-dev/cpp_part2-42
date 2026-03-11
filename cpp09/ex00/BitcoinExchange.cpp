#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool validDate(const std::string &d)
{
	if (d.size() != 10 || d[4] != '-' || d[7] != '-')
		return false;

	for (size_t i = 0; i < d.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(d[i]))
			return false;
	}

	int y = ::atoi(d.substr(0, 4).c_str());
	int m = ::atoi(d.substr(5, 2).c_str());
	int day = ::atoi(d.substr(8, 2).c_str());

	if (m < 1 || m > 12)
		return false;

	int mdays = 31;

	if (m == 4 || m == 6 || m == 9 || m == 11)
		mdays = 30;

	else if (m == 2)
	{
		bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
		if (leap)
			mdays = 29;
		else
			mdays = 28;
	}

	if (day < 1 || day > mdays)
		return false;
	
	return true;
}

static std::string trim(const std::string &str)
{
	size_t start = 0;
	size_t end = str.size();

	while (start < end && (str[start] == ' ' || str[start] == '\t'))
		start++;

	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;

	std::string result = str.substr(start, end - start);
	return result;
}

static bool parseDataLine(const std::string &line, std::string &date, double &value)
{
	std::istringstream iss(line);
	std::string valStr;

	std::getline(iss, date, ',');
	std::getline(iss, valStr);

	std::istringstream vs(valStr);
	vs >> value;

	if (vs.fail())
		return false;
	
	return true;
}

static bool parseInputLine(const std::string &line, std::string &date, double &value)
{
	std::istringstream iss(line);
	std::string valStr;

	std::getline(iss, date, '|');
	std::getline(iss, valStr);

	date = trim(date);
	valStr = trim(valStr);

	std::istringstream vs(valStr);
	vs >> value;

	if (vs.fail())
		return false;
	
	return true;
}

bool BitcoinExchange::loadData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	if (!std::getline(file, line))
		return false;

	while (std::getline(file, line))
	{
		std::string d;
		double v;
		if (!parseDataLine(line, d, v) || !validDate(d))
			continue;

		_rates[d] = v;
	}
	
	return true;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: cannot open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string d;
		double v;
		if (!parseInputLine(line, d, v) || !validDate(d))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (v < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (v > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = _rates.lower_bound(d);

		if (it == _rates.end() || it->first != d)
		{
			if (it == _rates.begin())
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			--it;
		}

		std::cout << d << " => " << v << " = " << (v * it->second) << std::endl;
	}
}

