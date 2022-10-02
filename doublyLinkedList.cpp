#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

void displayForward(Node* p){
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    
}

void displayBackward(Node* p){
    while (p)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
    cout<<endl;
    
}

int main(){
    int n;
    cout<<"Enter Number of Nodes ";
    cin>>n;
    cout<<"Enter Elementes"<<endl;
    Node *head=0,*temp,*newnode;
    while (n--)
    {
        newnode=new Node;
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    cout<<"Forward Traverse ";
    displayForward(head);
    cout<<"\bBackward Traverse ";
    displayBackward(temp);
    return 0;
}