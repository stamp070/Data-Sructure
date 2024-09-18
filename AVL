#include<iostream>
using namespace std;
class node{
	public:
	int key;
	node *left;
	node *right;
	int height;
	
	node(int data){
		key = data;
		left = right = NULL;
		height = 1;
	}
};

int height(node* root){
	if(root == NULL) return 0;
	
	return root->height;
}

int getbalance(node* root){
	if(root == NULL) return 0;
	return height(root->left) - height(root->right);
}

node *rightRotate(node* y){
	node* x = y->left;
	node* T2 = x->right;
	
	//rotate
	x->right = y;
	y->left = T2;
	
	// update height
	x->height = 1 + max(height(x->left),height(x->right));
	y->height = 1 + max(height(y->left),height(y->right));
	return x;
}

node *leftRotate(node* x){
	node* y = x->right;
	node* T2 = y->left;
	
	//rotate
	y->left = x;
	x->right = T2;
	
	// update height
	x->height = 1 + max(height(x->left),height(x->right));
	y->height = 1 + max(height(y->left),height(y->right));
	return y;
}

node *insert(node* root,int key){
	if (root == NULL) return new node(key);
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    
    // update height
    root->height = 1 + max(height(root->left),height(root->right));
    
    int balance = getbalance(root);
    
    // left left case
    if(balance > 1 && key < root->left->key){
    	return rightRotate(root);
	}
	
	// left right case
	if(balance >1 && key > root->left->key){
		root->left = leftRotate(root->left); 
		return rightRotate(root);
	}
	
	// right right case
	if(balance < -1 && key > root->right->key){
		return leftRotate(root);
	}
	
	// right left case
	if(balance < -1 && key < root->right->key){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
    
}

node *deleteNode(node* root, int key){
	
	if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } 
	else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    // data equal to value
	else{
		// leaf node
    	if(root->left == NULL && root->right == NULL){
    		delete root;
    		root = NULL;
    		return root;
		}
		// one child
		else if(root->left == NULL){
			node *temp = root->right;
			delete root;
			return temp;
		}
		// one child
		else if(root->right == NULL){
			node *temp = root->left;
			delete root;
			return temp;
		}
		// two child
		else{
			node *temp = root->right;
			while (temp && temp->left != NULL)
       			temp = temp->left;
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
	if (root == NULL) {
		return root;
	}
	// update height
    root->height = 1 + max(height(root->left),height(root->right));
    
    int balance = getbalance(root);
    
    // left left case
    if(balance > 1 && getbalance(root) >=0){
    	return rightRotate(root);
	}
	
	// left right case
	if(balance >1 && getbalance(root) < 0){
		root->left = leftRotate(root->left); 
		return rightRotate(root);
	}
	
	// right right case
	if(balance < -1 && getbalance(root)<=0){
		return leftRotate(root);
	}
	
	// right left case
	if(balance < -1 && getbalance(root) >0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
	
}

void preorder(node* root){
	if(root == NULL) return;
	
	cout << root->key << " ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	
    node* root = NULL;
    char inp;
    int data;

    while (true) {
        cin >> inp;

        if (inp == 'a') {
            cin >> data;
            root = insert(root, data);
        } else if (inp == 'd') {
            cin >> data;
            root = deleteNode(root, data);
        } else if (inp == 'p') {
            preorder(root);
            cout << endl;
        } else if (inp == 'x') {
            break;
        }
    }

}
