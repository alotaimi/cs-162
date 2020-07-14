#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include<stdio.h> 
using namespace std;

void merge(int arr[], int a, int b, int c) 
{ 
    int q, w, e; 
    int size1 = b - a + 1; 
    int size2 =  c - b; 
  
    int L[size1], R[size2]; 
  
    for (q = 0; q < size1; q++){
        L[q] = arr[a + q]; 
    }
    for (w = 0; w < size2; w++){
        R[w] = arr[b + 1+ w];
    } 
  
    q = 0; 
    w = 0; 
    e = a; 
    while (q < size1 && w < size2) 
    { 
        if (L[q] <= R[w]) 
        { 
            arr[e] = L[q]; 
            q++; 
        } 
        else
        { 
            arr[e] = R[w]; 
            w++; 
        } 
        e++; 
    } 
  
    while (q < size1) 
    { 
        arr[e] = L[q]; 
        q++; 
        e++; 
    } 
  
    while (w < size2) 
    { 
        arr[e] = R[w]; 
        w++; 
        e++; 
    } 
} 
  
void Sort(int arr[], int a, int b) 
{ 
    if (a < b) 
    { 
        int m = a+(b-a)/2; 
  
        Sort(arr, a, m); 
        Sort(arr, m+1, b); 
  
        merge(arr, a, m, b); 
    } 
} 
int primenum(int x){
    bool prime = true;
    for(int i = 2; i <= x/2; i++){
        if(x%i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}
int main(){
    bool prime;
    int loop = 0;
    int size;
    while(loop ==0){
    cout << "what's the size of the array?"<<endl;
    cin >> size; 
    if(size >= 0 && size < 20){
        loop++;
    }
    else{
        cout << "it's either too big or too small"<<endl;
    }
    }
    cout <<endl;
    int* arr = new int [size];
    srand(time(NULL));
    for(int i =0; i< size; i++){
        arr[i] = rand()%50 + 1;
    }
    for(int i = 0; i < size; i++){
        cout << arr[i]<<endl;
    }
    Sort(arr, 0, size - 1); 
    cout << "------------------------------------------------ Sorted ------------------------------------------------"<<endl;
    for(int i = 0; i < size; i++){
        prime = primenum(arr[i]);
        if(prime == true){
            cout << "Prime"<<endl;
            cout << arr[i]<<endl;
        }
        else{
            cout <<"not prime"<<endl;
            cout << arr[i]<<endl;
        }
    }
    delete [] arr;
}
