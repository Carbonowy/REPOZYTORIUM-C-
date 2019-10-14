#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct node
{
    int nr = 0;
    node* next;
    string registration ;
    string mark ;
    string model ;
    int mileage = 0;
};

class borrow
{
    private:
        int length;
        node* head;
    public:
        borrow();
        void setLength(int n);
        void setHead(int f_);
        void addnewC(string registration_,string mark_, string model_, int mileage_);
        node* getHead();
        int getLength();
        void bubblesortmileage();
        void bubblesortregistration();
        void bubblesortmark();
        void bubblesortmodel();
        node* findbyregistration(string n);
        void findbymileage(int i);
        void findbymark(string n);
        void findbymodel(string n);
        void findbyregistrationtodelete(string n);
        node* structlist();
        void printlist();
        ~borrow();
};

#endif