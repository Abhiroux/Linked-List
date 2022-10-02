#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
}*head=NULL;


//this function will create and return a linked list
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

//Display function displays the linked list
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

//findMin finds Max in list
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

//this function will insert element at starting
void InsertionAtFront(Node **p){
    int element;
    cout<<"Enter data for Insertion ";
    cin>>element;
    Node *temp=new Node;
    temp->data=element;
    temp->next=NULL;
    if(*p==NULL){
        *p=temp;
        return;
    }
    temp->next=*p;
    *p=temp;
}

void insertAtEnd(Node **p){
    int x;
    cout<<"Enter data for Insertion ";
    cin>>x;
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

void insertAtPosition(Node** p){
    int index,element;
    cout<<"Enter position for insertion ";
    cin>>index;
    if(index==1){
        InsertionAtFront(p);
        return;
    }
    cout<<"Enter data for insertion ";
    cin>>element;
    Node* n=new Node;
    n->data=element;
    n->next=NULL;
    Node *temp=*p;
    
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

void DeleteAtFront(Node **p){
    if(*p==NULL){
        cout<<"List is Empty";
        return;
    }
    Node* temp=*p;
    *p=temp->next;
    delete temp;
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

void DeleteAtPosition(Node **p){
    if(*p==NULL){
        cout<<"List is empty ";
        return;
    }
    int index;
    cout<<"Enter Node Index for Deletion ";
    cin>>index;
    if(index==1){
        DeleteAtFront(p);
        return;
    }
    Node *n=new Node;
    Node *temp=*p;
    for(int i=1;i<index-1;i++){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Invalid Position!! Deletion Failed\n";
            return;
        }
    }
    n=temp->next;
    temp->next=n->next;
}

void findMean(Node **p){
    if(*p==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=*p;
    int sum=0,count=0;
    float mean;
    for(temp;temp!=NULL;temp=temp->next){
        sum+=temp->data;
        count++;
    }
    mean=float(sum)/float(count);
    cout<<"Mean of All list elements is "<<mean<<endl;
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
    // Node* head=NULL;
    int choice; 
    while (1)
    {

        cout<<"\n(1)Create LinkedList\t\t(2)Display/Traverse\t\t(3)Find Maximum In List\n(4)Insert At Front\t\t(5)Insert At End\t\t(6)Insert At Position"<<endl;
        cout<<"(7)Delete First Element\t\t(8)Delete Last Element\t\t(9)Delete At Position"<<endl<<"(10)Mean of List Elements\t\t(11)Sorting\t\t(12)Reverse Linked List\n(13)Exit"<<endl<<endl;
        cout<<"Select any Option ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            head=createLL();
            cout<<"List Created\n";
            break;
        case 2:
            Display(head);
            break;
        case 3:
            findMax(&head);
            break;
        case 4:
            InsertionAtFront(&head);
            cout<<"Element Inserted\n";
            break;
        case 5:
            insertAtEnd(&head);
            cout<<"Element Inserted\n";
            break;
        case 6:
            insertAtPosition(&head);
            cout<<"Element Inserted\n";
            break;
        case 7:
            DeleteAtFront(&head);
            cout<<"\nFirst Element Deleted\n";
            break;
        case 8:
            DeleteAtEnd(&head);
            cout<<"\nLast Element Deleted\n";
            break;
        case 9:
            DeleteAtPosition(&head);
            cout<<"Element Deleted\n";
            break;
        case 10:
            findMean(&head);
            break;
        case 11:
            sort(&head);
            cout<<"Sorting Completed\n";
            break;
        case 12:
            head=reverse(&head);
            cout<<"Reversing Completed\n";
            break;
        case 13:
            cout<<"Thank You\n";
            exit(1);
            break;
        
        default:
            cout<<"!!Selected Option is not Valid\n";
            break;
        }
        fflush(stdin);
    }
        return 0;
}