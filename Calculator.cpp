#include<iostream>
#include <string>
using namespace std;

class clsCalculator {
private:
	float _OldResult = 0, _CurrentResult = 0,_CurrentOperand = 0;
	string _CurrentOperation = "Clear";
	bool IsZero(int num) {
		return num == 0;
	}

public:

	void Add(float operand) {
		_OldResult = _CurrentResult;
		_CurrentResult += operand;
		_CurrentOperand = operand;
		_CurrentOperation = "Adding";
	};
	void Subtract(float operand) {
		_OldResult = _CurrentResult;
		_CurrentResult -= operand;
		_CurrentOperand = operand;
		_CurrentOperation = "Subtraction";
	};
	void Multiply(float operand) {
		_OldResult = _CurrentResult;
		_CurrentResult *= operand;
		_CurrentOperand = operand;
		_CurrentOperation = "Multiply";
	};
	void Divide(float operand) {
		_CurrentOperand = operand;
		operand = (IsZero(operand) ? 1 : operand);
		_OldResult = _CurrentResult;
		_CurrentResult /= operand;
		_CurrentOperation="Dividing";
	};
	void PrintResult() {
		cout << "Result After " << _CurrentOperation << " " << _CurrentOperand << " is : " << _CurrentResult << "\n";
	};
	void CancelLastOperation() {
		_CurrentResult = _OldResult;
		_CurrentOperand = 0;
		_CurrentOperation = "Cancel Last Operation";
	};
	void Clear() {
		_OldResult = 0, _CurrentResult = 0, _CurrentOperand = 0, _CurrentOperation = "Clear";
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

	cal1.Clear();
	cal1.PrintResult();
	return 0;
}
