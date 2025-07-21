#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {

public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void readData(const std::string &filename);
	void processInput(const std::string &filename);

private:

	std::map<std::string, double> _data;

	void _printResult(const std::string &date, double value) const;
	bool _isValidDate(const std::string &date) const;
	bool _isValidValue(const std::string &valueStr, double &value) const;

};

#endif
