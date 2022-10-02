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

void findMax(Node **p){
    if(*p==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node* temp=*p;
    int max=INT8_MIN;
    for(temp;temp!=NULL;temp=temp->next){
        if(temp->data>max)
        max=temp->data;
    }
    cout<<max<<" is maximum value"<<endl;
}
void findMin(Node **p){
    if(*p==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node* temp=*p;
    int min=INT8_MAX;
    for(temp;temp!=NULL;temp=temp->next){
        if(temp->data<min)
        min=temp->data;
    }
    cout<<min<<" is minimum value"<<endl;
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
    findMax(&head);
    findMin(&head);

    return 0;
}