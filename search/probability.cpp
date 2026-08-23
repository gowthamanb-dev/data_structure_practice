//Probability Search
#include<iostream>
using namespace std;
bool probability_search(int a[],int last,int target,int &loc){
	int looker=0;
	while((looker<=last) && (target!=a[looker])){
		looker++;
	}
	loc=looker;
	if(a[looker]==target){
		if(looker!=0){
			int tem=a[looker];
			a[looker]=a[looker-1];
			a[looker-1]=tem;
			cout<<"Elements after moving the Search Element : ";
			for(int i=0;i<=last;i++){
				cout<<a[i]<<" ";
			}
			loc--;
			cout<<endl;
		}
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"Probability Search : "<<endl;
	int n;
	cout<<"Enter Number of Elements : ";
	cin>>n;
	int a[n];
	cout<<"Enter Array Elements : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int target;
	bool check;
	while(1){
		cout<<"Enter Element to Search : ";
		cin>>target;
		int loc;
		if(probability_search(a,n-1,target,loc)){
			cout<<"Element Found at index "<<loc<<endl;
		}
		else{
			cout<<"Element Not Found"<<endl;
		}
		cout<<"Enter 1(continue) 0(exit) : ";
		cin>>check;
		if(!check){
			cout<<"Program exists...."<<endl;
			break;
		}
	}
	return 0;
}