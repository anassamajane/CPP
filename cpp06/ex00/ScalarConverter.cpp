#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}


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

static bool handlePseudo(const std::string& literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return true;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
        return true;   
    }
    return false;
}

static bool parseLiteral(const std::string& literal, double& value)
{
    if (isCharLiteral(literal))
        value = static_cast<double>(literal[1]);
    else if (literal.length() == 1 &&
             std::isprint(literal[0]) &&
             !std::isdigit(literal[0]))
        value = static_cast<double>(literal[0]);
    else if (isIntLiteral(literal) ||
             isFloatLiteral(literal) ||
             isDoubleLiteral(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
        return false;
    return true;
}

static void printConversions(double value)
{
    
    std::cout << "char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint((value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    
    std::cout << "int: ";
    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    
    float f = static_cast<float>(value);
    std::cout << "float: ";
    if (f == static_cast<int>(f))
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
    else{
        std::cout << f << "f\n";
    }

    
    std::cout << "double: ";
    if (value == static_cast<int>(value))
        std::cout << std::fixed << std::setprecision(1) << value << "\n";
    else
        std::cout << value << "\n";
}

void ScalarConverter::convert(const std::string &literal)
{
    double value;

    if (handlePseudo(literal))
        return;
    if (!parseLiteral(literal, value))
    {
        std::cout << "Error: Invalid literal\n";
        return;
    }
    printConversions(value);
}