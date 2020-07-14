#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void art(){
    string x;
    ifstream file;
    file.open("art.txt");
    while(!file.eof()){
        getline(file,x);
        cout << x<<endl;
    }
}
