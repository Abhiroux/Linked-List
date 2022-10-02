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
void DeleteAtEnd(Node **p){
    if(*p==NULL){
        cout<<"List is Empty";
        return;
    }
    Node* prevNode;
    Node* temp=*p;
    while (temp->next!=NULL)
    {
        prevNode=temp;
        temp=temp->next;
    }
    prevNode->next=NULL;
    delete temp;
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
    DeleteAtEnd(&head);
    Display(head);

    return 0;
}