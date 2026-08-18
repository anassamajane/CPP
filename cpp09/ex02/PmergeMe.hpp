#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <climits>

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    
    
    bool parseAndValidate(const std::string &str, int &out) const;
    
    public:
    struct Node
    {
        int value;
        std::vector<Node> losers;

        Node() : value(0), losers() {}
        Node(int value) : value(value), losers()
        {
        }
    };
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        void parseArguments(int ac, char **av);

        std::vector<Node> createNodesVector() const;
        std::vector<Node> makePairsVector(const std::vector<Node> &nodes);
        std::vector<Node> fordJohnsonVector(const std::vector<Node> &nodes);
        std::vector<Node> insertLosers(const std::vector<Node> &sorted, const std::vector<Node> &winners) const;
        std::vector<Node> getLosers(const std::vector<Node> &winners) const;
        std::vector<std::size_t> generateInsertionOrder(std::size_t size) const;
        void printNode(const Node &node, int level) const;
        
};

#endif