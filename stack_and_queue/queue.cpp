//Queue
#include<iostream>
using namespace std;
class Queue{
	private:
		int n;
		int *a;
		int front;
		int rear;
	public:
		Queue(int n){
			this->n=n;
			front=-1;
			rear=-1;
			a=new int[n];
		}
		bool enqueue(int datain){
			if(rear==n-1){
				return 0;
			}
			else{
				rear++;
				a[rear]=datain;
				if(front==-1){
					front=0;
				}
				return 1;
			}
		}
		bool dequeue(int &dataout){
			if((front==-1) && (rear==-1)){
				return 0;
			}
			else{
				dataout=a[front];
				if(front==rear){
					front=-1;
					rear=-1;
				}
				else{
					front++;
				}
				return 1;
			}
		}
		bool empty(){
			if((front==-1) && (rear==-1)){
				return 1;
			}
			else{
				return 0;
			}
		}
		bool full(){
			if(rear==n-1){
				return 1;
			}
			else{
				return 0;
			}
		}
		bool queuefront(int& dataout){
			if((front==-1) && (rear==-1)){
				return 0;
			}
			else{
				dataout=a[front];
				return 1;
			}
		}
		bool queuerear(int &dataout){
			if((front==-1) && (rear==-1)){
				return 0;
			}
			else{
				dataout=a[rear];
				return 1;
			}
		}
		int count(){
			if((front==-1) && (rear==-1)){
				return 0;
			}
			else{
				return (rear-front+1);
			}
		}
};
int main(){
	cout<<"Queue : "<<endl;
	int n;
	cout<<"Enter Number of Elements  : ";
	cin>>n;
	Queue q(n);
	int choice;
	int x;
	bool con=1;
	while(con){
		cout<<"1.Enqueue 2.Dequeue 3.Empty 4.Full 5.Front 6.Rear 7.Count 8.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Element to Enqueue : ";
				cin>>x;
				if(q.enqueue(x)){
					cout<<"Enqueue : "<<x<<endl;
				}
				else{
					cout<<"Queue is Full"<<endl;
				}
				break;
			case 2:
				if(q.dequeue(x)){
					cout<<"Dequeue Element : "<<x<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 3:
				if(q.empty()){
					cout<<"Queue is Empty"<<endl;
				}
				else{
					cout<<"Queue is Not Empty"<<endl;
				}
				break;
			case 4:
				if(q.full()){
					cout<<"Queue is Full"<<endl;
				}
				else{
					cout<<"Queue is not Full"<<endl;
				}
				break;
			case 5:
				if(q.queuefront(x)){
					cout<<"Front Element : "<<x<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 6:
				if(q.queuerear(x)){
					cout<<"Rear Element : "<<x<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 7:
				cout<<"Count : "<<q.count()<<endl;
				break;
			case 8:
				con=0;
				break;
		}
	}
	return 0;
}