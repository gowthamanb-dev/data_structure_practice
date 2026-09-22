//Infix to Postfix Conversion
#include<iostream>
#include<string.h>
using namespace std;
struct Node{
	char data;
	Node* next;
};
class Stack{
	private:
		Node* top;
		Node* pnew;
	public:
		Stack(){
			top=nullptr;
			pnew=nullptr;
		}
		void push(char x){
			pnew=new Node();
			pnew->data=x;
			pnew->next=top;
			top=pnew;
		}
		void pop(char &dataout){
			dataout=top->data;
			top=top->next;
		}
		void topnode(char &dataout){
			dataout=top->data;
		}
		bool isempty(){
			if(top==nullptr){
				return 1;
			}
			else{
				return 0;
			}
		}
};
int priority(char op){
	if(op=='^'){
		return 3;
	}
	else if((op=='*') || (op=='/')){
		return 2;
	}
	else if((op=='+') || (op=='-')){
		return 1;
	}
	else{
		return 0;
	}
}
bool checkopertor(char a){
	if((a=='+') || (a=='-') || (a=='*') || (a=='/') || (a=='^')){
		return 1;
	}
	else{
		return 0;
	}
}
string intopos(string formula){
	Stack s;
	char character;
	char take;
	string str="";
	for(int i=0;formula[i] != '\0';i++){
		character=formula[i];
		if(character=='('){
			s.push(character);
		}
		else if(character==')'){
			s.pop(character);
			while(character != '('){
				str +=character;
				s.pop(character);
			}
		}
		else if(checkopertor(character)){
			int priority1=priority(character);
			if(!s.isempty()){
				s.topnode(take);
				int priority2=priority(take);
				while((!s.isempty()) && (priority1 <= priority2)){
					str+=take;
					s.pop(take);
					priority2=priority(take);
				}
			}
			s.push(character);
		}
		else{
			str+=character;
		}
	}
	while(!s.isempty()){
		s.pop(take);
		str+=take;
	}
	return str;
}
int main(){
	string formula;
	string postfix;
	cout<<"Infix to Postfix Expression"<<endl
		<<"-----------------------------------------------------------"<<endl;
	cout<<"Enter Infix Expression : ";
	cin>>formula;
	postfix=intopos(formula);
	cout<<"Postfix Expression : "<<postfix<<endl;
	return 0;
}