#include <string>
#include <vector>
#include <iostream>

using namespace std;
//----------------------------Task 1----------------------------

template <class T>
class Pair1
{
private:
    T first;
    T second;
public:
    Pair1(T num1, T num2) : first(num1), second(num2) {
    }

    ~Pair1() {
    }

};

//----------------------------Task 2----------------------------

template <class t1, class t2>
class Pair
{
private:
    t1 first;
    t2 second;
public:
    Pair(t1 num1, t2 num2) : first(num1), second(num2) {
    }

    ~Pair() {
    }
};

//----------------------------Task 3----------------------------

template <typename S> 
class StringValuePair : public Pair <string, S> 
{
private:
    
public:
    StringValuePair(string Line, S Value) : Pair(num1, num2) {
    }

    ~StringValuePair() {
    }
};

//----------------------------Task 4----------------------------

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
        Collection.clear(); // в прошлом задании вы написали, что нужно не забывать про освобождение памяти на этой строчке. Я не смог разобраться. Подскажите как это сделать?
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

class GenericPlayer : public Hand
{
private:
    string name;
public:
    GenericPlayer(string NewName) : name(NewName) {
    }
    virtual bool IsHitting();
    bool IsBoosted() {
        if(GetHandValue() > 21) { return true; }
        else { return false; }
    }
    void Bust() {
        cout << name << "is busted!" << endl;
    }
    ~GenericPlayer() {
    }
};
