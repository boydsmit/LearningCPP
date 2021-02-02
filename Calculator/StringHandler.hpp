#pragma once
#include <iostream>
#include <vector> 

int* parseStringToInt(std::string equation, std::vector<size_t> ops, int index, int curAns = 0);
std::vector<size_t> GetOperatorLocations(std::string equation);
std::string replaceStringWithAnswer(std::string string, int* intArray, char op, int replacer);