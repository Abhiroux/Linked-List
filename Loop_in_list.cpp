#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void Display(Node* p){
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void loopAfter(Node** headRef,int index){
    int count=0;
    Node* temp=*headRef;
    Node* loopNode=new Node;
    while(temp->next!=NULL)
    {
        if(count==index){
            loopNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=loopNode; 
}

Node* DetectCycle(Node **headRef){
    Node *slow,*fast;
    slow=*headRef;
    fast=*headRef;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            cout<<"Loop Detected"<<endl;
            return slow;
        }
    }
    cout<<"No loop in the list"<<endl;
    return NULL;
}

void RemoveCycle(Node **headRef,Node **loopNode){
    Node *N1=new Node,*N2=new Node;
    N1=*headRef;
    N2=*loopNode;
    while (N1->next!=N2->next)
    {
        N1=N1->next;
        N2=N2->next;
    }
    N2->next=NULL;
    cout<<"Loop Removed"<<endl;

}

int main(){
    int n;
    cout<<"Enter the Number of Nodes"<<endl;
    cin>>n;
    n>0 ? cout<<"Enter Elements: "<<endl : cout<<"";
    Node *head=NULL,*newnode,*temp;
    for(int i=0;i<n;i++){
        newnode=new Node;
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
    loopAfter(&head,2);
    // Display(head);
    Node *loopNode=new Node;
    loopNode = DetectCycle(&head);
    RemoveCycle(&head,&loopNode);
    Display(head);
    return 0;
}