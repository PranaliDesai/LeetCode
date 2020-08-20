# include<iostream>

using namespace std;

class node{
  public:
  int data;
  node *next;
};
class Stack
{
	node *front;  // points to the head of list
	public:
	Stack()
	{
		front = NULL;
	}
	// push method to add data element
	void push(int);
	// pop method to remove data element
	void pop();
	// top method to return top data element
	int top();
  void display();
};

void Stack ::push(int x){
  node *temp=new node();
  temp->data=x;
	if(front == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = front;
	}
	front = temp;
}
void Stack ::pop(){
  if(front == NULL)
		cout << "UNDERFLOW\n";
	else {
    front =front->next;
  }
}
void Stack ::display(){
  while(front!=NULL){
    cout<<front->data<<endl;
    front=front->next;
  }

}
// main function
int main() {

    Stack s1;
    s1.push(10);
    s1.push(100);
    //s1.pop();
    /*
        preform whatever operation you want on the stack
    */
    s1.display();
    return 0;
}
