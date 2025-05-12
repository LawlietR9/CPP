#include "Character.hpp"

Character::Character(const std::string &name) : name(name) {}

Character::~Character() {}

std::string const & Character::getName() const {
    return name;
}