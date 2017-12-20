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
#ifndef __Assignment2__Sightseeing__
#define __Assignment2__Sightseeing__

#include "Attraction.h"

template<class T>
class Sightseeing : public Attraction<T>
{
public:
    
    void Display();
    void LastInformation();
};


#endif /* defined(__Assignment2__Sightseeing__) */
