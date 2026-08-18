#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

// parsing

void PmergeMe::parseArguments(int ac, char **av)
{
    if (ac < 2)
        throw std::runtime_error("Error");
    
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        int number;

        if (!parseAndValidate(arg, number))
            throw std::runtime_error("Error");

        _vector.push_back(number);
        _deque.push_back(number);
    }
}

bool PmergeMe::parseAndValidate(const std::string &str, int &out) const
{
    if (str.empty())
        return false;

    for (std::size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;

    errno = 0;
    char *endptr = 0;
    long value = std::strtol(str.c_str(), &endptr, 10);

    if (*endptr != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    if (value <= 0 || value > INT_MAX)
        return false;
    
    out = static_cast<int>(value);
    return true;
}

// vector implementation

std::vector<PmergeMe::Node> PmergeMe::createNodesVector() const
{
    std::vector<Node> nodes;

    for (std::size_t i = 0; i < _vector.size(); i++)
        nodes.push_back(Node(_vector[i]));
    return nodes;
}

std::vector<PmergeMe::Node> PmergeMe::makePairsVector(const std::vector<Node> &nodes)
{
    std::vector<Node> winners;

    for (std::size_t i = 0; i + 1 < nodes.size(); i += 2)
    {
        Node small = nodes[i];
        Node large = nodes[i + 1];

        if (small.value > large.value)
            std::swap(small, large);
        
        large.losers.push_back(small);
        winners.push_back(large);
    }
    return winners;
}

void printNodeTree(std::ostream &os, const PmergeMe::Node &item, const std::string &prefix, bool isLast)
{
    os << prefix << (isLast ? "└── " : "├── ") 
       << "\033[1;97mNode:\e[0m \033[1;32m" << item.value << "\e[0m\n";

    std::size_t size = item.losers.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        bool lastLoser = (i == size - 1);
        printNodeTree(os, item.losers[i], prefix + (isLast ? "    " : "│   "), lastLoser);
    }
}

std::ostream &operator<<(std::ostream &os, const PmergeMe::Node &item)
{
    os << "\033[1;97mNode:\e[0m \033[1;32m" << item.value << "\e[0m\n";
    
    std::size_t size = item.losers.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        printNodeTree(os, item.losers[i], "", (i == size - 1));
    }
    
    return os;
}

std::vector<PmergeMe::Node> PmergeMe::fordJohnsonVector(const std::vector<Node> &nodes)
{
    // for (std::size_t i = 0; i < nodes.size(); i++)
    //         std::cout << nodes[i];
    // std::cout << std::endl;

    bool hasStraggler = nodes.size() % 2 != 0;
    Node straggler;

    if (hasStraggler)
        straggler = nodes.back();

    if (nodes.size() <= 1)// up up up
    {
        std::cout << "===== RECURSION FINISHED =====" << std::endl;
        return nodes;
    }

    std::vector<Node> winners = makePairsVector(nodes);
    std::vector<PmergeMe::Node> result = fordJohnsonVector(winners);
    
    result = insertLosers(result, winners);

    if (hasStraggler)
    {
        std::vector<Node>::iterator it = result.begin();

        while (it != result.end() && it->value < straggler.value)
            ++it;

        result.insert(it, straggler);
    }

    // std::cout << "RESULT FROM RECURSION:" << std::endl;
    // for (std::size_t i = 0; i < result.size(); i++)
    //     std::cout << result[i];

    return (result);
}


std::vector<PmergeMe::Node> PmergeMe::insertLosers(const std::vector<Node> &sorted, const std::vector<Node> &winners) const
{
    std::vector<Node> result = sorted;
    std::vector<std::size_t> order = generateInsertionOrder(winners.size());
    
    
    std::cout << "Insertion order: ";
    for (std::size_t i = 0; i < order.size(); i++)
        std::cout << order[i] << " ";
    std::cout << std::endl;



    for (std::size_t i = 0; i < order.size(); i++)
    {
        std::size_t loserIndex = order[i];

        if (loserIndex >= winners.size())
            continue;

        Node loser = winners[loserIndex].losers.back();
        std::vector<Node>::iterator winnerIt = result.begin();

        while (winnerIt != result.end())
        {
            if (winnerIt->value == winners[loserIndex].value)
                break;
            ++winnerIt;
        }

        std::vector<Node>::iterator it = result.begin();

        while (it != winnerIt && it->value < loser.value)
            ++it;
        
        result.insert(it, loser);
    }
    return result;
}


std::vector<std::size_t> PmergeMe::generateInsertionOrder(std::size_t size) const
{
    std::vector<std::size_t> order;
    
    if (size == 0)
    return order;
    
    order.push_back(0);
    
    std::size_t previous = 1;
    std::size_t current = 3;
    
    while (previous < size)
    {
        std::size_t end = current;
        
        if (end > size)
        end = size;
        
        std::size_t i = end;
        
        while (i > previous)
        {
            --i;
            order.push_back(i);
        }
        
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

// std::vector<PmergeMe::Node> PmergeMe::getLosers(const std::vector<Node> &winners) const
// {
//     std::vector<Node> losers;

//     for (std::size_t i = 0; i < winners.size(); i++)
//     {
//         if (!winners[i].losers.empty())
//             losers.push_back(winners[i].losers.back());
//     }

//     return losers;
// }