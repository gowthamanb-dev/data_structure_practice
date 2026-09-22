//Stack using SLL
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
struct stackstr{
	int count;
	Node* top;
};
class Stack{
	private:
		stackstr pile;
		Node* pnew;
	public:
		Stack(){
			pile.count=0;
			pile.top=nullptr;
			pnew=nullptr;
		}
		bool push(int x){
			pnew=new Node();
			pnew->data=x;
			pnew->next=pile.top;
			pile.top=pnew;
			pile.count++;
			return 1;
		}
		bool pop(int &dataout){
			if(pile.top == nullptr){
				return 0;
			}
			else{
				dataout=pile.top->data;
				pile.top=pile.top->next;
				pile.count--;
				return 1;
			}
		}
		bool top(int &dataout){
			if(pile.top==nullptr){
				return 0;
			}
			else{
				dataout=pile.top->data;
				return 1;
			}
		}
		int count(){
			return pile.count;
		}
		bool isempty(){
			if(pile.top==nullptr){
				return 1;
			}
			else{
				return 0;
			}
		}
		void display(){
			Node* traversel=pile.top;
			while(traversel != nullptr){
				cout<<traversel->data;
				traversel=traversel->next;
				if(traversel != nullptr){
					cout<<" -> ";
				}
			}
			cout<<endl;
		}
		void destory(){
			pile.count=0;
			while(pile.top!=nullptr){
				pile.top=pile.top->next;
			}
			cout<<"Stack is Destoryed!"<<endl;
		}
};
int main(){
	Stack s;
	int sent;
	int take;
	int choice;
	bool state=1;
	cout<<"Stack Using SLL"<<endl
		<<"-------------------------------------------------"<<endl;
	while(state){
		cout<<"1.Push 2.Pop 3.Top 4.IsEmpty 5.Count 6.Display 7.Destroy 8.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Push Node : ";
				cin>>sent;
				s.push(sent);
				break;
			case 2:
				if(s.pop(take)){
					cout<<"Popped Node : "<<take<<endl;
				}
				else{
					cout<<"Stack is Empty"<<endl;
				}
				break;
			case 3:
				if(s.top(take)){
					cout<<"Top Node : "<<take<<endl;
				}
				else{
					cout<<"Stack is Empty"<<endl;
				}
				break;
			case 4:
				if(s.isempty()){
					cout<<"Stack is Empty"<<endl;
				}
				else{
					cout<<"Stack is Not Empty"<<endl;
				}
				break;
			case 5:
				cout<<"Count of the Stack : "<<s.count()<<endl;
				break;
			case 6:
				cout<<"Stack : ";
				s.display();
				break;
			case 7:
				s.destory();
				break;
			case 8:
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