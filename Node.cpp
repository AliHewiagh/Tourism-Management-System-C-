/*************************************
 Program: Tourism Information System
 Course: OOPD
 Year: 2016/02 Trimester 2
 Name: ALI OMRAN ALI HEWAIGH
 ID:  1141327922
 Lecture: TC101
 Lab: TT01
 Email: alihewaigh@gmail.com.com
 Phone: 011-23159383
 *************************************/

#include "Node.h"
#include<iostream>
using namespace std;


template<class T>
Node<T>::Node() : next(nullptr)
{
} // end default constructor



template<class T>
Node<T>::Node(const T& anItem) : item(anItem), next(nullptr)
{
} // end constructor



template<class T>
Node<T>::Node(const T& anItem, const T& KeyWord) : item(anItem), next(nullptr), KeyWord(KeyWord){
} // end constructor


template<class T>
Node<T>::Node(const T& anItem , const T& KeyWordType, const T& OrginalWord) :
item(anItem), next(nullptr), KeyWordType(KeyWordType), OrginalWord(OrginalWord)
{
} // end constructor


template<class T>
Node<T>::Node(const T& anItem , const T& KeyWordType, const T& OrginalWord, const T& Info) :
item(anItem), next(nullptr), KeyWordType(KeyWordType), OrginalWord(OrginalWord), Info(Info)
{
} // end constructor


template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr) :
item(anItem), next(nextNodePtr)
{
} // end constructor



template<class T>
void Node<T>::setItem(const T& anItem)
{
    item = anItem;
} // end setItem

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
    next = nextNodePtr;
} // end setNext

template<class T>
void Node<T>::setKeyWord(const T& KeyWord)
{
    
    this->KeyWord=KeyWord;
    
}


template<class T>
void Node<T>::setKeyWordType(const T& KeyWordType)
{
    
    this->KeyWordType=KeyWordType;
    
}


template<class T>
void Node<T>::setOrginalWord(const T& OrginalWord)
{
    
    this->OrginalWord=OrginalWord;
    
}

template<class T>
void Node<T>::setInfo(const T& Info)
{
    
    this->Info=Info;
    
}

template<class T>
T Node<T>::getItem() const
{
    return item;
} // end getItem

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
} // end getNext


template<class T>
T Node<T>::getKeyWord() const
{
    
    return KeyWord;
    
    
}

template<class T>
T Node<T>::getKeyWordTypee() const
{
    
    return KeyWordType;
    
    
}

template<class T>
T Node<T>::getOrginalWord() const
{
    
    return OrginalWord;
    
    
}


template<class T>
T Node<T>::getInfo() const
{
    
    return Info;
    
    
}

