#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &src, int nb)
{
    typename T::iterator res = find(src.begin(), src.end(), nb);
    return (res);
}

#endif