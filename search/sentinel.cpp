//Sentinel Search
#include<iostream>
using namespace std;
bool sentinel_search(int a[],int last,int target,int &loc){
	int looker=0;
	a[last+1]=target;
	while(target!=a[looker]){
		looker++;
	}
	cout<<"Element after adding Sentinel Element : ";
	for(int i=0;i<=last+1;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	loc=looker;
	if(looker<=last){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"Sentinel Search : "<<endl;
	int n;
	cout<<"Enter Number of Elements : ";
	cin>>n;
	int a[n+1];
	cout<<"Enter Array Elements : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int target;
	cout<<"Enter Element to Search : ";
	cin>>target;
	int loc;
	if(sentinel_search(a,n-1,target,loc)){
		cout<<"Element Found at index "<<loc<<endl;
	}
	else{
		cout<<"Element Not Found"<<endl;
	}
	return 0;
}