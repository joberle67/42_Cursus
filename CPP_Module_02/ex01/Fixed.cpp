#include "Fixed.hpp"

const int Fixed::byte = 8;

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->nb = 0;
}

Fixed::Fixed(int const &nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->nb = nb << this->byte;
}

Fixed::Fixed(float const &nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->nb = roundf(nb * (1 << this->byte));
}

Fixed::Fixed(Fixed const &tmp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = tmp;
}

Fixed &Fixed::operator=(Fixed const &tmp)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->nb = tmp.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
    return (this->nb);
}

void Fixed::setRawBits(int const raw)
{
    this->nb = raw;
}

float Fixed::toFloat(void)const
{
    return ((float)this->nb / (float)(1 << this->byte));
}
int Fixed::toInt(void)const
{
    return (this->nb >> this->byte);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}