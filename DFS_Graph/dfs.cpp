//Depth First Search of Graph
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
enum vcolor{ White,Gray,Black};
struct node{
	int ver;
	node* next;
};
struct vnode{
	string name;
	int d;
	int f;
	int pi;
	vcolor color;
	node* adjptr;
};
class DFS{
	private:
		vector<vnode> vertex;
		int n;
		int time;
	public:
		void create();
		void dfs();
		void dfs_visit(int u);
		void display();
};
void DFS::create(){
	int u,v;
	cout<<"Enter Number of Vertex : ";
	cin>>n;
	vertex.resize(n);
	for(int i=0;i<n;i++){
		cout<<"Enter Name of the Vertex "<<i+1<<" : ";
		cin>>vertex[i].name;
		vertex[i].adjptr=nullptr;
		cout<<"Enter Number of Adjacent Vertices of "<<vertex[i].name<<" : ";
		cin>>u;
		for(int j=0;j<u;j++){
			cout<<"Enter Index of the Adjacent Vertex(1-"<<n<<") : ";
			cin>>v;
			node* pnew=new node();
			pnew->ver=v-1;
			pnew->next=nullptr;
			node* tem=vertex[i].adjptr;
			if(tem == nullptr){
				vertex[i].adjptr=pnew;
			}
			else{
				while(tem->next != nullptr){
					tem=tem->next;
				}
				tem->next=pnew;
			}
		}
	}
}
void DFS::dfs(){
	for(int i=0;i<n;i++){
		vertex[i].pi=-1;
		vertex[i].color=White;
		vertex[i].d=0;
		vertex[i].f=0;
	}
	time=0;
	for(int i=0;i<n;i++){
		if(vertex[i].color == White){
			dfs_visit(i);
		}
	}
}
void DFS::dfs_visit(int v){
	time=time+1;
	vertex[v].d=time;
	vertex[v].color=Gray;
	static bool first=true;
	if(!first){
		cout<<" -> ";
	}
	cout<<vertex[v].name;
	first=false;
	node* walker=vertex[v].adjptr;
	while(walker != nullptr){
		int u=walker->ver;
		if(vertex[u].color == White){
			vertex[u].pi=v;
			dfs_visit(u);
		}
		walker=walker->next;
	}
	time=time+1;
	vertex[v].f=time;
	vertex[v].color=Black;
}
void DFS::display(){
	string msg="";
	cout<<"------------------------------------------------------------------"
	<<"----------------------------------------------------------------"<<endl;
	cout<<"DFS Traversel "<<endl;
	cout<<"------------------------------------------------------------------"
	<<"----------------------------------------------------------------"<<endl;
	cout<<left<<setw(10)<<"Vertex"<<setw(22)<<"Adjacent Vertex"
		<<setw(20)<<"Discovery"<<setw(20)<<"Finishing"<<setw(10)<<"Parent"
		<<setw(10)<<"color"<<endl;
	cout<<"------------------------------------------------------------------"
	<<"----------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<left<<setw(10)<<vertex[i].name;
		node* tem=vertex[i].adjptr;
		if(tem == nullptr){
			msg="NULL";
		}
		else{
			while(tem != nullptr){
				msg=msg+vertex[tem->ver].name;
				tem=tem->next;
				if(tem != nullptr){
					msg=msg+" -> ";
				}
			}
		}
		cout<<left<<setw(22)<<msg;
		cout<<left<<setw(20)<<vertex[i].d;
		cout<<left<<setw(20)<<vertex[i].f;
		msg="";
		if(vertex[i].pi==-1){
			msg="NIL";
		}
		else{
			msg=vertex[vertex[i].pi].name;
		}
		cout<<left<<setw(10)<<msg;
		msg="";
		if(vertex[i].color == White){
			msg="White";
		}
		else if(vertex[i].color == Gray){
			msg="Gray";
		}
		else{
			msg="Black";
		}
		cout<<setw(10)<<msg<<endl;
		msg="";
	}
	cout<<"------------------------------------------------------------------"
	<<"----------------------------------------------------------------"<<endl;
}
int main(){
	DFS d;
	d.create();
	cout<<endl<<"DFS Traversel : ";
	d.dfs();
	cout<<endl;
	d.display();
	return 0;
}