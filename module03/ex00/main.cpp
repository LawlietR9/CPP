#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");
    
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("Target");
    clap.takeDamage(8);
    clap.beRepaired(5);
    clap.attack("Target");
    
    return 0;
}