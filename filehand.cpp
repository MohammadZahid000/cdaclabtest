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
    outFile.write(reinterpret_cast<char*>(&record), sizeof(record));
    outFile.close();
    cout << "Record added successfully." << endl;
}

void showrecords() 
{
    bankrecord record;
    ifstream inFile("bank_records.txt", ios::binary);
    
    cout << "Account Number\tName\tBalance" << endl;
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) 
    {
        cout << record.accountnumber << "\t" << record.name << "\t" << record.balance << endl;
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

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) 
    {
        if (record.accountnumber == accnum) 
        {
            cout << "Record found: " ;
            cout << "Account Number: " << record.accountnumber;
            cout << "Name: " << record.name;
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
    int accnum;
    cout << "Enter account number to edit: ";
    cin >> accnum;

    bankrecord record;
    fstream file("bank_records.txt", ios::in | ios::out | ios::binary);
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(record))) 
    {
        if (record.accountnumber == accnum) 
        {
            cout << "\n Editing Record: ";
            cout << "\n Current Name: " << record.name;
            cout << "\n Current Balance: " << record.balance;

            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, record.name);
            cout << "Enter New Balance: ";
            cin >> record.balance;

            file.seekp(file.tellg() - sizeof(record));
            file.write(reinterpret_cast<char*>(&record), sizeof(record));
            found = true;
            cout << "\n Record updated successfully!";
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Record not found.";
    }
}

void deleterecord() 
{
    int accnum;
    cout << "Enter Account Number to delete: ";
    cin >> accnum;

    bankrecord record;
    ifstream inFile("bank_records.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(record))) 
    {
        if (record.accountnumber != accnum) 
        {
            outFile.write(reinterpret_cast<char*>(&record), sizeof(record));
        } 
        else 
        {
            found = true;
        }
    }
    inFile.close();
    outFile.close();

    remove("bank_records.txt"); 
    rename("temp.txt", "bank_records.txt"); 

    if (found) {
        cout << "Record deleted successfully!";
    } else {
        cout << "Record not found." ;
    }
}

int main() 
{
    int choice;
    do {
        cout << "\nBanking Record System Menu:";
        cout << "\n1. Add Record";
        cout << "\n2. Show/List Data";
        cout << "\n3. Search Record";
        cout << "\n4. Edit Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addrecord(); break;
            case 2: showrecords(); break;
            case 3: searchrecord(); break;
            case 4: editrecord(); break;
            case 5: deleterecord(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl; break;
        }
    } while (choice != 6);

    return 0;
}
