#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


void Display(Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

Node* reverse(Node** p){
    if(*p==NULL){
        cout<<"List is empty"<<endl;
        return 0;
    }
    Node *curr=*p,*prev=NULL,*temp;
    while (curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

int main(){
    int n;
    cout<<"Enter the Number of Nodes ";
    cin>>n;
    Node *head=0,*temp,*newnode;
    n>0 ? cout<<"Enter Elemnets"<<endl : cout<<"";  //if n<=0 then print nothing 
    for(int i=0;i<n;i++){
        newnode=new Node();
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    
    head = reverse(&head);
    Display(head);
    
    return 0;
}