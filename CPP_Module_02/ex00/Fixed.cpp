#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->nb = 0;
}

Fixed::Fixed(const Fixed &cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

void Fixed::operator=(Fixed const &cp)
{
    std::cout << "copy assignement operator called" << std::endl;
    this->nb = cp.getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->nb);
}

void    Fixed::setRawBits(int const raw)
{
    this->nb = raw;
}