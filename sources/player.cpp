
#include "card.hpp"
#include <iostream>
#include <stack>
#include "player.hpp"

using namespace std;
namespace ariel{

    Player::Player() {
        name_ = ("No name");
    }
    Player::Player(std::string name) {
        name_ = name;
    }
    std::string Player::Getname(){
        return name_;
    }

    Card Player::Getcard(){
        Card first =  cards_.top();
        cards_.pop();
        CardSize -= 1;
        return first;
    }
    void Player::won(stack<Card> cardt)
    {
        while (!cardt.empty()){
            takenCards_.push(cardt.top());
            cardt.pop();
            CardTaken += 1;
        }
        won_ += 1;
    }
    void Player::lost()
    {
        lose_ += 1;
    }
    void Player::draw()
    {
        draw_ += 1;
    }
    int Player::cardesTaken()
    {
        return CardTaken;
    }

    void Player::newCard(Card c){
        cards_.push(c);
        CardSize++;
    }
    int Player::stacksize() {
        return CardSize;
    }
    void Player::playerStats() {
        int rounds =  draw_ + lose_ + won_;
        double winR = double(won_ )/ double(rounds); 
        double loseR = double(lose_ )/ double(rounds); 
        double drawR = double(draw_ )/ double(rounds); 
        cout << "Player: " + name_ << endl;
        cout << "Win rate: "<< winR << endl;
        cout << "Cards won: "<< CardTaken << endl;
        cout << "Lose rate: "<< loseR << endl;
        cout << "Draw rate: "<< drawR << endl;
        cout << "Amount of draw: " << draw_ << endl;
    }
}