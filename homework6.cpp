#include <iostream>
#include <vector>

using namespace std;

//----------------------------Task 2----------------------------

ostream& endll(ostream& strm) {
    strm << "\n\n";
    strm.flush();
    return strm;
}

//--------------------------Task 3,4,5--------------------------

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
            FaceUp = false;
        }
        friend ostream& operator<<(ostream& out, Card card);
        void Flip() {
            FaceUp = true;
        }
        const int GetValue() {
            return Value;
        }
        const int GetSuit() {
            return Suit;
        }
        bool State() { return FaceUp; }
        ~Card() {
    }
};

ostream& operator<< (ostream& out, Card card) {
    const string Ranks[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string Suits[] = { "h", "s", "d", "c" };   
    if(card.State() == false) {
        cout << "XX     XX" << endl;
    }
    else {
        cout << Suits[card.GetSuit()] << "     " << Ranks[card.GetValue()] << endl;
        return out;
    }
}

class Hand
{
public:
    vector<Card*> Collection;
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
    virtual ~Hand() {
    }
};

class GenericPlayer : public Hand
{
private:
    string name;
public:
    GenericPlayer(const string& NewName) : name(NewName) {
    }
    friend ostream& operator<< (ostream& out, GenericPlayer& player);
    virtual bool IsHitting() const = 0;
    bool IsBoosted() {
        return GetHandValue() > 21;
    }
    string const GetName() { return name; }
    void Bust() {
        cout << name << "is busted!" << endl;
    }
    ~GenericPlayer() {
    }
};

ostream& operator<< (ostream& out, GenericPlayer& player) {
    cout << player.GetName() << "       " << endl;
    for(int i = 0; i < player.Collection.size(); i++) {
        cout << player.Collection[i];
    }
    cout << endl << "total: " << player.GetHandValue() << endl;
}

class Player : public GenericPlayer
{
public:
    Player(string NewName) : GenericPlayer(NewName) {
    }
    virtual bool IsHitting() const {
        cout << "Card? Y/N  ";
        char answer;
        cin.get(answer);
        if(answer == 'Y') { 
            cin.sync();
            return true; 
        }
        else { 
            cin.sync();
            return false; 
        }

    }
    void Win() {
        cout << GetName() << ": Won!";
        return; 
    }
    void Lose() {
        cout << GetName() << ": Lose!";
        return; 
    }
    void Push() {
        cout << GetName() << ": Draw!";
        return; 
    }
    ~Player() {
    }
};

class House : public GenericPlayer
{
public:
    House(string NewName) : GenericPlayer(NewName) {
    }
    virtual bool IsHitting() const {
        cout << "Card? Y/N  ";
        char answer;
        cin.get(answer);
        if(answer == 'Y') { 
            cin.sync();
            return true; 
        }
        else { 
            cin.sync();
            return false; 
        }

    }
    void FlipFirstCard() {
        Collection[0]->Flip();
    }
    ~House() {
    }
};


int main() {
//----------------------------Task 1----------------------------
    int i;
    cout<<"Enter int : ";
    while(!(cin>>i) || cin.get() != '\n') {
        cin.clear();
        cin.sync();
        cout<<"Enter int : ";
    }
    return 0;
}