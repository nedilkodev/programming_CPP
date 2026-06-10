#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    int age;
    bool isSleeping;
    std::string typeName; 

public:
    Animal(std::string n, int a, std::string type = "animal");
    virtual ~Animal() = default; 

    virtual void makeSound() const;
    virtual void eat() const;
    virtual void sleep();
    virtual void wakeUp(); 
};

class Mammal : public Animal
{
public:
    Mammal(std::string n, int a, std::string type = "mammal");
    void makeSound() const override;
};


class Tail
{
public:
    Tail() = default;
    void wag() const;
};

class Dog : public Mammal
{
private:
    Tail tail; 

public:
    Dog(std::string n, int a);
    void makeSound() const override;
    void fetch() const;
    void wagTail() const;
};

class Cat : public Mammal
{
private:
    int numberOfLives;

public:
    Cat(std::string n, int a);
    void makeSound() const override;
};