#include <iostream>
#include <string>

using namespace std;

class Cars
{
public:
    string name;
    int wheels;
    int model;
};

int main()
{
    Cars version[7];
    cout << "What is the name of your dream car?" << endl;
    getline(cin, version.name);
    getline(cin, version.name);
    getline(cin, version.name);
    getline(cin, version.name);
    getline(cin, version.name);
    getline(cin, version.name);
    getline(cin, version.name);

    cout << "How many wheels are on your car?" << endl;
    cin >> version.wheels;
    cout << "in what year was your car made?" << endl;
    cin >> version.model;
    cout << "Is this your car?" << endl;
    cout << "Name " << version.name << "\t"
         << "Wheels "
         << "\t" << version.wheels << "\t"
         << "Model" << version.model;
    string x;
    cout << "is this it?" << endl;
    cin >> x;
    if (x == "Yes" || x == "yes" || x == " ")
    {
        cout << "Thank you for using my program" << endl;
    }
    else
    {
        cout << "sorry for wasting your time Bitch" << endl;
    }
    for (int i = 0; i < 7; i++)
    {
        cout << "Name " << version.name[i] << endl;
    }
    return 0;
}