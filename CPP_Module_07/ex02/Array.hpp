#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    public :
            Array<T>(void){size = 0, array = new T[0];};
            Array<T>(unsigned int n){this->size = n, this->array = new T[n];};
            Array<T>(const Array &src){
                this->size = src.size;
                this->array = new T[src.size];
                for (unsigned int i = 0; i < src.size; i++)
                    this->array[i] = src.array[i];
            };
            Array<T> &operator=(const Array &src){
                if (this != src)
                {
                    this->~array();
                    this = Array(src);
                }
                return (*this);
            };
            ~Array(void){delete[] this->array;};

            T &operator[](int i)
            {
                if (i < 0 || i >= static_cast<int>(this->size))
                    throw Array::tooException();
                return (this->array[i]);
            }

            int getSize(void)
            {
                return (this->size);
            }

            class tooException : public std::exception
            {
                virtual const char *what() const throw()
                {
                    return ("out of range");
                }
            };

    private :
            unsigned int size;
            T *array;
};

#endif