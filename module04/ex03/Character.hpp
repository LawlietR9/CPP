#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
    std::string name;
public:
    Character(const std::string &name);
    virtual ~Character();
    virtual std::string const & getName() const;
};

#endif