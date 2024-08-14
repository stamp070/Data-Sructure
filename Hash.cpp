#include <iostream>
#include<string>
#define size 17
using namespace std;
class node{
	public:
	int key;
	string value;
	node* next;
	node(){
		key=-1;
		value = "-";
		next = NULL;
	}
	node(int k,string v){
		key = k;
		value = v;
	}
};
class HashTable{
	public:
	node* table[size];
	HashTable(){
		for(int i=0;i<size;i++){
			table[i] = new node;
		}
	}
	void add(int key,string value){
		int index = key%size;
		
		// check already have key
		node* n = table[index];
		bool check = false;
		while(n!=NULL){
			
			if(n->key==key){
				check = true;
			}
			n=n->next;
			
		}
		
		if(check){
			
			cout << "key already exist" << endl;
			return;
		}else{
			
			if(table[index]->key==-1){
				table[index]->key = key;
				table[index]->value = value;
			}else{
				node* check = table[index];
				while(check->next!=NULL){
					check = check->next;
				}
				check->next = new node(key,value);
				
			}
		}
	}
	void search(int key){
		int index = key%size;
		if(table[index]->key==key){
			cout << table[index]->value << endl;
			return;
		}else{
			node *check = table[index];
			while(check!=NULL){
				if(check->key==key){
					cout << check->value << endl;
					return;
				}
				check=check->next;
			}
			cout << "-" << endl;
			return;
		}
	}
	
	void print(){
		for(int i=0;i<size;i++){
			cout <<"(" << table[i]->key << "," << table[i]->value << ")" ;
			node* n = table[i];
			while(n->next!=NULL){
				n=n->next;
				cout <<"(" << n->key << "," << n->value << ")";
			}
			cout << endl;
		}
	}
	
};

int main(){
	HashTable h;
	char s;
	int key;
	string value;
	while(true){
		cin >> s;
		if(s=='a'){
			cin >> key >> value;
			h.add(key,value);
			
		}else if(s=='p'){
			h.print();
		}else if(s=='s'){
			cin >> key;
			h.search(key);
		}else if(s=='e'){
			break;
		}
	}
	
}
