#include <iostream>
#include <iomanip>
#include <cstdlib> // for the rand and srand functions, which will be used to generate random numbers
#include <ctime>   // for the time function, which will be used to seed the random number generator

#include "unorderedLinkedList.h"

using namespace std;

int main()
{
    unorderedLinkedList<double> list;
    srand(time(0)); // seed the random number generator with the current time

    int randomNumber = (rand() % 6) + 10; //we generate a random number form 1 to 5 then add 10 to it so we get a number between 10 and 15

    for (int i = 0; i < randomNumber; i++)
    {
        list.insertLast(rand() % 100 / 10.0); // insert random double values between 0.0 and 9.9    
    }
    list.insertLast(0.01);
    list.insertLast(0.01);

    cout << "List: " << endl;
    list.print();

    double firstValue = list.front();
    cout << "Deleting the first value node: " << firstValue << endl;
    list.deleteNode(firstValue);
    cout << "List after deleting the first value node: " << endl;
    list.print();


    double total = 0;
    double subtotalNoPenny = 0;
    linkedListIterator<double> iter;

    for (iter = list.begin(); iter != list.end(); ++iter)
    {
        double value = *iter;
        total += value;
        if (value != 0.01)
        {
            subtotalNoPenny += value;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Total: " << total << endl;
    cout << "Subtotal without pennies: " << subtotalNoPenny << endl;

    cout << "Submitted by: Fausto" << endl;

}