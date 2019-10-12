#include <iostream>
using namespace std;

struct node
{  
    int nr;
    node* next;
};

class list
{
    public:
        
        list(int n)
        {
            setLength(n);
            setHead();
        }
        ~list(){}
        void setLength( int n )
        {
            length = n;
        }
        void setHead()
        {
            head = structlist();
        }
        node* getHead()
        {
            return head;
        }
        node* structlist()
        {
            node* tmp2;
            node* head;
            node* tmp1;

            for(int i=0; i<length; i++)
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
        void printlist()
        {
            node* a = getHead();

            while(a != NULL)
            {
                cout<<a->nr<<" ";
                a = a -> next;
            }
        }

    
    private: 
        int length;
        node* head;
};

int main()
{
    int n;
    cin>>n;
    list a(n);

    a.printlist();

    return 0;
}