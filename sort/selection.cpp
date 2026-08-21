//Selection Sort
#include<iostream>
using namespace std;
void selection_sort(int a[],int n){
	for(int i=0;i<=n-1;i++){
		int min=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp;
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
		cout<<"Element after pass - "<<i+1<<" : ";
		for(int j=0;j<=n;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n;
	cout<<"Selection Sort : "<<endl;
	cout<<"Enter Number of the Element : ";
	cin>>n;
	int *a=new int[n];
	cout<<"Enter Element of the Array : ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selection_sort(a,n-1);
	cout<<endl<<"Sorted Array : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}