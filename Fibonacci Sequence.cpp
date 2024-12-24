#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

uint64_t fib(int n, vector<uint64_t> &knownFibs) {
    // If we already know the fib of the number needed, we return it
    if (knownFibs[n] != 0) {
        return knownFibs[n];
    }

    // If the number is 2 or lower, then the fib is 1
    if (n <= 2) {
        return 1;
    }

    // If all passed, calulate the fib for the number and add it to the memory
    // To calculate the fib, we need to add the fib of the num - 1 with the fib of the num - 2
    knownFibs[n] = fib(n - 1, knownFibs) + fib(n - 2, knownFibs);

    // Return the fib of the number
    return knownFibs[n];
}

int main()
{
    // Initialize main variable
    int numOfFibs;

    // Get what fib the user wants to calculate
    cout << "How many fibonacci sequences would you like to calculate: ";
    cin >> numOfFibs;

    // If fib is bigger than 93 then it can't be calculated
    if (numOfFibs > 93) {
        cout << "\nSorry, but due to computational limitations, it is not possible to calculate the fib of " << numOfFibs << " in this program\n";
        return 0;
    }

    // Create a vector that is as long as the num of fibs + 1 and fill it with 0's for memory
    vector<uint64_t> knownFibs(numOfFibs + 1, 0);

    // Get and print the result
    cout << "\nFibonacci of " << numOfFibs << " is " << fib(numOfFibs, knownFibs) << "\n";

    return 0;
}
