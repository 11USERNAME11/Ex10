// Copyright 2020 Mikhail Bogomazov
#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_
#include <string>

std::string infix2postfix(std::string infix);
bool parseSymbol(const std::string &symbol);
int getPriority(const std::string &s);
bool isOperator(const std::string &s);

#endif  // INCLUDE_POSTFIX_H_
