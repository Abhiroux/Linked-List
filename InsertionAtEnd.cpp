#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtEnd(Node **p,int x){
    Node* n=new Node();
    n->data=x;
    n->next=NULL;
    if(*p==NULL){
        *p=n;
        return;
    }
    Node* temp=*p;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    int i=0;
    int arr[]={2,4,5,64,3,11};
    Node *head=0,*temp,*newnode;
    while (i<6)
    {
        newnode=new Node;
        newnode->data=arr[i];
        newnode->next=NULL;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        i++;
    }
    display(head);
    insertAtEnd(&head,29);
    insertAtEnd(&head,49);
    insertAtEnd(&head,48);
    insertAtEnd(&head,4);

    cout<<"\nList After Insertion"<<endl;
    display(head);
    return 0;
}