#include "PhoneBook.hpp"

void    PhoneBook::init_nb(void)
{
    this->nb = 0;
}

void    PhoneBook::init_index(void)
{
    this->index = 0;
}


void    PhoneBook::plus_nb(void)
{
    this->nb++;
    if (this->index <= 8)
    {
        if(this->index == 8)
            this->index = 8;
        else 
            this->index = nb;
    }
    if (nb == 8)
        init_nb();
}

int PhoneBook::get_nb(void)
{
    return (this->nb);
}

int ft_count(std::string result)
{
    int i;

    i = -1;
    while (result[++i])
    {
        if (result[i] > 32 && result[i] < 127)
            return (1);
    }
    return (0);
}

std::string ft_collect(std::string str)
{
    std::string result;

    while (1)
    {
        std::cout << str;
        std::cin >> result;
        std :: cin.clear();
        std :: cin.ignore();
        if (ft_count(result) == 1)
            break;
    }
    return (result);
}

void    PhoneBook::ft_menu(void)
{
    std::cout << "#============================================#\n";
    std::cout << "# ADD (add a contact on the PhoneBook)       #\n";
    std::cout << "# SEARCH (search a contact on the PhoneBook) #\n";
    std::cout << "# EXIT (close the PhoneBook)                 #\n";
    std::cout << "#============================================#\n\n\n";
    std::cout << "$> ";

}


 PhoneBook::~PhoneBook(void)
{
    std::cout << "GOODBYE\n";
}

void PhoneBook::add_contact(void)
{
    std::string result;

    result = ft_collect("First Name : ");
    this->contact[get_nb()].add_first(result);
    result = ft_collect("Last Name : ");
    this->contact[get_nb()].add_last(result);
    result = ft_collect("Nickname : ");
    this->contact[get_nb()].add_nick(result);
    result = ft_collect("Phone Number : ");
    this->contact[get_nb()].add_number(result);
    result = ft_collect("Darkest Secret : ");
    this->contact[get_nb()].add_secret(result);
    std::cout << "Contact Added With Success \n";
    this->plus_nb();
}

void    PhoneBook::ft_search(void)
{
    int i;
    int result;

    i = 0;
    std::cout << "#===========================================#\n";
    std::cout << "|  Index   |First Name|Last Name | Nickname |\n";
    while (i < this->index)
    {
        std::cout <<"|    " << i + 1 << "     |"; 
        this->do_dix(this->contact[i].get_firstname());
        std :: cout << "|";
        this->do_dix(this->contact[i].get_lastname());
        std::cout << "|";
        this->do_dix(this->contact[i].get_nick());
        std::cout << "|" << std::endl;
        i++;
    }
    std::cout << "#===========================================#\n";
        std :: cout << "Please select a index : ";
        std :: cin >> result;
        std :: cin.clear();
        std :: cin.ignore();
        if (result <= i && result > 0)
            ft_index(result - 1);
        else
        {
            std :: cout << "this index does not exist \n";
        }
}

int PhoneBook::ft_count(void)
{
    int i = 0;
    while(this->contact[i].get_firstname() != "")
    {
        if (this->contact[i].get_firstname() == "")
            break ;
        i++;
    }
    return (i);
}


void    PhoneBook::ft_index(int nb)
{
    int result;
    std::cout << "    First Name :"<< this->contact[nb].get_firstname() << std::endl;
    std::cout << "    Last Name  :"<< this->contact[nb].get_lastname() << std::endl;
    std::cout << "  Phone Number :"<< this->contact[nb].get_number() << std::endl;
    std::cout << "      Nickname :" << this->contact[nb].get_nick() << std::endl;
    std::cout << "Darkest Secret :" << this->contact[nb].get_secret() << std::endl;
    while (1)
    {
        std :: cout << "\ntype 1 for quit :";
        std::cin >> result;
        std :: cin.clear();
        std :: cin.ignore();
        if (result == 1)
            break;
    }
}

void PhoneBook::do_dix(std::string str)
{
    int i = 0;
    while(str[i] && i < 9)
    {
        std::cout << str[i];
        i++;
    }
    if (i != 9)
    {
        while (i < 10)
        {
            std :: cout << " ";
            i++;
        }
        return ;
    }
    if (i == 9)
        std :: cout << ".";
}