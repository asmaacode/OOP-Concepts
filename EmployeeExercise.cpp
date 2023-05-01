#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

class clsEmployee {
private:
	int _ID;
	string _FirstName, _LastName, _Email, _Phone,_Title,_Department;
	float _Salary;

public:
	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone,string Title,string Department,float Salary) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}
	string GetFirstName() { return _FirstName; }
	void SetFirstName(string FirstName) { _FirstName = FirstName; }
	
	void SetLastName(string LastName) { _LastName = LastName; }
	string GetLastName() { return _LastName; }

	void SetEmail(string Email) { _Email = Email; }
	string GetEmail() { return _Email; }

	void SetPhone(string Phone) { _Phone = Phone; }
	string GetPhone() { return _Phone; }

	void SetTitle(string Title) { _Title = Title; }
	string GetTitle() { return _Title; }

	void SetDepartment(string Department) { _Department = Department; }
	string GetDepartment() { return _Department; }
	
	void SetSalary(float Salary) { _Salary = Salary; }
	float GetSalary() { return _Salary; }

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
	__declspec(property(get = GetDepartment, put = SetDepartment)) string Department;
	__declspec(property(get = GetTitle, put = SetTitle)) string Title;
	__declspec(property(get = GetSalary, put = SetSalary)) float Salary;

};
int main() {
	clsEmployee Employee1(100,"Asma","Sabbah","asma@gmail.com","078587654321","Developer","IT",1500);
	Employee1.Print();

	Employee1.SendEmail("Announcement","Tommorrow will be a break");
	Employee1.SendSMS("SMS is very important");

	
	return 0;

}
