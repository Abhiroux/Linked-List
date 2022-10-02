#include<iostream>
using namespace std;

struct Node{
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
void DisplayRev(Node *p){
    if(p!=0)
    {
        DisplayRev(p->next);
        cout<<p->data<<" ";
    }
}

int main(){
    Node *head=0,*temp,*newnode;
    int n,i=0;
    cout<<"Enter Number of Nodes ";
    cin>>n;
    cout<<"Enter the Elements"<<endl;
    while (i<n)
    {
        newnode = new Node;
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        i++;  
    }
    Display(head);
    cout<<"\nList in reverse Order"<<endl;
    DisplayRev(head);
    
    return 0;
}