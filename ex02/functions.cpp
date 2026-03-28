#include "functions.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

Base* generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception&)
	{
	}
}
