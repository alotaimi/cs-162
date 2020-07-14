#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "multdiv.h"
using namespace std;

int main(int argc,char** argv){
  srand(time(NULL));
 int col =atoi(argv[2]);
  int row =atoi(argv[1]);
   multdiv_entry** table = new multdiv_entry*[row];
      for(int i = 0; i < row; i++){
          table[i] = new multdiv_entry[col];
      }
 
      create_table(table,row, col);
      print_table(table,  row,  col);
      delete_table(table, row);
}

