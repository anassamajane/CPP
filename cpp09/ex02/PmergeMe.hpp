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
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        void parseArguments(int ac, char **av);
        bool parseAndValidate(const std::string &str, int &out) const;
        long long getTime() const;
        void printBefore() const;
        void printAfter() const;
    
        // vector implementatio
        struct v_Node
        {
            int value;
            std::vector<v_Node> losers;

            v_Node() : value(0), losers() {}
            v_Node(int value) : value(value), losers()
            {
            }
        };
        std::vector<v_Node> createNodesVector() const;
        void makePairsVector(std::vector<v_Node> &nodes);
        std::vector<std::size_t> generateInsertionOrderVector(std::size_t size) const;
        void fordJohnsonVector(std::vector<v_Node> &nodes);
        void sortVector();
        

        //deque implementation
        struct d_Node
        {
            int value;
            std::deque<d_Node> losers;

            d_Node() : value(0), losers() {}
            d_Node(int value) : value(value), losers()
            {
            }
        };
        std::deque<d_Node> createNodesDeque() const;
        void makePairsDeque(std::deque<d_Node> &nodes);
        std::deque<std::size_t> generateInsertionOrderDeque(std::size_t size) const;
        void fordJohnsonDeque(std::deque<d_Node> &nodes);
        void sortDeque();
};

#endif