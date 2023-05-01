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
int main() {
	clsPerson Person1(100,"Asma","Sabbah","asma@gmail.com","07876543212");
	Person1.Print();

	Person1.SendEmail("Announcement","Tomorrow will be a break");
	Person1.SendSMS("SMS is very important");

	return 0;
}
