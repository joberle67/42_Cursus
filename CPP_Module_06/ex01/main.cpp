#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}


Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
    Data *ptr = NULL;
    uintptr_t raw = 0;
    Data *b = ptr;
    
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "raw = " << raw << std::endl;

    ptr = deserialize(raw);
    std::cout << "deserialize ptr = " << ptr << std::endl;

    raw = serialize(b);
    std::cout << "serialize raw = " << ptr << std::endl;
}