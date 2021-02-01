#include <iostream>
#include <string>
#include <vector>

//Parses to given string to an int and splits the integers in seperate arrays
int* parseStringToInt(std::string equation, std::vector<size_t> ops, int index, int curAns) {
	static int subStrArray[2];
	int endLoc;
	if (ops.size() < index) {
		endLoc = ops[index + 1] - 1;
	}
	else {
		endLoc = std::string::npos;
	}

	try { 
		if (curAns != 0 )
		{
			subStrArray[0] = curAns;
			subStrArray[1] = std::stoi(equation.substr(ops[index] + 1, endLoc));
		}
		else {
			subStrArray[0] = std::stoi(equation.substr(0, ops[index]));
			subStrArray[1] = std::stoi(equation.substr(ops[index] + 1, endLoc));
		}
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