#include "Animal_proposal.h"

Animal::Animal(std::string n, int a, std::string type)
    : name(n), age(a), isSleeping(false), typeName(type) {}

void Animal::makeSound() const
{
    if (isSleeping)
        return;
    std::cout << "This is a generic animal sound." << std::endl;
}

void Animal::eat() const
{
    if (isSleeping)
    {
        std::cout << "The " << typeName << " can't eat because it's sleeping." << std::endl;
        return;
    }
    std::cout << "The " << typeName << " is eating." << std::endl;
}

void Animal::sleep()
{
    if (!isSleeping)
    {
        std::cout << "The " << typeName << " is sleeping." << std::endl;
        isSleeping = true;
    }
}

void Animal::wakeUp()
{
    if (isSleeping)
    {
        std::cout << name << " (the " << typeName << ") wakes up!" << std::endl;
        isSleeping = false;
    }
}

Mammal::Mammal(std::string n, int a, std::string type) : Animal(n, a, type) {}

void Mammal::makeSound() const
{
    if (isSleeping)
        return;
    std::cout << "This is a generic mammal sound." << std::endl;
}

void Tail::wag() const
{
    std::cout << " tail is wagging." << std::endl;
}

Dog::Dog(std::string n, int a) : Mammal(n, a, "dog") {}

void Dog::makeSound() const
{
    if (isSleeping)
        return;
    std::cout << "Woof!" << std::endl;
}

void Dog::fetch() const
{
    if (isSleeping)
        return;
    std::cout << "The dog is fetching." << std::endl;
}

void Dog::wagTail() const
{
    if (isSleeping)
    {
        std::cout << "The dog can't wag its tail because it's sleeping." << std::endl;
    }
    else
    {
        std::cout << "The dog's";
        tail.wag();
    }
}

Cat::Cat(std::string n, int a) : Mammal(n, a, "cat")
{
    numberOfLives = 9;
}

void Cat::makeSound() const
{
    if (isSleeping)
        return;
    std::cout << "Meow!" << std::endl;
}