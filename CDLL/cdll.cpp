//Circular Linked List
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* fore;
	Node* back;
};
struct Liststr{
	int count;
	Node* head;
	Node* rear;
};
class CDLL{
	private:
		Liststr list;
		Node* pnew;
		Node* predecessor;
		Node* successor;
		Node* deletenode;
	public:
		CDLL(){
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
			Node* walker=list.head;
			successor=walker;
			if(walker == nullptr){
				return 0;
			}
			if(walker->data == target){
				deletenode=walker;
				return 1;
			}
			if(walker->data > target){
				return 0;
			}
			predecessor=walker;
			walker=walker->fore;
			successor=walker;
			while((walker != list.head) && (walker->data < target)){
				predecessor=walker;
				walker=walker->fore;
				successor=walker;
			}
			if(walker->data == target){
				deletenode=walker;
				return 1;
			}
			else{
				return 0;
			}
		}
		bool insert(int x){
			if(search(x)){
				return 0;
			}
			pnew=new Node();
			pnew->data=x;
			if(predecessor == nullptr){
				if(list.head==nullptr){
					list.head=pnew;
					list.rear=pnew;
				}
				else{
					list.head->back=pnew;
					list.rear->fore=pnew;
				}
				pnew->back=list.rear;
				pnew->fore=list.head;
				list.head=pnew;
			}
			else{
				pnew->fore=successor;
				pnew->back=predecessor;
				predecessor->fore=pnew;
				if(successor == list.head){
					list.rear=pnew;
				}
				successor->back=pnew;
			}
			list.count++;
			return 1;
		}
		bool del(int x){
			if(!search(x)){
				return 0;
			}
			if(predecessor != nullptr){
				predecessor->fore=deletenode->fore;
				deletenode->fore->back=predecessor;
				if(deletenode == list.rear){
					list.rear=predecessor;
				}
			}
			else{
				list.head=deletenode->fore;
				deletenode->fore->back=deletenode->back;
				list.rear->fore=deletenode->fore;
			}
			list.count--;
			if(list.count == 0){
				list.head=nullptr;
				list.rear=nullptr;
			}
			return 1;
		}
		void htr(){
			Node* traversel=list.head;
			if(traversel == nullptr){
				return;
			}
			cout<<traversel->data;
			traversel=traversel->fore;
			while(traversel != list.head){
				cout<<" -> ";
				cout<<traversel->data;
				traversel=traversel->fore;
			}
		}
		void rth(){
			Node* traversel=list.rear;
			if(traversel == nullptr){
				return;
			}
			cout<<traversel->data;
			traversel=traversel->back;
			while(traversel != list.rear){
				cout<<" -> ";
				cout<<traversel->data;
				traversel=traversel->back;
			}
		}
		bool  isempty(){
			if(list.head == nullptr){
				return 1;
			}
			else{
				return 0;
			}
		}
		int count(){
			return list.count;
		}
		bool search_htr(int target,int &index){
			Node* walker=list.head;
			int i=0;
			if(walker == nullptr){
				return 0;
			}
			if(walker->data == target){
				index=i;
				return 1;
			}
			if(walker->data > target){
				return 0;
			}
			walker=walker->fore;
			i++;
			while((walker != list.head) && (walker->data < target)){
				walker=walker->fore;
				i++;
			}
			if(walker->data == target){
				index=i;
				return 1;
			}
			else{
				return 0;
			}
		}
		bool search_rth(int target,int &index){
			Node* walker=list.rear;
			int i=0;
			if(walker == nullptr){
				return 0;
			}
			if(walker->data == target){
				index=i;
				return 1;
			}
			if(walker->data < target){
				return 0;
			}
			walker=walker->back;
			i++;
			while((walker != list.rear) && (walker->data > target)){
				i++;
				walker=walker->back;
			}
			if(walker->data == target){
				index=i;
				return 1;
			}
			else{
				return 0;
			}
		}
		void destory(){
			if(list.head == nullptr){
				cout<<"No List to Destory!"<<endl;
				return;
			}
			Node* tem;
			list.count=0;
			pnew=nullptr;
			predecessor=nullptr;
			successor=nullptr;
			deletenode=nullptr;
			Node* walker=list.head;
			walker=walker->fore;
			while(walker != list.head){
				tem=walker;
				tem->back=nullptr;
				walker=walker->fore;
				tem->fore=nullptr;
				delete tem;
			}
			list.head->back=nullptr;
			list.head=nullptr;
			list.rear->back=nullptr;
			list.rear->fore=nullptr;
			list.rear=nullptr;
			cout<<"List is Destoryed!"<<endl;
		}
};
int main(){
	int send;
	int take;
	int choice;
	CDLL cd;
	bool state=1;
	cout<<"Circular Linked List"<<endl
		<<"---------------------------------------------------------------"<<endl;
	while(state){
		cout<<"1.Insert 2.Delete 3.Search From Head 4.Search from Rear 5.isEmpty "
			<<"6.Count 7.Display from Head 8.Display from Rear 9.Destory 0.Exit"
			<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Insert Node : ";
				cin>>send;
				if(cd.insert(send)){
					cout<<"Inserted Successfully"<<endl;
				}
				else{
					cout<<"Duplication of the Node"<<endl;
				}
				break;
			case 2:
				cout<<"Enter Delete Node : ";
				cin>>send;
				if(cd.del(send)){
					cout<<"Node Deleted!"<<endl;
				}
				else{
					cout<<"Node is Not Presend"<<endl;
				}
				break;
			case 3:
				cout<<"Enter Search Node : ";
				cin>>send;
				if(cd.search_htr(send,take)){
					cout<<"Node is Found at Position(Front) "<<take<<endl;
				}
				else{
					cout<<"Node is Not Found!"<<endl;
				}
				break;
			case 4:
				cout<<"Enter Search Node : ";
				cin>>send;
				if(cd.search_rth(send,take)){
					cout<<"Node is Found at Position(Rear) "<<take<<endl;
				}
				else{
					cout<<"Node is Not Found!"<<endl;
				}
				break;
			case 5:
				if(cd.isempty()){
					cout<<"List is Empty"<<endl;
				}
				else{
					cout<<"List is Not Empty"<<endl;
				}
				break;
			case 6:
				cout<<"Count of the List : "<<cd.count()<<endl;
				break;
			case 7:
				cout<<"Display from Head : ";
				cd.htr();
				cout<<endl;
				break;
			case 8:
				cout<<"Display from Rear : ";
				cd.rth();
				cout<<endl;
				break;
			case 9:
				cd.destory();
				break;
			case 0:
				state=0;
				cout<<"Program Existing....."<<endl;
				break;
			default:
				cout<<"Invaild Choice!"<<endl;
				break;
		}
	}
	return 0;
}