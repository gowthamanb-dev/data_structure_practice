 //Queue using SLL
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
struct queuestr{
	int count;
	Node* front;
	Node* rear;
};
class Queue{
	private:
		queuestr line;
		Node* pnew;
	public:
		Queue(){
			line.count=0;
			line.front=nullptr;
			line.rear=nullptr;
		}
		bool enqueue(int x){
			pnew=new Node();
			pnew->data=x;
			pnew->next=nullptr;
			if(line.rear==nullptr){
				line.front=pnew;
				line.rear=pnew;
			}
			else{
				line.rear->next=pnew;
				line.rear=pnew;
			}
			line.count++;
			return 0;
		}
		bool dequeue(int &dataout){
			if(line.front==nullptr && line.rear==nullptr){
				return 0;
			}
			else{
				dataout=line.front->data;
				line.front=line.front->next;
				if(line.front==nullptr){
					line.rear=nullptr;
				}
				line.count--;
				return 1;
			}
		}
		bool retrievefront(int & dataout){
			if(line.front==nullptr && line.rear==nullptr){
				return 0;
			}
			else{
				dataout=line.front->data;
				return 1;
			}
		}
		bool retrieverear(int &dataout){
			if(line.front==nullptr && line.rear==nullptr){
				return 0;
			}
			else{
				dataout=line.rear->data;
				return 1;
			}
		}
		void display(){
			Node* traversel=line.front;
			while(traversel!=nullptr){
				cout<<traversel->data;
				traversel=traversel->next;
				if(traversel != nullptr){
					cout<<" -> ";
				}
			}
			cout<<endl;
		}
		bool isempty(){
			if(line.front==nullptr && line.rear==nullptr){
				return 1;
			}
			else{
				return 0;
			}
		}
		int count(){
			return line.count;
		}
		void destory(){
			line.count=0;
			while(line.front!=nullptr){
				line.front=line.front->next;
			}
			line.rear=nullptr;
			pnew=nullptr;
			cout<<"Queue is Destoryed!"<<endl;
		}
};
int main(){
	Queue q;
	int sent;
	int take;
	int choice;
	bool state=1;
	cout<<"Queue using SLL"<<endl
		<<"--------------------------------------------------"<<endl;
	while(state){
		cout<<"1.Enqueue 2.Dequeue 3.Front_Retrieve 4.Rear_Retrieve 5.isEmpty "
			<<"6.Count 7.Display 8.Destory 9.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Enqueue Node : ";
				cin>>sent;
				if(q.enqueue(sent)){
					cout<<"Node is Enqueued"<<endl;
				}
				break;
			case 2:
				if(q.dequeue(take)){
					cout<<"Dequeue Node : "<<take<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 3:
				if(q.retrievefront(take)){
					cout<<"Front Node : "<<take<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 4:
				if(q.retrieverear(take)){
					cout<<"Rear Node : "<<take<<endl;
				}
				else{
					cout<<"Queue is Empty"<<endl;
				}
				break;
			case 5:
				if(q.isempty()){
					cout<<"Queue is Empty"<<endl;
				}
				else{
					cout<<"Queue is Not Empty"<<endl;
				}
				break;
			case 6:
				cout<<"Count : "<<q.count()<<endl;
				break;
			case 7:
				cout<<"Queue  : ";
				q.display();
				break;
			case 8:
				q.destory();
				break;
			case 9:
				state=0;
				cout<<"Program Existing...."<<endl;
				break;
			default:
				cout<<"Invalid Choice"<<endl;
				break;
		}
	}
	return 0;
}