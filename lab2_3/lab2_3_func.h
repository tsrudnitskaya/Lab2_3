#pragma once
#include <string>

bool isOperator(std::string s);
bool isBracket(std::string s);
bool isOperand(std::string s);
int getPriority(std::string op);//получение приоритета операции

#pragma endregion