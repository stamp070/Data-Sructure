#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node *right;
	node(int d){
		data = d;
		left = right = NULL; 
	}
};

node* insert(node* root, int val) {
    if (root == NULL) return new node(val);
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}
void bredth_first(node *r){
	queue<node*> q;
	node *ptr;
	q.push(r);
	q.push(NULL);
	
	while(!q.empty()){
		ptr = q.front();
		q.pop();
		if(ptr == NULL){
			if(!q.empty()){
				cout << "|";
				q.push(NULL);
			}
			
		}else{
			cout << ptr->data << ",";
			if(ptr->left!=NULL) q.push(ptr->left);
			if(ptr->right!=NULL) q.push(ptr->right);
		}
	}
	cout << "|" << endl;
}

node* Delete(node *r, int val){
	if (r == NULL) {
		cout << "tree is empty" << endl;
		return r;
	}
    
    if (val < r->data) {
        r->left = Delete(r->left, val);
    } 
	else if(val > r->data){
        r->right = Delete(r->right, val);
    }
    // data equal to value
	else{
		// leaf node
    	if(r->left == NULL && r->right == NULL){
    		delete r;
    		r = NULL;
    		return r;
		}
		// one child
		else if(r->left == NULL){
			node *temp = r->right;
			delete r;
			return temp;
		}
		// one child
		else if(r->right == NULL){
			node *temp = r->left;
			delete r;
			return temp;
		}
		// two child
		else{
			node *temp = r->right;
			while (temp && temp->left != NULL)
       			temp = temp->left;
			r->data = temp->data;
			r->right = Delete(r->right,temp->data);
			
		}
		
	}
    
    return r;
	
	
}
void preorder(node* r){
	if (r == NULL) return;
	
	cout << r->data<< ",";
	preorder(r->left);
	preorder(r->right);
}
void postorder(node* r){
	if (r == NULL) return;
	
	postorder(r->left);
	postorder(r->right);
	cout << r->data<< ",";
}
void inorder(node* r){
	if (r == NULL) return;
	
	inorder(r->left);
	cout << r->data << ",";
	inorder(r->right);
}
int main(){
	node*r=NULL;
	char s;
	int data;
	
	 while (true) {
        cin >> s;
        if (s == 'a') {
            cin >> data;
            r = insert(r,data);
        } else if (s == 'd') {
            cin >> data;
            r = Delete(r,data);
        } else if (s == 'b') {
            bredth_first(r);
            
        } else if (s == 'i') {
           inorder(r);
           cout << endl;
           
        } else if (s == 'p') {
           preorder(r);
           cout << endl;
           
        } else if (s == 't') {
           postorder(r);
           cout << endl;
           
        } else if (s == 'x') {
            break;
        }
    }

    return 0;
}
/*
a 10
a 7
a 13
a 2
a 9
a 20
a 11
b
i
p
t
d 10
b
d 9 
b
x
*/
