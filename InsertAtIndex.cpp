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
void InsertionAtFront(Node **p,int element){
    Node *t=new Node;
    t->data=element;
    t->next=NULL;
    if(*p==NULL){
        *p=t;
        return;
    }
    t->next=*p;
    *p=t;
}

void insertAtIndex(Node** p,int index,int element){
    Node* n=new Node;
    n->data=element;
    n->next=NULL;
    Node *temp=*p;
    if(index==1){
        InsertionAtFront(p,element);
        return;
    }
    for(int i=1;i<index-1;i++){       //this loop will move the pointer to the index of insertion
        temp=temp->next;
        if(temp==NULL){
            cout<<"!!Insertion Failed\nInvalid Index"<<endl;
            return;
        }
    }
    n->next=temp->next;
    temp->next=n;
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
    // Display(head);
    cout<<endl;
    insertAtIndex(&head,9,58);
    Display(head);


    return 0;
}