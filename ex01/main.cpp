#include "Serializer.hpp"

#include <iostream>

int main(void)
{
	Data original;
	original.id = 42;
	original.label = "cpp06";
	original.value = 4.2;

	uintptr_t raw = Serializer::serialize(&original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "original:  " << &original << std::endl;
	std::cout << "serialized: " << raw << std::endl;
	std::cout << "restored:  " << restored << std::endl;
	std::cout << "same pointer: " << (&original == restored ? "true" : "false") << std::endl;
	std::cout << "data: " << restored->id << ", " << restored->label
		<< ", " << restored->value << std::endl;
	return 0;
}
