#include <iostream>
#include <fstream>
#include <string>
#include "borrow.h"
using namespace std;
borrow a;

void addnewcar()
{
    string registration, mark, model;
    
    int mileage;
    
    cout<<"input data in order:"<<
   
    endl<<"registration - mark - model - mileage"<<endl;
    
    cin>>registration>>mark>>model>>mileage; cout<<endl;
    
    a.addnewC(registration, mark, model, mileage);
}
void changeparameter()
{
    
    node* car; int x; string n ;
    
    cout<<"ADD THE EXISTING REGISTRETION TO FIND THE CAR:::";
    cout<<endl<<"input registration  ";
    
    cin>>n; car = a.findbyregistration(n);
    cout<<endl;
    
    cout<<"WHICH PARAMETER DO YOU WANT TO CHANGE:::"<<
    endl<<"1. Mileage"<<
    endl<<"2. registration"<<
    endl<<"3. mark"<<
    endl<<"4. model"<<endl;

    cin>>x;
    
    switch (x)
    {
        case 1:  cin>>car->mileage; break;
        case 2:  cin>>car->registration; break;
        case 3:  cin>>car->mark; break;
        case 4:  cin>>car->model; break;
    
        default:
            break;
    }
   
}
void deletecar()
{
    node* car; int x; string n ;
    cout<<"ADD THE EXISTING REGISTRETION TO FIND THE CAR:::";
    cout<<endl<<"input registration  ";
    
    cin>>n; a.findbyregistrationtodelete(n);
    cout<<endl;
}
void findAcarAndPrintHer()
{
    int x;

    cout<<"Do you want to find car by:::"<<
    endl<<"1. Mileage"<<
    endl<<"2. registration"<<
    endl<<"3. mark"<<
    endl<<"4. model"<<endl;

    cin>>x; cout<<endl<<"input parameter  ";
    string n ; int k;
    node* car;
    cout<<endl;
    switch (x)
    {
        case 1: cin>>k; a.findbymileage(k); break;
        case 2: cin>>n; car = a.findbyregistration(n); break;
        case 3: cin>>n; a.findbymark(n); break;
        case 4: cin>>n; a.findbymodel(n); break;
    
        default:
            break;
    }

    
}
void Cdatabase()
{
    string registration, mark, model; int n;
    cout<<"How many cars do you want to add?"<<
    endl<<"type the amount";

    cin>>n;

    cout<<endl<<"then input data in order:"<<
    endl<<"registration - mark - model - mileage"<<endl;
    int mileage;  cout<<endl;

    a.setLength(n);
    a.setHead(0);
    node* tmp = a.getHead();
    
    while(tmp->next != NULL)
    {
        cin>>registration>>mark>>model>>mileage;
        tmp -> registration = registration;
        tmp -> mark = mark;
        tmp -> model = model;
        tmp -> mileage = mileage;
        cout<<endl;

        tmp = tmp -> next;
    }
}

void ExportToTxt()
{
    string n;
    cout << "input txt file name ";cin>>n;
    
    node* car; car = a.getHead();

    char  s = ';';
    char l = '\n';

    ofstream dane(n);

    for(int i=0; i<a.getLength(); i++)
    {
        dane<<car->nr<<s<<car->registration
        <<s<<car->mark<<s<<car->model<<s
        <<car->mileage<<l;

        if(car!=NULL)
        car = car->next;
    }
}
void sortdatabase()
{
    int x; 

    cout<<"Do you want to sort by:::"<<
    endl<<"1.registration"<<
    endl<<"2.mark"<<
    endl<<"3.model"<<
    endl<<"4.mileage"<<endl; cin>>x; cout<<"\n\n";
    
    switch(x)
    {
        case 1: a.bubblesortregistration(); break;
        case 2: a.bubblesortmark(); break;
        case 3: a.bubblesortmodel(); break;
        case 4: a.bubblesortmileage(); break;
        default:break;
    }

    cout<<"sorting finished"<<"\n\n";
}

void printallcars()
{
    a.printlist();
}
int main()
{
    bool f = false;
    int x;

    while(true)
    {
        cout<<"1. add new car"<<
        endl<<"2. change parameter"<<
        endl<<"3. delete car"<<
        endl<<"4. find a car"<<
        endl<<"5. Create completely new database"<<
        endl<<"6. sort data base"<<
        endl<<"7. print all cars"<<
        endl<<"8. Export database to text file"<<
        endl<<"0. quit"<<endl;

        cin>>x;

        switch(x)
        {
            case 1: addnewcar(); break;
            case 2: changeparameter(); break;
            case 3: deletecar(); break;
            case 4: findAcarAndPrintHer(); break;
            case 5: Cdatabase(); break;
            case 6: sortdatabase(); break;
            case 7: printallcars(); break;
            case 8: ExportToTxt(); break;
            case 0: f = true; break;
            default: break; 
        }                                     

        if(f == true) break;
    }

    return 0;
}