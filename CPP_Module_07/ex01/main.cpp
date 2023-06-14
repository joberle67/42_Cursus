#include "iter.hpp"

template <typename T>
void ft_putstr(const T& str)
{
    std::cout << str << std::endl;
}
template <typename T>
void ft_multi(const T& str)
{
    std::cout << str * 10 << std::endl;
}

int main(void)
{
    int str[] = {1, 2, 3, 4, 5}; 
    std::cout << "print the tab : " << std::endl;                                                                                                                                                                                                                                                                                                                  
    iter(str, 5, &ft_putstr);
    std::cout << "print the tab with * 10 on every nb" << std::endl;
    iter(str, 5, &ft_multi);
}