//Binary Search(Recursive)
#include<iostream>
using namespace std;
bool binary_search(int a[],int last,int target,int &mid,int begin=0){
	if(begin>last){
		return 0;
	}
	mid=(begin+last)/2;
	if(target > a[mid]){
		return binary_search(a,last,target,mid,mid+1);
	}
	else if(target < a[mid]){
		return binary_search(a,mid-1,target,mid,begin);
	}
	else{
		return 1;
	}
}
int main(){
	cout<<"Binary Search(Recursive) : "<<endl;
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
	if(binary_search(a,n-1,target,loc)){
		cout<<"Element Found at index "<<loc<<endl;
	}
	else{
		cout<<"Element Not Found"<<endl;
	}
	return 0;
}