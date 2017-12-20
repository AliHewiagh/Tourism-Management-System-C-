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



#ifndef __pro__LinkedInterFace__
#define __pro__LinkedInterFace__

template<class T>
class LinkedInterFace
{
public:
    
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool insert(int newPosition, const T& newEntry)=0;
    virtual bool insertAttraction(int newPosition, const T& newEntry, const T& KeyWord)=0;
    virtual bool insertAttractionType(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord)=0;
    virtual bool insertAttractionInfo(int newPosition, const T& newEntry, const T& KeyWordType, const T& OrginalWord, const T& Info)=0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual T getEntry(int position) const = 0;
    virtual void setEntry(int position, const T& newEntry) = 0;
};
#endif /* defined(__pro__LinkedInterFace__) */
