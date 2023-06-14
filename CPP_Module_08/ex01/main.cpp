#include "Span.hpp"
#include <cstdlib>

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}


/*int main(void)
{
	Span				span3(5);
	std::vector<int>	vect;

	vect.push_back(25);
	vect.push_back(-5);
	vect.push_back(12);
	vect.push_back(90);
	vect.push_back(8);
	span3.addByIteratorRange(vect.begin(), vect.end());
	std::cout << span3.getN(1) << std::endl;
}*/




/*int main(void)
{
    Span test(100000);
    for (int i = 0; i < 100000; i++)
    {
        try{
            test.addNumber(rand() % 1000000);}
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    try{std::cout << test.shortestSpan() << std::endl;}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    try{std::cout << test.getN(30) << std::endl;}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    try{std::cout << test.longestSpan() << std::endl;}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
}*/