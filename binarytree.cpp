#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
	node(int d){
		int data = d;
		left = right = NULL; 
	}
};
class tree{
	public:
		
};
void preorder(node *r){
	if(r!=NULL){
		cout << r->data;
		preorder(r->left);
		preorder(r->right);
	}
}
void postorder(node * r){
	if(r!=NULL){
		preorder(r->left);
		preorder(r->right);
		cout << r->data;
	}
}
void inorder(node *r){
	if(r==NULL){
		inorder(r->left);
		cout << r->data;
		inorder(r->right);
	}
}
int main(){
	node *root=NULL;
	while(true){
		
	}
}
