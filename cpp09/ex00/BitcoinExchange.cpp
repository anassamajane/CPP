#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) 
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open the file.");
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;

        std::getline(ss, date, ',');
        std::getline(ss, rate);

        _database[date] = std::atof(rate.c_str());
    }
}
void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Error: could not open the file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;

        std::getline(ss, date, '|');
        std::getline(ss, value);

        if (line.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date);
        value = trim(value);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double amount;
        if (!parseValue(value, amount))
            continue;

        std::map<std::string, double>::iterator it;

        it = _database.lower_bound(date);
        if (it == _database.begin() && it->first != date)
        {
            std::cout << "Error: date is before database range." << std::endl;
            continue;
        }
        if (it == _database.end())
            --it;
        else if (it->first != date)
            --it;
        
        double rate = it->second;
        double result = amount * rate;

        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
        return false;
    
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (std::size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        maxDay = 29;
    
    if (day < 1 || day > maxDay)
        return false;

    return true;
}

bool BitcoinExchange::parseValue(const std::string &str, double &value) const
{
    if (str.empty())
    {
        std::cout << "Error: invalid value." << std::endl;
        return false;
    }

    if (str[0] == '-')
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    
    bool dot = false;
    bool hasDigit = false;

    for (std::size_t i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
        {
            hasDigit = true;
            continue;
        }
        if (str[i] == '.' && !dot)
        {
            dot = true;
            continue;
        }
        std::cout << "Error: invalid value." << std::endl;
        return false;
    }

    if (!hasDigit)
    {
        std::cout << "Error: invalid value." << std::endl;
        return false;
    }
    
    value = std::atof(str.c_str());
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

std::string BitcoinExchange::trim(const std::string &str) const
{
    std::size_t start = 0;
    std::size_t end = str.length();

    while (start < end && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}