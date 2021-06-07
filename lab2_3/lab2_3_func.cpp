#include "lab2_3_func.h"
#include <stdexcept>

bool isOperator(std::string s)
{
	return (s == "+" ||
		s == "-" ||
		s == "*" ||
		s == "/") ? true : false;
}

bool isBracket(std::string s)
{
	return (s == "(" || s == ")") ? true : false;
}

bool isOperand(std::string s)
{
	if (s == "x" || s == "y" || s == "z" || s == "X" || s == "Y" || s == "Z") return true;
	int num;
	try {
		num = std::stoi(s);
		return true;
	}
	catch (const std::invalid_argument& ia) {
		return false;
	}
}

int getPriority(std::string op)
{
	if (op == "+" || op == "-") return 1;
	if (op == "*" || op == "/") return 2;
	if (op == "(" || op == ")") return 0;
}
