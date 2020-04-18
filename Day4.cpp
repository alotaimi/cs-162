#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("input.txt");
    int counter = 0;
    string x;
    int z;
    int d;
    while (getline(file, x))
    {
        counter++;
    }
    cout << counter << endl;
    return 0;
}