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

void sort(Node** p){
    Node* current=*p;
    Node* itr;
    int temp;
    for(current;current!=NULL;current=current->next){
        itr=current->next;
        for(itr;itr!=NULL;itr=itr->next){
            if (itr->data < current->data)
            {
                temp=itr->data;
                itr->data=current->data;
                current->data=temp;
            }
            
        }
    }
    
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
    sort(&head);
    Display(head);

    return 0;
}