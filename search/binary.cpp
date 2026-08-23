//Binary Search
#include<iostream>
using namespace std;
bool binary_search(int a[],int last,int target,int &loc){
	int begin=0;
	int end=last;
	int mid;
	while(begin<=end){
		mid=(begin+end)/2;
		if(target > a[mid]){
			begin=mid+1;
		}
		else if(target < a[mid]){
			end=mid-1;
		}
		else{
			begin=end+1;
		}
	}
	loc=mid;
	if(a[mid]==target){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"Binary Search  : "<<endl;
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