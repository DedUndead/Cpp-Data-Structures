#include <list>
#include <string>

#define NUM_CELLS 10

/**
 * Hash table with separate chaining collision resolution
 */
class HashTable {
public:
    HashTable(){}
	void insert_item(int key, std::string value);
	void remove_item(int key);
	std::string search_table(int key);
    void print_table();
private:
	std::list<std::pair<int, std::string>> table[NUM_CELLS];
	int hash_function(int key);
};