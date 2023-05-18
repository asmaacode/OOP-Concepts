//initiate an inner-class using constructor
#include<iostream> 
using namespace std;
class clsPerson {
	class clsAddress {
	public:
		string AddressLine1;
		string AddressLine2;
		string City;
		string Country;
		clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {
			this->AddressLine1 = AddressLine1;
			this->AddressLine2 = AddressLine2;
			this->City = City;
			this->Country = Country;
		}
		void Print() {
			cout << "\nAddress:\n";
			cout << AddressLine1 << endl;
			cout << AddressLine2 << endl;
			cout << City << endl;
			cout << Country << endl;
		}
	};
public:
	string FullName;
	clsAddress Address = clsAddress("", "", "", "");//Object

	clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country) {
		FullName = "Mohammed Abu-Hadhoud";
		Address = clsAddress( AddressLine1, AddressLine2, City, Country);//Fill The Object
	}
};

int    main() {
	clsPerson Person1("Mohammed Abu-Hadhoud", "Building 10", "Queen Rania Street", "Amman", "Jordan");
	Person1.Address.Print();
	system("pause>0");
	return 0;
}
