#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void)rhs;
	return *this;
}

void ScalarConverter::convert(std::string const &literal) {
    std::string special_types[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    std::string type = "unknown";
    double d;
    char *end;

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        type = "char";
        d = static_cast<double>(literal[0]);
    }
    else {
        d = std::strtod(literal.c_str(), &end);
        if (*end == '\0' && literal.length() > 0) {
            if (literal.find('.') != std::string::npos) {
                if (*(end - 1) == 'f') {
                    type = "float";
                }
                else
                    type = "double";
            }
            else
                type = "int";
        }
        else {
            for (int i = 0; i < 6; ++i) {
                if (literal == special_types[i]) {
                    type = "special";
                    break;
                }
            }
        }
    }

    std::cout << "char: ";
    if (type == "special" || std::isnan(d) || std::isinf(d)) {
        std::cout << "impossible" << std::endl;
    } else if (!isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    std::cout << "int: ";
    if (type == "special" || std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    std::cout << "float: ";
    if (literal == "nan" || literal == "nanf") {
        std::cout << "nanf" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "+inff" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "-inff" << std::endl;
    } else if (type == "special") {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<float>(d) << (d == static_cast<int>(d) ? ".0f" : "f") << std::endl;
    }

    std::cout << "double: ";
    if (literal == "nan" || literal == "nanf") {
        std::cout << "nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "+inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "-inf" << std::endl;
    } else if (type == "special") {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
    }
}
