//Doubly Linked List
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* fore;
	Node* back;
};
struct liststr{
	int count;
	Node* head;
	Node* rear;
};
class DLL{
	private:
		liststr list;
		Node* pnew;
		Node* predecessor;
		Node* successor;
		Node* deletenode;
	public:
		DLL(){
			list.count=0;
			list.head=nullptr;
			list.rear=nullptr;
			pnew=nullptr;
			predecessor=nullptr;
			successor=nullptr;
			deletenode=nullptr;
		}
		bool search(int target){
			predecessor=nullptr;
			successor=nullptr;
			Node* walker=list.head;
			while((walker != nullptr) && (walker->data < target)){
				predecessor=walker;
				walker=walker->fore;
				successor=walker;
			}
			if(walker == nullptr){
				return 0;
			}
			else{
				if(walker->data == target){
					deletenode=walker;
					return 1;
				}
				else{
					return 0;
				}
			}
		}
		bool insert(int x){
			if(search(x)){
				return 0;
			}
			pnew=new Node();
			pnew->data=x;
			if(predecessor == nullptr){
				pnew->back=nullptr;
				pnew->fore=list.head;
				list.head=pnew;
			}
			else{
				pnew->fore=successor;
				pnew->back=predecessor;
				predecessor->fore=pnew;
			}
			if(successor == nullptr){
				list.rear=pnew;
			}
			else{
				successor->back=pnew;
			}
			list.count++;
			return 1;
		}
		bool del(int x){
			if(!search(x)){
				return 0;
			}
			if(deletenode->back != nullptr){
				predecessor->fore=deletenode->fore;
			}
			else{
				list.head=deletenode->fore;
			}
			if(deletenode->fore != nullptr){
				successor->back=deletenode->back;
			}
			else{
				list.rear=deletenode->back;
			}
			list.count--;
			return 1;
		}
		void htr(){
			Node* walker=list.head;
			while(walker != nullptr){
				cout<<walker->data;
				walker=walker->fore;
				if(walker != nullptr){
					cout<<" - > ";
				}
			}
			cout<<endl;
		}
		void rth(){
			Node* walker=list.rear;
			while(walker != nullptr){
				cout<<walker->data;
				walker=walker->back;
				if(walker != nullptr){
					cout<<" -> ";
				}
			}
			cout<<endl;
		}
		bool search_htr(int target,int &index){
			Node* walker=list.head;
			int i=0;
			while((walker != nullptr) && (walker->data < target)){
				walker=walker->fore;
				i++;
			}
			if(walker == nullptr){
				index=-1;
				return 0;
			}
			else{
				if(target == walker->data){
					index=i;
					return 1;
				}
				else{
					index=-1;
					return 0;
				}
			}
		}
		bool search_rth(int target,int &index){
			Node* walker=list.rear;
			int i=0;
			while((walker != nullptr) && (walker->data > target)){
				walker=walker->back;
				i++;
			}
			if(walker == nullptr){
				index=-1;
				return 0;
			}
			else{
				if(target == walker->data){
					index=i;
					return 1;
				}
				else{
					index=-1;
					return 0;
				}
			}
		}
		int count(){
			return list.count;
		}
		void destory(){
			pnew=nullptr;
			predecessor=nullptr;
			successor=nullptr;
			list.count=0;
			list.rear=nullptr;
			while(list.head != nullptr){
				list.head=list.head->fore;
			}
			cout<<"List is Destoryed!"<<endl;
		}
};
int main(){
	DLL d;
	bool state=1;
	int sent;
	int take;
	int choice;
	cout<<"Doubly Linked List"<<endl
		<<"-------------------------------------------------------"<<endl;
	while(state){
		cout<<"1.insert 2.Delete 3.Search from Head 4.Search from Rear "
			<<"5. Display from Head 6.Dispay from Rear 7.Count 8.Destory 9.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Insert Node : ";
				cin>>sent;
				if(d.insert(sent)){
					cout<<"Node is Inserted!"<<endl;
				}
				else{
					cout<<"Node is Already Present"<<endl;
				}
				break;
			case 2:
				cout<<"Enter Delete Node : ";
				cin>>sent;
				if(d.del(sent)){
					cout<<"Node is Deleted!"<<endl;
				}
				else{
					cout<<"Node is Not Found"<<endl;
				}
				break;
			case 3:
				cout<<"Enter Search Node : ";
				cin>>sent;
				if(d.search_htr(sent,take)){
					cout<<"Node Found at the Position(Head) : "<<take<<endl;
				}
				else{
					cout<<"Node Not Found"<<endl;
				}
				break;
			case 4:
				cout<<"Enter Search Node : ";
				cin>>sent;
				if(d.search_rth(sent,take)){
					cout<<"Node Found at the Position(Rear) : "<<take<<endl;
				}
				else{
					cout<<"Node Not Found"<<endl;
				}
				break;
			case 5:
				cout<<"DLL From Head : ";
				d.htr();
				break;
			case 6:
				cout<<"DLL From Rear : ";
				d.rth();
				break;
			case 7:
				cout<<"Count : "<<d.count()<<endl;
				break;
			case 8:
				d.destory();
				break;
			case 9:
				state=0;
				cout<<"Program Existing....."<<endl;
				break;
			default:
				cout<<"Invalid Choice : "<<endl;
				break;
		}
	}
	return 0;
}