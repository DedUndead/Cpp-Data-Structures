#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "HashTable.h"

using namespace std;

/**
 * @brief Simple hashing function.
 * Returns hash by modulus of number of groups
 * @param  key Target key to be hashed
 * @return     Hash
 */
int HashTable::hash_function(int key) 
{
	return key % NUM_CELLS;
}

/**
 * @brief Insert new item to the table
 * Rewrites value if the key already exists
 * @param key  Key of the item
 * @param cell Value of the item
 */ 
void HashTable::insert_item(int key, string value) 
{
	int hash_value = hash_function(key);
	auto& cell = table[hash_value];

	// Check if the key already exists and rewrite value
	for (auto& element : cell) {
		if (element.first == key) {
			element.second = value;
			return;
		}
	}

	// Add new item if key doesnt exist
	cell.emplace_back(key, value);
}

/**
 * @brief Remove value from the has table by key
 * @param key Key of the item
 */
void HashTable::remove_item(int key)
{
	int hash_value = hash_function(key);
	auto& cell = table[hash_value];
	auto cell_iter = cell.begin();

	// Search and erase value
	for (; cell_iter != cell.end(); ++cell_iter) {
		if (cell_iter->first == key) {
			cell.erase(cell_iter);
			return;
		} 
	}
}

/**
 * @brief  Find element by key
 * @param  key Key of the item
 * @return     Value of the item. If no found, empty string
 */ 
string HashTable::search_table(int key)
{
	int hash_value = hash_function(key);
	auto& cell = table[hash_value];

	for (auto element : cell) {
		if (element.first == key) {
			return element.second; 
		}
	}

	return "";
}

/**
 * @brief Print values for non empty cells
 */
void HashTable::print_table()
{
	for (int i = 0; i < NUM_CELLS; i++) {
		if (table[i].size() == 0) continue;

		if (table[i].size() != -1) {
			for (auto element : table[i]) {
					cout << setw(8) << left << element.first << " : " << element.second << endl;
			}
		}
	}
}