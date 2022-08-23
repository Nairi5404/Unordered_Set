#include <iostream>
#include "hash_table.h"


int main()
{
    /*HashTable<std::string> obj(10);
    obj.insert("asduk");
    obj.insert("ask");
    obj.insert("bade");*/
    //HashTable<int> obj = {1,2,3,4,5,6,7};
    HashTable<int> obj(10);
    obj.insert(20);
    obj.insert(10);
    obj.insert(3);
    //obj.swap(obj2);
    //std::cout << obj.contains(3);
    //std::cout << obj.size();
    //std::cout << obj.count(10);
    //std::cout << obj.at(4);
    //std::cout<<obj.size();
    //HashTable<int> obj2(obj);
    obj.print();
    /*std::cout << "          ";
    obj2.print();*/
}


