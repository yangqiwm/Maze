// MysteryPlace.cpp : 定义控制台应用程序的入口点。
/*实现迷宫的遍历*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int m=5;
int n = 6;
int q[256*256];
int vis[10][10];
int fa[10][10];
int dist[10][10];
int last_dir[10][10];
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int maze[][5]={{1,1,0,1,1},{1,0,1,1,1},{1,0,1,0,0},{1,0,1,1,1},{1,1,1,0,1},{1,1,1,1,1}};

void mybfs(int x,int y)
{
	int u = x * m +y;
	int *queue = (int *)malloc(sizeof(int) * m * n);
	int front=0,rear =0;
	queue[rear++] = u;
	while(front < rear)
	{
		u = queue[front++];
		for(int i=0;i<4;i++)
		{
			int nx = u/m + dx[i],ny = u%m + dy[i];
			if(nx >=0 && nx <n && ny >=0 && ny <m && maze[nx][ny] && !vis[nx][ny])
			{
				cout<<"nx= "<<nx<<" ny ="<<ny<<endl;
				queue[rear++] = nx *m +ny;
				vis[nx][ny] = 1;
				fa[nx][ny] = u;
				dist[nx][ny] = dist[x][y] +1;
				last_dir[nx][ny] = i;
			}
		}
		//cout<<"front: "<<front<<" rear: "<<rear<<endl;
	}
}

int GetPath(int x,int y)
{
	vector<pair<int,int> > path;
	path.push_back(make_pair(x,y));

	
	while(1)
	{
		int f = fa[x][y];
		x = f/m, y = f % m;
		path.push_back(make_pair(x,y));
		if(0 == x && 0 == y)
			break;
	}
	for(vector<pair<int ,int> >::reverse_iterator it = path.rbegin();it != path.rend();it ++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}

void show(int A[][10],int n,int m,const char *str)
{
	cout<<str<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	mybfs(0,0);
	show(fa,6,5,"fa");
	show(dist,6,5,"dist");
	show(last_dir,6,5,"last_dir");
	GetPath(5,4);
	system("pause");
	return 0;
}

