# include<iostream>

using namespace std;

class node{
  public:
  int data;
  node *next;
};
class queue
{
	node *front;  // points to the head of list
	public:
	queue()
	{
		front = NULL;
	}
	// push method to add data element
	void enqueue(int);
	// pop method to remove data element
	void dequeue();
	// top method to return top data element
	int top();
  void display();
};

void queue ::enqueue(int x){
  
  node *temp=new node();
  temp->data=x;
	if(front == NULL)
	{
    front=temp;
		front->next = NULL;
	}
	else
	{
		front->next =temp;
	}
	//front = temp;
}
void queue ::dequeue(){
  if(front == NULL)
		cout << "UNDERFLOW\n";
	else {
    front =front->next;
  }
}
void queue ::display(){
  while(front!=NULL){
    cout<<front->data<<endl;
    front=front->next;
  }
}
int queue ::top(){
  if (front!=NULL) return front->data;
  return 0;
}
// main function
int main() {

    queue q1;
    q1.enqueue(10);
    q1.enqueue(100);
    cout<<q1.top()<<endl;
    /*
        preform whatever operation you want on the stack
    */
    q1.display();
    return 0;
}
