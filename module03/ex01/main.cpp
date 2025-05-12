#include "ScavTrap.hpp"

int main()
{
    {
        std::cout << "=== Testing ClapTrap ===" << std::endl;
        ClapTrap clap("CL4P-TP");
        std::cout << "\nClapTrap actions:" << std::endl;
        clap.attack("Target");
        clap.takeDamage(5);
        clap.beRepaired(3);
        std::cout << std::endl;
    }

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    std::cout << "\nScavTrap actions:" << std::endl;
    scav.attack("Target");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    ScavTrap scav2(scav);
    scav2.attack("Target");
    std::cout << std::endl;

    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    {
        ScavTrap scav3("Original");
        std::cout << "\nBefore assignment:" << std::endl;
        scav3.attack("Target");
        
        std::cout << "\nAfter assignment:" << std::endl;
        scav3 = scav;
        scav3.attack("Target");
    }
    std::cout << std::endl;

    std::cout << "=== Destruction Phase ===" << std::endl;
    return 0;
}