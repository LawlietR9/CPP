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
    char *end;
    double d = std::strtod(literal.c_str(), &end);

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        type = "char";
        d = literal[0];
    } else {
        for (int i = 0; i < 6; ++i) {
            if (literal == special_types[i]) {
                type = "special";
                break;
            }
        }
        if (type == "unknown") {
            if (*end == 'f' && *(end + 1) == '\0') {
                type = "float";
            } else if (*end == '\0') {
                type = "double";
            }
        }
    }

    // char
    std::cout << "char: ";
    if (type == "special" || std::isnan(d) || std::isinf(d)) {
        std::cout << "impossible" << std::endl;
    } else if (!isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // int
    std::cout << "int: ";
    if (type == "special" || std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // float
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

    // double
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
