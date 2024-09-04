#include<iostream>
using namespace std;
class heap{
	public:
		int q[1000];
		int size=0;
	
	int parent(int i){ return (i-1)/2; }
	int leftchild(int i){ return i * 2 + 1 ;}
	int rightchild(int i){ return i * 2 + 2;}
	heap(){
		q[0]=0;
	}
	void add(int data){
		q[size] = data;
		size++;
		heapifyup();
	}
	void heapifyup(){
		int i = size-1;
		
		while(i>0 && q[i] > q[parent(i)] ){
			swap(q[i], q[parent(i)]);
			i = parent(i);
		}
	}
	void remove(){
		if(size == 0){
			cout << "heap is empty" << endl;
			return;
		}
		int max = q[0];
		
		q[0] = q[--size];
		
		heapifydown(0);
		cout << max << endl;
	}
	void heapifydown(int i){
		int largest = i;
		int l = leftchild(i);
		int r = rightchild(i);
		
		if(l<size && q[l] > q[largest]){
			largest = l;
		}
		if(r<size && q[r] > q[largest]){
			largest = r;
		}
		if(largest != i){
			swap(q[i],q[largest]);
			heapifydown(largest);
		}
		
	}
	void print(){
		for(int i=0;i<size;i++){
			cout << q[i] << " ";
		}
		cout << endl;
	}
};
int main(){
	char s;
	heap h;
	while(true){
		cin >> s;
		if(s=='a'){
			int num;
			cin >> num;
			h.add(num);
			
		}else if(s=='d'){
			h.remove();
			
			
		}else if(s=='p'){
			h.print();
		}else if(s=='e'){
			break;
		}
	}
}
/*
a 18
a 19
a 2
a 10
p
a 258
a 95
p
a 102
a 36
a 98
p
p
a 71
p
a 11
p
a 71
p
d
d
a 150
p
d
d
d
d
p 
*/
