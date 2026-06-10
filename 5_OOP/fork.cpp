#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    int age;

public:
    Animal(std::string n, int a);
    virtual void makeSound();

    // void eat();
    // Пояснення: щоб поліморфізм працював коректно через масив вказівників, методи, що перевизначаються, мають бути віртуальними.
    virtual void eat();

    virtual void sleep();
};

// class Mammal : protected Animal {
// protected успадкування приховує базовий клас. Потрібно public, щоб об'єкти працювали як Animal/Mammal зовні
class Mammal : public Animal
{
protected:
    // bool getSleeping;
    // Тута помилка в назві змінної. У методах нижче використовується isSleeping:
    bool isSleeping;

public:
    Mammal(std::string n, int a);
    void makeSound();
    void eat();
    void sleep();
};

// class Tail : public Dog {
// public:
//   Tail(std::string n, int a);
// };
// Якась фігня. Хвіст не є собакою ("is-a"), собака МАЄ хвіст ("has-a"), тому створюємо незалежний клас хвоста ПЕРЕД собакою:
class Tail
{
public:
    Tail() {}
    void wag()
    {
        std::cout << " tail is wagging." << std::endl;
    }
};

class Dog : public Mammal
{
private:
    // bool isTailWagging;
    // Замість прапорця логічніше використовувати реальний об'єкт хвоста (композиція).
    Tail tail;

public:
    Dog(std::string n, int a);
    void makeSound();
    void eat();
    void sleep();
    void fetch();
    void wagTail();
};

class Cat : public Mammal
{
private:
    int numberOfLives;

public:
    Cat(std::string n, int a);
    void makeSound();
    void eat();
    void sleep();
};

Animal::Animal(std::string n, int a)
{
    name = n;
    age = a;
}

void Animal::makeSound()
{
    std::cout << "This is a generic animal sound." << std::endl;
}

void Animal::eat() { std::cout << "The animal is eating." << std::endl; }

void Animal::sleep() { std::cout << "The animal is sleeping." << std::endl; }

// Mammal::Mammal(std::string n, int a) : Animal(n) { isSleeping = false; }
// Конструктор Animal очікує два аргументи (n, a), тому правильно буде:
Mammal::Mammal(std::string n, int a) : Animal(n, a) { isSleeping = false; }

void Mammal::makeSound()
{
    std::cout << "This is a generic mammal sound." << std::endl;
}

void Mammal::eat() { std::cout << "The mammal is eating." << std::endl; }

void Mammal::sleep()
{
    std::cout << "The mammal is sleeping." << std::endl;
    isSleeping = true;
}

Dog::Dog(std::string n, int a) : Mammal(n, a) {}

void Dog::makeSound() { std::cout << "Woof!" << std::endl; }

void Dog::eat() { std::cout << "The dog is eating." << std::endl; }

void Dog::sleep()
{
    std::cout << "The dog is sleeping." << std::endl;
    isSleeping = true;
}

void Dog::fetch() { std::cout << "The dog is fetching." << std::endl; }

void Dog::wagTail()
{
    if (isSleeping)
    {
        std::cout << "The dog can't wag its tail because it's sleeping." << std::endl;
    }
    else
    {
        std::cout << "The dog's";
        tail.wag(); // Використовуємо об'єкт хвоста
    }
}

Cat::Cat(std::string n, int a) : Mammal(n, a) { numberOfLives = 9; }

void Cat::makeSound() { std::cout << "Meow!" << std::endl; }

void Cat::eat() { std::cout << "The cat is eating." << std::endl; }

void Cat::sleep()
{
    std::cout << "The cat is sleeping." << std::endl;
    isSleeping = true;
}

// Tail::Tail(std::string n, int a) : Dog() {}
// Цу вже не актуально, оскільки тепер це простий клас.

// int Cat::eat = eat();
// А тут лише синтаксична помилка.

int main()
{
    Dog d("Fido", 3);
    Cat c("Fluffy", 5);
    Dog d1("Barky", 3);

    Mammal *arr[] = {&d, &c, &d1};

    // should woof, meow, woof
    for (int i = 0; i < 3; i++)
    {
        arr[i]->makeSound();
    }

    // should eat in dog, cat, dog order
    for (int i = 0; i < 3; i++)
    {
        arr[i]->eat();
    }

    // should woof, meow, woof
    for (int i = 0; i < 3; i++)
    {
        arr[i]->makeSound();
    }

    // should sleep in dog, cat, dog order
    for (int i = 0; i < 3; i++)
    {
        arr[i]->sleep();
    }

    // shoudn't do anything as they're sleeping
    for (int i = 0; i < 3; i++)
    {
        arr[i]->makeSound();
    }

    // shouldn't wag tails, they are sleeping
    for (int i = 0; i < 3; i++)
    {

        // arr[i]->wagTail();
        // Mammal* не має методу wagTail().
        if (Dog *dogPtr = dynamic_cast<Dog *>(arr[i]))
        {
            dogPtr->wagTail();
        }
    }

    // Tail t("Taily", 2);
    // t.makeSound();
    // Так як хвіст більше не успадковується від собаки, у нього немає імені, віку та він не може гавкати
}