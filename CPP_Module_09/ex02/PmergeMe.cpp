#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}


void PmergeMe::insertValue(char **av)
{
    for(int i=1;av[i];i++)
		_vector.push_back(atoi(av[i]));
	for(int i=1;av[i];i++)
		_deque.push_back(atoi(av[i]));
}

int PmergeMe::checkError(std::string av)
{
	for(int i=0;av[i];i++)
	{
		if (isdigit(av[i]) == false)
			return (-1);
	}
	return(0);
}

void PmergeMe::sortValue(int argc)
{
	std::cout << "Before: ";
	for(int i=0;i<_vector.size();i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::clock_t start1 = std::clock();
	std::sort(_vector.begin(), _vector.end());
	std::clock_t end1 = std::clock();

	std::clock_t start2 = std::clock();
	std::sort(_deque.begin(), _deque.end());
	std::clock_t end2 = std::clock();
	
	double _vector_us = double(end1 - start1) / CLOCKS_PER_SEC * 1000;
	double _deque_us = double(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "After:  ";
	for(int i=0;i<_vector.size();i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::_vector : " << std::setprecision(5) << _vector_us << " us";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::_deque : " << std::setprecision(5) << _deque_us << " us";
	std::cout << std::endl;
}