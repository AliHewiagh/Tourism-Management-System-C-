/*************************************
 Program: Tourism Information System
 Course: OOPDS
 Year: 2016/02 Trimester 2
 Name: ALI OMRAN ALI HEWAIGH
 ID:  1141327922
 Lecture: TC101
 Lab: TT01
 Email: alihewaigh@gmail.com.com
 Phone: 011-23159383
 *************************************/

#include "LinkedList.h"
//#include "City.h"


#include <fstream>
#include<iostream>

using namespace std;

template<class T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList) : itemCount(aList.itemCount)
{
    Node<T>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
    
    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else
    {
        // Copy first node
        headPtr = new Node<T>();
        headPtr->setItem(origChainPtr->getItem());
        
        // Copy remaining nodes
        Node<T>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            T nextItem = origChainPtr->getItem();
            
            // Create a new node containing the next item
            Node<T>* newNodePtr = new Node<T>(nextItem);
            
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while
        
        newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor

template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
    return itemCount;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int newPosition, const T& newEntry)
{
    
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry);
        
        
        
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<T>* prevPtr = getNodeAt(newPosition - 1);
            
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if
        
        itemCount++;  // Increase count of entries
    }  // end if
    
    return ableToInsert;
}  // end insert


template<class T>
bool LinkedList<T>::insertAttraction(int newPosition, const T& newEntry, const T& KeyWord)
{
    
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry, KeyWord);
        
        
        
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<T>* prevPtr = getNodeAt(newPosition - 1);
            
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if
        
        itemCount++;  // Increase count of entries
    }  // end if
    
    return ableToInsert;
}  // end insert



template<class T>
bool LinkedList<T>::insertAttractionType(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord)
{
    
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry , KeyWordType, OrginalWord);
        
        
        
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<T>* prevPtr = getNodeAt(newPosition - 1);
            
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if
        
        itemCount++;  // Increase count of entries
    }  // end if
    
    return ableToInsert;
}  // end inser



template<class T>
bool LinkedList<T>::insertAttractionInfo(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord, const T& Info)
{
    
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry , KeyWordType, OrginalWord, Info);
        
        
        
        // Attach new node to chain
        if (newPosition == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<T>* prevPtr = getNodeAt(newPosition - 1);
            
            // Insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  // end if
        
        itemCount++;  // Increase count of entries
    }  // end if
    
    return ableToInsert;
}  // end inser

template<class T>
bool LinkedList<T>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<T>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            Node<T>* prevPtr = getNodeAt(position - 1);
            
            // Point to node to delete
            curPtr = prevPtr->getNext();
            
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if
        
        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        
        itemCount--;  // Decrease count of entries
    }  // end if
    
    return ableToRemove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
        
    }
    else
    {
        cout<<" "<<endl;
        exit(0);
    }
    
}

template<class T>
T LinkedList<T>::getKeyWord(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getKeyWord();
        
    }
    else
    {
        cout<<" "<<endl;
        exit(0);
    }
    
}

template<class T>
T LinkedList<T>::getKeyWordType(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getKeyWordTypee();
        
    }
    else
    {
        cout<<" "<<endl;
        exit(0);
    }
    
}


template<class T>
T LinkedList<T>::getOrginalWord(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getOrginalWord();
        
    }
    else
    {
        cout<<" "<<endl;
        exit(0);
    }
    
}


template<class T>
T LinkedList<T>::getInfo(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getInfo();
        
    }
    else
    {
        cout<<" "<<endl;
        exit(0);
    }
    
}



template<class T>
void LinkedList<T>::setEntry(int position, const T& newEntry)
{
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else
    {
        cout<<"wrong"<<endl;
    }  // end if
}  // end setEntry




template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
    Node<T>* curPtr = headPtr;
    
    // Debugging check of precondition
    if( (position >= 1) && (position <= itemCount) )
    {
        // Count from the beginning of the chain
        for (int skip = 1; skip < position; skip++)
            curPtr = curPtr->getNext();
    }
    return curPtr;
    
}
