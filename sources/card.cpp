#include <iostream>
#include <stack>
#include "card.hpp"
using namespace std;
namespace ariel{   
    int value_;
    std::string name_;
    std::string shape_;
    Card::Card(){
    }
    Card::Card(int value, string shape){
        this->value_ = value;
        this->shape_ = shape;
        this->name_ = setName(value);
    }
    std::string Card::setName(int value ){
        if( !value ) return "None";
        else if( value == 1) return "A";
        else if( value == 2) return "2";
        else if( value == 3) return "3";
        else if( value == 4) return "4";
        else if( value == 5) return "5";
        else if( value == 6) return "6";
        else if( value == 7) return "7";
        else if( value == 8) return "8";
        else if( value == 9) return "9";
        else if( value == 10) return "10";
        else if( value == 11) return "J";
        else if( value == 12) return "Q";
        else if( value == 13) return "K";
        return "None";
    }
    std::string Card::getName(int v ){
        return name_;
    }

    int Card::getValue(){return this->value_;}
            
    int Card::compare(Card c){
        if(value_== c.getValue()) return 0;
        else if( value_ == 1 && c.getValue() != 2) return 1;
        else if( value_ != 2 && c.getValue() == 1) return 2;
        else if( value_ > c.getValue()) return 1;
        else if( value_ < c.getValue()) return 2;
        return 0;
    }
    std::string Card::toString(){
        return this->name_+ " of " + this->shape_;
    }
}