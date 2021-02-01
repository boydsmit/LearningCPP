#pragma once
#include <iostream>
#include <vector>

int* parseStringToInt(std::string equation, std::vector<size_t> ops, int index, int curAns);
std::vector<size_t> GetOperatorLocations(std::string equation);