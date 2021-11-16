/**
 *   @file: Lab12.cc
 * @author: Hunter Stout
 *   @date: November 12, 2021
 *  @brief: (Lab 12) Vector & Structure Practice.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Records - Structure of vectors to house all employee data.
 * @param Id - Employee id.
 * @param first_Name - Employee first name.
 * @param last_Name - Employee last name.
  * @param salary - Employee salary.
 */
struct Records{
    int id;
    string first_Name;
    string last_Name;
    double salary;
};

/**
 * structLoader - Loads file data into our structure vector.
 * @param r - Structure vector (employee data).
 * @param inStream - Stream for grabbing file data from employees.txt.
 */
void structLoader (vector<Records>& r, ifstream& inStream);

/**
 * total - Finds total salary from all employees.
 * @param r - Structure vector (employee data).
 * @return - Total salary.
 */
double total (vector<Records> r);

/**
 * recipt - Prints recipt for all employees.
 * @param r - Structure vector (employee data).
 * @param tot - Total salary found from the total function.
 */
void recipt (vector<Records> r, double tot);
 
int main(){

    //Declare for stream, struct vector, & total.
    ifstream inStream;
    vector<Records> r;
    double tot;

    //Opens stream & fail checks.
    inStream.open("employees.txt");
        if (inStream.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate this file. Try again" << endl;
            exit (0);
        }

    //Loads structure with data from file & closes stream.
    structLoader (r, inStream);
    inStream.close();

    //Finds average salary.
    tot = total (r);

    //Prints recipt.
    recipt (r, tot);

return 0;
}

void structLoader (vector<Records>& r, ifstream& inStream) {

    //Declares inputs & counter.
    int input_Id, i = 0;
    string input_First, input_Last;
    double input_Salary;

    //Runs loop until the end of the file.
    while (!inStream.eof()) {

        //Pushes vector back then adds the id, first name, last name, and salary.
        r.push_back(Records());
        inStream >> input_Id;
        r[i].id = input_Id;

        inStream >> input_First;
        r[i].first_Name = input_First;

        inStream >> input_Last;
        r[i].last_Name = input_Last;

        inStream >> input_Salary;
        r[i].salary = input_Salary;
        //Counter for vector.
        i++;
    }
        //Removes extra vector slot at the end because all code is inside the loop.
        r.pop_back();
}

double total (vector<Records> r) {

    //Declares salary & total amount of salaries inside the vector.
    double total_Salary = 0.0;
    int size = r.capacity();

        //Loop adds up all the salaries.
        for (int i = 0; i < size; i++) {
            total_Salary += r[i].salary;
        }
    //Returns total.
    return (total_Salary);
}

void recipt (vector<Records> r, double tot) {

    //Declares placeholder strings & size of vector.
    string display, space = " ";
    int v_Size = r.capacity();

        //Top of recipt.
        cout << endl;
        cout << " Sorted by name" << endl;
        cout << endl;
        cout << " ID     Name                Salary" << endl;
        cout << "-------------------------------------" << endl;

    //Loop displays id, salary, placeholds name, & inputs correct amount of spaces for clean output.
    for (int i = 0; i < v_Size; i++) {

        cout << " " << r[i].id << "   ";

        display = r[i].first_Name;
        display += space;
        display += r[i].last_Name;

        //Declares placeholder sizes of name to input correct amount of spaces.
        int s_Size = display.size();
        int s_Size2 = 20 - s_Size;

        //Inserts correct amount of spaces to placeholder string.
        for (int j = 0; j < s_Size2; j++) {

            display.insert(s_Size, " ");
            s_Size++;
        }

        cout << display;
        cout << fixed << setprecision(2);
        cout << "$" << r[i].salary << endl;
    }
        //Bottom half of recipt.
        cout << endl;
        cout << fixed << setprecision(2);
        cout << "Total Payroll: $" << tot << endl;
}