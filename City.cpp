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
#include "City.h"
#include "LinkedList.h"
#include "Attraction.h"
#include "Sport.h"
#include "Culture.h"
#include "Sightseeing.h"
#include "HistoricalPlaces.h"


void InterFace();
#include<fstream>
#include<iostream>
using namespace std;

    


template<class T>
void City<T>::Menu()
{
    
    //Load City List
    /////////////////////////////////////////////////////////////////////////////////
    LinkedList<string> l;
    int a;
    string Cname , KeyWord, KeyWordType, orginalword;
    ofstream fout;
    ifstream theFile;
    
    theFile.open("City.txt");
    if(theFile.fail())
        cout << "      " << endl;
    while(theFile >> a >> Cname)
    {
        
        l.insert(a, Cname);
        
        
    }
    fout.open("City.txt");
    for(int i = 1 ; i <= l.getLength();i++)
    {
        fout<< i <<l.getEntry(i)<<endl;
        
    }
    fout.close();
    /////////////////////////////////////////////////////////////////////////////////
    
        
    cout<<"            ##################################"<<endl;
    for(int i = 1 ; i <= l.getLength(); i++)
    {
        cout<<"            ||                              || "<<endl;
        cout<<"                    "<<i<<". "<<l.getEntry(i)<<endl;
        
        
    }
    cout<<"            ||                              ||"<<endl;
    cout<<"            ##################################"<<endl;
    cout<<"            ||                              ||"<<endl;
    
    cout<<"            ||    111. Back                 ||"<<endl;
    cout<<"            ||                              ||"<<endl;
    cout<<"            ##################################"<<endl;
    
    
    cout<<endl;
    int m;
    cout<<"            Choose a city ";
    cin >> m;
   //////////////////////////////////////////////
    ofstream ff;
    ff.open("FFF.txt");      /// Save the postirion of a city, Cuz it is needed in other functions
    ff << m ;
    ff.close();
    ////////////////////////////////////////////
    if(m == 111)
    {
       InterFace();
        
    }
    else{
    Menu2();
    }
}


template<class T>
void City<T>::Menu2()
{
    
    // Load City List
     /////////////////////////////////////////////////////////////////////////////////
    
    LinkedList<string> l;
    int a;
    string Cname , KeyWord, KeyWordType, orginalword;
    ofstream fout;
    ifstream theFile;
    
    theFile.open("City.txt");
    if(theFile.fail())
        cout << "      " << endl;
    while(theFile >> a >> Cname)
    {
        
        l.insert(a, Cname);
        
        
    }
    
    //Load The city position
 /////////////////////////////////////////////////////////////////////////////////
    int m;
    int f;
    ifstream ff;
    ff.open("FFF.txt");
    ff >> f;
    m = f;
   ////////////////////////////////
    
    
    
    ///////////////////////////////  
    Sport<T> spo;
    Culture<T> cul;
    Sightseeing<T> sig;
    HistoricalPlaces<T> his;
    
    Attraction<T> *attra1 = &spo;
    Attraction<T> *attra2 = &cul;
    Attraction<T> *attra3 = &sig;
    Attraction<T> *attra4 = &his;
    
    
    
    bool prevent2 = false;
   
    do{
        
        
        if(m <= l.getLength())
        {
             prevent2 = true;
            
            char choice;
            do{
                
                cout<<endl<<endl;
                cout<<"         ###########################################"<<endl;
                cout<<"         ||                                       ||"<<endl;
                cout<<"         ||      ID    |   Attraction Name        ||"<<endl;
                cout<<"                                                    "<<endl;
                cout<<"                                                    "<<endl;
                cout<<"         ||       1.   |   Sport                  ||"<<endl;
                cout<<"         ||       2.   |   Culture                ||"<<endl;
                cout<<"         ||       3.   |   Sightseeing            ||"<<endl;
                cout<<"         ||       4.   |   Historical Places      ||"<<endl;
                cout<<"                                                    "<<endl;
                cout<<"         ||       5.   |   Back                   ||"<<endl;
                cout<<"         ||            |                          ||"<<endl;
                cout<<"         ||                                       ||"<<endl;
                cout<<"         ###########################################"<<endl;
                cout<<endl<<endl;
                cout<<"      Please enter the ID ==> ";
                cin >> choice;
                cout<<endl;
                switch(choice)
                {
                    case '1':
                        attra1->Display();
                        break;
                    case '2':
                        attra2->Display();
                        break;
                    case '3':
                        attra3->Display();
                        break;
                    case '4':
                        attra4->Display();
                        break;
                    case '5':
                        break;
                    default: cout<<"Invaild Input....please try again ";
                        
                        
                }
                
            }while (choice != '5');
            
        }
        else{
            
            cout<<"     Ivaild Input please try again...press enter to return "<<endl;
            cin.ignore();
            cin.get();
            Menu();
            
        }
        
        
    }while(prevent2 != true);
    Menu();

    
    
    
    
    
    
}





