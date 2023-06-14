#include "PhoneBook.hpp"


int main(void)
{
    PhoneBook phone;
    std::string result;

    phone.init_nb();
    phone.init_index();
    while(1)
    {
        phone.ft_menu();
        std::cin >> result;
        std :: cin.clear();
        std :: cin.ignore();
        if (result == "ADD")
            phone.add_contact();
        else if (result == "SEARCH" && phone.get_nb() > 0)
            phone.ft_search();
        else if (result == "EXIT")
            break;
    }
}