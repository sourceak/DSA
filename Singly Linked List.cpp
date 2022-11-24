#include <iostream>
using namespace std;

class Node{
public:
	int key, data;
	Node *next;
	Node():key(0),data(0),next(NULL){}
	Node(int k,int d){
		key = k;
		data = d;
		next = NULL;
	}
};

class SinglyLinkedList{
public:
	Node *head;

	SinglyLinkedList():head(NULL){}
	SinglyLinkedList(Node* h):head(NULL){
		head = h; //the first node is the head
	}

	Node* nodeExists(int k){
		Node* ptr = head;
		Node* temp = NULL;
		while(ptr!=NULL){
			if(ptr->key==k){
				temp=ptr;
			}
			ptr=ptr->next;
		}
		return temp;
	}

	void appendNode(Node* n){
		Node* ptr = head;

		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl;
		}else{
			if(head==NULL){
				head=n;
			}else{
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=n;
			}
			cout<<"key data next"<<endl;
			cout<<n->key<<"   "<<n->data<<"   "<<n->next<<" appended"<<endl<<endl;
		}
	}

	void prependNode(Node* n){
		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl;
		}else{
			n->next=head;
			head=n;
			cout<<"key data next"<<endl;
			cout<<n->key<<"   "<<n->data<<"   "<<n->next<<" prepended"<<endl;
		}
	}

	void insertAfterNode(int k, Node* n){
		Node* ptr = nodeExists(k);
		int key = n->key;
		Node* check = nodeExists(key);
		Node* temp = NULL;
		if(check==NULL){
			if(ptr==NULL){
				cout<<"No node with key "<<k<<" exists"<<endl;
			}else{
				temp=ptr;
				ptr=ptr->next;
				n->next=ptr;
				temp->next=n;
				cout<<"key data next"<<endl;
				cout<<n->key<<"   "<<n->data<<"   "<<n->next<<" inserted between keys "<<temp->key<<" & "<<ptr->key<<endl;
			}
		}else{
			cout<<"Node with key "<<n->key<<" already exists"<<endl;
		}
	}

	void updateNode(int k, int val){
		Node* ptr = nodeExists(k);
		if(ptr!=NULL){
			ptr->data=val;
			cout<<"key data next"<<endl;
			cout<<ptr->key<<"   "<<ptr->data<<"   "<<ptr->next<<" update"<<endl;
		}else{
			cout<<"No node with key "<<k<<" exists"<<endl;
		}
	}

	void deleteNode(int k){
		Node *ptr = head;
		Node *after = NULL;
		Node *previous = NULL;
		Node* current = nodeExists(k);

		if(current!=NULL){
			if(head->key==k){
				head=head->next;
			}else if(current->next==NULL){
				while(ptr->next!=current){
					ptr=ptr->next;
				}
				ptr->next=NULL;
			}else{
				while(ptr->next!=current){
					ptr=ptr->next;
				}
				previous=ptr;
				after=current->next;
				previous->next=after;
			}
			cout<<"key data next"<<endl;
			cout<<current->key<<"   "<<current->data<<"   "<<current->next<<" deleted"<<endl;
		}else{
			cout<<"No Node with key "<<k<<" exists"<<endl;
		}
	}
	void displayNodes(){
		Node* ptr = head;
		cout<<endl;
		cout<<"key data next"<<endl;
		while(ptr->next!=NULL){
			cout<<ptr->key<<"   "<<ptr->data<<"   "<<ptr->next<<endl;
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
			cout<<ptr->key<<"   "<<ptr->data<<"   "<<ptr->next<<endl;
		cout<<endl;
	}
};

int main(){

	SinglyLinkedList s;
	int option, key, data, k1;

	do{
		cout<<"What operation would you like to perform? Select Option Number. Enter 0 to exit."<<endl;
		cout<<"1. Append Node()"<<endl;
		cout<<"2. Prepend Node()"<<endl;
		cout<<"3. Insert After Node()"<<endl;
		cout<<"4. Update Node()"<<endl;
		cout<<"5. Delete Node()"<<endl;
		cout<<"6. Display Node()"<<endl<<endl;

		cout<<"Enter option # >> "<<flush;
		cin>>option;
		cout<<endl;
		Node *n1 = new Node();

		switch(option){
		case 0:
			break;
		case 1:
			cout<<"Append Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			s.appendNode(n1);
			break;
		case 2:
			cout<<"Prepend Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			s.prependNode(n1);
			break;
		case 3:
			cout<<"Insert Function Called"<<endl;
			cout<<"Enter Node to Insert After: "<<flush;
			cin>>k1;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			s.insertAfterNode(k1, n1);
			break;
		case 4:
			cout<<"Update Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			cout<<"Enter data: "<<flush;
			cin>>data;
			s.updateNode(k1, data);
			break;
		case 5:
			cout<<"Delete Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			s.deleteNode(k1);
			break;
		case 6:
			cout<<"Display Function Called"<<endl;
			s.displayNodes();
			break;
		default:
			cout<<"Enter Proper Number"<<endl;
		}
	}while(option!=0);

	return 0;
}









