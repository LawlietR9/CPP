#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs)
		this->_data = rhs._data;
	return *this;
}

void BitcoinExchange::readData(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open data file.");

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		double rate;
		std::getline(ss, date, ',');
		ss >> rate;
		_data[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, valueStr;
		double value;

		if (std::getline(ss, date, '|') && ss >> value) {
			date.erase(date.find_last_not_of(" ") + 1);
			date.erase(0, date.find_first_not_of(" "));
			if (!_isValidDate(date))
				std::cerr << "Error: bad input => " << date << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
				_printResult(date, value);
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}

void BitcoinExchange::_printResult(const std::string &date, double value) const {
	std::map<std::string, double>::const_iterator it = _data.find(date);
	if (it == _data.end()) {
		it = _data.lower_bound(date);
		if (it == _data.begin())
			return;
		--it;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

bool BitcoinExchange::_isValidDate(const std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			if (day > 29)
				return false;
		} else {
			if (day > 28)
				return false;
		}
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	return true;
}
