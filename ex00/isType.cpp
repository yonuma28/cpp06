# include "isType.hpp"

bool isInt(const std::string& str)
{
    if (str.empty())
		return false;

    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (i == str.length())
		return false;

	for (; i < str.length(); ++i)
	{
        if (!std::isdigit(str[i]))
			return false;
    }
    return true;
}

bool isFloat(const std::string& str)
{
    if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
    
    bool hasDot = false;
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;

	for (; i < str.length() - 1; i++)
	{
        if (str[i] == '.')
		{
            if (hasDot)
				return false;
            hasDot = true;
        } 
		else if (!std::isdigit(str[i]))
		{
            return false;
        }
    }
    return true;
}

bool isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "inf" || str == "inff" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}
