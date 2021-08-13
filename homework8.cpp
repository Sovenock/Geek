#include <iostream>

using namespace std;

//----------------------------Task 1----------------------------

template <typename T>
T div(T numenator, T denominator) {
    if(static_cast<int>(denominator) == 0) { 
        throw exception("Divison by zero attempt");
    }
    cout << numenator/denominator;
}

//----------------------------Task 2----------------------------

class Ex
{
private:
    float x;
public:
    Ex(float num) : x(num) {
    }
    float GetValue() {
        return x;
    }
    ~Ex() {
    }
};

class Bar
{
private:
    float y;
public:
    Bar() {
        y = 0;
    }
    void Set(float num) {
        if(y + num > 100) {
            throw Ex(num*y);
        }
        else { y = num;}
    }
    ~Bar() {
    }
};

//----------------------------Task 3----------------------------

class Robot
{
private:
    int x;
    int y;
public:
    Robot() {
        x = 1;
        y = 1;
    }
    int GetX() { return x;}
    int GetY() { return y;}
    void Move(int NewX, int NewY) {
        if((x + 1 == NewX || x - 1 == NewX) && (y + 1 == NewY || y - 1 == NewY)) {
            if((NewX <= 10 && NewX >= 1) && (NewY <= 10 && NewY >= 1)) {
                x = NewX;
                y = NewY;
            }
            else{ throw OffTheField(GetX(),GetY());}
        }
        else { throw IllegalCommand(GetX(),GetY());}
    }

    ~Robot() {
    }
};

class OffTheField
{
private:
    string Error;
    int x;
    int y;
public:
    OffTheField(int NewX, int NewY) {
        Error = "Atempt to leave the field";
        x = NewX;
        y = NewY;
    }
    string What() {
        cout << "X: " << x << " Y: " << y;
        return Error;
    }

    ~OffTheField() {
    }    
};

class IllegalCommand
{
private:
    int x;
    int y;
    string Error;
public:
    IllegalCommand(int NewX, int NewY) {
        Error = "Wrong coordinates";
        x = NewX;
        y = NewY;
    }
    string What() {
        cout << "X: " << x << " Y: " << y;
        return Error;
    }
    ~IllegalCommand() {
    }
};



int main() {
//----------------------------Task 1----------------------------
    int first = 10;
    int second = 0;
    try{
        div(first, second);
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 0;
    }

//----------------------------Task 2----------------------------

    int num;
    Bar Obj;
    try
    {
        while(true) {
            cin >> num;
            Obj.Set(num);
        }
        
    }
    catch(Ex& e)
    {
        cerr << e.GetValue() << '\n';
    }


//----------------------------Task 3----------------------------

    Robot robot;
    int x = 0;
    int y = 0;
    char Answer;
    try {
        do{
            cin >> x;
            cin >> y;
            robot.Move(x,y);
            cout << "Again? Y/N";
            cin >> Answer;
        }while(Answer == 'Y' || Answer == 'y');
    }
    catch(OffTheField& e) {
        cerr << e.What() << '\n';
    }
    catch(IllegalCommand& e) {
        cerr << e.What() << '\n';
    }
        
    return 0;
}