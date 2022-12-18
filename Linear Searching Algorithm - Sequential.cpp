#include <iostream>
using namespace std;

void linearSearch(int a[], int num){

	for(int i=0; i<5; i++){
		if(a[i]==num){
			cout<<num<<" found at index position "<<i<<endl;
			break;
		}else if(4==i){
			cout<<"Value "<<num<<" is unable to be located"<<endl;
		}
	}
}


int main(){

	int arr[5];
	cout<<"Enter 5 elements for the array"<<endl;

	for(int i=0; i<5; i++){
		int z;
		cin>>z;
		arr[i]=z;
	}

	//show array
	for(int i=0; i<5; i++){
		cout<<arr[i]<<" "<<flush;
	}

	cout<<"Enter a value to search"<<endl;

	int x;
	cin>>x;

	linearSearch(arr,x);

	return 0;
}
