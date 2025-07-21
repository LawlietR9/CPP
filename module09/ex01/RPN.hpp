#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {

public:

	RPN();
	RPN(const RPN &src);
	~RPN();

	RPN &operator=(const RPN &rhs);

	int execute(const std::string &expression);

private:

	std::stack<int> _stack;

	void _executeOperation(char op);

};

#endif
