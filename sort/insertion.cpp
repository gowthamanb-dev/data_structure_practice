//Insertion Sort
#include<iostream>
using namespace std;
void insertion_sort(int a[],int n){
	for(int i=1;i<=n;i++){
		int key=a[i];
		int j=i-1;
		while((j>=0) && (a[j]>key)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		cout<<"Element after pass - "<<i<<" : ";
		for(j=0;j<=n;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n;
	cout<<"Insertion Sort : "<<endl;
	cout<<"Enter No of the Element : ";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter Element of the Array : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion_sort(a,n-1);
	cout<<endl<<"Elements after Sorted : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}