#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node *p){
    if(p!=0)
    {
        cout<<p->data<<" ";
        Display(p->next);
    }
}


int main(){
    Node *head=0,*temp,*newnode;
    int n,i=0;
    cout<<"Enter Number of Node ";
    cin>>n;
    while (i<n)
    {
        newnode=new Node;
        cin>>newnode->data;
        newnode->next=0;
        if(head==NULL)
        head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
        i++;
    }
    Display(head);
    Node *t;
    cout<<"\nEnter Element for Insertion at front ";
    cin>>t->data;
    t->next=head;
    head=t;
    cout<<"\nAfter Insertion"<<endl;
    Display(head);
    
    return 0;
}