#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node(){
    data=0;
    next=NULL;
  }
  node(int x){
    data=x;
    next=NULL;
  }
};
class LinkedList{
  public:
  node* head;
  //function to add Node at front
  void addAtFront(node *n);
  //function to check whether Linked list is empty
  int isEmpty();
  //function to add Node at the End of list
  void addAtEnd(node *n);
  //function to search a value
  node* search(int k);
  //function to delete any Node
  node* deleteNode(int x);
  
  void display();

  LinkedList() 
  {
      head = NULL;
  }
  
};

void LinkedList :: addAtFront(node *n){
  n->next=head;
  head =n;
}

void LinkedList :: addAtEnd(node *n){
  node *temp = head;
  if(head == NULL){
    head=n;
    n->next=NULL;
  }
  else{
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=n; 
  }
}

node* LinkedList :: search(int x) {
  node *ptr = head;
  while(ptr != NULL && ptr->data != x) {
    ptr = ptr->next;
  }
  return ptr;

}

int LinkedList :: isEmpty() {
  if(head == NULL) {
    return 1;
  }
  else { return 0; }
}

node* LinkedList :: deleteNode(int x) {
  //searching the Node with data x
  node *n = search(x);
  node *ptr = head;
  if(ptr == n) {
    ptr->next = n->next;
    return n;
  }
  else {
    while(ptr->next != n) {
      ptr = ptr->next;
    }
    ptr->next = n->next;
    return n;
  }
}
void LinkedList :: display(){
  while(head!=NULL){
    cout<<head->data<<endl;
    head=head->next;
  }
}

int main() {
  LinkedList L;
  //We will ask value from user, read the value and add the value to our Node
  // int x = 10;
  // node *n1;
  //Creating a new node with data as x
  node *n1 = new node(10);
  node *n2 = new node(0);
  node *n3 = new node(1);
  //Adding the node to the list
  L.addAtFront(n1);
  L.addAtEnd(n2);
  L.addAtFront(n3);
  L.deleteNode(0);
  L.display();
  
  return 0;
}
