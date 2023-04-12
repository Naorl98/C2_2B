
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <algorithm>
#include <iostream>
#include <random>
namespace ariel{

        Game::Game(Player & player1, Player & player2) : player1(player1), player2(player2){
                rounds_ = 0;
                vector<Card> deck;
                for (int i = 1; i <= 13; i++)
                {
                        deck.push_back(Card(i, "Spades"));
                        deck.push_back(Card(i, "Hearts"));
                        deck.push_back(Card(i, "Diamonds"));
                        deck.push_back(Card(i, "Clubs"));
                }

                random_device rnd;
                mt19937 g(rnd());
                shuffle(deck.begin(), deck.end(), g);
                unsigned long int size = 0;
                while (size < 52){
                        player1.newCard(deck[size]);
                        player2.newCard(deck[size+1]);
                        size += 2;                     
                        }
                }
                
       

        void Game::playTurn() {
                Card c1;
                Card c2;
                stack<Card> cards;
                if (player1.stacksize() == 0 || player2.stacksize() == 0){
                        throw logic_error("Game finished");  
                        return;
                }
                if (&player1 == &player2){
                        throw logic_error("Same player");
                        return;
                }
                try{
                        c1 = player1.Getcard();
                        c2 = player2.Getcard();
                        cards.push(c1);
                        cards.push(c2);
                }
                catch (exception e)
                {
                        return;
                }
                while (c1.compare(c2) == 0){
                        player1.draw();
                        player2.draw();
                        turns.push_back(player1.Getname() +" played " + c1.toString() +", "+ player2.Getname() +" played " + c2.toString() + ". Draw.");
                        rounds_++;
                        if(player1.stacksize() <= 1 && player2.stacksize() <= 1){
                                if(player1.stacksize() == 1 && player2.stacksize() == 1){
                                        c1 = player1.Getcard();
                                        c2 = player2.Getcard();
                                        cards.push(c1);
                                        cards.push(c2);                                        
                                }
                                stack<Card> cards1;
                                stack<Card> cards2;
                                while(!cards.empty()){
                                        cards2.push(cards.top());
                                        cards.pop();
                                        cards1.push(cards.top());
                                        cards.pop();                                        
                                }
                                player1.won(cards1);
                                player2.won(cards2);
                                break;
                        }
                        try{
                                c1 = player1.Getcard();
                                c2 = player2.Getcard();
                                cards.push(c1);
                                cards.push(c2);
                                c1 = player1.Getcard();
                                c2 = player2.Getcard();
                                cards.push(c1);
                                cards.push(c2);
                        }
                        catch (exception e)
                        {
                                cout << "No more Cards" << endl;
                        }
                }
                if(c1.compare(c2) == 1){
                        turns.push_back(player1.Getname() +" played " + c1.toString() +", "+ player2.Getname() +" played " + c2.toString() + "." + player1.Getname() +" wins.");
                        rounds_++;
                        player1.won(cards);
                        player2.lost();  
                }
                else if(c1.compare(c2) == 2){
                        turns.push_back(player1.Getname() +" played " + c1.toString()+", " + player2.Getname() +" played " + c2.toString() + "." + player2.Getname() +" wins.");                       
                        rounds_++;
                        player2.won(cards);
                        player1.lost();        
                }


        }

        void Game::printLastTurn() {
                cout << turns.back() << endl;         
        }

        void Game::playAll() {
                while(player1.stacksize() != 0 || player2.stacksize() != 0) 
                        playTurn();
        }

        void Game::printWiner() {
                if(player1.cardesTaken() > player2.cardesTaken())
                        cout << player1.Getname() + " WON" << endl;
                else if(player1.cardesTaken() < player2.cardesTaken())
                        cout << player2.Getname() + " WON" << endl;
                else
                        cout << "it's a DRAW!!" << endl;
        }

        void Game::printLog() {
                for (unsigned long int i = 0; i < rounds_; i++)
                {
                        cout << turns[i]<< endl;         
                }
                
        }

        void Game::printStats() {      
                player1.playerStats();
                player2.playerStats();       

        }
            
}