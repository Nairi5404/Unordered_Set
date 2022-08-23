#pragma once
#include <vector>
#include <list>
#include <string>

template <typename T>
class HashTable //Unordered Set
{
public:
	HashTable() = default;
	HashTable(size_t);
	HashTable(const HashTable&);
	HashTable(HashTable&&);
	HashTable(std::initializer_list<T>);
	HashTable& operator=(const HashTable&);
	HashTable& operator=(HashTable&&);
	HashTable& operator=(std::initializer_list<T>);
	~HashTable();

public:
	void insert(T);
	//void insert(const std::string&);
	//size_t hashFunction(std::string);
	bool empty() const noexcept;
	size_t size() const noexcept;
	void clear() noexcept;
	void swap(HashTable&) noexcept;
	size_t count(const T&) const;
	bool contains(const T&) const;
	size_t hash_function(T) const;
	void print() const;
private:
	size_t m_cap{};
	std::vector<std::list<T> > m_ptr;
};

#include "hash_table.hpp"
