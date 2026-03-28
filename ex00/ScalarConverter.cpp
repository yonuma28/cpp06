#include "ScalarConverter.hpp"
#include "isType.hpp"

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

namespace
{
	void printImpossible(void)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}

	double parseLiteral(ScalarConverter::Type type, const std::string& literal)
	{
		if (type == ScalarConverter::TYPE_CHAR)
			return static_cast<double>(literal[0]);
		if (type == ScalarConverter::TYPE_INT)
			return static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
		return std::strtod(literal.c_str(), NULL);
	}

	void printChar(double value)
	{
		std::cout << "char: ";
		if (std::isnan(value) || std::isinf(value)
			|| value < std::numeric_limits<char>::min()
			|| value > std::numeric_limits<char>::max())
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		char c = static_cast<char>(value);
		if (!std::isprint(static_cast<unsigned char>(c)))
		{
			std::cout << "Non displayable" << std::endl;
			return;
		}
		std::cout << "'" << c << "'" << std::endl;
	}

	void printInt(double value)
	{
		std::cout << "int: ";
		if (std::isnan(value) || std::isinf(value)
			|| value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << static_cast<int>(value) << std::endl;
	}

	void printFloat(double value)
	{
		std::cout << "float: ";
		if (std::isnan(value))
		{
			std::cout << "nanf" << std::endl;
			return;
		}
		if (std::isinf(value))
		{
			std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
			return;
		}
		if (std::fabs(value) > std::numeric_limits<float>::max())
		{
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << std::fixed << std::setprecision(1)
			<< static_cast<float>(value) << "f" << std::endl;
	}

	void printDouble(double value)
	{
		std::cout << "double: ";
		if (std::isnan(value))
		{
			std::cout << "nan" << std::endl;
			return;
		}
		if (std::isinf(value))
		{
			std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
			return;
		}
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal)
{
	if (isPseudoLiteral(literal))
		return TYPE_PSEUDO;
	if (isChar(literal))
		return TYPE_CHAR;
	if (isInt(literal))
		return TYPE_INT;
	if (isFloat(literal))
		return TYPE_FLOAT;
	if (isDouble(literal))
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string& literal)
{
	Type type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		printImpossible();
		return;
	}

	errno = 0;
	double value = parseLiteral(type, literal);
	if (errno == ERANGE && !std::isinf(value))
	{
		printImpossible();
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
