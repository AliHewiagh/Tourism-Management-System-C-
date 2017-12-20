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


#ifndef __pro__Node__
#define __pro__Node__



template<class T>
class Node
{
private:
    T        item; // A data item
    Node<T>* next; // Pointer to next node
    T        KeyWord;
    T        KeyWordType;
    T        OrginalWord;
    T        Info;
public:
    Node();
    Node(const T& anItem);
    Node(const T& anItem, const T& KeyWord);
    Node(const T& anItem, const T& KeyWordType, const T& OrginalWord);
    Node(const T& anItem, const T& KeyWordType, const T& OrginalWord,const T& Info );
    Node(const T& anItem, Node<T>* nextNodePtr);
    void setItem(const T& anItem);
    void setNext(Node<T>* nextNodePtr);
    void setKeyWord(const T& KeyWord);
    void setKeyWordType(const T& KeyWordType);
    void setOrginalWord(const T& OrginalWord);
    void setInfo(const T& Info);
    T getItem() const ;
    Node<T>* getNext() const ;
    T getKeyWord() const;
    T getKeyWordTypee() const;
    T getOrginalWord() const;
    T getInfo() const;
    
}; // end Node1


#endif /* defined(__pro__Node__) */
