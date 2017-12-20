
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
 
 I used Xcode to complile the prohram
 *************************************/
#include <fstream>
#include<iostream>
using namespace std;

#include "City.h"
#include "City.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Node.cpp"
#include "Attraction.cpp"
#include "Sport.cpp"
#include "Culture.cpp"
#include "Sightseeing.cpp"
#include "HistoricalPlaces.cpp"



void InterFace();
void Admin();
void SettingCity();
void SettingSport();
void SettingCulture();
void SettingSightseeing();
void SettingHistoricalPlaces();
void SettingSportInfo();
void SettingCultureInfo();
void SettingSightseeingInfo();
void SettingHistoricalPlacesInfo();




int main()
{
    
    InterFace();
    
    return 0;
    
}




void InterFace()
{
    City<string> t;
    char choice;
    
    do{
        cout<<endl;
        cout<<"         <<<<          Main Menu         >>>>\n\n";
        cout<<"       ###############################################\n";
        cout<<"       ###                                         ###\n";
        cout<<"       ###    1.      User                         ###\n";
        cout<<"       ###    2.      Admin (Password = 123)       ###\n";
        cout<<"       ###    3.      Exit                         ###\n";
        cout<<"       ###                                         ###\n";
        cout<<"       ###############################################\n\n";
        
        cout<<"                Please Enter your choice ";
        cin >> choice;
        switch(choice)
        {
                
            case '1':
                t.Menu();
                break;
            case '2':
                Admin();
                break;
            case '3':
                exit(0);
                break;
            default: cout<<"Good Bye :) "<<endl;
                
        }
        
        
        
    }while (choice != '3');
    
    
}



void Admin()
{
    // The menu of the syatem adminstrator
    int password;
    cout<<"       Please enter the password --> ";
    cin >> password;
    if(password == 123)
    {
    
    
    char choice;
    
    do{
        cout<<endl;
        cout<<"<<<<                Setting Menu         >>>>\n\n";
        cout<<"         1.      Setting City Menu\n";
        cout<<"         2.      Setting Sport List\n";
        cout<<"         3.      Setting Culture List\n";;
        cout<<"         4.      Setting Sightseeing List\n";
        cout<<"         5.      Setting Historical Places List\n";
        cout<<"         6.      Setting Sport Information\n";
        cout<<"         7.      Setting Culture Information\n";
        cout<<"         8.      Setting Sightseeing Information\n";
        cout<<"         9.      Setting Historical Places Information\n";
        cout<<"         B.      Back\n\n";
        cout<<"         Please Enter your choice --> ";
        cin >> choice;
        switch(choice)
        {
                
            case '1':
                SettingCity();
                break;
            case '2':
                SettingSport();
                break;
            case '3':
                SettingCulture();
                break;
            case '4':
                SettingSightseeing();
                break;
            case '5':
                SettingHistoricalPlaces();
                break;
            case'6':
               SettingSportInfo();
                break;
            case'7':
                SettingCultureInfo();
                break;
            case '8':
                SettingSightseeingInfo();
                break;
            case '9':
                SettingHistoricalPlacesInfo();
                break;
            case 'B':
                break;
            default: cout<<"Invaild Input...please try again "<<endl;
                
        }
        
        
        
    }while (choice != 'B');
    
    //Back function
    InterFace();
    }
    else{
        cout<<"     Incorrect Password "<<endl;
        cout<<"     Please press Enter to get the main menu "<<endl;
        cin.ignore();
        cin.get();
        
       InterFace();
    }
}



// Making Changes in City menu
void SettingCity()
{
   
    ofstream fout;
    ifstream theFile;
    int a;
    string Cname;
    
    char y;
    char choice;
    LinkedList<string> ali;
    do{
        
        cout<< endl << endl;
        cout<<"             1. Add a city to the back "<<endl;
        cout<<"             2. Add a city "<<endl;
        cout<<"             3. Erase a city at specific position"<<endl;
        cout<<"             4. Erase a city specified by its name"<<endl;
        cout<<"             5. change a city "<<endl;
        cout<<"             6. Save and Load all cities From/To a file "<<endl;
        cout<<"             7. Back "<<endl;
        cout<<endl;
        cout<<"            --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch;
        
        int position;
        switch(choice)
        {
            case '1':
                cout << "      Please enter a city ==> ";
                cin >> ch;
                ali.insert(ali.getLength()+1,ch);
                break;
            case '2':
                cout << "      Please enter a city ==> ";
                cin >> ch;
                cout<<"        Please enter the position of the city ==> ";
                cin >> position;
                ali.insert(position, ch);
                break;
            case '3':
                cout << "      Please enter the position ==> ";
                cin >> position;
                ali.remove(position);
                break;
            case '4':
                cout<< "       Please enter the city name ==> ";
                cin >> ch;
                for(int i = 1 ; i <= ali.getLength(); ++i)
                {
                    
                    if(ali.getEntry(i) == ch)
                    {
                        ali.remove(i);
                        break;
                    }
                }
                break;
            case '5':
                cout<<"        If you change the city, attraction types of the city will be discarded \n";
                cout<<"        To change enter y else enter n ";
                cin >> y;
                if(y == 'y' || y =='Y')

                {
                cout<<"        Please enter the city name ==>  ";
                cin >> ch;
                cout<<"        Please enter the position of the city ==> ";
                cin >> position;
                ali.setEntry(position ,ch );
                }
                else{
                    cout<< "       No Changes \n";
                }
                break;
            case '6':
                theFile.open("City.txt");
                if(theFile.fail())
                    cout << "      " << endl;
                while(theFile >> a >> Cname)
                {
                    
                    ali.insert(a, Cname);
                    
                    
                }
                
                fout.open("City.txt");
                for(int i = 1 ; i <= ali.getLength();i++)
                {
                    fout<< i <<" "<<ali.getEntry(i)<<endl;
                    
                    
                }
               
               
                fout.close();
                
                if(ali.getLength() >= 1)
                {
                    cout << "                These are the all cities in the system :\n\n";
                    for(int i = 1 ; i <= ali.getLength();i++)
                    {
                        
                        cout<<"       "<< i <<" - "<<ali.getEntry(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"              There is no any city in the menu "<<endl;
                }
                
                break;
                
            case '7' :
                break;
           
            default: cout<<"      Invaild input...please try again\n";
                break;
                
                
                
                
                
        }
        
        
        
        
        
    }while(choice != '7');
    
    
    
    void Admin();
    
}





// Making Changes in Sport List
void SettingSport()
{
    
    
    
    
    ofstream fout1;
    ifstream theFile1;
    int a;
    string Cname;
    string KeyWord;
    char y;
    
    char choice;
    LinkedList<string> list;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add a type of sport to the back "<<endl;
        cout<<"           2. Add a type of sport using position "<<endl;
        cout<<"           3. Erase a type of sport at specific position"<<endl;
        cout<<"           4. Erase a type of sport specified by its name"<<endl;
        cout<<"           5. Change the type of attraction \n";
        cout<<"           6. Save and Load all types of sport To/From a file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword;
        string filename;
        int position;
        switch(choice)
        {
            case '1':
                cout<<"         Please enter a type of sport ";
                cin >> ch;
                cout<<"         Please enter a city of this type ";
                cin >> keyword;
                list.insertAttraction(list.getLength()+1,ch, keyword);
                break;
            case '2':
                cout << "      Please enter a type of sport ==> ";
                cin >> ch;
                cout<<"        Please enter the position of this type ==> ";
                cin >> position;
                cout<<"        Please enter a city of this type ==> ";
                cin >> keyword;
                list.insertAttraction(position, ch, keyword);
                break;
            case '3':
                cout << "     Please enter the position ==> ";
                cin >> position;
                list.remove(position);
                break;
            case '4':
                cout<< "      Please enter the type of attraction name ==> ";
                cin >> ch;
                for(int i = 1 ; i <= list.getLength(); ++i)
                {
                    
                    if(list.getEntry(i) == ch)
                    {
                        list.remove(i);
                        break;
                    }
                }
                break;
            case '5':
                cout<<"        If you change the attraction, data of the attraction will be discarded \n";
                cout<<"        To change enter y else enter n ";
                cin >> y;
                if(y == 'y' || y =='Y')
                    
                {
                    cout<<"        Please enter the new attraction type name ==>  ";
                    cin >> ch;
                    cout<<"        Please enter the position of the new attraction type ==> ";
                    cin >> position;
                    list.setEntry(position ,ch );
                }
                else{
                    cout<< "       No Changes \n";
                }
                break;
            case '6':
                theFile1.open("Sport.txt");
                if(theFile1.fail())
                    cout << "   " << endl;
                while(theFile1 >> a >> Cname >> keyword)
                {
                    
                    list.insertAttraction(a, Cname, keyword);
                    
                }
                
                fout1.open("Sport.txt");
                for(int i = 1 ; i <= list.getLength();i++)
                {
                    fout1<< i <<" "<<list.getEntry(i)<<" "<<list.getKeyWord(i)<<endl;
                }
                fout1.close();
                
                if(list.getLength() >= 1)
                {
                    cout << "              These are the all types of attraction in the system :\n";
                    for(int i = 1 ; i <= list.getLength();i++)
                    {
                        
                        cout<<"   "<< i <<"  "<<list.getEntry(i)<<"  "<<list.getKeyWord(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"            There is no any type of attraction in the system "<<endl;
                }
                
                
                break;
                
            case '7' :
                break;
            default: cout<<"         Invaild input...please try again\n";
                
        }
        
        
    }while(choice != '7');
    
    void Admin();
    
    
    
}


// Making Changes in Culture List
void SettingCulture()
{
    
    
    
    
    ofstream fout2;
    ifstream theFile2;
    int a;
    string Cname;
    string KeyWord;
    
    char y;
    char choice;
    LinkedList<string> list;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add a type of culture to the back "<<endl;
        cout<<"           2. Add a type of culture using position "<<endl;
        cout<<"           3. Erase a type of culture at specific position"<<endl;
        cout<<"           4. Erase a type of culture specified by its name"<<endl;
        cout<<"           5. Change the type of attraction               "<<endl;
        cout<<"           6. Save and Load all types of culture To/From a file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword;
        string filename;
        int position;
        switch(choice)
        {
            case '1':
                cout<<"           Please enter a type of culture ";
                cin >> ch;
                cout<<"           Please enter a city of this type ";
                cin >> keyword;
                list.insertAttraction(list.getLength()+1,ch, keyword);
                break;
            case '2':
                cout << "         Please enter a type of culture ==> ";
                cin >> ch;
                cout<<"           Please enter the position of this type ==> ";
                cin >> position;
                cout<<"           Please enter a city of this type ==> ";
                cin >> keyword;
                list.insertAttraction(position, ch, keyword);
                break;
            case '3':
                cout << "         Please enter the position ==> ";
                cin >> position;
                list.remove(position);
                break;
            case '4':
                cout<< "          Please enter the type of attraction name ==> ";
                cin >> ch;
                for(int i = 1 ; i <= list.getLength(); ++i)
                {
                    
                    if(list.getEntry(i) == ch)
                    {
                        list.remove(i);
                        break;
                    }
                }
                break;
            case '5':
                cout<<"        If you change the attraction, data of the attraction will be discarded \n";
                cout<<"        To change enter y else enter n ";
                cin >> y;
                if(y == 'y' || y =='Y')
                    
                {
                    cout<<"        Please enter the new attraction type name ==>  ";
                    cin >> ch;
                    cout<<"        Please enter the position of the new attraction type ==> ";
                    cin >> position;
                    list.setEntry(position ,ch );
                }
                else{
                    cout<< "       No Changes \n";
                }
                break;

            case '6':
                theFile2.open("Culture.txt");
                if(theFile2.fail())
                    cout << "   " << endl;
                while(theFile2 >> a >> Cname >> keyword)
                {
                    
                    list.insertAttraction(a, Cname, keyword);
                    
                }
                
                fout2.open("Culture.txt");
                for(int i = 1 ; i <= list.getLength();i++)
                {
                    fout2<< i <<" "<<list.getEntry(i)<<" "<<list.getKeyWord(i)<<endl;
                }
                fout2.close();
                
                if(list.getLength() >= 1)
                {
                    cout << "              These are the all types of attraction in the system :\n";
                    for(int i = 1 ; i <= list.getLength();i++)
                    {
                        
                        cout<<"   "<< i <<"  "<<list.getEntry(i)<<"  "<<list.getKeyWord(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no any type of attraction in the system "<<endl;
                }
                
                
                break;
                
            case '7' :
                break;
            default: cout<<"         Invaild input...please try again\n";
                
        }
        
        
    }while(choice != '7');
    
    void Admin();
    
    
    
}



// Making Changes in Sightseeing List
void SettingSightseeing()
{
    
    
    
    
    ofstream fout3;
    ifstream theFile3;
    int a;
    string Cname;
    string KeyWord;
    char y;
    
    char choice;
    LinkedList<string> list;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add a type of Sightseeing to the back "<<endl;
        cout<<"           2. Add a type of Sightseeing using position "<<endl;
        cout<<"           3. Erase a type of Sightseeing at specific position"<<endl;
        cout<<"           4. Erase a type of Sightseeing specified by its name"<<endl;
        cout<<"           5. Change the attraction type\n";
        cout<<"           6. Save and Load all types of Sightseeing To/From a file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword;
        string filename;
        int position;
        switch(choice)
        {
            case '1':
                cout<<"         Please enter a type of Sightseeing ";
                cin >> ch;
                cout<<"         Please enter a city of this type ";
                cin >> keyword;
                list.insertAttraction(list.getLength()+1,ch, keyword);
                break;
            case '2':
                cout << "      Please enter a type of Sightseeing ==> ";
                cin >> ch;
                cout<<"        Please enter the position of this type ==> ";
                cin >> position;
                cout<<"        Please enter a city of this type ==> ";
                cin >> keyword;
                list.insertAttraction(position, ch, keyword);
                break;
            case '3':
                cout << "     Please enter the position ==> ";
                cin >> position;
                list.remove(position);
                break;
            case '4':
                cout<< "      Please enter the type of attraction name ==> ";
                cin >> ch;
                for(int i = 1 ; i <= list.getLength(); ++i)
                {
                    
                    if(list.getEntry(i) == ch)
                    {
                        list.remove(i);
                        break;
                    }
                }
                break;
            case '5':
                cout<<"        If you change the attraction, data of the attraction will be discarded \n";
                cout<<"        To change enter y else enter n ";
                cin >> y;
                if(y == 'y' || y =='Y')
                    
                {
                    cout<<"        Please enter the new attraction type name ==>  ";
                    cin >> ch;
                    cout<<"        Please enter the position of the new attraction type ==> ";
                    cin >> position;
                    list.setEntry(position ,ch );
                }
                else{
                    cout<< "       No Changes \n";
                }
                break;

            case '6':
                theFile3.open("Sightseeing.txt");
                if(theFile3.fail())
                    cout << "   " << endl;
                while(theFile3 >> a >> Cname >> keyword)
                {
                    
                    list.insertAttraction(a, Cname, keyword);
                    
                }
                
                fout3.open("Sightseeing.txt");
                for(int i = 1 ; i <= list.getLength();i++)
                {
                    fout3<< i <<" "<<list.getEntry(i)<<" "<<list.getKeyWord(i)<<endl;
                }
                fout3.close();
                
                if(list.getLength() >= 1)
                {
                    cout << "              These are the all types of attraction in the system :\n";
                    for(int i = 1 ; i <= list.getLength();i++)
                    {
                        
                        cout<<"   "<< i <<"  "<<list.getEntry(i)<<"  "<<list.getKeyWord(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no any type of attraction in the system "<<endl;
                }
                
                
                break;
                
            case '7' :
                break;
            default: cout<<"         Invaild input...please try again\n";
                
        }
        
        
    }while(choice != '7');
    
    void Admin();
    
    
    
}


// Making Changes in HistoricalPlaces List
void SettingHistoricalPlaces()
{
    
    
    
    
    ofstream fout4;
    ifstream theFile4;
    int a;
    string Cname;
    string KeyWord;
    
    char y;
    char choice;
    LinkedList<string> list;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add a type of HistoricalPlaces to the back "<<endl;
        cout<<"           2. Add a type of HistoricalPlaces using position "<<endl;
        cout<<"           3. Erase a type of HistoricalPlaces at specific position"<<endl;
        cout<<"           4. Erase a type of HistoricalPlaces specified by its name"<<endl;
        cout<<"           5. Change the attraction type\n";
        cout<<"           6. Save and Load all types of HistoricalPlaces To/From a file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword;
        string filename;
        int position;
        switch(choice)
        {
            case '1':
                cout<<"         Please enter a type of HistoricalPlaces ";
                cin >> ch;
                cout<<"         Please enter a city of this type ";
                cin >> keyword;
                list.insertAttraction(list.getLength()+1,ch, keyword);
                break;
            case '2':
                cout << "      Please enter a type of HistoricalPlaces ==> ";
                cin >> ch;
                cout<<"        Please enter the position of this type ==> ";
                cin >> position;
                cout<<"        Please enter a city of this type ==> ";
                cin >> keyword;
                list.insertAttraction(position, ch, keyword);
                break;
            case '3':
                cout << "     Please enter the position ==> ";
                cin >> position;
                list.remove(position);
                break;
            case '4':
                cout<< "      Please enter the type of attraction name ==> ";
                cin >> ch;
                for(int i = 1 ; i <= list.getLength(); ++i)
                {
                    
                    if(list.getEntry(i) == ch)
                    {
                        list.remove(i);
                        break;
                    }
                }
                break;
            case '5':
                cout<<"        If you change the attraction, data of the attraction will be discarded \n";
                cout<<"        To change enter y else enter n ";
                cin >> y;
                if(y == 'y' || y =='Y')
                    
                {
                    cout<<"        Please enter the new attraction type name ==>  ";
                    cin >> ch;
                    cout<<"        Please enter the position of the new attraction type ==> ";
                    cin >> position;
                    list.setEntry(position ,ch );
                }
                else{
                    cout<< "       No Changes \n";
                }
                break;

            case '6':
                theFile4.open("HistoricalPlaces.txt");
                if(theFile4.fail())
                    cout << "   " << endl;
                while(theFile4 >> a >> Cname >> keyword)
                {
                    
                    list.insertAttraction(a, Cname, keyword);
                    
                }
                
                fout4.open("HistoricalPlaces.txt");
                for(int i = 1 ; i <= list.getLength();i++)
                {
                    fout4<< i <<" "<<list.getEntry(i)<<" "<<list.getKeyWord(i)<<endl;
                }
                fout4.close();
                
                if(list.getLength() >= 1)
                {
                    cout << "              These are the all types of attraction in the system :\n";
                    for(int i = 1 ; i <= list.getLength();i++)
                    {
                        
                        cout<<"   "<< i <<"  "<<list.getEntry(i)<<"  "<<list.getKeyWord(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no any type of attraction in the system "<<endl;
                }
                
                
                break;
                
            case '7' :
                break;
            default: cout<<"         Invaild input...please try again\n";
                
        }
        
        
    }while(choice != '7');
    
    void Admin();
    
    
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Making Changes in Sport Information List
void SettingSportInfo()
{
    
    
    cout<<"       Sport\n\n ";
    ofstream fout5;
    ifstream theFile5;
    ofstream fout55;
    ifstream theFile55;
    int a = 0;
    string Cname, KeyWord, KeyWordType;
    
    
    
    char choice;
    LinkedList<string> type;
    LinkedList<string> goo;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add information to the back "<<endl;
        cout<<"           2. Add information using a position "<<endl;
        cout<<"           3. Change the information "<<endl;
        cout<<"           4. Erase information from a specific position"<<endl;
        cout<<"           5. Save the information To a text file "<<endl;
        cout<<"           6. Load the information From a text file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword, keywordtype;
        
        
        int position;
        switch(choice)
        {
            case '1':
                  cout << "      Please enter information ==> ";
                  cin.ignore();
                  cin.clear();
                  getline(cin , ch);
                cout << "      Please enter a type of attraction of this information ==> ";
                cin >> keyword;
                cout << "      Please enter an city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(type.getLength()+1,ch);
                type.insertAttraction(type.getLength()+1, keyword, keywordtype);

                break;
            case '2':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position of this information ==> ";
                cin >> position;
                cout<<"        Please enter the attraction of this information ==> ";
                cin >> keyword;
                cout<<"        Please enter the city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(position, ch);
                type.insertAttraction(position , keyword, keywordtype);
                break;
            case '3':
                cout<<"        Please enter thw new information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position ==> ";
                cin >> position;
                goo.setEntry(position, ch);
            case '4':
                cout << "      Please enter the position ==> ";
                cin >> position;
                goo.remove(position);
                type.remove(position);
                break;
                          ///////////////////////////////////////////
            case '5':
                
                fout55.open("Omran.txt");
                for(int i = 1 ; i <= goo.getLength();i++)
                {
                    fout55 <<i<<" "<<goo.getEntry(i)<<" "<<endl;
                }
                fout55.close();
                
                fout5.open("ferna.txt");
                for(int i = 1 ; i <= type.getLength();i++)
                {
                    fout5 <<i<<" "<<type.getEntry(i)<<" "<<type.getKeyWord(i)<<endl;
                    
                }
                fout5.close();
                
                ////////////////////////////////////////////////////////////////
                
                if(goo.getLength() >= 1)
                {
                    
                    cout << "                These are the all information of attraction types in the system :\n";
                    for(int i = 1 ; i <= goo.getLength();i++)
                    {
                        
                        cout<<"         "<< i <<" - "<<goo.getEntry(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"              There is no information in the system for this attraction type "<<endl;
                }
                
                break;

            case '6':
                theFile55.open("Omran.txt");
                if(theFile55.fail())
                    cout << "   " << endl;
                while(theFile55 >> a , getline(theFile55 , Cname))
                {
                    
                    goo.insert(a, Cname);
                    
                }
                theFile55.close();
                
                theFile5.open("ferna.txt");
                if(theFile5.fail())
                    cout<<"  "<<endl;
                while(theFile5 >> a >> KeyWord >> KeyWordType)
                {
                    
                    type.insertAttraction(a, KeyWord , KeyWordType);
                    
                }
                theFile5.close();
                break;
                
            case '7' :
                break;
            default: cout<<"             Invaild input...please try again\n";
                break;
                
                
                
                
                
        }
        
        
        
    }while(choice != '7');
    
    
    
    void Admin();
    
}





// Making Changes in Cultrue Information List
void SettingCultureInfo()
{
    cout<<"      Culture\n\n ";
    
    
    ofstream fout55;
    ifstream theFile55;
    int a;
    string Cname, KeyWord, KeyWordType;
    
  
    
    char choice;
    LinkedList<string> type;
    LinkedList<string> goo;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"           1. Add information to the back "<<endl;
        cout<<"           2. Add information using a position "<<endl;
        cout<<"           3. Change the information "<<endl;
        cout<<"           4. Erase information from a specific position"<<endl;
        cout<<"           5. Save the information To a text file "<<endl;
        cout<<"           6. Load the information From a file "<<endl;
        cout<<"           7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
       
        choice = toupper(choice);
        string ch, keyword, keywordtype;
        
       
        int position;
        switch(choice)
        {
            case '1':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout << "      Please enter a type of attraction of this information ==> ";
                cin >> keyword;
                cout << "      Please enter an city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(type.getLength()+1,ch);
                type.insertAttraction(type.getLength()+1, keyword, keywordtype);
                
                break;
            case '2':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position of this information ==> ";
                cin >> position;
                cout<<"        Please enter the attraction of this information ==> ";
                cin >> keyword;
                cout<<"        Please enter the city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(position, ch);
                type.insertAttraction(position , keyword, keywordtype);
                break;
            case '3':
                cout<<"        Please enter thw new information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position ==> ";
                cin >> position;
                goo.setEntry(position, ch);
            case '4':
                cout << "      Please enter the position ==> ";
                cin >> position;
                goo.remove(position);
                type.remove(position);
                break;
            case '5':
                fout55.open("CultureInformation.txt");
                for(int i = 1 ; i <= goo.getLength();i++)
                {
                    fout55 <<i<<" "<<goo.getEntry(i)<<" "<<endl;
                }
                fout55.close();
                
                fout55.open("CultureTypes.txt");
                for(int i = 1 ; i <= type.getLength();i++)
                {
                    fout55 <<i<<" "<<type.getEntry(i)<<" "<<type.getKeyWord(i)<<endl;
                    
                }
                fout55.close();
                
                if(goo.getLength() >= 1)
                {
                    
                    cout << "            These are the all information of attraction types in the system :\n";
                    for(int i = 1 ; i <= goo.getLength();i++)
                    {
                        
                        cout<<"         "<< i <<" - "<<goo.getEntry(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no information in the system for this attraction type "<<endl;
                }
                
                break;
                
            case '6':
                theFile55.open("CultureInformation.txt");
                if(theFile55.fail())
                    cout << "     " << endl;
                while(theFile55 >> a , getline(theFile55 , Cname))
                {
                    
                    goo.insert(a, Cname);
                    
                }
                theFile55.close();
                
                theFile55.open("CultureTypes.txt");
                if(theFile55.fail())
                    cout<<"    "<<endl;
                while(theFile55 >> a >> KeyWord >> KeyWordType)
                {
                    
                    type.insertAttraction(a, KeyWord , KeyWordType);
                    
                }
               
                break;
            case '7' :
                break;
            default: cout<<"             Invaild input...please try again\n";
                break;
                
                
                
                
                
        }
        
        
        
    }while(choice != '7');
    
    
    
    void Admin();
    
}



// Making Changes in Sightseeing Information List
void SettingSightseeingInfo()
{
    
    
    
    ofstream fout55;
    ifstream theFile55;
    int a;
    string Cname, KeyWord, KeyWordType;
    
    
    
    char choice;
    LinkedList<string> type;
     LinkedList<string> goo;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"                1. Add information to the back "<<endl;
        cout<<"                2. Add information using a position "<<endl;
        cout<<"                3. Change the information "<<endl;
        cout<<"                4. Erase information from a specific position"<<endl;
        cout<<"                5. Save the information To a text file"<<endl;
        cout<<"                6. Load the information From a text file "<<endl;
        cout<<"                7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword, keywordtype;
        int position;
        switch(choice)
        {
            case '1':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout << "      Please enter a type of attraction of this information ==> ";
                cin >> keyword;
                cout << "      Please enter an city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(type.getLength()+1,ch);
                type.insertAttraction(type.getLength()+1, keyword, keywordtype);
                
                break;
            case '2':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position of this information ==> ";
                cin >> position;
                cout<<"        Please enter the attraction of this information ==> ";
                cin >> keyword;
                cout<<"        Please enter the city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(position, ch);
                type.insertAttraction(position , keyword, keywordtype);
                break;
            case '3':
                cout<<"        Please enter thw new information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position ==> ";
                cin >> position;
                goo.setEntry(position, ch);
            case '4':
                cout << "      Please enter the position ==> ";
                cin >> position;
                goo.remove(position);
                type.remove(position);
                break;
            case '5':
                fout55.open("SightseeingInformation.txt");
                for(int i = 1 ; i <= goo.getLength();i++)
                {
                    fout55 <<i<<" "<<goo.getEntry(i)<<" "<<endl;
                }
                fout55.close();
                
                fout55.open("SightseeingTypes.txt");
                for(int i = 1 ; i <= type.getLength();i++)
                {
                    fout55 <<i<<" "<<type.getEntry(i)<<" "<<type.getKeyWord(i)<<endl;
                    
                }
                fout55.close();
                
                if(goo.getLength() >= 1)
                {
                    
                    cout << "            These are the all information of attraction types in the system :\n";
                    for(int i = 1 ; i <= goo.getLength();i++)
                    {
                        
                        cout<<"            "<< i <<" - "<<goo.getEntry(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no information in the system for this attraction type "<<endl;
                }
                
                break;
                
            case '6':
                theFile55.open("SightseeingInformation.txt");
                if(theFile55.fail())
                    cout << "   " << endl;
                while(theFile55 >> a , getline(theFile55 , Cname))
                {
                    
                    goo.insert(a, Cname);
                    
                }
                theFile55.close();
                
                theFile55.open("SightseeingTypes.txt");
                if(theFile55.fail())
                    cout<<"    "<<endl;
                while(theFile55 >> a >> KeyWord >> KeyWordType)
                {
                    
                    type.insertAttraction(a, KeyWord , KeyWordType);
                    
                }
                break;
            case '7' :
                break;
            default: cout<<"             Invaild input...please try again\n";
                break;
                
                
                
                
                
        }
        
        
        
    }while(choice != '7');
    
    
    
    void Admin();
    
}


// Making Changes in HistoricalPlaces Information List
void SettingHistoricalPlacesInfo()
{
    
    
    
    ofstream fout55;
    ifstream theFile55;
    int a;
    string Cname, KeyWord, KeyWordType;
    
    
    
    char choice;
    LinkedList<string> type;
    LinkedList<string> goo;
    do{
        
        cout<< endl << endl <<endl;
        cout<<"               1. Add information to the back "<<endl;
        cout<<"               2. Add information using a position "<<endl;
        cout<<"               3. Change the information "<<endl;
        cout<<"               4. Erase information from a specific position"<<endl;
        cout<<"               5. Save the information To a text file"<<endl;
        cout<<"               6. Load the information From a text file "<<endl;
        cout<<"               7. Back "<<endl;
        cout<<endl;
        cout<<"          --> ";
        cin >> choice;
        
        choice = toupper(choice);
        string ch, keyword, keywordtype;
        int position;
        switch(choice)
        {
            case '1':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout << "      Please enter a type of attraction of this information ==> ";
                cin >> keyword;
                cout << "      Please enter an city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(type.getLength()+1,ch);
                type.insertAttraction(type.getLength()+1, keyword, keywordtype);
                
                break;
            case '2':
                cout << "      Please enter information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position of this information ==> ";
                cin >> position;
                cout<<"        Please enter the attraction of this information ==> ";
                cin >> keyword;
                cout<<"        Please enter the city of this type of attraction ==> ";
                cin >> keywordtype;
                goo.insert(position, ch);
                type.insertAttraction(position , keyword, keywordtype);
                break;
            case '3':
                cout<<"        Please enter thw new information ==> ";
                cin.ignore();
                cin.clear();
                getline(cin , ch);
                cout<<"        Please enter the position ==> ";
                cin >> position;
                goo.setEntry(position, ch);
            case '4':
                cout << "      Please enter the position ==> ";
                cin >> position;
                goo.remove(position);
                type.remove(position);
                break;
            case '5':
                fout55.open("HistoricalPlacesInformation.txt");
                for(int i = 1 ; i <= goo.getLength();i++)
                {
                    fout55 <<i<<" "<<goo.getEntry(i)<<" "<<endl;
                }
                fout55.close();
                
                fout55.open("HistoricalPlacesTypes.txt");
                for(int i = 1 ; i <= type.getLength();i++)
                {
                    fout55 <<i<<" "<<type.getEntry(i)<<" "<<type.getKeyWord(i)<<endl;
                    
                }
                fout55.close();
                
                if(goo.getLength() >= 1)
                {
                    
                    cout << "            These are the all information of attraction types in the system :\n";
                    for(int i = 1 ; i <= goo.getLength();i++)
                    {
                        
                        cout<<"         "<< i <<" - "<<goo.getEntry(i)<<endl;
                        
                        
                    }
                }
                else{
                    
                    cout<<"               There is no information in the system for this attraction type "<<endl;
                }
                
                break;
                
            case '6':
                theFile55.open("HistoricalPlacesInformation.txt");
                if(theFile55.fail())
                    cout << "    " << endl;
                while(theFile55 >> a , getline(theFile55 , Cname))
                {
                    
                    goo.insert(a, Cname);
                    
                }
                theFile55.close();
                
                theFile55.open("HistoricalPlacesTypes.txt");
                if(theFile55.fail())
                    cout<<"   "<<endl;
                while(theFile55 >> a >> KeyWord >> KeyWordType)
                {
                    
                    type.insertAttraction(a, KeyWord , KeyWordType);
                    
                }
                break;
                
            case '7' :
                break;
            default: cout<<"             Invaild input...please try again\n";
                break;
                
                
                
                
                
        }
        
        
        
    }while(choice != '7');
    
    
    
    void Admin();
    
}

