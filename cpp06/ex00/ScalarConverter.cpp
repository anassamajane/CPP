#include "ScalarConverter.hpp"

static bool isCharLiteral(const std::string &s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isIntLiteral(const std::string &s)
{
    int i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == (int)s.length())
        return false;
    while (i < (int)s.length())
    {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloatLiteral(const std::string &s)
{
    if (s[s.length() - 1] != 'f')
        return false;
    
    std::string core = s.substr(0, s.length() - 1);
    bool dotFound = false;
    int i = 0;

    if (core[i] == '+' || core[i] == '-')
        i++;
    while (i < (int)core.length())
    {
        if (core[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(core[i]))
            return false;
        i++;
    }
    return dotFound;
}
static bool isDoubleLiteral(const std::string &s)
{
    bool dotFound = false;
    int i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    while (i < (int)s.length())
    {
        if (s[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return dotFound;
}

void ScalarConverter::convert(const std::string &literal)
{
    double value;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
        return;   
    }

    if (isCharLiteral(literal))
        value = static_cast<double>(literal[1]);
    else if (literal.length() == 1 && std::isprint(literal[0])
         && !std::isdigit(literal[0]))
        value = static_cast<double>(literal[0]);
    else if (isIntLiteral(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloatLiteral(literal))
        value = std::strtof(literal.c_str(), NULL);
    else if (isDoubleLiteral(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "Error: invalid literal\n";
        return;
    }

    // char
    std::cout << "char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    //int
    std::cout << "int: ";
    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    //float
    std::cout << "float: ";
    std::cout << std::fixed << static_cast<float>(value) << "f\n";

    //double
    std::cout << "double: ";
    std::cout << std::fixed << value << "\n";
}