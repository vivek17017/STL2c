#include<iostream>
using namespace std;
template<typename X>
struct node
{
    X item;
    node<X>* next;
};
template<typename X>
class SLL
{
    private:
        node<X>* start;
    public:
        SLL();
        void insertAtStart(X);
        void insertAtLast(X);
        node<X>* search(X);
        void insertAfter(node<X>*,X);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node<X>*);
        ~SLL();
        node* getFirstNode();
};
template<typename X>
SLL<X>::SLL()
{
    start=nullptr;
}
template<typename X>
void SLL<X>::insertAtStart(X data)
{
    node* temp=new node;
    temp->item=data;
    temp->next=start;
    start=temp;
}
template<typename X>
void SLL<X>::insertAtLast(X data)
{
    
    node<X>* n=new node;
    n->item=data;
    n->next=nullptr;
    node<X>* t=start;
    if(start==nullptr)
        start=n;
    else{
    while(t->next!=nullptr)
        t=t->next;
    t->next=n;
    }
}
template<class X>
node<X>* SLL<X>::search(X data)
{
    node* t=start;
    while(t!=nullptr)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return nullptr;
}
template<typename X>
void SLL<X>::insertAfter(node<X>* t,X data)
{
    if(search(t->item)==t)
    {
        node<X>* temp=new node;
        temp->item=data;
        temp->next=t->next;
        t->next=temp;
    }
    else
        cout<<"node not found";
}
template<typename X>
void SLL<X>::deleteFirst()
{
    if(start)
    {
        node* temp=start;
        start=start->next;
        delete temp;
    }
}
template<typename X>
void SLL<X>::deleteLast()
{
    
    node<X> *t=start;
    if(start->next==nullptr)
    {
        delete start;
        start=nullptr;
    }
    else
    {
    while(t->next->next!=nullptr)
    {
        t=t->next;
    }
    delete t->next;
    t->next=nullptr;
}
}
template<typename X>
void SLL<X>::deleteNode(node<X>* t)
{
    if(search(t->item)==t)
    {
        if(t==start)
            deleteFirst();
        else if(t->next==nullptr)
            deleteLast();
        else
        {
            node<X> *temp=start;
            while(temp->next!=t)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            delete t;
        }
    }
}

template<typename X>
SLL<X>::~SLL()
{
    while(start!=nullptr)
        deleteFirst();
}
template<typename X>
node<X>* getFirstNode()
{
    if(start)
        return start;
}
int main()
{
    SLL<double> d;
    d.insertAtStart(5.6);
    SLL<int> e;
    e.insertAtStart(6);

}