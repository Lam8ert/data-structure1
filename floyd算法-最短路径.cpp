#include<iostream>
#include<vector>
using namespace std;
#define inf 100 
int main()
{
	int dis[4][4]={{0,10,1,inf},{10,0,4,1},{1,4,0,1},{inf,1,1,0}};
	int path[4][4]={{-1,0,0,-1},{1,-1,1,1},{2,2,-1,2},{-1,3,3,-1}};
	for(int i=0;i<4;i++){
		for(int a=0;a<4;a++){
			for(int b=0;b<4;b++){
				if(i!=a&&i!=b&&a!=b&&dis[a][i]+dis[i][b]<dis[a][b]){
					dis[a][b]=dis[a][i]+dis[i][b];
					path[a][b]=i;
				}
			}
		}
	}
	cout<<"最短路径"<<dis[0][1]<<endl;
	vector<int>v1;
	if(path[0][1]!=0){
		v1.push_back(1);
	}
	int k=path[0][1];
	while(1){
		if(path[0][k]!=0){
			v1.push_back(k);
			k=path[0][k];
		}
		else {
			v1.push_back(k);
			v1.push_back(0);
			break;
		}
	}
	cout<<"经过点";
	for(int i=v1.size()-1;i>=0;i--){
		cout<<v1[i];
	}
}
