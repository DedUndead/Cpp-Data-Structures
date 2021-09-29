/**
 * 1) Create a hash table data structure that includes several methods:
 * insert, print, remove, search
 * Use separate chaining collision resolution
 * Demonstrate that these methods work
 */

#include <iostream>
#include "HashTable.h"

int main(void)
{
    // Hash table maps office room number to office's owner
    HashTable offices;

    // Add elemets
    offices.insert_item(100, "Tommi");
    offices.insert_item(312, "Joseph");
    offices.insert_item(1401, "Keijo");
    offices.insert_item(202, "Karlson"); // Collision resolution check
    offices.print_table(); std::cout << std::endl;

    // Remove elements
    offices.remove_item(202);
    offices.print_table(); std::cout << std::endl;

    // Find element
    std::cout << offices.search_table(100) << std::endl;

    return 0;
}