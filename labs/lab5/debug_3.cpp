/*
 * This program should compute the average and maximum age of all of the
 * people in a TSV data file whose lines each look like this:
 *
 *   LAST_NAME  FIRST_NAME  ID AGE
 *
 * Once compiled, you can run this program like so:
 *   ./debug_3 data.tsv
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

struct person {
  string last_name;
  string first_name;
  string id;
  int age;
};


/*
 * This function counts and returns the number of entries in a TSV file.  The
 * number of entries is counted as the number of non-empty lines.
 *
 * Hint: there shouldn't be any bugs in this function.
 */
int count_tsv_file_entries(string x) {
  string line;
    int counter = 0;
    ifstream fin;
    fin.open(x.c_str());
    while (!fin.eof())
    {
        getline(fin, line);
        counter++;
    }
    fin.close();
    return counter;
}


/*
 * This function reads people from a specified data file (with TSV format as
 * described in the file header) into an array of person structs and returns
 * the number of people read.
 */
int read_people(ifstream& filename, person*& people) {
  ifstream infile;
  infile.open("data.tsv");
  int i = 0, n = count_tsv_file_entries("data.tsv");
  person* new_person;
  new_person = new person[n];
      for(int i = 0; i < n; i++){
         filename >> new_person[i].last_name >> new_person[i].first_name >> new_person[i].id >> new_person[i].age;
         people[i] = new_person[i];
       }

  return n;
}


/*
 * This function computes and returns the average age of all of the people in
 * an array of person structs.
 */
float compute_avg_age(person* people, int n) {
  float avg = 0;
  for (int i = 0; i < n; i++) {
    avg += people[i].age;
  }
  avg /= n;
  return avg;
}


/*
 * This function computes and returns the maximum age of all of the people in
 * an array of person structs.
 */
int compute_max_age(person* people, int n) {
  int max = 0;
  int idx = 0;
  for (int i = 0; i < 8; i++) {
      max = people[i].age;
      idx = i;
  }
  return people[idx].age;
}


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Error: must specify a data file."
      << endl << endl;
    cout << "usage: " << argv[0] << " <data_file>" << endl;
    return 1;
  }
  ifstream file;
  file.open("data.tsv");
  person* people = new person[8];
  int n = read_people(file, people);
  float avg_age = compute_avg_age(people, 8);
  int max_age = compute_max_age(people, 8);

  cout << "The average age of the " << 8 << " people is: " << avg_age
    << endl;
  cout << "The maximum age of the " << 8 << " people is: " << max_age
    << endl;

  return 0;  
}