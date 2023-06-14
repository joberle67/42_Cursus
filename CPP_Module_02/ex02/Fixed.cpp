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

Fixed &Fixed::min(Fixed &nb1, Fixed &nb2)
{
    if (nb1.nb < nb2.nb)
        return (nb1);
    return (nb2);
}

const Fixed &Fixed::min(Fixed const &nb1, Fixed const &nb2)
{
    if (nb1.nb < nb2.nb)
        return (nb1);
    return (nb2);
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2)
{
    if (nb1.nb > nb2.nb)
        return (nb1);
    return (nb2);
}

const Fixed &Fixed::max(Fixed const &nb1, Fixed const &nb2)
{
    if (nb1.nb > nb2.nb)
        return (nb1);
    return (nb2);
}

bool Fixed::operator>(Fixed tmp) const 
{
    return (this->toFloat() > tmp.toFloat());
}

bool Fixed::operator<(Fixed tmp) const 
{
    return (this->toFloat() < tmp.toFloat());
}

bool Fixed::operator>=(Fixed tmp) const
{
    return (this->toFloat() >= tmp.toFloat());
}

bool Fixed::operator<=(Fixed tmp) const
{
    return (this->toFloat() <= tmp.toFloat());
}

bool Fixed::operator==(Fixed tmp) const
{
    return (this->toFloat() == tmp.toFloat());
}

bool Fixed::operator!=(Fixed tmp) const
{
    return (this->toFloat() != tmp.toFloat());
}

float Fixed::operator+(Fixed tmp)const
{
    return (this->toFloat() + tmp.toFloat());
}

float Fixed::operator-(Fixed tmp)const
{
    return (this->toFloat() - tmp.toFloat());
}

float Fixed::operator*(Fixed tmp)const
{
    return (this->toFloat() * tmp.toFloat());
}

float Fixed::operator/(Fixed tmp)const
{
    return (this->toFloat() / tmp.toFloat());
}

Fixed Fixed::operator++()
{
    this->nb++;
    return (*this);
}

Fixed Fixed::operator--()
{
    this->nb--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    
    ++this->nb;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    
    --this->nb;
    return (tmp);
}


