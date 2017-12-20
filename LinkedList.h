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
#ifndef __pro__LinkedList__
#define __pro__LinkedList__

#include "Node.h"
#include "LinkedInterFace.h"
//#include "city.h"

void mainMenu();


template<class T>
class LinkedList : public LinkedInterFace<T>

{
private:
    Node<T>* headPtr;
    int itemCount;
    Node<T>* getNodeAt(int position) const;
    
    
public:
    LinkedList();
    LinkedList(const LinkedList<T>& aList);
    virtual ~LinkedList();
    
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const T& newEntry);
    bool insertAttraction(int newPosition, const T& newEntry, const T& KeyWord);
    bool insertAttractionType(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord );
    bool insertAttractionInfo(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord , const T& Info);
    bool remove(int position);
    void clear();
    T getEntry(int position) const;
    T getKeyWord(int position) const;
    T getKeyWordType(int position) const;
    T getOrginalWord(int position) const;
    T getInfo(int position) const;
    void setEntry(int position, const T& newEntry);
    //void SecondMenue();
    //void AttractionSetting();
    
    
};

#endif /* defined(__pro__LinkedList__) */
