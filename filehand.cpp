#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct bankrecord 
{
    int accountnumber;
    string name;
    double balance;
};

void addrecord()
 {
    bankrecord record;
    cout << "Enter Account Number: ";
    cin >> record.accountnumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, record.name);
    cout << "Enter Balance: ";
    cin >> record.balance;
    ofstream outFile("bank_records.txt", ios::app | ios::binary);
    outFile.write((&record), sizeof(record));
    outFile.close();
    cout << "Record added successfully";
}

void showrecord() 
{
    bankrecord record;
    ifstream inFile("bank_records.txt", ios::binary);
    cout << "Account Number";
    while (inFile.read((&record), sizeof(record))) 
	{
        cout<<record.accountnumber<<record.name<<record.balance;
    }
    inFile.close();
}

void searchrecord() 
{
    int accnum;
    cout << "Enter account number to search: ";
    cin >> accnum;

    bankrecord record;
    ifstream inFile("bank_records.txt", ios::binary);
    bool found = false;

    while
	{
        if (record.accountnumber == accnum) 
		{
            cout << "Record found: " ;
            cout << "Account Number: " << record.accountNumber;
            cout << "Name: " << record.name ;
            cout << "Balance: " << record.balance ;
            found = true;
            break;
        }
    }
    inFile.close();

    if (!found) 
	{
        cout << "Record not found.";
    }
}

void editrecord() 
{
    int accNum;
    cout << "Enter account number to edit: ";
    cin >> accNum;

    bankrecord record;
    fstream file("bank_records.dat", ios::in | ios::out | ios::binary);
    bool found = false;

    while() 
	{
        if (record.accountNumber == accNum) 
		{
            cout << "Editing Record: " ;
            cout << "Current Name: " << record.name ;
            cout << "Current Balance: " << record.balance;

            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, record.name);
            cout << "Enter New Balance: ";
            cin >> record.balance;

            file.seekp(file.tellg() - sizeof(record));
            file.write(reinterpret_cast<char*>(&record), sizeof(record));
            found = true;
            cout << "Record updated successfully!" << endl;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Record not found." << endl;
    }
}

void deleteRecord() {
    int accnum;
    cout << "Enter Account Number to delete: ";
    cin >> accnum;

    bankrecord record;
    ifstream inFile("bank_records.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    bool found = false;

    while
	 {
        if (record.accountNumber != accNum) 
		{
            outFile.write(reinterpret_cast<char*>(&record), sizeof(record));
        } else 
		{
            found = true;
        }
    }
    inFile.close();
    outFile.close();

    remove("bank_records.dat"); 
    rename("temp.dat", "bank_records.dat"); 

    if (found) {
        cout << "Record deleted successfully!" ;
    } else {
        cout << "Record not found." << endl;
    }
}
int main() 
{
    int choice;
    do {
        cout << "\n banking record system menu:";
        cout << "1. \n Add Record\n";
        cout << "2. \n Show/List Data\n";
        cout << "3. \n Search Record\n";
        cout << "4. \n Edit Record\n";
        cout << "5. \n Delete Record\n";
        cout << "6. \n Exit\n";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addrecord();
			break;
            case 2: showrecords(); 
			break;
            case 3: searchrecord(); 
			break;
            case 4: editrecord(); 
			break;
            case 5: deleterecord(); 
			break;
            case 6: cout << "Exiting..."; 
			break;
            default: cout << "Invalid choice. please try again"; 
			break;
        }
    } while (choice != 6);

    return 0;
}
