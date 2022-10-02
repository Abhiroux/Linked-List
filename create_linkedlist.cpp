#include <iostream>
using namespace std;


class Node{
  public:
  int data;
  Node *next;
};
void display(Node *p){
    while (p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

int main()
{
    int i=0,n;
    cout<<"Enter Number of Elements ";
    cin>>n;
    Node *temp,*newnode,*head=0;
    while(i<n){
        newnode=new Node;
        cin>>newnode->data;
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
    return 0;
}
