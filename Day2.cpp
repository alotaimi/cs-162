#include <iostream>
#include <string>

using namespace std;

class Cars
{
public:
    Cars()
    {
        cout << "Auto" << endl;
    }
    void setName(string x)
    {
        name = x;
    }
    string getName()
    {
        return name;
    }
    void Display()
    {
        cout << name << endl;
    }

private:
    string name;
};

int main()
{
    Cars car;
    car.Display;
    Cars vs;
}