/******************************************************
** Program: Game.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <ctime>
#include "Game.h"
#include "Pit.h"
#include "Gold.h"
#include "Bats.h"
#include "Wumpus.h"
#include "Escape.h"
using namespace std;
/*********************************************************************
** Function:game
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
// it was over 15 lines because i had to initialize all y and x axis to all events
game::game(int x){
    r_p = 0;
    c_p = 0;
    r_e = 0;
    c_e = 0;
    yw = 0;
    xw = 0;
    yb = 0;
    xb = 0;
    yg = 0;
    xg = 0;
    yp = 0;
    xp = 0;
    arrow = 3;
    row = x;
    col = x;
    alive = true;
    palive = true;
    escaped = false;
    treasure = false;
    }
/*********************************************************************
** Function:game
** Description:Constructer that initialize everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
// it was over 15 lines because i had to initialize all y and x axis to all events
game::game(int q , int w,int e , int r,int t, int y,int u,int i , int o,int p, int a,int s , int d){
    r_p = q;
    c_p = w;
    r_e = e;
    c_e = r;
    yw = t;
    xw = y;
    yb = u;
    xb = i;
    yg = o;
    xg = p;
    yp = a;
    xp = s;
    arrow = 3;
    row = d;
    col = d;
    alive = true;
    palive = true;
    escaped = false;
    treasure = false;
}
/*********************************************************************
** Function:game
** Description:deconstructer that delete everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
game::~game(){
    for(int i =0; i < row; i++){
        for(int j = 0; j < col; j++){
           delete rooms[i][j].getevent();
        }
    }
}
/*********************************************************************
** Function:create cave
** Description:creates the cave and the x and y axis  + create events
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//i had to check all y and x axis to not be duplicated
void game::create_cave(){
    srand(time(NULL));
    r_p = rand()% row;
    c_p = rand()% row;
    yw = rand()% row;
    xw = rand()% row;
    r_e = r_p;
    c_e = c_p;
    xb = rand()% row;
    xg = rand()% row;
    xp = rand()% row;
    while(yw == r_p){
        yw =rand()% row;
    }
    yb = rand()% row;
    while(yw == yb || r_p == yb){
        yb =rand()% row;
    }
    yg = rand()% row;
        while(yw == yg || yg == yb || r_p == yg){
        yg =rand()% row;
    }
    yp = rand()% row;
        while(yw == yp || yg == yp || yb == yp || r_p == yp){
        yp =rand()% row;
    }
        for(int i =0; i < row; ++i){
        vector<Room> row_room;
        for(int j=0; j < col; ++j){
            row_room.push_back(room);
        }
        rooms.push_back(row_room);
        }
    Event* pit = new Pit;
    Event* gold = new Gold;
    Event* wumpus = new Wumpus;
    Event* bats = new Bats;
    rooms[yp][xp].setevent(pit);    
    rooms[yg][xg].setevent(gold);
    rooms[yw][xw].setevent(wumpus);
    rooms[yb][xb].setevent(bats);
    Event* escape = new Escape;
    rooms[r_e][c_e].setevent(escape);
}
/*********************************************************************
** Function:create caveS
** Description:creates the cave and the x and y axis  + create events
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void game::create_caveS(){
    for(int i =0; i < row; ++i){
        vector<Room> row_room;
        for(int j=0; j < col; ++j){
            row_room.push_back(room);
        }
        rooms.push_back(row_room);
        }
    Event* pit = new Pit;
    Event* gold = new Gold;
    Event* wumpus = new Wumpus;
    Event* bats = new Bats;
    rooms[yp][xp].setevent(pit);    
    rooms[yg][xg].setevent(gold);
    rooms[yw][xw].setevent(wumpus);
    rooms[yb][xb].setevent(bats);
    Event* escape = new Escape;
    rooms[r_e][c_e].setevent(escape);
}
/*********************************************************************
** Function:move
** Description:moves for all direction and shoot
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because it includes shoot and move function. I tried to do it separately but couldn't
void game::move(){
    string move;
    int loop = 0;
    while(loop == 0 && palive == true && escaped == false){
    cout << "which direction would you like to move? W (north), A (west), S (south), or D (east), X"<<endl;
    cin >> move;
    if(move == "X"){
        if(!(arrow == 0)){
            shoot();
            loop++;
        }
        else{
            cout <<"You are out of arrows"<<endl;
        }
    }
    if(move == "W"){
        int test = r_p;
        if(!(test - 1 < 0)){
            r_p--;
        }
        else{
            cout <<"You can't go that way"<<endl;
        }
        loop++;
    }
        if(move == "A"){
        int test = c_p;
        if(!(test - 1 < 0)){
            c_p--;
        }
        else{
            cout <<"You can't go that way"<<endl;
        }
        loop++;
    }
        if(move == "S"){
        int test = r_p;
        if(!(test + 1 == row)){
            r_p++;
        }
        else{
            cout <<"You can't go that way"<<endl;
        }
        loop++;
    }
        if(move == "D"){
        int test = c_p;
        if(!(test + 1 == col)){
            c_p++;
        }
        else{
            cout <<"You can't go that way"<<endl;
        }
        loop++;
    }
    }
}
/*********************************************************************
** Function:check
** Description:checks everything
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void game::check(){
    cout << "-----------Notification-----------"<<endl;
    if(r_p - 1 >= 0){
        if(rooms[r_p - 1][c_p].gethas() == true){
            cout << rooms[r_p - 1][c_p].getmessage()<<endl;
        }
    }
        if(c_p - 1 >= 0){
        if(rooms[r_p][c_p - 1].gethas() == true){
            cout << rooms[r_p][c_p - 1].getmessage()<<endl;
        }
    }
        if(r_p + 1 != row){
        if(rooms[r_p + 1][c_p].gethas() == true){
            cout << rooms[r_p + 1][c_p].getmessage()<<endl;
        }
    }
        if(c_p + 1 !=row ){
        if(rooms[r_p][c_p+ 1].gethas() == true){
            cout << rooms[r_p][c_p+ 1].getmessage()<<endl;
        }
    }
}
/*********************************************************************
** Function:shoot
** Description:shoot function
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void game::shoot(){
    string x;
    cout << "Which direction would you like to shoot? W (north), A (west), S (south), or D (east)"<<endl;
    cin >> x;
    if(x == "W"){
        shootUp();
    }
        if(x == "A"){
            shootLeft();
    }
        if(x == "S"){
            shootDown();
    }
        if(x == "D"){
            shootRight();
}
}
/*********************************************************************
** Function:moveW
** Description:moves the wumpus 
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void game::moveW(){
    rooms[yw][xw].sethas(false);
    int loop = 0;
    while(loop == 0){
    int x = rand()% row;
    int z = rand()% row;
        if(!(rooms[z][x].gethas() == true)){
            yw = z;
            xw = x;
            rooms[z][x].sethas(false);
            Event* wumpus = new Wumpus;
            rooms[yw][xw].setevent(wumpus);
            loop++;
        }
    }
}
/*********************************************************************
** Function:getescaped
** Description:get function
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
bool game::getescaped(){
    return escaped;
}
/*********************************************************************
** Function:shootUp
** Description:shoots W
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if its exceeds the number of rows and then check the rooms
void game::shootUp(){
    int test = r_p;
					if(test - 3 < 0){
						if(test - 1 >= 0){
							if(rooms[r_p-1][c_p].getWho() == "Wumpus"){
								rooms[r_p-1][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test - 2 >= 0){
							if(rooms[r_p-2][c_p].getWho() == "Wumpus"){
								rooms[r_p-2][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test - 3 >= 0){
							if(rooms[r_p-3][c_p].getWho() == "Wumpus"){
								rooms[r_p-3][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						else{
                            int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                         cout << "You need to Train your aim more, you just missed your shot"<<endl;
                            arrow-=1;
                         int p = rand()% 100;
                         if(p < 75){
                          moveW();
                         if(r_p == yw && c_p == xw){
                            palive = false;
                      }
                        }
						}
                        }
					}
					else{
						if(rooms[r_p-1][c_p].getWho() == "Wumpus"){
								rooms[r_p-1][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p-2][c_p].getWho() == "Wumpus"){
								rooms[r_p-2][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p-3][c_p].getWho() == "Wumpus"){
								rooms[r_p-3][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else{
                                                        int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                cout << "You need to Train your aim more, you just missed your shot"<<endl;
                 arrow-=1;
                 int p = rand()% 100;
                    if(p < 75){
                 moveW();
                if(r_p == yw && c_p == xw){
                    palive = false;
                }
            }
                            }
						}
					}
}
/*********************************************************************
** Function:shootDown
** Description:shoots S
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if its exceeds the number of rows and then check the rooms
void game::shootDown(){
    int test = r_p;
					if(test + 3 >= row){
						if(test + 1 < row){
							if(rooms[r_p+1][c_p].getWho() == "Wumpus"){
								rooms[r_p+1][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test + 2 < row){
							if(rooms[r_p+2][c_p].getWho() == "Wumpus"){
								rooms[r_p+2][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test + 3 < row){
							if(rooms[r_p+3][c_p].getWho() == "Wumpus"){
								rooms[r_p+3][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						else{
                            int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                         cout << "You need to Train your aim more, you just missed your shot"<<endl;
                            arrow-=1;
                         int p = rand()% 100;
                         if(p < 75){
                          moveW();
                         if(r_p == yw && c_p == xw){
                            palive = false;
                      }
                        }
						}
                        }
					}
					else{
						if(rooms[r_p+1][c_p].getWho() == "Wumpus"){
								rooms[r_p+1][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p+2][c_p].getWho() == "Wumpus"){
								rooms[r_p+2][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p+3][c_p].getWho() == "Wumpus"){
								rooms[r_p+3][c_p].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else{
                                                        int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                cout << "You need to Train your aim more, you just missed your shot"<<endl;
                 arrow-=1;
                 int p = rand()% 100;
                    if(p < 75){
                 moveW();
                if(r_p == yw && c_p == xw){
                    palive = false;
                }
            }
                            }
						}
					}
}
/*********************************************************************
** Function:shootLeft
** Description:shoots A
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if its exceeds the number of rows and then check the rooms
void game::shootLeft(){
        int test = c_p;
					if(test - 3 < 0){
						if(test - 1 >= 0){
							if(rooms[r_p][c_p -1].getWho() == "Wumpus"){
								rooms[r_p][c_p-1].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test - 2 >= 0){
							if(rooms[r_p][c_p - 2].getWho() == "Wumpus"){
								rooms[r_p][c_p - 2].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test - 3 >= 0){
							if(rooms[r_p][c_p - 3].getWho() == "Wumpus"){
								rooms[r_p][c_p - 3].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						else{
                            int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                         cout << "You need to Train your aim more, you just missed your shot"<<endl;
                            arrow-=1;
                         int p = rand()% 100;
                         if(p < 75){
                          moveW();
                         if(r_p == yw && c_p == xw){
                            palive = false;
                      }
                        }
						}
                        }
					}
					else{
						if(rooms[r_p][c_p - 1].getWho() == "Wumpus"){
								rooms[r_p][c_p - 1].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p][c_p-2].getWho() == "Wumpus"){
								rooms[r_p][c_p-2].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p][c_p-3].getWho() == "Wumpus"){
								rooms[r_p][c_p-3].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else{
                                                        int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                cout << "You need to Train your aim more, you just missed your shot"<<endl;
                 arrow-=1;
                 int p = rand()% 100;
                    if(p < 75){
                 moveW();
                if(r_p == yw && c_p == xw){
                    palive = false;
                }
            }
                            }
						}
					}
}
/*********************************************************************
** Function:shootRight
** Description:shoots D
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to check first if its exceeds the number of rows and then check the rooms
void game::shootRight(){
            int test = c_p;
					if(test + 3 >= row){
						if(test + 1 < row){
							if(rooms[r_p][c_p +1].getWho() == "Wumpus"){
								rooms[r_p][c_p+1].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test + 2 < row){
							if(rooms[r_p][c_p + 2].getWho() == "Wumpus"){
								rooms[r_p][c_p + 2].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						if(test + 3 < row){
							if(rooms[r_p][c_p + 3].getWho() == "Wumpus"){
								rooms[r_p][c_p + 3].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
							}
						}
						else{
                            int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                         cout << "You need to Train your aim more, you just missed your shot"<<endl;
                            arrow-=1;
                         int p = rand()% 100;
                         if(p < 75){
                          moveW();
                         if(r_p == yw && c_p == xw){
                            palive = false;
                      }
                        }
						}
                        }
					}
					else{
						if(rooms[r_p][c_p + 1].getWho() == "Wumpus"){
								rooms[r_p][c_p + 1].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p][c_p+2].getWho() == "Wumpus"){
								rooms[r_p][c_p+2].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else if(rooms[r_p][c_p+3].getWho() == "Wumpus"){
								rooms[r_p][c_p+3].sethas(false);
								cout << "You have killed the Wumpus"<<endl;
                                alive = false;
								arrow--;
						}
						else{
                                                        int miss =0;
                            for(int i =0; i<row; i++){
                                for(int j =0; j < row; j++){
                                    if(rooms[i][j].getWho() == "Wumpus" && rooms[i][j].gethas() == true){
                                        miss++;
                                    }
                                }
                            }
                            if(miss == 1){
                cout << "You need to Train your aim more, you just missed your shot"<<endl;
                 arrow-=1;
                 int p = rand()% 100;
                    if(p < 75){
                 moveW();
                if(r_p == yw && c_p == xw){
                    palive = false;
                }
            }
                            }
						}
					}
}
/*********************************************************************
** Function:Esp
** Description:print the cave with letters
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines because i had to design it :)
void game::Esp(){
    for(int i=0;i<col;i++){
        cout << " ----";
    }
    cout << endl;
    for(int i=0;i<row;i++)
    {
    	cout << "   |";
        for(int j=0;j<col;j++)
        {
            if(rooms[i][j].gethas() == true){
            	if(rooms[i][j].getWho() == "Wumpus")
            		cout << "_W_|";
                else if(rooms[i][j].getWho() == "Pit")
            		cout << "_P_|";
            	else if(rooms[i][j].getWho() == "Bats")
            		cout << "_B_|";
            	else if(rooms[i][j].getWho() == "Gold")
            		cout << "_G_|";
            	else if(rooms[i][j].getWho() == "Escape")
            		cout << "_E_|";
            }
            else if(i == r_p && j == c_p)
            	cout << "_#_|";
            else
               	cout << "___|";
            if(j==(col-1))
                cout << endl;
        }   
    }
    cout << endl;
    cout << "You have: " << arrow << " Arrows"<<endl;
}
/*********************************************************************
** Function:Esp
** Description:print the cave with letters
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
void game::legit(){
    for(int i=0;i<col;i++){
        cout << "---+";
    }
    cout << endl;
    for(int i=0;i<row;i++)
    {
    	cout << "   |";
        for(int j=0;j<col;j++)
        {
            if(i == r_p && j == c_p)
            	cout << "_#_|";
            else
               	cout << "___|";
            if(j==(col-1))
                cout << endl;
        }   
    }
    cout << endl;
    cout << "You have: " << arrow << " Arrows"<<endl;
}
/*********************************************************************
** Function:getpalive
** Description:get function
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
bool game::getpalive(){
    return palive;
}
/*********************************************************************
** Function:Actions
** Description:
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
//it was over 15 lines i had to check if the player is on the event or not 
void game::actions(){
    if(r_p == yw && c_p == xw){
        if(rooms[yw][xw].gethas() == true){
        rooms[yw][xw].action();
        palive = false;
        }
    }
     if(r_p == yb && c_p == xb){
        if(rooms[yb][xb].gethas() == true){
        rooms[yb][xb].action();
        int r = rand() % row;
		int c = rand() % col;
		r_p = r;
		c_p = c;
        rooms[yb][xb].sethas(false);
        actions();
        }
    }
     if(r_p == yg && c_p == xg){
        if(rooms[yg][xg].gethas() == true){
        rooms[yg][xg].action();
        rooms[yg][xg].sethas(false);
        treasure = true;
        }
    }
     if(r_p == yp && c_p == xp){
         if(rooms[yp][xp].gethas() == true){
        rooms[yp][xp].action();
        rooms[yp][xp].sethas(false);
        palive = false;
        }
    }
     if(r_p == r_e && c_p == c_e){
        if(treasure == true && alive == false){
            rooms[r_e][c_e].action();
            escaped = true;
        }
        else if(treasure == true && alive == true){
            cout<<"You have to Hunt the Wumpus"<<endl;
        }
        else{
            cout << "Can't escape without gold"<<endl;
        }
    }
}
/*********************************************************************
** Function:getters
** Description:get all the positions
** Parameters:-
** Pre-Conditions:-
** Post-Conditions:-
*********************************************************************/
int game::getrp(){
    return r_p;
}
int game::getcp(){
    return c_p;
}
int game::getre(){
    return r_e;
}
int game::getce(){
    return c_e;
}
int game::getyw(){
    return yw;
}
int game::getxw(){
    return xw;
}
int game::getyb(){
    return yb;
}
int game::getxb(){
    return xb;
}
int game::getyg(){
    return yg;
}
int game::getxg(){
    return xg;
}
int game::getyp(){
    return yp;
}
int game::getxp(){
    return xp;
}