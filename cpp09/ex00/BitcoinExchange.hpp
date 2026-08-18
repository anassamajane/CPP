#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;

        void loadDatabase(const std::string &filename);
        bool isValidDate(const std::string &date) const;
        std::string trim(const std::string &str) const;
        bool parseValue(const std::string &str, double &value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void processInputFile(const std::string &filename);
};

#endif