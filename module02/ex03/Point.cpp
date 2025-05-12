#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {
}

// Constructor with parameters
Point::Point(const float x, const float y) : x(x), y(y) {
}

// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y) {
}

// Copy assignment operator
Point &Point::operator=(const Point &other) {
    // Since x and y are const, they cannot be reassigned.
    // This operator is defined to satisfy the Orthodox Canonical Form but does nothing.
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {
}

// Getter for x
Fixed Point::getX() const {
    return this->x;
}

// Getter for y
Fixed Point::getY() const {
    return this->y;
}
