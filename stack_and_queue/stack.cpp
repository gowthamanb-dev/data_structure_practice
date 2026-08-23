//Stack
#include<iostream>
using namespace std;
class Stack{
	private:
		int n;
		int *a;
		int top;
	public:
		Stack(int n){
			this->n=n;
			a=new int[5];
			top=-1;
		}
		bool push(int datain){
			if(top==n-1){
				return 0;
			}
			else{
				top++;
				a[top]=datain;
				return 1;
			}
		}
		bool pop(int &dataout){
			if(top==(-1)){
				return 0;
			}
			else{
				dataout=a[top];
				top--;
				return 1;
			}
		}
		bool empty(){
			if(top==(-1)){
				return 1;
			}
			else{
				return 0;
			}
		}
		bool full(){
			if(top==n-1){
				return 1;
			}
			else{
				return 0;
			}
		}
		int count(){
			return top+1;
		}
		bool topelement(int &dataout){
			if(top==(-1)){
				return 0;
			}
			else{
				dataout=a[top];
				return 1;
			}
		}
};
int main(){
	cout<<"Stack : "<<endl;
	int n;
	cout<<"Enter Number of Elements : ";
	cin>>n;
	Stack s(n);
	int choice;
	int x;
	bool con=1;
	while(con){
		cout<<"1.Push 2.Pop 3.Empty 4.Full 5.Count 6.Top 7.Exit"<<endl;
		cout<<"Enter Choice  : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Element to Push : ";
				cin>>x;
				if(s.push(x)){
					cout<<"Insert Element : "<<x<<endl;
				}
				else{
					cout<<"Stack is Full"<<endl;
				}
				break;
			case 2:
				if(s.pop(x)){
					cout<<"Popped Element : "<<x<<endl;
				}
				else{
					cout<<"Stack is Empty"<<endl;
				}
				break;
			case 3:
				if(s.empty()){
					cout<<"Stack is Empty"<<endl;
				}
				else{
					cout<<"Stack is not Empty"<<endl;
				}
				break;
			case 4:
				if(s.full()){
					cout<<"Stack is Full"<<endl;
				}
				else{
					cout<<"Stack is Not Full"<<endl;
				}
				break;
			case 5:
				cout<<"Count : "<<s.count()<<endl;
				break;
			case 6:
				if(s.topelement(x)){
					cout<<"Top Element : "<<x<<endl;
				}
				else{
					cout<<"Stack is Empty"<<endl;
				}
				break;
			case 7:
				con=0;
				break;
		}
	}
	return 0;
}