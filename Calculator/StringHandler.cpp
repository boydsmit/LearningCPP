#include <iostream>
#include <string>
#include <vector>

/// <summary>
/// Parses to given string to an int and splits the integers in seperate arrays.
/// </summary>
/// <param name="equation">Holds the string of the equation</param>
/// <param name="ops">Holds the locations of all the operators</param>
/// <param name="index">Holds the index of the current iteration</param>
/// <param name="curAns">Holds the previous given answer</param>
/// <returns>Returns a pointer to an integer array</returns>
int* parseStringToInt(std::string equation, std::vector<size_t> ops, int index, int curAns) {
	static int subStrArray[2];
	int startLoc = 0;
	int endLoc;

	if (index != 0) {
		startLoc = ops[index - 1] + 1;
	}

	if (ops.size() < index) {
		endLoc = ops[index + 1] - 1;
	}
	else {
		endLoc = std::string::npos;
	}

	try { 
		if (curAns != 0 )
		{
			//If an answer is already existant the answer needs to be incremented with the next value
			subStrArray[0] = curAns;
			subStrArray[1] = std::stoi(equation.substr(ops[index] + 1, endLoc));
		}
		else {
			subStrArray[0] = std::stoi(equation.substr(startLoc, ops[index]));
			subStrArray[1] = std::stoi(equation.substr(ops[index] + 1, endLoc));
		}
		return subStrArray;
	}
	catch (std::exception& err) {
		std::cout << "Something went wrong parsing the string to an integer";
		return 0;
	}
}

/// <summary>
/// Finds all operators that are used in the equation.
/// </summary>
/// <param name="equation">Holds the string of the equation</param>
/// <returns>Returns a vector of the found operators</returns>
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

/// <summary>
/// Replaces a part of the equation with the given answer of the specific part.
/// </summary>
/// <param name="string">Holds the string that needs to be replaced</param>
/// <param name="intArray">Holds the integers of the string the old string that needs to be replaced</param>
/// <param name="op">Holds the current used operator of the equation</param>
/// <param name="replacer">Holds the answer the string needs to be replaced with</param>
/// <returns>Returns a string that holds the new equation</returns>
std::string replaceStringWithAnswer(std::string string, int* intArray, char op, int replacer) {
	std::string subString = std::to_string(intArray[0]) + op + std::to_string(intArray[1]);
	size_t index = string.find(subString);
	return string.replace(index, subString.length(), std::to_string(replacer));
}