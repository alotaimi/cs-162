struct multdiv_entry {
int mult;
float div;
};
bool is_valid_dimensions(char* , char*);
void print_table(multdiv_entry**, int, int);
void delete_table(multdiv_entry**, int );
 multdiv_entry** create_table(multdiv_entry**,int,int);
