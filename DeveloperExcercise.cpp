#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

class clsPerson {
private:
	int _ID;
	string _FirstName, _LastName, _Email, _Phone;
public:
	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void SetFirstName(string FirstName) { _FirstName = FirstName; }
	void SetLastName(string LastName) { _LastName = LastName; }
	void SetEmail(string Email) { _Email = Email; }
	void SetPhone(string Phone) { _Phone = Phone; }
	string GetFirstName() { return _FirstName; }
	string GetLastName() { return _LastName; }
	string GetEmail() { return _Email; }
	string GetPhone() { return _Phone; }
	int GetID() { return _ID; }

	string GetFullName() {
		return _FirstName + " " + _LastName;
	}
	void Print() {
		cout << "Info:" << "\n";
		cout << "____________________\n";
		cout << "ID" << setw(9) << ":" << _ID << "\n";
		cout << "First Name" << ":" << _FirstName << "\n";
		cout << "Last Name" << ":" << _LastName << "\n";
		cout << "Full Name" << ":" << GetFullName() << "\n";
		cout << "Email" << setw(6) << ":" << _Email << "\n";
		cout << "Phone" << setw(5) << ":" << _Phone << "\n";
		cout << "____________________\n\n";

	}
	void SendEmail(string title, string body) {
		cout << "The following message sent successfully to email : " << _Email << "\n";
		cout << "Title : " << title << "\n";
		cout << "Body : " << body << "\n\n";
	}
	void SendSMS(string SMS) {
		cout << "The following message sent successfully to phone : " << _Phone << "\n";
		cout << "SMS : " << SMS << "\n\n";
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	__declspec(property(get = GetID, put = SetID)) int ID;
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

};
class clsEmployee : public clsPerson {
private:
	string _Title, _Department;
	float _Salary;

public:
	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary) :
		clsPerson(ID, FirstName, LastName, Email, Phone) {

		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	void SetTitle(string Title) { _Title = Title; }
	string GetTitle() { return _Title; }

	void SetDepartment(string Department) { _Department = Department; }
	string GetDepartment() { return _Department; }

	void SetSalary(float Salary) { _Salary = Salary; }
	float GetSalary() { return _Salary; }

	void Print() {
		//clsPerson::Print()
		cout << "Info:" << "\n";
		cout << "____________________\n";
		cout << "ID" << setw(9) << ":" << GetID() << "\n";
		cout << "First Name" << ":" << GetFirstName() << "\n";
		cout << "Last Name" << " :" << GetLastName() << "\n";
		cout << "Full Name" << " :" << GetFullName() << "\n";
		cout << "Email" << setw(6) << ":" << GetEmail() << "\n";
		cout << "Phone" << setw(6) << ":" << GetPhone() << "\n";
		cout << "Title" << setw(6) << ":" << _Title << "\n";
		cout << "Department" << ":" << _Department << "\n";
		cout << "Salary" << setw(5) << ":" << _Salary << "\n";
		cout << "____________________\n\n";

	}
	__declspec(property(get = GetDepartment, put = SetDepartment)) string Department;
	__declspec(property(get = GetTitle, put = SetTitle)) string Title;
	__declspec(property(get = GetSalary, put = SetSalary)) float Salary;
};
class clsDeveloper :public clsEmployee {
	string _MainPL = "";
public:
	clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary, string MainPL)
		:clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary) {
		_MainPL = MainPL;
	}
	void SetMainPL(string MainPL) { _MainPL = MainPL; }
	string GetMainPL() { return _MainPL; }
	void Print() {
		clsEmployee::Print();
		cout << "P.L." << setw(7) << _MainPL << "\n";
	}
	_declspec(property(get = GetMainPL, put = SetMainPL)) string MainPL;
};

int main() {
	clsDeveloper Developer1(100, "Asma", "Sabbah", "asma@gmail.com", "07887654321", "Developer", "IT", 1500,"PHP");
	Developer1.Print();
	return 0;
}
