#include <iostream>
#include <cmath>
#include <cstdint>

//----------------------------Task 1----------------------------
class Power {
private:
    std::uint32_t variable1;
    std::uint32_t variable2;
public:
    Power::Power(/* args */) {
        variable1 = 0;
        variable2 = 0;
    }
    void Power::Set() {
        std::cout << "Nums please\n";
        std::cin >> variable1;
        std::cout << std::endl;
        std::cin >> variable2;
    }
    void Power::Calculate() {
        std::cout << std::pow(variable1,variable2)<< std::endl;
    }
    Power::~Power() {

    }
};

//----------------------------Task 2----------------------------

class RGBA {
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0 ;
    std::uint8_t m_alpha = 255;    
public:
    RGBA::RGBA(/* args */) {
        std::cout << "Red value : ";
        std::cin >> m_red;
        std::cout << std::endl;
        std::cout << "Green value : ";
        std::cin >> m_green;
        std::cout << std::endl;
        std::cout << "Blue value : ";
        std::cin >> m_blue;
        std::cout << std::endl;
        std::cout << "Alpha value : ";
        std::cin >> m_alpha;
    }
    void RGBA::Print() {
        std::cout << "Red value : " << m_red << std::endl;
        std::cout << "Green value : " << m_green << std::endl;
        std::cout << "Blue value : " << m_blue << std::endl;
        std::cout << "Alpha value : " << m_alpha << std::endl;
    }

RGBA::~RGBA() {
    }
};

//----------------------------Task 3----------------------------

class Stack {
private:
    int mass[10];
    int counter = 0;
public:
    Stack(/* args */) {
        for(int i = 0; i < 10; i++) {
            mass[i] = 0;
        }
    }
    
    bool Push(int New_Value) {
        for(int i = counter; i >= 0; i--) {
                mass[i+1] = mass[i];
            }
            counter++;
            mass[0] = New_Value;
        if(counter == 9) return false;
        else return true;
    }
    
    int Pop() {
        if(counter == 0) {
            std::cout << "Array is empty\n";
        }
        else {
                int ToReturn = mass[0];
            for(int i = 0; i <= counter; i++) {
                mass[i] = mass[i+1];
            }
            counter--;
            return ToReturn;
        }
    }
    
    void Print() {
        for(int i = 0; i <= counter; i++) {
            std::cout << " " << mass[i];
        }
        std::cout << std::endl;
    }

    void Reset() {
        for(int i = 0; i < 10; i++) {
            mass[i] = 0;
        }
        counter = 0;
    }
    
    ~Stack() {
        delete mass;
    }
};


int main() {
    return 0;
}