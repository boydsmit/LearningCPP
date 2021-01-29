#include <iostream>
#include <string>
#include <vector>

//Parses to given string to an int and splits the integers in seperate arrays
int* parseStringToInt(std::string equation, char op) {
	static int subStrArray[2];

	try {
		subStrArray[0] = std::stoi(equation.substr(0, equation.find(op)));
		subStrArray[1] = std::stoi(equation.substr(equation.find(op) + 1, std::string::npos));
		return subStrArray;
	}
	catch (std::exception& err) {
		std::cout << "Something went wrong parsing the string to an integer";
		return 0;
	}
}

//Finds all operators that are used in the equation
std::vector<size_t> GetOperatorLocations(std::string equation) {
	std::vector<size_t> positions;
	
	for (int i = 0; i < equation.size(); i++)
	{
		switch (equation[i]) {
		case '+':
			positions.push_back(i);
			break;
		case '-':
			positions.push_back(i);
			break;
		case '*':
			positions.push_back(i);
			break;
		case '/':
			positions.push_back(i);
			break;
		}
	}
	return positions;
}