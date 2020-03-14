#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct BB
{
	string name[10], location[10], dt[10], bg[10], city[10], ts[10];
	void ADD()
	{
		ofstream bb("Donor Records.txt");
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter Record of " << i + 1 << " donor : \n\n";
			bb << "Enter Record of " << i + 1 << " donor : " << endl;
			cout << "Enter donor name : ";
			cin >> name[i];
			bb << "Name of donor is : " << name[i] << endl;
			cout << "Enter donor address : ";
			cin >> location[i];
			bb << "Address of donor is : " << location[i] << endl;
			cout << "Enter Date and Time of availability : ";
			cin >> dt[i];
			bb << "Date and Time of availability is : " << dt[i] << endl;
			cout << "Enter donor blood group : ";
			cin >> bg[i];
			bb << "Blood Group of donor is : " << bg[i] << endl;
			cout << "Enter donor city : ";
			cin >> city[i];
			bb << "Donor of city is : " << city[i] << endl;
			cout << "Enter donor test status : ";
			cin >> ts[i];
			bb << "Donor Status is : " << ts[i] << endl;
			cout << "\n\n";
			system("cls");
		}
		bb.close();
	}
	void search(string BG)
	{
		ifstream readFile("Donor Records.txt");
		string buffer[60];
		if (!readFile.fail())
		{
			for (int i = 0; i < 60; i++)
			{
				getline(readFile, buffer[i]);
			}
			for (int i = 0; i < 60; i = i + 6)
			{
				if (buffer[i] == BG)
				{
					for (int j = i; j < i + 6; j++)
					{
						cout << buffer[j] << "\n";
					}
				}
			}
		}
		else {
			cout << "error in opening file\n";
		}
		readFile.close();
	}
};
int main()
{
	BB A;
	string a;
	cout << "Enter the Blood Group want to search : ";
	cin >> a;
	cout << "\nAvaliable donors are : \n\n";
	A.ADD();
	A.search(a);
}