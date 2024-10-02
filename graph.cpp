#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class graph{
	public:
	int edges[100][100];
	int s_v;
	graph(int n){
		s_v = n;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				edges[i][j] = 0;
			}
		}
	}
	void add_edge(int x,int y,int w){
		edges[x][y] = w;
	}
	void DFT(int start){
		bool visited[100] = {false};
		stack<int> stk;
		stk.push(start);
		
		
		while(!stk.empty()){
			int node = stk.top();
			stk.pop();
			
			if (!visited[node]) {
			 	cout << node << " ";
	            visited[node] = true;
			}
	        for (int i = s_v - 1; i >= 0; i--) {
	            if (edges[node][i] != 0 && !visited[i]) {
	                stk.push(i);
	            }
	        }  
	   }   
        cout << endl;
	}
	void BFT(int start){
		bool visited[100] = {false};
		queue<int> q;
		q.push(start);
		visited[start] = true;
		
		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout << node << " ";
			
			for(int i=0;i<s_v;i++){
				if(edges[node][i]!=0 && !visited[i]){
					visited[i] = true;
					q.push(i);
				}
			}
		}
		cout << endl;
	}
};
int main(){
	
	int x,y,w,vertices;
	char s;
	cin >> vertices;
	graph g(vertices);
	while(true){
		cin >> s;
		if(s=='e'){
			cin >> x >> y >> w;
			g.add_edge(x,y,w);
			
		}else if(s=='s'){
			while(true){
				cin >> s;
				if(s=='d'){
					cin >> x;
					g.DFT(x);
					
				}else if(s=='b'){
					cin >> x;
					g.BFT(x);
					
				}else if(s=='q'){
					return 0;
				}
			}
		}
		else if(s == 'q'){
			return 0;
		}
	}
}
/*
6
e 0 1 1
e 1 0 1
e 0 2 1
e 2 0 1
e 1 2 1
e 2 1 1
e 2 5 1
e 5 2 1
e 2 4 1
e 4 2 1
e 2 3 1
e 3 2 1
e 3 4 1
e 4 3 1
e 5 4 1
e 4 5 1
s
d 2
d 0
d 5
d 3
b 1
b 0
b 5
q
*/
