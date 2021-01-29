#include "StringHandler.hpp"

int main()
{
	std::string equation;
	std::cout << "Please Enter a sum:\n";
	std::cin >> equation;
	 
	//Checks if equation only contains valid characters
	if (equation.find_first_not_of("123456789+-*/") != std::string::npos) {
		std::cout << "Equation contained an illegal character. Please make sure to only use: Digits, operators and brackets.";
		return 0;
	}

	//Gets all the operators from the equation
	std::vector<size_t> operators = GetOperatorLocations(equation);
	
	int* subStringArr;
	//Performs the equation
	for (int i = 0; i < operators.size(); i++) {
		switch (equation[i + 1])
		{
		case '+':
			subStringArr = parseStringToInt(equation, '+');
			std::cout << "The answer is: " << subStringArr[0] + subStringArr[1];
			break;
		case '-':
			subStringArr = parseStringToInt(equation, '-');
			std::cout << "The answer is: " << subStringArr[0] - subStringArr[1];
			break;
		case '*':
			subStringArr = parseStringToInt(equation, '*');
			std::cout << "The answer is: " << subStringArr[0] * subStringArr[1];
			break;
		case '/':
			subStringArr = parseStringToInt(equation, '/');
			std::cout << "The answer is: " << subStringArr[0] / subStringArr[1];
			break;
		default:
			std::cout << "Sum did not contain a valid operator.";
			return 0;
		}
	}
}