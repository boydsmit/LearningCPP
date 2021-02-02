#include "StringHandler.hpp"
#include <string>

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
	
	//Performs the multiplications and divides inside the equation and injects the answers insdide the string
	while(equation.find_first_of("*/") != std::string::npos) {
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
			answer = intArray[0] + intArray[1];
			break;
		case '-':
			intArray = parseStringToInt(equation, operators, i, answer);
			answer = intArray[0] - intArray[1];
			break;
		}
	}

	//If no answer was generated from from the equation the answer already resides in the equation
	if (answer == 0)
	{
		answer = std::stoi(equation);
	}
	std::cout << "The answer is : " << answer;
}