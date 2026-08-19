#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe sorter;

        sorter.parseArguments(ac, av);

        sorter.printBefore();

        long long start = sorter.getTime();
        sorter.sortVector();
        long long end = sorter.getTime();

        double vectorTime =
            static_cast<double>(end - start);

        start = sorter.getTime();
        sorter.sortDeque();
        end = sorter.getTime();

        double dequeTime =
            static_cast<double>(end - start);

        sorter.printAfter();

        std::cout << std::fixed << std::setprecision(5);

        std::cout
            << "Time to process a range of "
            << ac - 1
            << " elements with std::vector : "
            << vectorTime
            << " us"
            << std::endl;

        std::cout
            << "Time to process a range of "
            << ac - 1
            << " elements with std::deque  : "
            << dequeTime
            << " us"
            << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}