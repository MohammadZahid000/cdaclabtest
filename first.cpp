#include <iostream>
using namespace std;

class Employee
{
protected:
    int empid;
    float salary;
    string name;

public:
    void inputData() {
        cout << "\nEnter the name of the employee: ";
        getline(cin, name);
        cout << "Enter the salary of the employee: ";
        cin >> salary;
        cout << "Enter the employee id: ";
        cin >> empid;
        cin.ignore();
    }

    void displayData() {
        cout << "Employee ID: " << empid << ", Name: " << name << ", Salary: " << salary;
    }

    float getSalary() 
	{
        return salary;
    }
};

int main() {
    Employee employees[10];
    
    for(int i = 0; i < 10; i++) 
	{
        cout << "Enter details for employee " << (i + 1);
        employees[i].inputData();
    }

    int highestSalaryIndex = 0;
    for(int i = 1; i < 10; i++) {
        if(employees[i].getSalary() > employees[highestSalaryIndex].getSalary())
		 {
            highestSalaryIndex = i;
        }
    }

    cout << "\n Employee with the highest salary:";
    employees[highestSalaryIndex].displayData();

    return 0;
}