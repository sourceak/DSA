#include <iostream>
using namespace std;

class Stack{
private:
	int top;
	int arr[5];
public:
	Stack():top(-1){
		for(int i=0;i<5;i++){
			arr[i]=0;
		}
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	bool isFull(){
		if(top==4)
			return true;
		else
			return false;
	}
	void push(int val){
		if(isFull()){
			cout<<"Stack is in overflow"<<endl;
		}else{
			top++;
			arr[top]=val;
		}
	}
	int pop(){
		if(isEmpty()){
			cout<<"Stack is in underflow"<<endl;
			return 0;
		}else{
			int popVal=arr[top];
			arr[top]=0;
			top--;
			return popVal;
		}
	}
	int count(){
		return top+1;
	}
	void change(int val, int pos){
		arr[pos]=val;
		cout<<"Value at location "<<pos<<" changed to "<<val<<endl;
	}
	int peek(int pos){
		if(isEmpty()){
			cout<<"Stack is in underflow"<<endl;
			return 0;
		}else{
			return arr[pos];
		}
	}
	void display(){
		cout<<"All values in the Stack are:"<<endl;
		for(int i=4;i>-1;i--){
			cout<<i<<": "<<arr[i]<<endl;
		}
	}
};

int main(){

	Stack s1;
	int option, value, position;
	do{
		cout<<"Which operation would you like to perform. Select an option. Enter 0 to exit."<<endl;
		cout<<"1. Push()"<<endl;
		cout<<"2. Pop()"<<endl;
		cout<<"3. isFull()"<<endl;
		cout<<"4. isEmpty()"<<endl;
		cout<<"5. peek()"<<endl;
		cout<<"6. count()"<<endl;
		cout<<"7. change()"<<endl;
		cout<<"8. display()"<<endl<<endl;

		cout<<"Option #"<<flush;
		cin>>option;

		switch(option){
		case 0:
			break;
		case 1:
			cout<<"Push Function Called"<<endl<<endl;
			cout<<"Enter an item to push to the stack >> "<<flush;
			cin>>value;
			s1.push(value);
			break;
		case 2:
			cout<<"Pop Function Called"<<endl<<endl;
			cout<<"Popped value: "<<s1.pop()<<endl;
			break;
		case 3:
			if(s1.isFull()){
				cout<<"Stack is Full."<<endl;
			}else{
				cout<<"Stack is not Full."<<endl;
			}
			break;
		case 4:
			if(s1.isEmpty()){
				cout<<"Stack is Empty."<<endl;
			}else{
				cout<<"Stack is not Empty."<<endl;
			}
			break;
		case 5:
			cout<<"Peek Function Called"<<endl<<endl;
			cout<<"Enter Position >> "<<flush;
			cin>>position;
			cout<<"Value at position "<<position<<" is "<<s1.peek(position)<<endl;
			break;
		case 6:
			cout<<"Count Function Called"<<endl<<endl;
			cout<<"There are "<<s1.count()<<" items in the Stack"<<endl;
			break;
		case 7:
			cout<<"Change Function Called"<<endl<<endl;
			cout<<"Enter Position >> "<<flush;
			cin>>position;
			cout<<"Enter Value >> "<<flush;
			cin>>value;
			s1.change(value, position);
			break;
		case 8:
			cout<<"Display Function Called"<<endl<<endl;
			s1.display();
			break;
		default:
			cout<<"Enter proper option number"<<endl;
		}
	}while(option!=0);

	return 0;
}
