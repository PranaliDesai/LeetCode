
#include<iostream>

using namespace std;

#define SIZE 10

class Queue{
  int a[SIZE];
  int rear;
  int front;
  public:
  Queue()
  {
    rear = front = -1;
  }
  void enqueue(int x);     
  void dequeue();
  void display();
};

void Queue :: enqueue(int x){
  if(front == -1) {
      front++;
  }
  if( rear == SIZE-1)
  {
      cout << "Queue is full";
  }
  else
  {
    cout<<front<<" "<<rear<<endl;
      a[++rear] = x;
  }
}

void Queue :: dequeue(){
  if(front>rear) return;
  front++;
}


void Queue :: display()
{
    int i;
    for( i = front; i <= rear; i++)
    {
        cout << a[i] << endl;
    }
}

// the main function
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(11);
    q.dequeue();
    q.dequeue();
    q.dequeue();
  q.dequeue();
    q.enqueue(1004);
  q.enqueue(1004);
  q.enqueue(1004);
    
    q.display();
    
    return 0;
}
