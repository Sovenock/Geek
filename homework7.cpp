#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>

using namespace std;

//----------------------------Task 1----------------------------
/*
class Date
{
private:
    uint8_t day;
    uint8_t month;
    uint8_t year;
    
public:
    Date(uint8_t NewDay, uint8_t NewMonth, uint8_t NewYear) : day(NewDay), month(NewMonth), year(NewYear) {
    }
    uint8_t GetDay() const {
        return day;
    }
    uint8_t GetMonth() const {
        return month;
    }
    uint8_t GetYear() const {
        return year;
    }
    friend ostream& operator<<(ostream& out, Date date);
    ~Date() {
    }
};

ostream& operator<<(ostream& out, Date date) {
    cout << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() << endl;
    out.flush();
    return out;
}

template <class T>
class today
{
private:
    T* m_obj;
public:
    today(T* obj) : m_obj(obj) {
    }
    T* operator->() { return m_obj; }
    T& operator* () { return *m_obj; }
    ~today() {
        delete m_obj;
    }
};

template <class T>
class date
{
private:
    T* m_obj;
public:
    date(T* obj) : m_obj(obj) {
    }
    T* operator->() { return m_obj; }
    T& operator* () { return *m_obj; }
    ~date() {
        delete m_obj;
    }
};

//----------------------------Task 2----------------------------

void OlderOne(today& date1, today& date2) {
    if(date1->GetYear() > date2->GetYear()) { return date1; }
    else if(date1->GetYear() < date2->GetYear()) { return date2; }
    else {
        if(date1->GetMonth() > date2->GetMonth()) { return date1; }
        else if(date1->GetMonth() < date2->GetMonth()) { return date2; }
        else {
            if(date1->GetDay() > date2->GetDay()) { return date1; }
            else if(date1->GetDay() < date2->GetDay()) { return date2; }
        }
    }
}
*/
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
        Card(suit NewSuit, value NewValue) {
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
    GenericPlayer(){
    };
    GenericPlayer(const string& NewName) : name(NewName) {
    }
    friend ostream& operator<< (ostream& out, GenericPlayer& player);
    virtual bool IsHitting() const;
    bool IsBusted() {
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
    bool IsHitting() const override {
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
    House() : GenericPlayer() {
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

class Deck : public Hand
{
private:
    
public:
    Deck() {
        Populate();
    }
    void Populate() {
        Clear();
        for (int s = heart; s <= cross; ++s)
        {
            for (int r = ace; r <= king; ++r)
            {
                Add(new Card(static_cast<suit>(s),static_cast<value>(r)));
            }
        }
    }
    void Shuffle() {
        random_shuffle(Collection.begin(), Collection.end());
    }
    void Deal(Hand& aHand)
    {
        if (!Collection.empty())
        {
            aHand.Add(Collection.back());
            Collection.pop_back();
        }
        else
        {
            cout << "Out of cards. Unable to deal.";
        }
    }
    void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        cout << endl;
        while(!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;
            if (aGenericPlayer.IsBusted())
            {
                aGenericPlayer.Bust();
            }
        }
    }

    ~Deck() {
    }
};

class Game
{
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
public:
    Game(const vector<string>& names) {
        vector<string>::const_iterator pName;
        for (pName = names.begin(); pName != names.end(); ++pName)
        {
            m_Players.push_back(Player(*pName));
        }
        srand(static_cast<unsigned int>(time(0)));
        m_Deck.Populate();
        m_Deck.Shuffle();
    }
    void Game::Play()
{
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard();
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << m_House << endl;
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AdditionalCards(*pPlayer);
    }
    m_House.FlipFirstCard();
    cout << endl << m_House;
    m_Deck.AdditionalCards(m_House);
    if (m_House.IsBusted())
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                if (pPlayer->GetHandValue() > m_House.GetHandValue())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetHandValue() < m_House.GetHandValue())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }
        
    }
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    m_House.Clear();
}

    ~Game() {
    }
};


int main() {
/*//----------------------------Task 1----------------------------
    today<Date> pDate(new Date(15, 6, 2021));
    cout << pDate->GetDay() << "." << pDate->GetMonth() << "." << pDate->GetYear() << endl;
    cout << pDate;
    date<Date> p2Date(new Date(8,5,1973));
    p2Date = pDate;
    cout << p2Date;
//----------------------------Task 2----------------------------
    today<Date> date1(new Date(4,8,1456));
    today<Date> date2(new Date(5,9,2567));
*/

    cout << "Enter number of players : ";
    int PlayersCount;
    cin >> PlayersCount;
    vector<string> names;
    for(int i = 0; i < PlayersCount; i++) {
        cout << "Name please : ";
        cin >> names[i];
        cout << endl;
    }
    char Answer = 'Y';
    do 
    {
        Game game(names);
        game.Play();
        cout << "Another one? Y/N : ";
    }
    while(Answer ==  'Y' || Answer == 'y');
    return 0;
}