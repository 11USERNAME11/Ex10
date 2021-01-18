// Copyright 2020 Mikhail Bogomazov
#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <vector>
#include "../include/MyStack.h"
#include "../include/postfix.h"

std::string infix2postfix(std::string infix) {
  std::string res;
  for (int i = 0; i < static_cast<int>(infix.length()); i++) {
    if (infix[i-1] == '(' || infix[i] == ')') {
      infix.insert(i, " ");
      i++;
    }
  }
  std::istringstream iss(infix);
  std::vector<std::string> tokens;
  while (iss) {
    std::string temp;
    iss >> temp;
    tokens.push_back(temp);
  }
  std::vector<std::string> outputList;
  MyStack<std::string> st;


  for (unsigned int i = 0; i < tokens.size(); i++) {
    if (parseSymbol(tokens[i])) {
        outputList.push_back(tokens[i]);
    }
    if (tokens[i] == "(") {
        st.push(tokens[i]);
    }
    if (tokens[i] == ")") {
      while (!st.isEmpty() && st.get() != "(") {
        outputList.push_back(st.get());
        st.pop();
      }
      st.pop();
    }
    if (isOperator(tokens[i]) == true) {
      while (!st.isEmpty() &&
        getPriority(st.get()) >= getPriority(tokens[i])) {
          outputList.push_back(st.get());
          st.pop();
      }
      st.push(tokens[i]);
    }
  }
  while (!st.isEmpty()) {
    outputList.push_back(st.get());
    st.pop();
  }

  for (unsigned int i = 0; i < outputList.size(); i++) {
    res += outputList[i];
    res += " ";
  }
  return res.substr(0, res.size()-1);
}

bool parseSymbol(const std::string &symbol) {
  bool isNumber = false;
  for (unsigned int i = 0; i < symbol.size(); i++) {
    if (!isdigit(symbol[i])) {
      isNumber = false;
    } else {
      isNumber = true;
    }
  }
  return isNumber;
}

int getPriority(const std::string &s) {
  if (s == "*" || s == "/") {
      return 2;
  }
  if (s== "+" || s == "-") {
      return 1;
  } else {
    return 0;
  }
}

bool isOperator(const std::string &s) {
  return (s == "+" || s == "-" || s == "*" || s == "/");
}
