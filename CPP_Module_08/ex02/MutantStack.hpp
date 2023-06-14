#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
            MutantStack<T>(void){return;};
            MutantStack<T>(const MutantStack &src){*this = src;};
            MutantStack<T> &operator=(const MutantStack &src){(void)src; return *this;};
            ~MutantStack<T>(void){return;};
    
            typedef typename std::stack<T>::container_type::iterator iterator;
            iterator begin(void) {return this->c.begin();}
            iterator end(void){return this->c.end();}

            static bool verbose;
    private: 
};

#endif