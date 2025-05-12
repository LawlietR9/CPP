#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Basic Animal Tests ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "\nType checks:" << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        std::cout << "\nSound checks:" << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        std::cout << "\nCleaning up:" << std::endl;
        delete meta;
        delete j;
        delete i;
    }

    std::cout << "\n=== Wrong Animal Tests ===" << std::endl;
    {
        const WrongAnimal* wrong_meta = new WrongAnimal();
        const WrongAnimal* wrong_cat = new WrongCat();

        std::cout << "\nType checks:" << std::endl;
        std::cout << wrong_cat->getType() << " " << std::endl;

        std::cout << "\nSound checks:" << std::endl;
        wrong_cat->makeSound();
        wrong_meta->makeSound();

        std::cout << "\nCleaning up:" << std::endl;
        delete wrong_meta;
        delete wrong_cat;
    }

    std::cout << "\n=== Copy Constructor Tests ===" << std::endl;
    {
        Dog original_dog;
        Dog copied_dog(original_dog);
        Cat original_cat;
        Cat copied_cat(original_cat);

        std::cout << "\nSound checks for copies:" << std::endl;
        copied_dog.makeSound();
        copied_cat.makeSound();
    }

    std::cout << "\n=== Assignment Operator Tests ===" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        dog2 = dog1;

        Cat cat1;
        Cat cat2;
        cat2 = cat1;

        std::cout << "\nSound checks after assignment:" << std::endl;
        dog2.makeSound();
        cat2.makeSound();
    }

    return 0;
}