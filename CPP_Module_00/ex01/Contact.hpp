#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <string.h>

class Contact
{
    public :
            void        add_first(std::string f_name);
            void        add_last(std::string l_name);
            void        add_nick(std::string nickname);
            void        add_number(std::string phone_number);
            void        add_secret(std::string darkest_secret);
            std::string get_firstname(void);
            std::string get_lastname(void);
            std::string get_nick(void);
            std::string get_number(void);
            std::string get_secret(void);

    private :
            std::string f_name;
            std::string l_name;
            std::string nickname;
            std::string phone_number;
            std::string darkest_secret;
};


# endif