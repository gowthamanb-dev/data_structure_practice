//Breadth First Search Search of Graph
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
enum vcolor{
	White,
	Gray,
	Black
};
struct node{
	int ver;
	node* next;
};
struct vnode{
	string name;
	int d;
	int pi;
	vcolor color;
	node* adjptr;
};
class Graph{
	private:
		vector<vnode> vertex;
		vector<int> queue;
		int front;
		int rear;
		int n;
		void enqueue(int s);
		int dequeue();
		bool isempty();
	public:
		void create();
		void bfs(int s);
		void table_result();
		void printpath(int s,int v);
};
void Graph::enqueue(int s){
		if(rear==n-1){
			return;
		}
		rear++;
		queue[rear]=s;
		if(front==-1){
			front=0;
		}
}
int Graph::dequeue(){
	if((front==-1) && (rear==-1)){
		return -1;
	}
	int a=queue[front];
	front++;
	if(front>rear){
		front=-1;
		rear=-1;
	}
	return a;
}
bool Graph::isempty(){
	if((front==-1) && (rear==-1)){
				return 1;
			}
			else{
				return 0;
			}
}
void Graph::create(){
	int e,u,v;
	cout<<"Enter No of Vetices : ";
	cin>>n;
	vertex.resize(n);
	queue.resize(n);
	queue.clear();
	front=-1;
	rear=-1;
	for(int i=0;i<n;i++){
		cout<<"Enter Name of Vertex "<<i<<" : ";
		cin>>vertex[i].name;
		vertex[i].adjptr=nullptr;
	}
	cout<<"Enter No of Edges : ";
	cin>>e;
	cout<<"Enter Directed Edges(u,v) : "<<endl;
	for(int i=0;i<e;i++){
		cout<<1+i<<" : ";
		cin>>u>>v;
		node* pnew=new node();
		pnew->ver=v;
		pnew->next=nullptr;
		if(vertex[u].adjptr == nullptr){
			vertex[u].adjptr=pnew;
		}
		else{
			node* tem=vertex[u].adjptr;
			while(tem->next != nullptr){
				tem=tem->next;
			}
			tem->next=pnew;
		}
	}
}
void Graph::bfs(int s){
	int u,v;
	for(int i=0;i<n;i++){
		vertex[i].d=INT_MAX;
		vertex[i].pi=-1;
		vertex[i].color=White;
	}
	vertex[s].d=0;
	vertex[s].color=Gray;
	enqueue(s);
	cout<<"BFS Traversel : ";
	while(!isempty()){
		u=dequeue();
		cout<<vertex[u].name<<" ";
		node* p=vertex[u].adjptr;
		while(p != nullptr){
			v=p->ver;
			if(vertex[v].color == White){
				vertex[v].d= vertex[u].d+1;
				vertex[v].pi=u;
				vertex[v].color=Gray;
				enqueue(v);
			}
			p=p->next;
		}
		vertex[u].color=Black;
	}
	cout<<endl;
}
void Graph::printpath(int s,int v){
	if(v>=n){
		cout<<"Invaild Destination"<<endl;
		return;
	}
	if(s==v){
		cout<<vertex[s].name<<" ";
	}
	else if(vertex[v].pi==-1){
		cout<<"No Path Exists"<<endl;
	}
	else{
		printpath(s,vertex[v].pi);
		cout<<" -> "<<vertex[v].name<<" "; 
	}
}
void Graph::table_result(){
	cout<<"Vertex\tAdjacent\tDistance\tParent\tColor"<<endl;
	cout<<"------\t--------\t--------\t------\t-----"<<endl;
	for(int i=0;i<n;i++){
		cout<<vertex[i].name<<"\t";
		node* p=vertex[i].adjptr;
		if(p==nullptr){
			cout<<"-\t\t";
		}
		else{
			while(p!=nullptr){
				cout<<vertex[p->ver].name;
				p=p->next;
				if(p != nullptr){
					cout<<" , ";
				}
			}
			cout<<"\t\t";
		}
		if(vertex[i].d==INT_MAX){
			cout<<"-\t\t";
		}
		else{
			cout<<vertex[i].d<<"\t\t";
		}
		if(vertex[i].pi==-1){
			cout<<"-\t";
		}
		else{
			cout<<vertex[vertex[i].pi].name<<"\t";
		}
		if(vertex[i].color == White){
			cout<<"White"<<endl;
		}
		else if(vertex[i].color==Gray){
			cout<<"Gray"<<endl;
		}
		else{
			cout<<"Black"<<endl;
		}
	}
}
int main(){
	cout<<"BFS Of Graph"<<endl;
	cout<<"-------------------------------------------------------------------"
		<<endl;
	Graph g;
	int s,v;
	g.create();
	cout<<"Enter Source Destination : ";
	cin>>s;
	g.bfs(s);
	g.table_result();
	cout<<"Enter Vertex Destination : ";
	cin>>v;
	g.printpath(s,v);
	return 0;
}