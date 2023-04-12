#ifndef PLAYER_C
#define PLAYER_C
#include "card.hpp"
#include <stack>
namespace ariel{

    using namespace std;
    class Player{
    public:
        Player();
        Player(std::string name);
        std::string Getname();
        Card Getcard();
        void won(stack<Card> cards);
        int stacksize();
        int cardesTaken();
        void lost();
        void draw();
        void newCard(Card card);
        void playerStats();
    private:
        stack<Card> cards_;
        std::string name_;
        stack<Card> takenCards_;
        int draw_ = 0;
        int won_ = 0;
        int lose_ = 0;
        int CardSize = 0;
        int CardTaken = 0;
    };
}
#endif
