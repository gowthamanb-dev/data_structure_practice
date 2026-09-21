//Singular Linked List
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
struct Lisstr{
	int count;
	Node* link;
};
class SLL{
	private:
		Lisstr list;
		Node* pnew;
		Node* predecessor;
		Node* ploc;
	public:
		SLL(){
			list.count=0;
			list.link=nullptr;
			pnew=nullptr;
			predecessor=nullptr;
			ploc=nullptr;
		}
		bool search(int target){
			predecessor=nullptr;
			ploc=list.link;
			while((ploc!=nullptr) && (ploc->data < target)){
				predecessor=ploc;
				ploc=ploc->next;
			}
			if(ploc==nullptr){
				return 0;
			}
			else{
				if(target == ploc->data){
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
				pnew->next=list.link;
				list.link=pnew;
			}
			else{
				pnew->next=predecessor->next;
				predecessor->next=pnew;
			}
			list.count++;
			return 1;
		}
		bool del(int x){
			if(!search(x)){
				return 0;
			}
			if(predecessor==nullptr){
				list.link=ploc->next;
			}
			else{
				predecessor->next=ploc->next;
			}
			delete ploc;
			list.count--;
			return 1;
		}
		bool isemptylist(){
			if(list.link==nullptr){
				return 1;
			}
			else{
				return 0;
			}
		}
		bool retrieve(int x,int &take){
			Node* walker=list.link;
			int index=0;
			while((walker != nullptr) && (index<x)){
				walker=walker->next;
			}
			if(walker==nullptr){
				return 0;
			}
			else{
				take=walker->data;
				return 1;
			}
		}
		int count(){
			return list.count;
		}
		void display(){
			Node* traversal=list.link;
			while(traversal != nullptr){
				cout<<traversal->data;
				traversal=traversal->next;
				if(traversal != nullptr){
					cout<<" -> ";
				}
			}
			cout<<endl;
		}
		bool destory(){
			list.count=0;
			delete pnew;
			delete predecessor;
			delete ploc;
			while(list.link != nullptr){
				list.link=list.link->next;
			}
			return 1;
		}
};
int main(){
	SLL* list[5];
	int no_list=0;
	bool state=1;
	int id;
	int sent;
	int take;
	int choice;
	cout<<"Singlly Linked List "<<endl<<"-----------------------------------------"<<endl;
	while(state){
		cout<<"1.Create 2.Insert 3.Delete 4.Search "
		    <<"5.isEmptyList 6.Retrieve 7.Count 8.Display "<<
			"9.Destory 10.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				if(no_list>4){
					cout<<"Total No of List is 5"<<endl;
					break;
				}
				list[no_list]=new SLL();
				cout<<"List Created Successfully!"<<endl<<"List ID : "
					<<no_list+1<<endl;
				no_list++;
				break;
			case 2:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"Enter Insert Number : ";
				cin>>sent;
				if(list[id-1]->insert(sent)){
					cout<<"Node Inserted!"<<endl;
				}
				else{
					cout<<"Duplication Node"<<endl;
				}
				break;
			case 3:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"Enter Delete Node : ";
				cin>>sent;
				if(list[id-1]->del(sent)){
					cout<<"Node Deleted!"<<endl;
				}
				else{
					cout<<"Node Not Present"<<endl;
				}
				break;
			case 4:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"Enter Search Node : ";
				cin>>sent;
				if(list[id-1]->search(sent)){
					cout<<"Node is Found!"<<endl;
				}
				else{
					cout<<"Node is Not Found"<<endl;
				}
				break;
			case 5:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				if(list[id-1]->isemptylist()){
					cout<<"List "<<id<<" is Empty"<<endl;
				}
				else{
					cout<<"List "<<id<<" is Not Empty"<<endl;
				}
				break;
			case 6:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"Enter Node to Retrieve(index) : ";
				cin>>sent;
				if(list[id-1]->retrieve(sent,take)){
					cout<<"Node Retrieved : "<<take<<endl;
				}
				else{
					cout<<"Invalid Index"<<endl;
				}
				break;
			case 7:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"List "<<id<<" Count : "<<list[id-1]->count()<<endl;
				break;
			case 8:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				cout<<"Linked List of "<<id<<" : ";
				list[id-1]->display();
				break;
			case 9:
				cout<<"Enter List ID : ";
				cin>>id;
				if(id > no_list+1){
					break;
				}
				if(list[id-1]->destory()){
					cout<<"List "<<id<<" is Destoryed!"<<endl;
				}
				break;
			case 10:
				state=0;
				cout<<"Program is Existing..."<<endl;
				break;
			default:
				cout<<"Invalid Choice"<<endl;
				break;
		}
	}
	return 0;
}