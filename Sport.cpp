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
#include "Sport.h"
#include "City.h"


#include<fstream>
#include<iostream>
using namespace std;



template <class T>
void Sport<T>::Display()
{
    
    //Load Sort List
    //////////////////////////////////////////////////////////////////////////////////
    LinkedList<string> list;
    int b;
    string Cname1 , KeyWord1, KeyWordType1, orginalword1;
    ifstream theFile1;
    
     theFile1.open("Sport.txt");
     if(theFile1.fail())
     cout << "      " << endl;
     while(theFile1 >> b >> Cname1 >> KeyWord1)
     {
     
     list.insertAttraction(b, Cname1, KeyWord1);
     
     
     }
    
    
    //Load City List
    ////////////////////////////////////////////////////////////////////////////////////
    
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
    
    //Load The Position of the city
    ////////////////////////////////////////////////////////////////////////////////
    int m;
    int f;
    ifstream ff;
    ff.open("FFF.txt");
    ff >> f;
      m = f;
  

    /////////////////////////////////////////////////////////////////////////////////

    
    bool prevent = false;
    do
    {
        
        
        
        if(m <= l.getLength() && m > 0)
        {
            
            prevent = true;
            
             cout<<endl;
             cout<<"             ######################################"<<endl;
             cout<<"             ||                                  ||"<<endl;
             cout<<"             ||      ID  |  Attraction Name      ||"<<endl;
             for(int i = 1 ; i <= list.getLength(); i++)
             {
             if(l.getEntry(m) == list.getKeyWord(i))
             {
             cout<<"                     "<<i<<".  |  "<<list.getEntry(i)<<endl;
             }
             
             }
             
             cout<<"             ||          |                       ||"<<endl;
             cout<<"             ||==================================||"<<endl;
             
             cout<<"             ||       Help Choice                ||\n"<<endl;
             cout<<"             ||                                  ||\n";
             cout<<"             ||     111. |   Back                ||\n";
             cout<<"             ||          |                       ||"<<endl;
             cout<<"             ######################################"<<endl;
         

    
        }
        else
        {
            cout<<endl;
            cout<<"        Invaild Input...please try again "<<endl;
           
            
        }
        
    }while(prevent != true);
    
    int r;
    cout<<"               Enter ID ";
    cin >> r;
    // Save the poisition of the attraction , cuz it is needed in other functions
    ////////////////////////////////////////////////////////
    ofstream RR;
    RR.open("RRR.txt");
    RR << r ;
    RR.close();
    /////////////////////////////////////////////////////////
    LastInformation();
    
}



template <class T>
void Sport<T>::LastInformation()
{
    
     // Load Sport List
    /////////////////////////////////////////////////////////////////////////
    LinkedList<string> list;
    int b;
    string Cname1 , KeyWord1, KeyWordType1, orginalword1;
    ifstream theFile1;
    
    theFile1.open("Sport.txt");
    if(theFile1.fail())
        cout << "      " << endl;
    while(theFile1 >> b >> Cname1 >> KeyWord1)
    {
        
        list.insertAttraction(b, Cname1, KeyWord1);
        
        
    }
    
    // Load City List
    /////////////////////////////////////////////////////////////////////////
    
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
    
    
    // Load Sport Information List
    //////////////////////////////////////////////////////////////////////
    
    LinkedList<T> omran;
    string Cname3 , KeyWord3, KeyWordType3, orginalword3;
    
    ifstream theFile3;
    theFile3.open("Omran.txt");
    if(theFile3.fail())
        cout<<"Can not"<<endl;
    while(theFile3 >> a , getline(theFile3 , Cname3))
    {
        
        omran.insert(a, Cname3);
        
    }
    theFile3.close();
    
    
    LinkedList<T> ferna;
    string Cname4 , KeyWord4, KeyWordType4, orginalword4;
    
    ifstream theFile4;
    theFile4.open("ferna.txt");
    if(theFile4.fail())
        cout<<" can not "<<endl;
    while(theFile4 >> a >> KeyWord4 >> KeyWordType4)
    {
        
        ferna.insertAttraction(a, KeyWord4 , KeyWordType4);
        
    }
    theFile4.close();
    
    
    
    /////////////////////////////////////////////////////////////////////////////////
    
    int m;
    int f;
    ifstream ff;
    ff.open("FFF.txt");
    ff >> f;
    m = f;
    
    
    int r;
    int v;
    ifstream vv;
    vv.open("RRR.txt");
    vv >> v;
    r = v;
  
    //////////////////////////////////////////////////////////////////////////////
   
    
    
    bool prevent2 = false;
    
    do{
        cout<<endl;
    
        if(r == 111 || r > omran.getLength())
        {
            prevent2 = true;
            
             if(r == 111)
            {
                

                
                City<T> c;
                c.Menu2();
            }
            
            else{
                cout<<endl;
                cout<<"      Ivaild Input....please try again "<<endl;
                cin.ignore();
                cin.get();
                Display();
            }
            
        }
        
        
        else if(list.getKeyWord(r) == l.getEntry(m))
        {
            prevent2 = true;
            if(r <= omran.getLength())
            {
                
                for(int i = 1 ; i <= omran.getLength(); i++)
                {
                    if(list.getEntry(r) == ferna.getEntry(i) && ferna.getKeyWord(i) == l.getEntry(m))
                    {
                        cout<<"      "<<omran.getEntry(i)<<endl;
                        cout<<"        Press enter to return \n";
                        cin.ignore();
                        cin.get();
                        Display();
                    
                    }
                    
                    else{
                        cout<<"        There is no Information at this moment\n";
                        Display();
                    }

                
               }
                
            }
        }
        else
        {
            
            cout<<"         Ivaild Input....please try again "<<endl;
             prevent2 = true;
            Display();
        }
        
    }while (prevent2 != true) ;
   
    cout<<"                There is no avaliable invormation at this moment\n";
    cout<<"                Please enter 1 to return ";
    
    int y;
    do{
        
        cin >> y;
        if(y == 1)
        {
            Display();
            
        }
        else{
            cout<<"       Invail Input....Please try again";
        }
        
    }while(y != 1);
}


