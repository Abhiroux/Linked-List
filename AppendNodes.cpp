#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* createLL(){
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
    return head;
}
void Display(Node *p){
    if(p==NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

Node* AppendNodes(Node* headRef,int k){
    Node* temp=headRef;
    Node* NewHead=new Node;
    int count=0;
    while (temp->next!=NULL)
    {
        count++;
        if(count==k){
            NewHead=temp->next;
            temp->next=NULL;
        }
        temp=temp->next;
    }
    Node* &t=NewHead;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=headRef;

    return NewHead;
    
    
}

int main(){
    Node* head = createLL();
    Display(head);
    head = AppendNodes(head,3);
    Display(head);
    return 0;
}