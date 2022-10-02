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

void InsertionAtFront(Node **p,int element){
    
    Node *temp=new Node;
    temp->data=element;
    temp->next=NULL;
    if(*p==NULL){
        *p=temp;
        return;
    }
    temp->next=*p;
    *p=temp;
}


int main(){
    Node *head=0,*temp,*newnode;
    int n,i=0;
    cout<<"Enter Number of Node ";
    cin>>n;
    while (i<n)
    {
        newnode=new Node();
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

    int a;
    cout<<"\nEnter Element for Insertion at front ";
    cin>>a;
    InsertionAtFront(&head,a);
    cout<<"\nAfter Insertion"<<endl;
    Display(head);
    
    return 0;
}