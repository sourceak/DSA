#include <iostream>
using namespace std;

class Queue{
private:
	int front, rear;
	int arr[5];
public:
	Queue():front(-1),rear(-1){
		for(int i=0;i<5;i++){
			arr[i]=0;
		}
	}

	bool isEmpty(){
		if(rear==-1)
			return true;
		else
			return false;
	}
	bool isFull(){
		if(rear==4)
			return true;
		else
			return false;
	}
	void enqueue(int val){
		if(isFull()){
			cout<<"Queue is full."<<endl;
		}else if(isEmpty()){
			front = rear = 0;
			arr[rear]=val;
		}else{
			rear++;
			arr[rear]=val;
		}
	 }
	int dequeue(){
		int x;
		if(isEmpty()){
			cout<<"Queue is empty."<<endl;
			return 0;
		}else if(front==rear){
			x=arr[front];
			arr[front]=0;
			front = rear = -1;
			return x;
		}else{
			x=arr[front];
			arr[front]=0;
			front++;
			return x;
		}
	}
	int count(){
		int zero=0;
		if(isEmpty())
			return zero;
		else
			return (rear - front)+1;
	}
	void display(){
		for(int i=0;i<5;i++){
			cout<<arr[i]<<" ";
		}
	}
};

int main(){

	int option, value;
	Queue q1;

	do{
		cout<<"Which operation would you like to perform. Select an option. Enter 0 to exit."<<endl;
		cout<<"1. enqueue()"<<endl;
		cout<<"2. dequeue()"<<endl;
		cout<<"3. isFull()"<<endl;
		cout<<"4. isEmpty()"<<endl;
		cout<<"5. count()"<<endl;
		cout<<"6. display()"<<endl<<endl;

		cout<<"Option #"<<flush;
		cin>>option;

		switch(option){
		case 0:
			break;
		case 1:
			cout<<"Enqueue Function Called"<<endl;
			cout<<"Enter a value to enqueue in the queue >> "<<flush;
			cin>>value;
			q1.enqueue(value);
			cout<<endl;
			break;
		case 2:
			cout<<"Dequeue Function Called"<<endl;
			cout<<"Dequeued value: "<<q1.dequeue()<<endl<<endl;
			break;
		case 3:
			if(q1.isFull())
				cout<<"Queue is Full."<<endl<<endl;
			else
				cout<<"Queue is not Full."<<endl<<endl;
			break;
		case 4:
			if(q1.isEmpty())
				cout<<"Queue is Empty."<<endl<<endl;
			else
				cout<<"Queue is not Empty."<<endl<<endl;
			break;
		case 5:
			cout<<"Count Function Called"<<endl;
			cout<<"There are "<<q1.count()<<" values in queue"<<endl<<endl;
			break;
		case 6:
			cout<<"Display Function Called"<<endl;
			cout<<"All values in the queue are: "<<endl;
			q1.display();
			cout<<endl<<endl;
			break;
		default:
			cout<<"Enter a proper option number"<<endl<<endl;
		}

	}while(option!=0);


	return 0;
}
