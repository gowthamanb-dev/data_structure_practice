//Disjoint Set
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct node{
	int data;
	int rank;
	node* parent;
};
class DisjointSet{
	private:
		int n;
		int i;
		vector<node*> element;
	public:
		void create(){
			cout<<"Enter Number of Elements : ";
			cin>>n;
			i=0;
			element.resize(n);
			for(int i=0;i<n;i++){
				make_set(i+1);
				cout<<"Element "<<i+1<<" Created Successfully"<<endl;
			}
		}
		void make_set(int x){
			node* pnew=new node;
			pnew->data=x;
			pnew->rank=1;
			pnew->parent=pnew;
			element[i++]=pnew;
		}
		node* find_set(node* x){
			if(x->parent != x){
				x->parent = find_set(x->parent);
				return x->parent;
			}
			else{
				return x->parent;
			}
		}
		node* find_set(int x){
			if(x<1 || x>n){
				return nullptr;
			}
			else{
				return find_set(element[x-1]);
			}
		}
		void Union(int u,int v){
			node* x=find_set(u);
			node* y=find_set(v);
			if(x != y){
				link(x,y);
				cout<<"Union is made between "<<u<<" and "<<v<<endl;
			}
			else{
				cout<<"Element Alredy in the Set "<<endl;
			}
		}
		void link(node* x,node* y){
			if(x->rank > y->rank){
				y->parent=x;
			}
			else{
				x->parent=y;
				if(x->rank == y->rank){
					y->rank=y->rank+1;
				}
			}
		}
		void display(){
			cout<<left<<setw(15)<<"Data : ";
			for(int i=0;i<n;i++){
				cout<<" "<<left<<setw(3)<<element[i]->data;
			}
			cout<<endl<<left<<setw(15)<<"Parent : ";
			for(int i=0;i<n;i++){
				cout<<" "<<left<<setw(3)<<element[i]->parent->data;
			}
			cout<<endl<<left<<setw(15)<<"Rank : ";
			for(int i=0;i<n;i++){
				cout<<" "<<left<<setw(3)<<element[i]->rank; 
			}
			cout<<endl;
		}
};
int main(){
	cout<<"Disjoint Set "<<endl;
	DisjointSet ds;
	node* tem;
	int choice;
	int x,y;
	bool state=1;
	ds.create();
	while(state){
		cout<<"1.Union 2.Find_Set 3.Display 4.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Element 1 : ";
				cin>>x;
				cout<<"Enter Element 2 : ";
				cin>>y;
				ds.Union(x,y);
				break;
			case 2:
				cout<<"Enter Element to Find in Set : ";
				cin>>x;
				tem=ds.find_set(x);
				if(tem==nullptr){
					cout<<"Element Not in the Set"<<endl;
				}
				else{
					cout<<"Element in the Set : "<<tem->data<<endl;
				}
				break;
			case 3:
				ds.display();
				break;
			case 4:
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