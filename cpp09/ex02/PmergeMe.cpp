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

std::vector<PmergeMe::v_Node> PmergeMe::createNodesVector() const
{
    std::vector<v_Node> nodes;

    for (std::size_t i = 0; i < _vector.size(); i++)
        nodes.push_back(v_Node(_vector[i]));
    return nodes;
}

void PmergeMe::makePairsVector(std::vector<v_Node> &nodes)
{
    std::vector<v_Node> winners;
    
    winners.reserve(nodes.size() / 2);
    for (std::size_t i = 0; i < nodes.size(); i += 2)
    {
        if (nodes[i].value < nodes[i + 1].value)
            std::swap(nodes[i], nodes[i + 1]);
        nodes[i].losers.push_back(nodes[i + 1]);
        winners.push_back(nodes[i]);
    }
    nodes = winners;
}

static bool lower_bound_compv(const PmergeMe::v_Node &item1, const PmergeMe::v_Node &item2)
{
    return item1.value < item2.value;
}

std::vector<std::size_t> PmergeMe::generateInsertionOrderVector(std::size_t size) const
{
    std::vector<std::size_t> order;
    
    if (size == 0)
        return order;
    
    order.push_back(1);
    
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
            order.push_back(i);
            --i;
        }
        
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

void PmergeMe::fordJohnsonVector(std::vector<v_Node> &nodes)
{
    if (nodes.size() <= 1)
        return;

    bool hasStraggler = nodes.size() % 2 != 0;
    v_Node straggler;

    if (hasStraggler)
    {
        straggler = nodes.back();
        nodes.pop_back();
    }

    makePairsVector(nodes);
    std::size_t generation = nodes[0].losers.size();
    //print_me(nodes);
    fordJohnsonVector(nodes);

    std::vector<std::size_t> order = generateInsertionOrderVector(nodes.size());

    for (std::size_t j = 0; j < order.size(); j++)
    {
        std::size_t target = order[j] - 1;
        for (std::size_t i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].losers.size() != generation)
            {
                continue;
            }

            if (target == 0)
            {
                v_Node guest = nodes[i].losers.back();
                std::vector<v_Node>::iterator place = std::lower_bound(nodes.begin(), nodes.begin() + i, guest, lower_bound_compv);
                nodes.insert(place, guest);
                break;
            }
            target--;
        }
    }
    for (std::size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].losers.size() == generation)
            nodes[i].losers.pop_back();
    }
    
    if (hasStraggler)
    {
        std::vector<v_Node>::iterator place = std::lower_bound(nodes.begin(), nodes.end(), straggler, lower_bound_compv);
        nodes.insert(place, straggler);
    }
    //print_me(nodes);
}

void PmergeMe::sortVector()
{
    std::vector<v_Node> nodes = createNodesVector();

    fordJohnsonVector(nodes);
    _vector.clear();

    for (std::size_t i = 0; i < nodes.size(); i++)
        _vector.push_back(nodes[i].value);
}


// deque implementation

std::deque<PmergeMe::d_Node> PmergeMe::createNodesDeque() const
{
    std::deque<d_Node> nodes;

    for (std::size_t i = 0; i < _deque.size(); i++)
        nodes.push_back(d_Node(_deque[i]));
    return nodes;
}


void PmergeMe::makePairsDeque(std::deque<d_Node> &nodes)
{
    std::deque<d_Node> winners;

    for (std::size_t i = 0; i < nodes.size(); i += 2)
    {
        if (nodes[i].value < nodes[i + 1].value)
            std::swap(nodes[i], nodes[i + 1]);
        
        nodes[i].losers.push_back(nodes[i + 1]);
        winners.push_back(nodes[i]);
    }

    nodes = winners;
}

static bool lower_bound_compd(const PmergeMe::d_Node &item1, const PmergeMe::d_Node &item2)
{
    return item1.value < item2.value;
}

std::deque<std::size_t> PmergeMe::generateInsertionOrderDeque(std::size_t size) const
{
    std::deque<std::size_t> order;
    
    if (size == 0)
        return order;
    
    order.push_back(1);
    
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
            order.push_back(i);
            --i;
        }
        
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

void PmergeMe::fordJohnsonDeque(std::deque<d_Node> &nodes)
{
    if (nodes.size() <= 1)
        return;

    bool hasStraggler = nodes.size() % 2 != 0;
    d_Node straggler;

    if (hasStraggler)
    {
        straggler = nodes.back();
        nodes.pop_back();
    }

    makePairsDeque(nodes);
    std::size_t generation = nodes[0].losers.size();
    fordJohnsonDeque(nodes);

    std::deque<std::size_t> order = generateInsertionOrderDeque(nodes.size());

    for (std::size_t j = 0; j < order.size(); j++)
    {
        std::size_t target = order[j] - 1;
        for (std::size_t i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].losers.size() != generation)
            {
                continue;
            }

            if (target == 0)
            {
                d_Node guest = nodes[i].losers.back();
                std::deque<d_Node>::iterator place = std::lower_bound(nodes.begin(), nodes.begin() + i, guest, lower_bound_compd);
                nodes.insert(place, guest);
                break;
            }
            target--;
        }
    }
    for (std::size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].losers.size() == generation)
            nodes[i].losers.pop_back();
    }
    
    if (hasStraggler)
    {
        std::deque<d_Node>::iterator place = std::lower_bound(nodes.begin(), nodes.end(), straggler, lower_bound_compd);
        nodes.insert(place, straggler);
    }
}

void PmergeMe::sortDeque()
{
    std::deque<d_Node> nodes = createNodesDeque();

    fordJohnsonDeque(nodes);
    _deque.clear();

    for (std::size_t i = 0; i < nodes.size(); i++)
        _deque.push_back(nodes[i].value);
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";

    for (std::size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";

    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After:  ";

    for (std::size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";

    std::cout << std::endl;
}

long long PmergeMe::getTime() const
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return static_cast<long long>(tv.tv_sec) * 1000000LL
        + static_cast<long long>(tv.tv_usec);
}