#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    {
        ClapTrap clap("CL4P-TP");
        std::cout << "\nClapTrap actions:" << std::endl;
        clap.attack("Target");
        clap.takeDamage(5);
        clap.beRepaired(3);
        std::cout << std::endl;
    }

    std::cout << "=== Testing FragTrap ===" << std::endl;
    {
        FragTrap frag("FR4G-TP");
        std::cout << "\nFragTrap actions:" << std::endl;
        frag.attack("Target");
        frag.takeDamage(30);
        frag.beRepaired(20);
        frag.highFivesGuys();
        std::cout << std::endl;
    }

    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    {
        FragTrap frag1("FR4G-1");
        FragTrap frag2(frag1);
        frag2.attack("Target");
        frag2.highFivesGuys();
        std::cout << std::endl;
    }

    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    {
        FragTrap frag1("FR4G-1");
        FragTrap frag2("FR4G-2");
        
        std::cout << "\nBefore assignment:" << std::endl;
        frag2.attack("Target");
        
        std::cout << "\nAfter assignment:" << std::endl;
        frag2 = frag1;
        frag2.attack("Target");
        frag2.highFivesGuys();
    }
    std::cout << std::endl;

    std::cout << "=== Testing Energy Consumption ===" << std::endl;
    {
        FragTrap frag("FR4G-TP");
        for (int i = 0; i < 101; ++i) {
            frag.attack("Target");
        }
        frag.beRepaired(10);
        frag.highFivesGuys();
    }

    return 0;
}