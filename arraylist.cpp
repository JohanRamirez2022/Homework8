#include "arraylist.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0){}

template<class ItemType>
ArrayList<ItemType>::ArrayList(const ArrayList<ItemType>& aList){
	itemCount = aList.itemCount;
	maxCount = aList.maxCount;
	
	for(int pos = 1; pos <= itemCount; pos++){
		items[pos] = aList.items[pos];
	}
}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const{
	return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const{
	return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry){
	bool ableToInsert = (newPosition >= 1) &&
                            (newPosition <= itemCount + 1) &&
                            (itemCount < maxCount);
	if(ableToInsert){
		for(int pos = itemCount + 1; pos > newPosition; pos--){
            		items[pos] = items[pos - 1];
        	}
        	items[newPosition] = newEntry;
		itemCount++;
	} 
	return ableToInsert;
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position){
	bool ableToRemove = (position >= 1) && (position <= itemCount);

	if(ableToRemove){
        	for(int pos = position; pos < itemCount; pos++){
            		items[pos] = items[pos + 1];
        	}
        	itemCount--;
	}
	return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear(){
	itemCount = 0;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);

	if (ableToGet){
		return items[position];
	} 
	throw "Item not found";
} 

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry){
	bool ableToReplace = (position >= 1) && (position <= itemCount);

	if (ableToReplace){
        	ItemType oldEntry = items[position];
        	items[position] = newEntry;
        	return oldEntry;
	} 
	throw "Item not found";
}
