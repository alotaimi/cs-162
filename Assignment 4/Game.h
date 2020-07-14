#ifndef GAME_H
#define GAME_H
#include "Room.h"
class game{
    private:
    int row; //Grid Y
    int col; //Grid X
    int r_p; // Player Y
    int c_p; // Player X
    int r_e; // Escape Y
    int c_e; // Escape X
    int yw; // Wumpus Y
    int xw; // Wumpus X
    int yb; //bats Y
    int xb; // Bats X
    int yg; //Gold Y
    int xg; // Gold X
    int yp; // Pit Y
    int xp; // Pit X
    int arrow;
    bool alive; // Wumpus alive
    bool palive; //Player Alive
    bool escaped; //Escape route
    bool treasure; //gold 
    Room room;
    vector <vector<Room> > rooms;
    public:
    game(int x);
    game(int , int,int , int,int , int,int,int , int,int , int,int , int);
    ~game();
    void create_cave();
    void create_caveS();
    void Esp();
    void legit();
    void move();
    void check();
    void shoot();
    void shootUp();
    void shootDown();
    void shootLeft();
    void shootRight();
    bool getescaped();
    bool getpalive();
    void actions();
    void moveW();

    int getrp();
    int getcp();
    int getre();
    int getce();
    int getyw();
    int getxw();
    int getyb();
    int getxb();
    int getyg();
    int getxg();
    int getyp();
    int getxp();
};
#endif