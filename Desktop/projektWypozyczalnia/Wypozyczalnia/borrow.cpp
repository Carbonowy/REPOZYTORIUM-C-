#include "borrow.h"

borrow::borrow()
{
}

void borrow::setLength( int n )
{
    length = n;
}

int borrow::getLength()
{
    return length;
}
void borrow::setHead(int f_)
{ 
        head = structlist(); 
}
node* borrow::getHead()
{
    return head;
}
node* borrow::structlist()
{
    node* tmp2;
    node* head;
    node* tmp1;

    for(int i=0; i<=length; i++)
    {
        tmp1 = new node;
        tmp1 -> nr = i+1;
                
        if(i == 0) head = tmp1;
        else
        {
            tmp2 -> next = tmp1;
        }

        tmp2 = tmp1;
    }

    tmp2 -> next = NULL;

    delete tmp1, tmp2;

    return head;
}
       
void borrow::addnewC(string registration_, string mark_, string model_, int mileage_ )
{
    node* finder;
    node*  tmp;
    finder = getHead();
    length++;

    while(finder -> next != NULL)
    {
        finder = finder -> next;
    }

    tmp = new node;
    finder -> next = tmp;
    tmp -> next = NULL;

    tmp -> nr = length;
    tmp -> registration = registration_;
    tmp -> mark = mark_;
    tmp -> model = model_;
    tmp -> mileage = mileage_;
}

void borrow::bubblesortmileage()
{
    node* tmp;
    node* tmp1;
    node* tmp2;
    node* tmp3;
    node* a;
    node* head1;

    head1 = getHead();

    tmp = head1;
    tmp1 = head1 -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next; 

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length-3; j++)
        {
    
            if(j == 0 && tmp->mileage > tmp1->mileage)
            {
                head1 = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;


            }
            else if(tmp3 -> next == NULL && tmp2->mileage > tmp3->mileage)
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->mileage > tmp2->mileage)
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = head1;
        tmp1 = head1 -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }

    head = head1;
}

void borrow::bubblesortregistration()
{
    node* tmp;
    node* tmp1;
    node* tmp2;
    node* tmp3;
    node* a;
    node* head1;

    head1 = getHead();

    tmp = head1;
    tmp1 = head1 -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next; 

    string t1, t2, t3, t4;

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length-3; j++)
        {
            t1 = tmp -> registration;
            t2 = tmp1 -> registration;
            t3 = tmp2 -> registration;
            t4 = tmp3 -> registration;

            if(j == 0 && t1[0] > t2[0])
            {
                head1 = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;


            }
            else if(tmp3 -> next == NULL && t3[0] > t4[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(t2[0] > t3[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = head1;
        tmp1 = head1 -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }

    head = head1;
}
node* borrow::findbyregistration(string n_)
{
    node* car; car = getHead();
    bool f = false;
    while(car != NULL)
    {
        if(car->registration == n_) 
        {
            cout<<car->nr<<"   "<<
            car -> registration<<"   "<<car -> mark
            <<"   "<<car -> model<<"   "<<
            car -> mileage<<endl;
            f = true;
            break;
        }
        car = car -> next;
    }
    if(f == true) return car;
    else return NULL;
}
void borrow::findbymark(string n_)
{
    node* car; car = getHead();
    bool f = false;
    while(car != NULL)
    {
        if(car->mark == n_) 
        {
            cout<<car->nr<<"   "<<
            car -> registration<<"   "<<car -> mark
            <<"   "<<car -> model<<"   "<<
            car -> mileage<<endl;
            f = true;
        }
        car = car -> next;
    }
    if(f == false) cout<<"there is/are no such car/s"; 
}
void borrow::findbymodel(string n_)
{
    node* car; car = getHead();
    bool f = false;
    while(car != NULL)
    {
        if(car->model == n_) 
        {
            cout<<car->nr<<"   "<<
            car -> registration<<"   "<<car -> mark
            <<"   "<<car -> model<<"   "<<
            car -> mileage<<endl;
            f = true;
        }
        car = car -> next;
    }
    if(f == false) cout<<"there is/are no such car/s"; 
}
void borrow::findbymileage(int i_)
{
    node* car; car = getHead();
    bool f = false;
    while(car != NULL)
    {
        if(car->mileage == i_) 
        {
            cout<<car->nr<<"   "<<
            car -> registration<<"   "<<car -> mark
            <<"   "<<car -> model<<"   "<<
            car -> mileage<<endl;
            f = true;
        }
        car = car -> next;
    }
    if(f == false) cout<<"there is/are no such car/s"; 
}
void borrow::findbyregistrationtodelete(string n_)
{
    node* k; 
    node* k1; 
    
    k = getHead();
    k1 = k->next;
    bool f = false;
    
    while(k1 != NULL)
    {
        if(k->registration == n_ && k == head)
        {
            head = k1;
            delete k;
            f = true;
            break;
        } 
        if(k1 -> next == NULL && k1->registration == n_)
        {
            k -> next = NULL;
            delete k1;
            f = true;
            break;
        }
        else if( k1 -> registration == n_)
        {
            k -> next = k1 -> next;
            delete k;
            f = true;
            break;
        }
        k = k->next;
        k1 = k1 -> next;
    }
    if(f == true) 
    {
        cout<<"car deleted"<<endl;
    }
    else
    {
        cout<<"there is no such car"<<endl;
    }
}
void borrow::bubblesortmark()
{
    node* tmp;
    node* tmp1;
    node* tmp2;
    node* tmp3;
    node* a;
    node* head1;

    head1 = getHead();

    tmp = head1;
    tmp1 = head1 -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next; 

    string t1, t2, t3, t4;

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length-3; j++)
        {
            t1 = tmp -> mark;
            t2 = tmp1 -> mark;
            t3 = tmp2 -> mark;
            t4 = tmp3 -> mark;

            if(j == 0 && t1[0] > t2[0])
            {
                head1 = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;


            }
            else if(tmp3 -> next == NULL && t3[0] > t4[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(t2[0] > t3[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = head1;
        tmp1 = head1 -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }    

    head = head1;
}

void borrow::bubblesortmodel()
{
    node* tmp;
    node* tmp1;
    node* tmp2;
    node* tmp3;
    node* a;
    node* head1;

    head1 = getHead();

    tmp = head1;
    tmp1 = head1 -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next; 

    string t1, t2, t3, t4;

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length-3; j++)
        {
            t1 = tmp -> model;
            t2 = tmp1 -> model;
            t3 = tmp2 -> model;
            t4 = tmp3 -> model;

            if(j == 0 && t1[0] > t2[0])
            {
                head1 = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;


            }
            else if(tmp3 -> next == NULL && t3[0] > t4[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(t2[0] > t3[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = head1;
        tmp1 = head1 -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
    
    head = head1; 
}


void borrow::printlist()
{
    node* a = getHead();

    while(a  != NULL)
    {
        cout<<a->nr<<"   "<<
        a -> registration<<"   "<<a -> mark
        <<"   "<<a -> model<<"   "<<a -> mileage<<endl;
        a = a -> next;
    }

    delete a;
}

borrow::~borrow(){}