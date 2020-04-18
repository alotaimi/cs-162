#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
struct interior
{
    string brand;
    int seats;
    int ac;
};

class Cars
{
private:
    interior *interiors;

public:
    Cars()
    {
        this->interiors = new interior[3];
        interiors->brand = " ";
        interiors->seats = 0;
        interiors->ac = 0;
        for (int i = 0; i < 3; i++)
        {
            cout << interiors[i].brand << interiors[i].seats << interiors[i].ac << endl;
        }
    }
    void Setbrand(string x)
    {
        interiors->brand = x;
    }
    void Setseats(int x)
    {
        interiors->seats = x;
    }
    void Setac(int x)
    {
        interiors->ac = x;
    }
    int getac()
    {
        return interiors->ac;
    }
    int getseats()
    {
        return interiors->seats;
    }
    string getbrand()
    {
        return interiors->brand;
    }
};

int main()
{
    Cars car;
    return 0;
}