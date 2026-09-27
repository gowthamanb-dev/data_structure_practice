//Binary Search Tree
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
class BST{
	private:
		Node* root;
		Node* addBST(Node* root,Node* pnew){
			if(root == nullptr){
				return pnew;
			}
			else if(pnew->data < root->data){
				root->left=addBST(root->left,pnew);
				return root;
			}
			else if(pnew-> data > root->data){
				root->right=addBST(root->right,pnew);
				return root;
			}
			else{
				return root;
			}
		}
		Node* find_largest(Node* root){
			if(root->right == nullptr){
				return root;
			}
			else{
				return find_largest(root->right);
			}
		}
		Node* find_smallest(Node* root){
			if(root->left == nullptr){
				return root;
			}
			else{
				return find_smallest(root->left);
			}
		}
		Node* del(Node* root,int delkey){
			if(root == nullptr){
				return nullptr;
			}
			if(delkey < root->data){
				root->left=del(root->left,delkey);
				return root;
			}
			else if(delkey > root->data){
				root->right=del(root->right,delkey);
				return root;
			}
			else{
				if(root->left == nullptr){
					Node* tem=root->right;
					delete root;
					return tem;
				}
				else if(root->right == nullptr){
					Node* tem=root->left;
					delete root;
					return tem;
				}
				else{
					Node* largest=find_largest(root->left);
					root->data=largest->data;
					root->left=del(root->left,largest->data);
					return root;
				}
			}
		}
		bool search_node(Node* root,int target){
			if(root == nullptr){
				return 0;
			}
			else if(target < root->data){
				return search_node(root->left,target);
			}
			else if(target > root->data){
				return search_node(root->right,target);
			}
			else{
				return 1;
			}
		}
		void inorder(Node* root){
			if(root != nullptr){
				inorder(root->left);
				cout<<" "<<root->data<<" ";
				inorder(root->right);
			}
			else{
				return;
			}
		}
		void preorder(Node* root){
			if(root != nullptr){
				cout<<root->data<<" ";
				preorder(root->left);
				preorder(root->right);
			}
			else{
				return;
			}
		}
		void postorder(Node* root){
			if(root != nullptr){
				postorder(root->left);
				postorder(root->right);
				cout<<" "<<root->data<<" ";
			}
			else{
				return;
			}
		}
	public:
		BST(){
			root=nullptr;
		}
		void insert(int x){
			Node* tem=new Node();
			tem->data=x;
			if(search_node(root,x)){
				cout<<"Duplication of the Node"<<endl;
				return;
			}
			root=addBST(root,tem);
			cout<<"Inserted Successfully"<<endl;
		}
		void remove(int x){
			if(!search_node(root,x)){
				cout<<"Node is Not Present"<<endl;
				return;
			}
			root=del(root,x);
			cout<<"Deleted Successfully"<<endl;
		}
		void search(int x){
			if(search_node(root,x)){
				cout<<"Node is Found"<<endl;
			}
			else{
				cout<<"Node is Not Found"<<endl;
			}
		}
		void largest(){
			Node* tem=find_largest(root);
			if(tem == nullptr){
				cout<<"Tree is Empty"<<endl;
			}
			else{
				cout<<"Largest Node : "<<tem->data<<endl;
			}
		}
		void smallest(){
			Node* tem=find_smallest(root);
			if(tem == nullptr){
				cout<<"Tree is Empty"<<endl;
			}
			else{
				cout<<"Smallest Node : "<<tem->data<<endl;
			}
		}
		void display_in(){
			cout<<"Inorder : ";
			inorder(root);
			cout<<endl;
		}
		void display_pre(){
			cout<<"Preorder : ";
			preorder(root);
			cout<<endl;
		}
		void display_post(){
			cout<<"Postorder : ";
			postorder(root);
			cout<<endl;
		}
};
int main(){
	int send;
	int choice;
	bool state=1;
	BST tree;
	cout<<"Binary Search Tree"<<endl
		<<"--------------------------------------------------------"<<endl;
	while(state){
		cout<<"1.Insert 2.Delete 3.Search 4.PreOrder 5.InOrder 6.PostOrder "
			<<"7.LargestNode 8.SmallestNode 9.Exit"<<endl;
		cout<<"Enter Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Insert Node : ";
				cin>>send;
				tree.insert(send);
				break;
			case 2:
				cout<<"Enter Delete Node : ";
				cin>>send;
				tree.remove(send);
				break;
			case 3:
				cout<<"Enter Search Node : ";
				cin>>send;
				tree.search(send);
				break;
			case 4:
				tree.display_pre();
				break;
			case 5:
				tree.display_in();
				break;
			case 6:
				tree.display_post();
				break;
			case 7:
				tree.largest();
				break;
			case 8:
				tree.smallest();
				break;
			case 9:
				state=0;
				cout<<"Program Existing...."<<endl;
				break;
			default:
				cout<<"Invaild Choice!"<<endl;
				break;
		}
	}
	return 0;
}