#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

//----------------------------Task 3----------------------------

enum suit {heart, spade, diamond, cross};
enum value {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10};

class Card
{
    private:
    suit Suit;
    value Value;
    bool FaceUp;
    public:
        Card() {
        }
        void Flip() {
            if (FaceUp == false) {
                FaceUp = true;
            }
            else {
                FaceUp = false;
            }
        }
        const int GetValue() {
            return Value;
        }
        ~Card() {
        }
};

class Hand
{
private:
    vector<Card*> Collection;    
public:
    Hand() {
    }
    void Add(Card* NewCard) {
        Collection.push_back(NewCard);
    }
    void Clear() {
        Collection.clear();
    }
    const int GetHandValue() {
        int result = 0;
        int AceCount = 0;;
        for(int i = 0; i < Collection.size(); i++) {
            if(Collection[i]->GetValue() == 1) { AceCount++;} 
            else { result+=Collection[i]->GetValue();}
        }
        while(AceCount != 0) {
            if(result + 11 <= 21) { result+= 11;}
            else{ result+= 1;}
        }
        return result;
    }
    ~Hand() {
    }
};



int main() {
    srand(time(NULL));
//----------------------------Task 2----------------------------
    int size = rand()%50;
    vector<int> array(size);
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    int count = 0, FinalCount = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(array[i] == array[j]) { count++;}
        }
        if(count > FinalCount) {
            FinalCount = count;
            count = 0;
        }
    }
    cout << FinalCount << endl;
    return 0;
}