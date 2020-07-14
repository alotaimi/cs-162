#include "./vector.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdexcept>
//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
int main (){
   vector<int> v;   //Our vector class
   vector<std::string> v1;
   std::vector<int> stdv; //Standard vector
   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
   cout << "Our vector Capacity: " << v.capacity() << endl;
   cout << "STL vector Capacity: " << stdv.capacity() << endl;
   cout << v.at(2) << endl;
   return 0;
}
