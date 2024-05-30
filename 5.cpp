// Арифметичний вираз
// 8*lg(b −1)−c / (a*2 + b/c)

// Опис класу-вираз
// Змінні - операнди виразу; конструктори; методи встановлення значень об’єкта, обчислення виразу, отримання значення об’єкта

// Завдання
// Написати програму на С++, у яких створити клас що представляє собою вираз. Членами даними класу будуть операнди виразу, а операціями – методи встановлення значень виразу та його обчислення. При обчисленні арифметичного виразу та введенні інформації передбачити обробку виняткових ситуацій.
// Доробити вихідний код лабораторної роботи з перевантаження операцій та операторів, включивши обробку виняткових ситуацій там, де це потрібно.
// Створити масив об’єктів; обчислити вираз для кожного об’єкта, вивести результат

#include <iostream>

class Expression{
    private:
        int a, b, c;
    public:
        Expression(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
        void setA(int a){
            this->a = a;
        }
        void setB(int b){
            this->b = b;
        }
        void setC(int c){
            this->c = c;
        }
        double calculate(){
            if (c == 0 || c == INT_MIN)
                throw "Division by zero";
                
            if((a * 2 + b / c) == 0){
                throw "Division by zero";
            }
            if(b - 1 < 0){
                throw "Logarithm of a negative number";
            }
            return 8 * log10(b - 1) - c / (a * 2 + b / c);
        }
};

int main(){
    Expression expressions[] = {
        Expression(1, 2, 3),
        Expression(4, 5, 6),
        Expression(7, 8, 0),
        Expression(7, 8, 9)
    };
    for(int i = 0; i < sizeof(expressions) / sizeof(expressions[0]); i++){
        try {
            std::cout << "Result " << i + 1 << ": " << expressions[i].calculate() << std::endl;
        } catch(const char *msg){
            std::cerr << "Error: " << msg << std::endl;
        }
    }
    return 0;
}