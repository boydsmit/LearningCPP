#pragma once
#include <iostream>
#include <vector>

int* parseStringToInt(std::string equation, char op);
std::vector<size_t> GetOperatorLocations(std::string equation);