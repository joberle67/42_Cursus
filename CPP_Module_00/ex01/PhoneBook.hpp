#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public :

    void    init_nb(void);
    void    init_index(void);
    void    plus_nb(void);
    int     get_nb(void);
    void    add_contact(void);
    void    ft_menu(void);
    void    ft_search(void);
    void    do_dix(std::string str);
    void    ft_index(int nb);
    int     ft_count(void);
    ~PhoneBook();


    private :
            Contact contact[8];
            int nb;
            int index;

};

#endif