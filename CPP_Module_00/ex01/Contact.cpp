#include "PhoneBook.hpp"

void    Contact::add_first(std::string f_name)
{
    this->f_name = f_name;
}

void    Contact::add_last(std::string l_name)
{
    this->l_name = l_name;
}

void    Contact::add_nick(std::string nick)
{
    this->nickname = nick;
}

void    Contact::add_number(std::string number)
{
    this->phone_number = number;
}

void    Contact::add_secret(std::string secret)
{
    this->darkest_secret = secret;
}

std::string Contact::get_firstname(void)
{
    return (this->f_name);
}

std::string Contact::get_lastname(void)
{
    return (this->l_name);
}

std::string Contact::get_nick(void)
{
    return (this->nickname);
}

std::string Contact::get_number(void)
{
    return (this->phone_number);
}

std::string Contact::get_secret(void)
{
    return (this->darkest_secret);
}