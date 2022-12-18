#include <iostream>
using namespace std;

void binarySearching(int a[], int num){

	int s,m,e;

	s=a[0];
	m=a[10/2];
	e=a[10-1];

	if(num>m){
		s=a[m];
		m=a[(m/2)+m]
	}
	cout<<s<<endl;
	cout<<m<<endl;
	cout<<e<<endl;
}

int main(){

	int arr[10];

	cout<<"Enter a value to search"<<endl;
	int x;

	cout<<"Enter 10 elements for the array"<<endl;
	for(int i=0;i<10;i++){
		int z;
		cin>>z;
		arr[i]=z;
	}

	return 0;
}
