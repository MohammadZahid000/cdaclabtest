//Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
//Pay_Rate and Salary. Write necessary functions to calculate and display the salary 
//of Worker. (Use
//Default values for Pay_Rate Rs. 500 per hours)
//[Q.No 2 Marks 10 ]
//====================================================================
#include <iostream>
#include <string>
using namespace std;
double calsal(int hour, double payrate=500) 
{
    return hour*payrate;
}
void display_worker_info(string workername, int hour, double payrate, double sal) 
{
    cout << "\n worker name: " << workername ;
    cout << "\n number of hours worked: " << hour;
    cout << "\n pay rate: Rs. " << payrate << " per hour";
    cout << "\n salary: Rs. " << sal;
}
main() {
    string workername;
    int hour;
    cout << "Enter worker name: ";
    getline(cin, workername);
    cout << "Enter number of hours worked: ";
    cin >> hour;

    double salary = calsal(hour);
    display_worker_info(workername, hour, 500.0, salary);

    return 0;
}
