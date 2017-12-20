
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
#include "HistoricalPlaces.h"

#include "LinkedList.h"
#include "City.h"

#include<fstream>
#include<iostream>

template <class T>
void HistoricalPlaces<T>::Display()
{
    
    
    //Load HistoricalPlaces List
    /////////////////////////////////////////////////////////
    LinkedList<string> list;
    int b;
    string Cname1 , KeyWord1, KeyWordType1, orginalword1;
   
    ifstream theFile1;
    
    
    theFile1.open("HistoricalPlaces.txt");
    if(theFile1.fail())
        cout << "      " << endl;
    while(theFile1 >> b >> Cname1 >> KeyWord1)
    {
        
        list.insertAttraction(b, Cname1, KeyWord1);
        
        
    }
    
    //Load City List
    /////////////////////////////////////////////////////////
    
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
    

    /////////////////////////////////////////////////////////
    int m;
    int f;
    ifstream ff;
    ff.open("FFF.txt");
    ff >> f;
    m = f;
    
    

    /////////////////////////////////////////////////////////
    
    
    
    
    
    bool prevent = false;
    do
    {
        
        
        if(m <= l.getLength() && m > 0)
        {
            
            prevent = true;
            
            cout<<endl;
            cout<<"         ######################################"<<endl;
            cout<<"         ||                                  ||"<<endl;
            cout<<"         ||      ID  |  Attraction Name      ||"<<endl;
            for(int i = 1 ; i <= list.getLength(); i++)
            {
                if(l.getEntry(m) == list.getKeyWord(i))
                {
                    cout<<"                  "<<i<<". |  "<<list.getEntry(i)<<endl;
                }
                
            }
            
            cout<<"         ||          |                       ||"<<endl;
            cout<<"         ||==================================||"<<endl;
            
            cout<<"         ||       Help Choice                ||\n"<<endl;
            cout<<"         ||                                  ||\n";
            cout<<"         ||     111. |   Back                ||\n";
            cout<<"         ||          |                       ||"<<endl;
            cout<<"         ######################################"<<endl;
            
            
            
            
        }
        else
        {
            
            cout<<"        Invaild Input...please try again "<<endl;
        }
        
    }while(prevent != true);
    
    int r;
    cout<<"               Enter ID ";
    cin >> r;
    // Save Teh position of the attraction cuz it is needed in other functions
    ofstream RR;
    RR.open("GGG.txt");
    RR << r ;
    RR.close();
   
    
    LastInformation();
    
}

template <class T>
void HistoricalPlaces<T>::LastInformation()
{
    
    
    //Load HistoricalPlaces List
    /////////////////////////////////////////////////////////
    LinkedList<string> list;
    int b;
    string Cname1 , KeyWord1, KeyWordType1, orginalword1;
    ifstream theFile1;
    
    theFile1.open("HistoricalPlaces.txt");
    if(theFile1.fail())
        cout << "      " << endl;
    while(theFile1 >> b >> Cname1 >> KeyWord1)
    {
        
        list.insertAttraction(b, Cname1, KeyWord1);
        
        
    }
    
    //Load City List
    /////////////////////////////////////////////////////////
    
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
    
    //Load HistoricalPlaces information List
    /////////////////////////////////////////////////////////
    
   
    LinkedList<T> info;
    string Cname3 , KeyWord3, KeyWordType3, orginalword3;
    ifstream theFile3;
    theFile3.open("HistoricalPlacesInformation.txt");
    if(theFile3.fail())
        cout<<"   "<<endl;
    while(theFile3 >> a , getline(theFile3 , Cname3))
    {
        
        info.insert(a, Cname3);
        
    }
    theFile3.close();
    
    
    
    LinkedList<T> ferna;
    string Cname4 , KeyWord4, KeyWordType4, orginalword4;
    ifstream theFile4;
    theFile4.open("HistoricalPlacesTypes.txt");
    if(theFile4.fail())
        cout<<"    "<<endl;
    while(theFile4 >> a >> KeyWord4 >> KeyWordType4)
    {
        
        ferna.insertAttraction(a, KeyWord4 , KeyWordType4);
        
    }
    theFile4.close();
    
    
    ////////////////////////////////////////////////////////////
    
    int m;
    int f;
    ifstream ff;
    ff.open("FFF.txt");
    ff >> f;
    m = f;
    
    
    
    int r;
    int v;
    ifstream vv;
    vv.open("GGG.txt");
    vv >> v;
    r = v;
    
   
   
   

    ////////////////////////////////////////////////////////////
    
    
    
    bool prevent2 = false;
    
    
    do{
        
        cout<<endl;
        
        if(r == 111 || r > info.getLength())
        {
            
            if(r == 111)
            {
                prevent2 = true;

                
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
            if(r <= info.getLength())
            {
                
                for(int i = 1 ; i <= info.getLength(); i++)
                {
                    if(list.getEntry(r) == ferna.getEntry(i) && ferna.getKeyWord(i) == l.getEntry(m))
                    {
                        cout<<"      "<<info.getEntry(i)<<endl;
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


