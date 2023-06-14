#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    public :
            Span(void);
            Span(int nb);
            Span(const Span &src);
            Span &operator=(const Span &src);
            ~Span(void);

            void addNumber(int nb);

            int getN(int nb);

            int shortestSpan(void);
            int longestSpan(void);

            void addByIteratorRange( std::vector<int>::iterator begin,std::vector<int>::iterator end);

        class tooException : public std::exception
        {
                virtual const char *what() const throw()
                {
                        return ("out of range");
                }
        };
    private :
            std::vector<unsigned int> N;
            int max;

};

#endif