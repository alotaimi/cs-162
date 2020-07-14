#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "multdiv.h"
using namespace std;


bool is_valid_dimensions(char* m, char* n){
    if(m > 0){
        if(n > 0){
            true;
        }
        else{
            false;
        }
    }
    else{
        false;
    }
}
multdiv_entry** create_table(multdiv_entry** table,int row, int col){
       for(int i = 0; i < row; i++){
        for(int j = 0; j < col;j++){
            table[i][j].mult = (i + 1) * (j + 1);
            table[i][j].div = (i + 1.00) / (j + 1.00);
        }
    }
}
void print_table(multdiv_entry** table, int row, int col){
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout <<table[i][j].mult;
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            cout <<table[i][j].div << " ";
        }
        cout << endl;
    }
}
void delete_table(multdiv_entry** table, int row){
    for(int i = 0; i < row; i++){
        delete [] table[i];
    }
    delete [] table;
}
