#include <iostream>
#include <cassert>

//----------------------------Task 1----------------------------
class Person {
private:
    std::string name;
    int age;
    std::string sex;
    int weight;
public:
    Person() {
        std::cin >> name;
        std::cin >> age;
        std::cin >> sex;
        std::cin >> weight;
    }
    void ChangeName() {
        std::cin >> name;
    }
    void ChangeAge() {
        std::cin >> age;
    }
    void ChangeWeight() {
        std::cin >> weight;
    }
    void Preview() {
        std::cout << name << std::endl;
    }
    void PrintPerson() {
        std::cout << name << "  " << age << "  " << sex << "  " << weight << std::endl;
    }
    ~Person() {
    }

};

uint32_t StudentCounter = 0;

class Student : public Person
{
private:
    std::string years;
public:
    Student():Person() {
        std::cin >> years;
        StudentCounter++;
    }
    void ChangeYears() {
        std::cin >> years;
    }
    void PrintStudent() {
        PrintPerson();
        std::cout << years << std::endl;
    }
    ~Student() {
        StudentCounter--;
    }
};

//----------------------------Task 2----------------------------

class Fruit {
private:
    std::string name;
    std::string color;
public:
    Fruit() {
    }
    void GetName() {
        std::cout << name << " ";
    }
    void GetColor() {
        std::cout << color << " ";
    }
    void SetName(std::string NewName) {
        name = NewName;
    }
    void SetColour(std::string NewColor) {
        color = NewColor;
    }
    ~Fruit() {
    }
};

class Apple : public Fruit{
public:
    Apple(){

    }
    Apple(std::string Name) {
        SetName("apple");
        SetColour(Name);
    }

    ~Apple() {
    }
};

class Banana : public Fruit {
    public:
    Banana() {
        SetName("banana");
        SetColour("yellow");
    }
    ~Banana() {

    }
};

class GrannySmith : public Apple {
    public:
    GrannySmith() {
        SetName("GrannySmith");
        SetColour("green");
    }
};


int main() {
//----------------------------Task 1----------------------------
    Student *mass[5];
    for(int i = 0; i < 5; i++) {
        mass[i]->Preview();
    }
    std::cout << "Student's № : ";
    uint8_t RequestedNumber;
    std::cin >> RequestedNumber;
    if(RequestedNumber - 1 > 4) {
        std::cout << "Wrong one\n";
    }
    else {
        mass[RequestedNumber - 1 ]->PrintStudent();
    }
}
/*В блэкджэке будет три класса : карта, диллер и игрок. Диллер будет дочерним классом игрока. Колоду реализовать через очередь. Имитировать будем игру одной колодой, то есть будем
сбрасывать и генерировать очередь заново после каждой игры. Слежение за наполнением очереди сделать со сверкой с, к примеру, булевым двумерным массивом. Или лучше сразу карты сгенерировать в
массив, а в с ам класс карты добвть булл в очереди или нет.*/