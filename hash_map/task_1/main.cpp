/**
 * Calculate frequency of alphabet characters in a string
 * Solve the task with linear complexity (O(n))
 */

#include <iostream>
#include "main.h"

int main(void)
{
    char name[] = "Pavel Arefyev";

    HashTable frequencies;
    fill_table_with_frequency(frequencies, name);
    print_table(frequencies);

    return 0;
}

void fill_table_with_frequency(HashTable& table, char* string)
{
    for (int i = 0; string[i] != '\0'; i++) {
        table.increment_value(string[i]);
    }
}

void print_table(HashTable& table)
{   
    // Print alphabet characters frequency
    for (char i = 'a'; i < TABLE_SIZE + 'a' - 1; i++) {
        int frequency = table.search_item(i);
        
        if (frequency != 0) {
            std::cout << i << " : " << frequency << std::endl;
        }
    }

    std::cout << "Other characters : " << table.search_item(';') << std::endl;
}