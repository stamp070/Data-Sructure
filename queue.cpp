#include<iostream>
using namespace std;
#define SIZE 4
class CQ {
public:
	int arry[SIZE];
	int tail = -1;
	int head = 0;
	int countsize=0;
	
	int enqueue(int input){
		if(countsize == SIZE){
			return -1;
		}else{
			tail++;
			countsize++;
			arry[tail%SIZE] = input;
		}
		
	}
	
	int dequeue(){
		if(countsize==0){
			return -1;
		}else{
			cout << arry[head] << endl;
			countsize--;
			return arry[head++];
		}
		
	}
	void print(){
		int n = head;
		for(int i = head;i<=tail;i++){
			cout << arry[i%SIZE] << " ";
		}
		cout << endl;
	}
	void showsize(){
		
		cout << countsize << endl;
		
	}
	void firstnlast(){
		cout << arry[head] << " " << arry[tail] << endl;
	}
};
int main(){
	CQ q;
	while(true){
		char s;
		cin >> s;
		if(s=='e'){
			int num;
			cin >> num;
			if(q.enqueue(num)==-1){
				cout << "full" << endl;
			}
		}else if(s=='d'){
			if(q.dequeue()==-1){
				cout << "empty" << endl;
			}
		}else if(s=='p'){
			q.print();
		}else if(s=='n'){
			q.showsize();
		}else if(s=='s'){
			q.firstnlast();
		}else if(s=='x'){
			break;
		}
	}
	return 1;
}
