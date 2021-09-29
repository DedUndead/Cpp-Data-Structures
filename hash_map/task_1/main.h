#include <iostream>
#include <ctype.h>

#define TABLE_SIZE 27

class HashTable {
    public:
        HashTable() : cells { 0 }  {}
        void increment_value(char key) {
            cells[hash_function(key)]++;
        };
        int search_item(char key) {
            return cells[hash_function(key)];
        }
    private:
        int cells[TABLE_SIZE];
        int hash_function(char key) {
            if      (!isalpha(key)) return 26;
            else if (isupper(key))  return key - 'A';
            else                    return key - 'a';
        };
};

void fill_table_with_frequency(HashTable& table, char* string);
void print_table(HashTable& table);