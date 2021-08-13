#include <iostream>
#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

//----------------------------Task 1----------------------------
class Figure {
    public:
        Figure(){

        } 
        
        virtual int Area();
        
        virtual ~Figure(){

        }
};
class Parrallelogram:public Figure {
    private:
        int height;
        int side;
    public:
        Parrallelogram(int a, int b) {
            this -> height = a;
            this -> side = b;
        }
        int Area() override {
            return height*side;
        }
        const int Get_Height() {
            return height;
        }
        const int Get_Side() {
            return side;
        }
        ~Parrallelogram() {

        }
};
class Circle:public Figure {
    private:
    int radius;
    public:
        Circle(int a){
            radius = a;
        }
        int Area() override {
            return M_PI*pow(radius, 2);
        }
        ~Circle() {
        }
};
class Rectangle:public Parrallelogram {
    public:
        Rectangle(int a, int b):Parrallelogram(a, b) {
        }
        int Area() override {
            return Get_Height() * Get_Side();
        }
        ~Rectangle() {
        }
};
class Square:public Parrallelogram {
    private:
    public:
        Square(int a, int b): Parrallelogram(a,b) {
        }
        int Area() override {
            return pow(Get_Side(), 2);
        }
        ~Square() {
        }
};
class Rhombus:public Parrallelogram {
    private:
    public:
        Rhombus(int a, int b) : Parrallelogram(a,b) {
        }
        int Area() override {
            return Get_Height() * Get_Side();
        }
        ~Rhombus() {
        }
};

//----------------------------Task 2----------------------------

class Car
{
    private:
    string Company;
    string Model;
    public:
        Car(string NewCompany, string NewModel) {
            Company = NewCompany;
            Model = NewModel;
            Print();
        }
        void Print() {
            cout << Company << " : " << Model << endl;
        }

        virtual ~Car() {
        }
};
class PassengerCar : public Car
{
    private:
    public:
        PassengerCar(string NewCompany, string NewModel) : Car(NewCompany, NewModel) {
        }

        ~PassengerCar() {
        }
};
class Bus : public Car
{
    private:
    public:
        Bus(string NewCompany, string NewModel) : Car(NewCompany, NewModel) {
        }

        ~Bus() {
        }
};
class Minivan : public PassengerCar, public Bus
{
    private:
    public:
        Minivan(string NewCompay, string NewModel) : PassengerCar(NewCompay,NewModel), Bus(NewCompay,NewModel) {
        }

        ~Minivan() {
        }
};

//----------------------------Task 3----------------------------

class Fraction
{
    private:
    int numinator;
    int denominator;
    bool IsTrue;
    public:
        Fraction(int  a, int b) {
            if(b == 0) {
                return; // не смог придумать или найти как запустить деструктор в случае если знаминатель равен нулю. 
            }
            else {
                numinator = a;
                denominator = b;
            }
        }
        friend Fraction operator+(Fraction &First, Fraction &Second);
        friend Fraction operator-(Fraction &First, Fraction &Second);
        friend Fraction operator*(Fraction &First, Fraction &Second);
        friend Fraction operator/(Fraction &First, Fraction &Second);
        friend Fraction operator==(Fraction &First, Fraction &Second);
        friend Fraction operator!=(Fraction &First, Fraction &Second);
        friend bool operator<(Fraction &First, Fraction &Second);
        friend bool operator>(Fraction &First, Fraction &Second);
        friend bool operator<=(Fraction &First, Fraction &Second);
        friend bool operator>=(Fraction &First, Fraction &Second);
        friend Fraction operator-(Fraction &First);
        ~Fraction() {
        }
};

Fraction operator+(Fraction &First, Fraction &Second){
    int multiplier = 1;
    while(First.denominator * multiplier != Second.denominator * multiplier) { multiplier++;}
    return Fraction((First.numinator+Second.numinator)*multiplier, First.denominator*multiplier);
}
Fraction operator-(Fraction &First, Fraction &Second) {
    int multiplier = 1;
    while(First.denominator * multiplier != Second.denominator * multiplier) { multiplier++;}
    return Fraction((First.numinator-Second.numinator)*multiplier, First.denominator*multiplier);
}
Fraction operator*(Fraction &First, Fraction &Second) {
    return Fraction(First.numinator*Second.numinator, First.denominator*Second.denominator);
}
Fraction operator/(Fraction &First, Fraction &Second) {
    return Fraction(First.numinator*Second.denominator, First.denominator*Second.numinator);
}
bool operator<(Fraction &First, Fraction &Second) {
    double Left = First.numinator/First.denominator;
    double Right = Second.numinator/Second.denominator;
    if(Left < Right) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>(Fraction &First, Fraction &Second) {
    double Left = First.numinator/First.denominator;
    double Right = Second.numinator/Second.denominator;
    if(Left > Right) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(Fraction &First, Fraction &Second) {
    double Left = First.numinator/First.denominator;
    double Right = Second.numinator/Second.denominator;
    if(Left <= Right) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>=(Fraction &First, Fraction &Second) {
    double Left = First.numinator/First.denominator;
    double Right = Second.numinator/Second.denominator;
    if(Left < Right) {
        return true;
    }
    else {
        return false;
    }
}
Fraction operator-(Fraction &First) {
    return Fraction(First.numinator*(-1), First.denominator);
}

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
        int GetValue() {
            return Value;
        }
        ~Card() {
        }
};

int main() {

    return 0;
}
