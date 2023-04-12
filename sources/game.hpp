#ifndef GAME_C
#define GAME_C
#include "player.hpp"
#include <iostream>
#include <vector>
namespace ariel{
    
    using namespace std;
    class Game{ 
    public:

        Game(Player & player1, Player & player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    private:
        std::string turn;
        Player & player1;
        Player & player2;
        int rounds_;
        vector<string> turns;
            
    };
}
#endif