#include<iostream>
#include <string>
using namespace std;

class clsCalculator {
private:
	float OldResult = 0, CurrentResult = 0;
	float  OldOperand = 0, CurrentOperand = 0;
	string OldOperation = "", CurrentOperation = "";

public:
	void setCurrentResult(float newResult) {
		OldResult = CurrentResult;
		CurrentResult = newResult;
	}
	void setCurrentOperand(float newOperand) {
		OldOperand = CurrentOperand;
		CurrentOperand = newOperand;
	}
	void setCurrentOperation(string newResult) {
		OldOperation = CurrentOperation;
		CurrentOperation = newResult;
	}
	void Add(float operand) {
		setCurrentResult(CurrentResult + operand);
		setCurrentOperand(operand);
		setCurrentOperation("Adding");
	};
	void Subtract(float operand) {
		setCurrentResult(CurrentResult - operand);
		setCurrentOperand(operand);
		setCurrentOperation("Subtraction");
	};
	void Multiply(float operand) {
		setCurrentResult(CurrentResult * operand);
		setCurrentOperand(operand);
		setCurrentOperation("Multiply");
	};
	void Divide(float operand) {
		operand == 0 ? operand = 1 : operand;
		setCurrentResult(CurrentResult / operand);
		setCurrentOperand(operand);
		setCurrentOperation("Dividing");
	};
	void PrintResult() {
		cout << "Result After " << CurrentOperation << " " << to_string(CurrentOperand) << " is : " << CurrentResult << "\n";
	};
	void CancelLastOperation() {
		CurrentOperand = OldOperand;
		CurrentResult = OldResult;
		CurrentOperation = OldOperation;
	};
	void Clear() {
		OldResult = 0, CurrentResult = 0;
		OldOperand = 0, CurrentOperand = 0;
		OldOperation = "", CurrentOperation = "";
	};
};
int main() {
	clsCalculator cal1;
	cal1.Clear();

	cal1.Add(100);
	cal1.PrintResult();

	cal1.Subtract(10);
	cal1.PrintResult();

	cal1.Multiply(10);
	cal1.PrintResult();

	cal1.Divide(10);
	cal1.PrintResult();

	cal1.CancelLastOperation();
	cal1.PrintResult();
	return 0;
}
