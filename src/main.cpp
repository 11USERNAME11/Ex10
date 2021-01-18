// Copyright 2020 Mikhail Bogomazov
#include <iostream>
#include <string>
#include "../include/postfix.h"

int main() {
  std::string s = "2 + 6 * 3 / (4 - 2)";
  std::cout << infix2postfix(s).compare("2 6 3 * 4 2 - / +")<< std::endl;
  return 0;
}
