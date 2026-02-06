# include "ScalarConverter.hpp"
# include "isType.hpp"

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
	INVALID
};

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal)
{
    if (isPseudo(literal))
		return PSEUDO;
    if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;
    if (isInt(literal))
		return INT;
    if (isFloat(literal))
		return FLOAT;
    
    char* endptr;
    std::strtod(literal.c_str(), &endptr);

    if (*endptr == '\0')
		return DOUBLE;

    return INVALID;
}

void ScalarConverter::convert(const std::string& literal) {
    e_type type = detectType(literal);
    double d = 0;
    char* endptr;

    switch (type)
	{
        case CHAR:
            d = static_cast<double>(literal[0]);
            break;
        case INT:
            d = static_cast<double>(std::atol(literal.c_str()));
            break;
        case FLOAT:
        case DOUBLE:
        case PSEUDO:
            d = std::strtod(literal.c_str(), &endptr);
            break;
        case INVALID:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
	}
	// --- char 表示 ---
    std::cout << "char: ";
    if (std::isnan(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    

    // --- int 表示 ---
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    

    // --- float 表示 ---
    // 擬似リテラルなら専用の表記、そうでなければ fixed で表示 [cite: 142, 154]
    std::cout << "float: ";
    if (std::isnan(d))
		std::cout << "nanf" << std::endl;
    else if (std::isinf(d))
		std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

    // --- double 表示 ---
    std::cout << "double: ";
    if (std::isnan(d))
		std::cout << "nan" << std::endl;
    else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}
