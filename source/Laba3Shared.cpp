
#include "pch.h"
#include <iostream>
#include <atomic>
#include <map>

#include "Shared.hpp"


int main()
{
	SharedPtr<int>ptr;
	int a = 1;
	int b = 2;
	
	ptr.reset(&a);
	SharedPtr<int> ptr2(&a);
	std::cout << ptr2.use_count() << std::endl;
	ptr.reset();
	std::cout << ptr2.use_count() << std::endl;
	
	SharedPtr<int> ptr3(&b);

	std::cout << *ptr2 << std::endl;
	std::cout << *ptr3 << std::endl;

	ptr2.swap(ptr3);
	std::cout << *ptr2 << std::endl;
	std::cout << *ptr3 << std::endl;	
}
