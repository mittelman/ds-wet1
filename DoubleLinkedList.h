/****************************************************************************/
/*                                                                          */
/* DoubleLinkedList template class implementation                           */
/*                                                                          */
/****************************************************************************/

#ifndef _234218_WET1_DOUBLE_LINKED_LIST_H_
#define _234218_WET1_DOUBLE_LINKED_LIST_H_

#include "library1.h"


template<typename ValueType>
class DoubleLinkedList {
public:
    // Constructor - Creates a new empty list
    // Time complexity: O(1)
    DoubleLinkedList() : mHead(NULL), mSize(0) {}

    // Destructor
    // Time complexity: O(k) where k is the list's length
    ~DoubleLinkedList() {
        // Free all nodes
        while (mHead) {
            mHead = current->next;
            // Free data
            delete current->data;
            // Free the node struct itself
            delete current;
            current = mhead;
        }
    }

    // Insert an element as the new first element
    // Time complexity: O(1)
    // Throws bad_alloc on allocation error
    void insertFront(const ValueType& elem) {
        // Allocate a new node
        Node* node = new Node;

        // Allocate a copy of elem, to keep in our node
        try {
            node->data = new ValueType(elem);
        } catch (const bad_alloc& e) {
            delete node;
            throw;
        }

        node->next = mHead;
        node->prev = NULL;

        // Insert the new node into the list and update mSize accordingly
        mHead = node;
        mSize++;
    }

    // Get the first element
    // Time complexity: O(1)
    // Throws NoSuchNodeException
    ValueType* getFront() const {
        if (isEmpty()) {
            throw NoSuchNodeException();
        }
        return mHead->data;
    }

    // Get the first element
    // Time complexity: O(1)
    unsigned int getSize() const {
        return mSize;
    }

    // Get the first element
    // Time complexity: O(1)
    bool isEmpty() const {
        return (mSize == 0);
    }

    // Not needed for this exercise
    //void remove(const ValueType& elem);

    // Get the value of the first node matching condition. The extra parameter
    // is sent to condition on execution.
    // (Condition should receive ValueType* and return true of false)
    // Time complexity: O(k) where k is the list's length
    // Throws NoSuchNodeException if no node matching the condition is found
    template<typename Condition>
    ValueType* getDataByPredicate(const Condition& condition,
            void* extra) const {

        // Iterate over all nodes until one matches the condition
        Node* p = head;
        while (p) {
            if (condition(p->data, extra)) {
                // Found it !
                return p->data;
            }
            p = p->next;
        }

        throw NoSuchNodeException();
    }


    // Exception classes
    class NoSuchNodeException {};

protected:
    struct Node {
        ValueType* data;
        Node* next;
        Node* prev;
    };

    Node* mHead;
    unsigned int mSize;
};

#endif    /* _234218_WET1_DOUBLE_LINKED_LIST_H_ */
