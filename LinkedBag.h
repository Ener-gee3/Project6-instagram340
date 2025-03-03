// LinkedBag.h

#pragma once
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"
#include <cstddef>
#include <vector>

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node
    int itemCount;           // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
    virtual ~LinkedBag();                       // Destructor

    // Assignment 2 functions:
    bool append(const ItemType& newEntry);
    Node<ItemType>* findKthItem(const int& indexK) const;

    // Standard BagInterface methods:
    int getCurrentSize() const override;
    bool isEmpty() const override;
    bool add(const ItemType& newEntry) override;
    bool remove(const ItemType& anEntry) override;
    void clear() override;
    bool contains(const ItemType& anEntry) const override;
    int getFrequencyOf(const ItemType& anEntry) const override;
    std::vector<ItemType> toVector() const override;
};

//
// Implementation of LinkedBag below (kept in header for templates):
//
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original bag is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;     // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();    // Advance original-chain pointer

        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); // Flag end of chain
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
    clear();
}

template<class ItemType>
bool LinkedBag<ItemType>::append(const ItemType& newEntry)
{
    Node<ItemType>* newNode = new Node<ItemType>(newEntry);
    if (headPtr == nullptr) {
        // If list is empty, make new node the head
        headPtr = newNode;
    }
    else {
        // Otherwise traverse to the end
        Node<ItemType>* curPtr = headPtr;
        while (curPtr->getNext() != nullptr) {
            curPtr = curPtr->getNext();
        }
        // Link in the new node
        curPtr->setNext(newNode);
    }
    itemCount++;
    return true;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::findKthItem(const int& indexK) const
{
    if (indexK <= 0 || indexK > itemCount) {
        return nullptr;
    }
    Node<ItemType>* curPtr = headPtr;
    for (int i = 1; i < indexK; i++) {
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
    // Add to beginning of chain:
    Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr);
    headPtr = nextNodePtr;
    itemCount++;
    return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = (!isEmpty() && (entryNodePtr != nullptr));
    if (canRemoveItem) {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
    }
    return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    }
    itemCount = 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
            frequency++;
        counter++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    return bagContents;
}

// private helper
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
    Node<ItemType>* curPtr = headPtr;
    bool found = false;
    while (!found && (curPtr != nullptr))
    {
        if (curPtr->getItem() == target)
            found = true;
        else
            curPtr = curPtr->getNext();
    }
    return curPtr;
}

#endif
