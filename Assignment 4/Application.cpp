/******************************************************
** Program: Application.cpp
** Author: Mishary alotaibi
** Date: 5/25/2020
** Description: Class defentations 
** Input: NONE
** Output: NONE
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <vector>
#include <fstream>
#include "Game.h"
using namespace std;
//
void art(){
    string x;
    ifstream file;
    file.open("art.txt");
    while(!file.eof()){
        getline(file,x);
        cout << x<<endl;
    }
}
int main(int argc, char* argv[]){
    int q,w,e,r,t,y,u,i,o,p,a,s,d;
    if(argc != 3){
        cout <<"You are missing either the size of the rooms or missing the settings"<<endl;
        return 1;
    }
    int num;
    string x;
    num = atoi(argv[1]);
    int loop = 0;
    if(num < 4){
        cout << "Sorry, we cannot design a game with this low number of rooms"<<endl;
        return 0;
    }
    if(string(argv[2]) == "True"){
        game g(num);
        g.create_cave();
        q = g.getrp();
        w  = g.getcp();
        e  = g.getre();
         r = g.getce();
         t = g.getyw();
         y = g.getxw();
        u  = g.getyb();
        i = g.getxb();
        o  = g.getyg();
         p = g.getxg();
         a = g.getyp();
         s = g.getxp();
         d = num;
        while(g.getescaped() == false && g.getpalive() == true){
        g.Esp();
        g.check();
        g.actions();
        g.move();
    }
        while(loop == 0){
        cout <<"would you like to continue? or Quit? If Continue then press C, if not then press Q"<<endl;
        cin >> x;
        if(x == "C"){
            cout <<"Same settings? Or random? If Same then press S, if random press R"<<endl;
            cin >> x;
            if(x == "S"){
        game g2(q,w,e,r,t,y,u,i,o,p,a,s,d);
        g2.create_caveS();
        while(g2.getescaped() == false && g2.getpalive() == true){
        g2.Esp();
        g2.check();
        g2.actions();
        g2.move();
        }
        }
        else if(x == "R"){
            game g1(num);
            g1.create_cave();
        while(g1.getescaped() == false && g1.getpalive() == true){
        g1.Esp();
        g1.check();
        g1.actions();
        g1.move();
        }
        }
        else{
            cout << "wrong input"<<endl;
        }
    }
    else if(x == "Q"){
        loop++;
        cout << "Thank you for playing"<<endl;
        art();
        return 0;
    }
}
    }
    else if(string(argv[2]) == "False"){
        game g(num);
        g.create_cave();
        q = g.getrp();
        w  = g.getcp();
        e  = g.getre();
         r = g.getce();
         t = g.getyw();
         y = g.getxw();
        u  = g.getyb();
        i = g.getxb();
        o  = g.getyg();
         p = g.getxg();
         a = g.getyp();
         s = g.getxp();
         d = num;
        while(g.getescaped() == false && g.getpalive() == true){
        g.legit();
        g.check();
        g.actions();
        g.move();
    }
        while(loop == 0){
        cout <<"would you like to continue? or Quit? If Continue then press C, if not then press Q"<<endl;
        cin >> x;
        if(x == "C"){
            cout <<"Same settings? Or random? If Same then press S, if random press R"<<endl;
            cin >> x;
            if(x == "S"){
        game g2(q,w,e,r,t,y,u,i,o,p,a,s,d);
        g2.create_caveS();
        while(g2.getescaped() == false && g2.getpalive() == true){
        g2.legit();
        g2.check();
        g2.actions();
        g2.move();
        }
        }
        else if(x == "R"){
            game g1(num);
            g1.create_cave();
        while(g1.getescaped() == false && g1.getpalive() == true){
        g1.legit();
        g1.check();
        g1.actions();
        g1.move();
        }
        }
        else{
            cout << "wrong input"<<endl;
        }
    }
    else if(x == "Q"){
        loop++;
        cout << "Thank you for playing"<<endl;
        art();
        return 0;
    }
}
}
else{
            cout <<"Wrong settings. You must pick either True or False"<<endl;
        return 1;
}
}