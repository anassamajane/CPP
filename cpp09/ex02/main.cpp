#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe sorter;

        sorter.parseArguments(ac, av);
        std::vector<PmergeMe::Node> result = sorter.fordJohnsonVector(sorter.createNodesVector());

        for (std::size_t i = 0; i < result.size(); i++)
            std::cout << result[i].value << " ";

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}