#ifndef CARD_C
#define CARD_C
#include <string>
namespace ariel{

    using namespace std;
    class Card{ 
    public:
        Card();
        Card(int value, string shape);
        string setName(int value);
        int getValue();
        string getName(int value);
        int compare(Card card);
        string toString();
    private:
        int value_;
        string name_;
        string shape_;

            
    };
}
#endif