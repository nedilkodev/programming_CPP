#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
    std::string name;
    int age;
    bool isSleeping;
    std::string typeName; // Помогает избежать дублирования в eat() и sleep() [DRY]

public:
    Animal(std::string n, int a, std::string type = "animal");
    virtual ~Animal() = default; // Виртуальный деструктор обязателен при полиморфизме

    virtual void makeSound() const;
    virtual void eat() const;
    virtual void sleep();
    virtual void wakeUp(); // [KISS] Простое решение проблемы "вечного сна"
};

class Mammal : public Animal
{
public:
    Mammal(std::string n, int a, std::string type = "mammal");
    void makeSound() const override;
};

// [SRP] Класс хвоста отвечает только за виляние хвостом
class Tail
{
public:
    Tail() = default;
    void wag() const;
};

class Dog : public Mammal
{
private:
    Tail tail; // Композиция: Собака "имеет" хвост

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