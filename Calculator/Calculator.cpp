#include <iostream>
#include <string>
using namespace std;

int sub1;
int sub2;
string equation;

class func {
public:
	static void parseStringToInt(char ope);
};

int main()
{
	cout << "Please Enter a sum:\n";
	cin >> equation;

	if (equation.find('+') != std::string::npos) {
		func::parseStringToInt('+');
		cout << "The answer is: " << sub1 + sub2;
	}
	else if(equation.find('-') != std::string::npos){
		func::parseStringToInt('-');
		cout << "The answer is: " << sub1 - sub2;
	}
	else if (equation.find('*') != std::string::npos) {	
		func::parseStringToInt('*');
		cout << "The answer is: " << sub1 * sub2;
	}
	else if (equation.find('/') != std::string::npos) {
		func::parseStringToInt('/');
		cout << "The answer is: " << sub1 / sub2;
	}
	else {
		cout << "Sum did not contain a valid operator.";
		return 0;
	}
}

void func::parseStringToInt(char ope){
	sub1 = stoi(equation.substr(0, equation.find(ope)));
	sub2 = stoi(equation.substr(equation.find(ope), string::npos));
}

