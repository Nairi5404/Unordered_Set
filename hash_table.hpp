#pragma once

template <typename T>
HashTable<T>::HashTable(size_t count)
{
	m_cap = count;
	m_ptr.resize(m_cap);
}

template <typename T>
HashTable<T>::HashTable(const HashTable& ob)
{
	m_cap = ob.m_cap;
	m_ptr.resize(m_cap);
	for (int i = 0;i < m_cap;++i) {
		m_ptr[i] = ob.m_ptr[i];
	}
}

template <typename T>
HashTable<T>::HashTable(HashTable&& ob)
{
	m_ptr = std::move(ob.m_ptr);
	m_cap = ob.m_cap;
}

template <typename T>
HashTable<T>::HashTable(std::initializer_list<T> ob) :m_cap(10), m_ptr(m_cap)
{
	for (auto it = ob.begin(); it != ob.end(); ++it) {
		insert(*it);
	}
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(std::initializer_list<T> ob)
{
	m_cap = ob.m_cap;
	m_ptr.resize(m_cap);
	for (auto it = ob.begin(); it != ob.end(); ++it) {
		insert(*it);
	}
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable& ob)
{
	if (this == &ob) {
		return *this;
	}

	ob.clear();
	m_cap = ob.m_cap;
	m_ptr.resize(m_cap);
	for (int i = 0;i < m_cap;++i) {
		m_ptr[i] = ob.m_ptr[i];
	}
	return *this;
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(HashTable&& rhs)
{
	rhs.clear();
	m_cap = rhs.m_cap;
	m_ptr = std::move(rhs.m_ptr);
}

template <typename T>
HashTable<T>::~HashTable() {
	clear();
}

template <typename T>
bool HashTable<T>::empty() const noexcept {
	return m_ptr.empty();
}

template <typename T>
size_t HashTable<T>::size() const noexcept 
{
	size_t count{};
	for (int i = 0;i < m_cap; ++i)
	{
		for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
		{
			++count;
		}
	}
	return count;
}

template <typename T>
size_t HashTable<T>::count(const T& val) const
{
	for (int i = 0;i < m_cap; ++i)
	{
		for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
		{
			if (val == *(it)) {
				return 1;
			}
		}
	}
	return 0;
}

template <typename T>
void HashTable<T>::clear() noexcept {
	m_ptr.clear();
}

template <typename T>
bool HashTable<T>::contains(const T& key) const
{
	if (!m_ptr.empty())
	{
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				if (m_ptr[key].empty()) {
					return false;
				}
			}
		}
	}
	return true;
}

template <typename T>
void HashTable<T>::insert(T key)
{
	if (!m_ptr.empty())
	{
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				if (key == *(it)) {
					return;
				}
			}
		}
	}
	int index = hash_function(key);
	m_ptr[index].push_back(key);
}

template <typename T>
size_t HashTable<T>::hash_function(T key) const
{
	if (m_cap != 0) {
		return key % m_cap;
	}
}

/*template <typename T>
void HashTable<T>::insert(const std::string& val)
{
	if (!m_ptr.empty())
	{
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				if (val == *(it)) {
					return;
				}
			}
		}
	}
	int index = hashFunction(val);
	m_ptr[index].push_back(val);
}

template <typename T>
size_t HashTable<T>::hashFunction(std::string str)
{
	unsigned long i = 0;
	for (int j = 0; str[j]; j++) {
		i += str[j];
	}
	return i % m_cap;
}*/

template <typename T>
void HashTable<T>::swap(HashTable& ob) noexcept
{
	std::vector<std::list<T> > tmp(m_cap);
	if (!m_ptr.empty() && !ob.m_ptr.empty())
	{
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				tmp[i].push_back(*it);
			}
		}
		clear();
		m_cap = ob.m_cap;
		m_ptr.resize(m_cap);
		for (int i = 0;i < ob.m_cap;++i)
		{
			for (auto it = ob.m_ptr[i].begin(); it != ob.m_ptr[i].end(); ++it)
			{
				m_ptr[i].push_back(*it);
			}
		}
		ob.clear();
		ob.m_cap = m_cap;
		ob.m_ptr.resize(ob.m_cap);
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = tmp[i].begin(); it != tmp[i].end(); ++it)
			{
				ob.m_ptr[i].push_back(*it);
			}
		}
	}
	else if(ob.m_ptr.empty())
	{
		ob.m_cap = m_cap;
		ob.m_ptr.resize(ob.m_cap);
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				ob.m_ptr[i].push_back(*it);
			}
		}
		clear();
	}
	else
	{
		m_cap = ob.m_cap;
		m_ptr.resize(m_cap);
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = ob.m_ptr[i].begin(); it != ob.m_ptr[i].end(); ++it)
			{
				m_ptr[i].push_back(*it);
			}
		}
		ob.clear();
	}
}

template <typename T>
void HashTable<T>::print() const
{
	if (!m_ptr.empty())
	{
		for (int i = 0;i < m_cap;++i)
		{
			for (auto it = m_ptr[i].begin(); it != m_ptr[i].end(); ++it)
			{
				std::cout << *(it) << " ";
			}
		}
	}
}