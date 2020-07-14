/******************************************************
** Program: run_wizard.cpp
** Author: Mishary alotaibi
** Date: 04/12/2020
** Description: sorting books,sorting spells,
** Input: id,passowrd,chocies
** Output: sorting everything
******************************************************/

#include "catalog.h"

using namespace std;

int main(int argc, char *argv[])
{
    // checking input
    if (argc != 3)
    {
        cout << "Wrong input" << endl;
        return -1;
    }
    if (string(argv[1]) != "wizards.txt" || string(argv[2]) != "spellbooks.txt")
    {
        cout << "Wrong files" << endl;
        return -1;
    }
    // read files
    ifstream fin1;
    ofstream file_;
    fin1.open("spellbooks.txt");
    if (!fin1.is_open())
    {
        cout << "Error opening the file to read!!" << endl;
        return 1;
    }
    string tmp_string1;
    getline(fin1, tmp_string1);

    ifstream fin;
    fin.open("wizards.txt");
    if (!fin.is_open())
    {
        cout << "Error opening the file to read!!" << endl;
        return 1;
    }
    string tmp_string;
    getline(fin, tmp_string);

    // init book
    int num_of_spellbooks;
    num_of_spellbooks = atoi(tmp_string1.c_str());
    spellbook *book = create_spellbooks(num_of_spellbooks);

    // init wizard
    int num_of_wizards;
    num_of_wizards = atoi(tmp_string.c_str());
    wizard *profile = new wizard[num_of_wizards];

    // create profiles for each user
    for (int i = 0; i < num_of_wizards; i++)
    {
        fin >> profile[i].name >> profile[i].id >> profile[i].password >> profile[i].position_title >> profile[i].beard_length;
    }

    int choice;
    int choice1;
    string arr[5];
    arr[0] = "death", arr[1] = "poison", arr[2] = "fire", arr[3] = "memory_loss", arr[4] = "bubble";
    string filename;
    int loop = 0;
    int username;
    string pass;
    string status;
    int atp = 0;
    // trials
    while (atp < 3)
    {
        // ask user
        cout << "Please enter your id: " << endl;
        cin >> username;
        cout << "Please enter your password" << endl;
        cin >> pass;
        // check if user exists
        for (int i = 0; i < num_of_wizards; i++)
        {
            // checking whether the user id entered and password matches with database
            if (username == profile[i].id && pass == profile[i].password)
            {
                cout << "Welcome " << profile[i].name << endl;
                cout << "ID: " << profile[i].id << endl;
                cout << "Status: " << profile[i].position_title << endl;
                cout << "Beard Length: " << profile[i].beard_length << endl;
                status = profile[i].position_title;
                populate_spellbook_data(book, num_of_spellbooks, fin1);
                while (loop == 0)
                {
                    cout << "Which option would you like to choose?"
                         << "\n"
                         << "1. Sort spellbooks by number of pages "
                         << "\n"
                         << "2. Group spells by their effect "
                         << "\n"
                         << "3. Sort spellbooks by average success rate"
                         << "\n"
                         << "4. Quit" << endl;
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "How would you like the information displayed?"
                             << "\t"
                             << "1. Print to screen (Press 1)"
                             << "\t"
                             << "2. Print to file (Press 2)" << endl;
                        cin >> choice1;
                        if (choice1 == 1)
                        {
                            sortbypage(book, num_of_spellbooks);
                            for (int i = 0; i < num_of_spellbooks; i++)
                            {
                                cout << book[i].title << book[i].num_pages << endl;
                            }
                        }
                        else if (choice1 == 2)
                        {
                            cout << "Please provide desired filename: ";
                            cin >> filename;
                            if (DoesFileExist(filename))
                            {
                                file_.open(filename.c_str(), ios::app);
                                sortbypage(book, num_of_spellbooks);
                                for (int i = 0; i < num_of_spellbooks; i++)
                                {
                                    file_ << book[i].title << " " << book[i].num_pages << endl;
                                }
                                file_.close();
                            }
                            else
                            {
                                file_.open(filename.c_str());
                                sortbypage(book, num_of_spellbooks);
                                for (int i = 0; i < num_of_spellbooks; i++)
                                {
                                    file_ << book[i].title << " " << book[i].num_pages << endl;
                                }
                                file_.close();
                            }
                        }
                    }
                    else if (choice == 2)
                    {
                        cout << "How would you like the information displayed?"
                             << "\t"
                             << "1. Print to screen (Press 1)"
                             << "\t"
                             << "2. Print to file (Press 2)" << endl;
                        cin >> choice1;
                        if (choice1 == 1)
                        {
                            sort_effect(arr, num_of_spellbooks, book, status);
                            for (int z = 0; z < 5; z++)
                            {                                               // loop through arr
                                for (int y = 0; y < num_of_spellbooks; y++) // loop through spellbook
                                {
                                    for (int j = 0; j < book[y].num_spells; j++) // loop through spells
                                    {
                                        if (arr[z] == book[y].s[j].effect)
                                        {
                                            cout << book[y].s[j].effect << " " << book[y].s[j].name << endl;
                                        }
                                    }
                                }
                            }
                        }
                        else if (choice1 == 2)
                        {
                            cout << "Please provide desired filename: ";
                            cin >> filename;
                            if (DoesFileExist(filename))
                            {
                                file_.open(filename.c_str(), ios::app);
                                sort_effect(arr, num_of_spellbooks, book, status);

                                for (int z = 0; z < 5; z++)
                                {                                               // loop through arr
                                    for (int y = 0; y < num_of_spellbooks; y++) // loop through spellbook
                                    {
                                        for (int j = 0; j < book[y].num_spells; j++) // loop through spells
                                        {
                                            if (arr[z] == book[y].s[j].effect)
                                            {
                                                file_ << book[y].s[j].effect << " " << book[y].s[j].name << endl;
                                            }
                                        }
                                    }
                                }

                                file_.close();
                            }
                            else
                            {
                                file_.open(filename.c_str());
                                sort_effect(arr, num_of_spellbooks, book, status);
                                for (int z = 0; z < 5; z++)
                                {                                               // loop through arr
                                    for (int y = 0; y < num_of_spellbooks; y++) // loop through spellbook
                                    {
                                        for (int j = 0; j < book[y].num_spells; j++) // loop through spells
                                        {
                                            if (arr[z] == book[y].s[j].effect)
                                            {
                                                file_ << book[y].s[j].effect << " " << book[y].s[j].name << endl;
                                            }
                                        }
                                    }
                                }
                                file_.close();
                            }
                        }
                    }
                    else if (choice == 3)
                    {
                        cout << "How would you like the information displayed?"
                             << "\t"
                             << "1. Print to screen (Press 1)"
                             << "\t"
                             << "2. Print to file (Press 2)" << endl;
                        cin >> choice1;
                        if (choice1 == 1)
                        {
                            sort_avg(book, num_of_spellbooks, status);
                            for(int i =0; i <num_of_spellbooks; i++)
                            {
                                cout << book[i].title << " " << book[i].avg_success_rate << endl;
                            }
                        }
                        else if (choice1 == 2)
                        {
                            cout << "Please provide desired filename: ";
                            cin >> filename;;
                            if (DoesFileExist(filename))
                            {
                                file_.open(filename.c_str(), ios::app);
                                sort_avg(book, num_of_spellbooks, status);
                                for(int i =0; i <num_of_spellbooks; i++ )
                                {
                                    file_ << book[i].title << " " << book[i].avg_success_rate << endl;
                                }
                                file_.close();
                            }
                            else
                            {
                                file_.open(filename.c_str());
                                sort_avg(book, num_of_spellbooks, status);
                                for(int i =0; i <num_of_spellbooks; i++ )
                                {
                                    file_ << book[i].title << " " << book[i].avg_success_rate << endl;
                                }
                                file_.close();
                            }
                        }
                    }
                    else if (choice == 4)
                    {
                    delete_info(profile,book, num_of_spellbooks);
                        return 0;
                    }
                    else
                    {
                        cout << "Wrong input" << endl;
                    }
                }
                return 0;
            }
        }
                    cout << "Wrong info" << endl;
            atp++;
    }
}
