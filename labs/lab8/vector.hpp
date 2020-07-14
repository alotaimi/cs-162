#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdexcept>
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }
	  
      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }
      int capacity(){
          int x = 0;
          for(int i =0; i < s; i++){
              x++;
          }
          return x;
      }
      vector(vector &other){
          s = other.s;
          v = new T[s];
          for(int i = 0; i < s; i++){
              v[i] = other.v[i];
          }
      }
      void operator=(vector<T> &other){
          this->s = other.s;
          for(int i =0; i< this->s; i++){
              this->v[i] = other.v[i];
          }
      }
        T operator[](int x){ 
        return v[x];
}
        T at(int x){
        if(x < s){
        return v[x];
        }
        else{
        throw std::out_of_range("out of my vector bounds");
}
}
};
