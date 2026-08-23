//Sequencial Search
#include<iostream>
using namespace std;
bool sequencial_search(int a[],int last,int target,int &loc){
	int looker=0;
	while((looker<=last) && (target!=a[looker])){
		looker++;
	}
	loc=looker;
	if(a[looker]==target){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"Squencial Search : "<<endl;
	int n;
	cout<<"Enter Number of Elements : ";
	cin>>n;
	int a[n];
	cout<<"Enter Array Elements : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int target;
	cout<<"Enter Element to Search : ";
	cin>>target;
	int loc;
	if(sequencial_search(a,n-1,target,loc)){
		cout<<"Element found at index "<<loc<<endl;
	}
	else{
		cout<<"Element is Not Found"<<endl;
	}
	return 0;
}