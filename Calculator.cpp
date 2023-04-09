#include<iostream>
#include <string>
using namespace std;

class clsCalculator {
private:
	float result = 0, latestOperand = 0;
	string latestOperation = "";

public:
	void Add(float operand) {
		result += operand;
		latestOperation = "Adding";
		latestOperand = operand;
	};
	void Subtract(float operand) {
		result -= operand;
		latestOperation = "Subtraction";
		latestOperand = operand;
	};
	void Multiply(float operand) {
		result *= operand;
		latestOperation = "Multiply";
		latestOperand = operand;
	};
	void Divide(float operand) {
		operand == 0 ? operand = 1 : operand;
		result /= operand;
		latestOperation = "Dividing";
		latestOperand = operand;
	};
	void PrintResult() { 
		cout <<"Result After "<<latestOperation<<" "<<to_string(latestOperand) <<" is : " << result<<"\n";
	};

};
int main() {
	clsCalculator cal1;
	cal1.Add(100);
	cal1.PrintResult();
	
	cal1.Subtract(10);
	cal1.PrintResult();

	cal1.Multiply(10);
	cal1.PrintResult();

	cal1.Divide(10);
	cal1.PrintResult();
	return 0;
}
