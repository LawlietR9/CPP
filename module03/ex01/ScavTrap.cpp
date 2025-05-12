#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << other.name << " is copied" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        std::cout << "ScavTrap " << this->name << " is assigned from " << other.name << std::endl;
        ClapTrap::operator=(other);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no hit points left to attack!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= this->hitPoints) {
        this->hitPoints = 0;
    } else {
        this->hitPoints -= amount;
    }
    std::cout << "ScavTrap " << this->name << " takes " << amount 
              << " points of damage! Hit points left: " << this->hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no energy points left to repair!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "ScavTrap " << this->name << " has no hit points left to repair!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ScavTrap " << this->name << " repairs itself for " << amount 
              << " points! Hit points now: " << this->hitPoints << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}