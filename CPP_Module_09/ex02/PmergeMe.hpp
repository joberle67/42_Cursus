#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>


class PmergeMe
{
    public :
            PmergeMe();
            PmergeMe(const PmergeMe &);
            PmergeMe &operator=(const PmergeMe &);
            ~PmergeMe();

            void insertValue(char **);
            void sortValue(int);
            int checkError(std::string);

    private :
            std::vector<int> _vector;
            std::deque<int> _deque;
};