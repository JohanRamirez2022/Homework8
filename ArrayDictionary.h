#ifndef ARRAY_DICTIONARY
#define ARRAY_DICTIONARY

#include "dictionary.h"
#include "arraylist.h"
#include "linkedlist.h"
#include "entry.h"
#include <iostream>
#include <cstring>

using namespace std;

template<class KeyType, class ValueType> 
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType>{ 
private:
    static const int HASHGROUPS = 1000;
    int hash(const KeyType& key) const;
    LinkedList<Entry<KeyType, ValueType>> table[HASHGROUPS];

public: 
    ArrayDictionary();
    bool isEmpty() const; 
    int getNumberOfEntries() const;
    bool add(const KeyType& newKey, const ValueType& newValue); 
    bool remove(const KeyType& targetKey); 
    void clear(); 
    bool contains(const KeyType& targetKey) const;
    ValueType getValue(const KeyType& targetKey) const;
    ~ArrayDictionary() {}
    
};


#include "ArrayDictionary.cpp"
#endif