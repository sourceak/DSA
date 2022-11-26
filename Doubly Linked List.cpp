#include <iostream>
using namespace std;

class Node{
public:
	int key, data;
	Node *next;
	Node *previous;

	Node():key(0),data(0),next(NULL),previous(NULL){}
	Node(int k,int d):key(k),data(d),next(NULL),previous(NULL){}
};

class DoublyLinkedList{
public:
	Node *head;

	DoublyLinkedList():head(NULL){}
	DoublyLinkedList(Node* h):head(NULL){
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
		Node* prev = NULL;

		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}else{
			if(head==NULL){
				head=n;
			}else{
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				prev=ptr;
				n->previous=prev;
				ptr->next=n;
			}
			cout<<"key:"<<n->key<<" "<<"data:"<<n->data<<" "<<"previous:"<<n->previous<<" "<<"next:"<<n->next<<" appended"<<endl<<endl;
		}
	}

	void prependNode(Node* n){
		Node* ptr = head;

		if(nodeExists(n->key)!=NULL){
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}else{
			ptr->previous=n;
			n->next=head;
			head=n;
			cout<<"key:"<<ptr->key<<" "<<"data:"<<ptr->data<<" "<<"previous:"<<ptr->previous<<" "<<"next:"<<ptr->next<<" prepend"<<endl<<endl;
		}
	}

	void insertAfterNode(int k, Node* n){
		Node* ptr = nodeExists(k);
		int key = n->key;
		Node* check = nodeExists(key);
		Node* temp = NULL;
		Node* top = head;
		Node* prev = NULL;

		if(check==NULL){
			if(ptr==NULL){
				cout<<"No node with key "<<k<<" exists"<<endl<<endl;
			}else if(ptr->next!=NULL){
				temp=ptr;
				n->previous=temp;
				ptr=ptr->next;
				n->next=ptr;
				temp->next=n;
				ptr->previous=n;
				cout<<"key:"<<n->key<<" "<<"data:"<<n->data<<" "<<"previous:"<<n->previous<<" "<<"next:"<<n->next<<" inserted between keys "<<temp->key<<" & "<<ptr->key<<endl<<endl;
			}else if(ptr->next==NULL){
				cout<<"hello"<<endl;
				while(top->next!=NULL){
					top=top->next;
				}
				prev=top;
				n->previous=prev;
				top->next=n;
				cout<<"key:"<<n->key<<" "<<"data:"<<n->data<<" "<<"previous:"<<n->previous<<" "<<"next:"<<n->next<<" appended"<<endl<<endl;
			}
		}else{
			cout<<"Node with key "<<n->key<<" already exists"<<endl<<endl;
		}
	}

	void updateNode(int k, int val){
		Node* ptr = nodeExists(k);

		if(ptr!=NULL){
			ptr->data=val;
			cout<<"key:"<<ptr->key<<" "<<"data:"<<ptr->data<<" "<<"previous:"<<ptr->previous<<" "<<"next:"<<ptr->next<<" updated"<<endl<<endl;
		}else{
			cout<<"No node with key "<<k<<" exists"<<endl<<endl;
		}
	}

	void deleteNode(int k){
		Node *ptr = head;
		Node *after = NULL;
		Node *prev = NULL;
		Node* current = nodeExists(k);

		if(current!=NULL){
			if(head->key==k){
				head=head->next;
				head->previous=NULL;
			}else if(current->next==NULL){
				while(ptr->next!=current){
					ptr=ptr->next;
				}
				ptr->next=NULL;
			}else{
				while(ptr->next!=current){
					ptr=ptr->next;
				}
				prev=ptr;
				after=current->next;
				after->previous=prev;
				prev->next=after;
			}
			cout<<"key:"<<ptr->key<<" "<<"data:"<<ptr->data<<" "<<"previous:"<<ptr->previous<<" "<<"next:"<<ptr->next<<" deleted"<<endl<<endl;
		}else{
			cout<<"No Node with key "<<k<<" exists"<<endl<<endl;
		}
	}

	void displayNodes(){
		Node* ptr = head;
		cout<<"head: "<<head<<endl;

		while(ptr->next!=NULL){
			cout<<"key:"<<ptr->key<<" "<<"data:"<<ptr->data<<" "<<"previous:"<<ptr->previous<<" "<<"next:"<<ptr->next<<endl<<endl;
			//cout<<ptr->key<<" "<<ptr<<endl;
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
			cout<<"key:"<<ptr->key<<" "<<"data:"<<ptr->data<<" "<<"previous:"<<ptr->previous<<" "<<"next:"<<ptr->next<<endl<<endl;
	}
};

int main(){

	DoublyLinkedList d;
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
			d.appendNode(n1);
			break;
		case 2:
			cout<<"Prepend Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>key;
			n1->key=key;
			cout<<"Enter data: "<<flush;
			cin>>data;
			n1->data=data;
			d.prependNode(n1);
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
			d.insertAfterNode(k1, n1);
			break;
		case 4:
			cout<<"Update Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			cout<<"Enter data: "<<flush;
			cin>>data;
			d.updateNode(k1, data);
			break;
		case 5:
			cout<<"Delete Function Called"<<endl;
			cout<<"Enter key: "<<flush;
			cin>>k1;
			d.deleteNode(k1);
			break;
		case 6:
			cout<<"Display Function Called"<<endl;
			d.displayNodes();
			break;
		default:
			cout<<"Enter Proper Number"<<endl;
		}
	}while(option!=0);

	return 0;
}









