#include "Calculator.hpp"

int sub1;
int sub2;

int main()
{
	std::string equation;

	std::cout << "Please Enter a sum:\n";
	std::cin >> equation;

	if (equation.find('+') != std::string::npos) {
		parseStringToInt(equation, '+');
		std::cout << "The answer is: " << sub1 + sub2;
	}
	else if(equation.find('-') != std::string::npos){
		parseStringToInt(equation, '-');
		std::cout << "The answer is: " << sub1 - sub2;
	}
	else if (equation.find('*') != std::string::npos) {	
		parseStringToInt(equation, '*');
		std::cout << "The answer is: " << sub1 * sub2;
	}
	else if (equation.find('/') != std::string::npos) {
		parseStringToInt(equation, '/');
		std::cout << "The answer is: " << sub1 / sub2;
	}
	else {
		std::cout << "Sum did not contain a valid operator.";
		return 0;
	}
}

void parseStringToInt(std::string equation,char ope){
	try {
		sub1 = std::stoi(equation.substr(0, equation.find(ope)));
		sub2 = std::stoi(equation.substr(equation.find(ope), std::string::npos));
	} catch (std::exception &err) {
		std::cout << "Something went wrong parsing the string to an integer";
	}
}

