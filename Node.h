// Node.h

#pragma once
#ifndef NODE_H
#define NODE_H

// Forward-declare classes if needed; for a templated Node, it’s often simplest to
// just include them inline or rely on the final includes in .cpp files.

template<class ItemType>
class Node {
private:
    ItemType item;               // A data item
    Node<ItemType>* next;        // Pointer to next node

public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    void setNext(Node<ItemType>* nextNodePtr);
    Node<ItemType>* getNext() const;
};

// Inline implementations of Node class

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) {}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem)
    : item(anItem), next(nullptr) {}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
    : item(anItem), next(nextNodePtr) {}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}

#endif // NODE_H
