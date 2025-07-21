#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

int RPN::execute(const std::string &expression) {
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
			_executeOperation(token[0]);
		} else {
			int value = std::atoi(token.c_str());
			if (value < 0 || value > 9)
				throw std::runtime_error("Error");
			_stack.push(value);
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}

void RPN::_executeOperation(char op) {
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int rhs = _stack.top();
	_stack.pop();
	int lhs = _stack.top();
	_stack.pop();

	if (op == '+')
		_stack.push(lhs + rhs);
	else if (op == '-')
		_stack.push(lhs - rhs);
	else if (op == '*')
		_stack.push(lhs * rhs);
	else if (op == '/') {
		if (rhs == 0)
			throw std::runtime_error("Error: Division by zero.");
		_stack.push(lhs / rhs);
	}
}
