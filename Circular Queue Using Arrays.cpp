#include <iostream>
using namespace std;

class CircularQueue{
private:
	int front, rear;
	int arr[5];
	int itemCount;
public:
	CircularQueue():front(-1),rear(-1),itemCount(0){
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
		if((rear+1)%5==front)
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
			itemCount++;
		}else{
			rear=(rear+1)%5;
			arr[rear]=val;
			itemCount++;
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
			itemCount--;
			return x;
		}else{
			x=arr[front];
			arr[front]=0;
			front=(front+1)%5;
			itemCount--;
			return x;
		}
	}
	int count(){
		return itemCount;
	}
	void display(){
		for(int i=0;i<5;i++){
			cout<<arr[i]<<" ";
		}
	}
};

int main(){

	int option, value;
	CircularQueue cq1;

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
			cq1.enqueue(value);
			cout<<endl;
			break;
		case 2:
			cout<<"Dequeue Function Called"<<endl;
			cout<<"Dequeued value: "<<cq1.dequeue()<<endl<<endl;
			break;
		case 3:
			if(cq1.isFull())
				cout<<"Queue is Full."<<endl<<endl;
			else
				cout<<"Queue is not Full."<<endl<<endl;
			break;
		case 4:
			if(cq1.isEmpty())
				cout<<"Queue is Empty."<<endl<<endl;
			else
				cout<<"Queue is not Empty."<<endl<<endl;
			break;
		case 5:
			cout<<"Count Function Called"<<endl;
			cout<<"There are "<<cq1.count()<<" values in queue"<<endl<<endl;
			break;
		case 6:
			cout<<"Display Function Called"<<endl;
			cout<<"All values in the queue are: "<<endl;
			cq1.display();
			cout<<endl<<endl;
			break;
		default:
			cout<<"Enter a proper option number"<<endl<<endl;
		}

	}while(option!=0);


	return 0;
}
