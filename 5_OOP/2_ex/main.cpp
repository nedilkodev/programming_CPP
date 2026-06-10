#include <iostream>
#include "Animal_proposal.h"

int main()
{
    Dog d("Fido", 3);
    Cat c("Fluffy", 5);
    Dog d1("Barky", 3);

    Mammal *arr[] = {&d, &c, &d1};

    std::cout << "--- Издаем звуки ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->makeSound();

    std::cout << "\n--- Едим ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->eat();

    std::cout << "\n--- Засыпаем ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->sleep();

    std::cout << "\n--- Пытаемся издать звук во сне ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->makeSound(); // Ничего не выведет, так как спят

    std::cout << "\n--- Пытаемся поесть во сне ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->eat();

    std::cout << "\n--- Пытаемся вильнуть хвостом во сне ---" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (Dog *dogPtr = dynamic_cast<Dog *>(arr[i]))
        {
            dogPtr->wagTail();
        }
    }

    std::cout << "\n--- Просыпаемся! ---" << std::endl;
    for (int i = 0; i < 3; i++)
        arr[i]->wakeUp();

    std::cout << "\n--- Виляем хвостом после пробуждения ---" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        if (Dog *dogPtr = dynamic_cast<Dog *>(arr[i]))
        {
            dogPtr->wagTail();
        }
    }

    return 0;
}