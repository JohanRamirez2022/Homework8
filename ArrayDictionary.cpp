#include "ArrayDictionary.h"

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary()
{
    for (int i = 0; i < HASHGROUPS; i++)
    {
        table[i] = LinkedList<Entry<KeyType, ValueType>>();
    }
}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::hash(const KeyType& targetKey) const
{
    return targetKey % HASHGROUPS;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const
{
    int sum;
    for (int i = 0; i < HASHGROUPS; i++)
    {
        sum += table[i].getLength();
    }
    if (!sum)
    {
        return true;
    }
    return false;
}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const
{
    int sum;
    for (int i = 0; i < HASHGROUPS; i++)
    {
        sum += table[i].getLength();
    }
    return sum;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue)
{   
    Entry<KeyType, ValueType> entry(newKey, newValue);

    int hashValue = hash(newKey);
    auto& list = table[hashValue];
    int size = list.getLength();

    bool keyExists = false;

    list.insert(size, entry);

    return true;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& targetKey)
{
    int hashValue = hash(targetKey);
    auto& list = table[hashValue];

    for (int i = 0; i < list.getLength(); i++)
    {
        if (list.getEntry(i).getKey() == targetKey)
        {
            list.remove(i);
            return true;
        }
    }
    return false;
}

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear()
{
    for (int i = 0; i < HASHGROUPS; i++)
        {
            table[i].clear();
        }
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const
{
    int hashValue = hash(targetKey);
    const auto& list = table[hashValue];

    for (int i = 0; i < list.getLength(); i++)
    {
        if (list.getEntry(i).getKey() == targetKey)
        {
            return true;
        }
    }
    return false;
}

template <class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const
{
    int hashValue = hash(targetKey);
    auto& list = table[hashValue];
        for (int i = 0; i < list.getLength(); i++)
        {
            if (list.getEntry(i).getKey() == targetKey)
            return list.getEntry(i).getValue();
        }
        throw "Cannot locate Item.";
}