#include<bits/stdc++.h>
using namespace std;

struct road{
	int to,dis,next;
} roads[3000];

int farm2road[805]={0}, cowsfarm[505]={0},roadcount=0,N,P,C,diss[805],isinqueue[805]={0};
queue<int> tosearch;

void put(int from,int to,int dis){
	road r;
	r.dis=dis;
	r.to=to;
	r.next=farm2road[from];
	roadcount++;
	roads[roadcount]=r;
	farm2road[from]=roadcount;
}
inline void put(int farm){
    if(isinqueue[farm]==0){
        tosearch.push(farm);
        isinqueue[farm]=1;
    }
}
inline void pop(){
    if(!tosearch.empty()){
        isinqueue[tosearch.front()]=0;
        tosearch.pop();
    }
}
void spfa(int origin){
    put(origin);
    while(!tosearch.empty()){
        int farm=tosearch.front();
        int index=farm2road[farm];
        while(index!=0){
            road r=roads[index];
            index=r.next;
            if(diss[r.to]>diss[farm]+r.dis){
                diss[r.to]=diss[farm]+r.dis;
                put(r.to);
            }
            pop();
        }
    }
    isinqueue[origin]=0;
}
int main(){
	int from,to,dis;
	cin>>N>>P>>C;
	for(int i=1;i<=N;i++){
		cin>>cowsfarm[i];
	}
	for(int i=1;i<=C;i++){
		cin>>from>>to>>dis;
		put(from,to,dis);
		put(to,from,dis);
	}
	int mind=0x77777777;
	for(int i=1;i<=P;i++){
        for(int j=0;j<=P;j++){
            diss[j]=0x77777777;
        }
        diss[i]=0;
        spfa(i);
        int total=0;
        for(int j=1;j<=N;j++){
            total+=diss[cowsfarm[j]];
        }
        mind=min(mind,abs(total));
	}
	cout<<mind;
	return 0;
}
