#include "StringHandler.hpp"
#include <string>

std::string Calculate(std::string equation);
std::string CalculateBrackets(std::string equation);

int main()
{
	std::vector<size_t> operators;
	int* intArray;
	int answer = 0;

	std::string equation;
	std::cout << "Please Enter a sum:\n";
	std::cin >> equation;

	//Checks if equation only contains valid characters
	if (equation.find_first_not_of("123456789+-*/()") != std::string::npos) {
		std::cout << "Equation contained an illegal character. Please make sure to only use: Digits, operators and brackets.";
		return 0;
	}
	equation = CalculateBrackets(equation);
	equation = Calculate(equation);
	std::cout << "The answer is : " << equation;
}

/// <summary>
/// Calculates the parts of the equation that is encased with brackets.
/// </summary>
/// <param name="equation">Holds the string of the eqation</param>
/// <returns>Returns a string of the new equation</returns>
std::string CalculateBrackets(std::string equation) {
	while (equation.find_first_of("()") != std::string::npos) {
		//Checks if the brackets are closed or opened properly
		if (equation.find_first_of("(") == std::string::npos || equation.find_first_of(")") == std::string::npos) {
			std::cout << "Equation did not contain correct form of brackets and were not closed or opened correctly.";
			break;	
		}

		size_t curOpenBracketPos = equation.find_first_of("(");
		size_t closeBrakcetPos = equation.find_first_of(")");
		std::string subEquation;

		//Checks if the current bracket is relative to the first closing brakcet
		if (equation.find("(", curOpenBracketPos + 1) != std::string::npos) {
			size_t secondOpenBracketPos = equation.find("(", curOpenBracketPos + 1);
			if (secondOpenBracketPos < closeBrakcetPos) {
				//If bracket was not reletative to eachother use the other bracket
				curOpenBracketPos = secondOpenBracketPos;
			}
		}
		subEquation = equation.substr(curOpenBracketPos + 1, closeBrakcetPos - curOpenBracketPos - 1);
		std::string ans = Calculate(subEquation);
		equation.replace(curOpenBracketPos, closeBrakcetPos - curOpenBracketPos + 1, ans);
	}
	return equation;
}

/// <summary>
/// Calculates the given equation to a string.
/// </summary>
/// <param name="equation">Holds the string of the equation</param>
/// <returns>Returns a string holding the answwer of the equation</returns>
std::string Calculate(std::string equation) {
	std::vector<size_t> operators;
	int answer = 0;
	int* intArray;

	//Performs the multiplications and divides inside the equation and injects the answers insdide the string
	while (equation.find_first_of("*/") != std::string::npos) {
		//Gets the current remaining operators inside the equation
		operators = GetOperatorLocations(equation);
		for (size_t i = 0; i < operators.size(); i++)
		{
			switch (equation[operators[i]]) {
			case '*':
				intArray = parseStringToInt(equation, operators, i);
				equation = replaceStringWithAnswer(equation, intArray, '*', intArray[0] * intArray[1]);
				break;
			case '/':
				intArray = parseStringToInt(equation, operators, i);
				equation = replaceStringWithAnswer(equation, intArray, '/', intArray[0] / intArray[1]);
				break;
			}
		}
	}

	operators = GetOperatorLocations(equation);

	//Performs the final plus and minus that remains inside the equation
	for (int i = 0; i < operators.size(); i++) {
		switch (equation[operators[i]])
		{
		case '+':
			intArray = parseStringToInt(equation, operators, i, answer);
			equation = replaceStringWithAnswer(equation, intArray, '+', intArray[0] + intArray[1]);
			;
			break;
		case '-':
			intArray = parseStringToInt(equation, operators, i, answer);
			equation = replaceStringWithAnswer(equation, intArray, '-', intArray[0] - intArray[1]);
			break;
		}
	}
	return equation;
}