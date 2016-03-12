/*********************
# Code in Linux Mint 17 && G++
# Author: skyword
# Email:  skyword_sun@gmail.com
# Last edited:	2016-03-11 16:58
********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
const double pi=acos(-1);
const int Mod=1e9+7;
bool isprime[20001];
int dp[20010];
int a,ans;
vector<int>v;
void init()
{
	for(int i=2;i<=20000;i++)isprime[i]=true;
	for(int i=2;i<=20000;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(i%j==0){
				isprime[i]=false;
				break;
			}
		}
		if(isprime[i]==true)v.push_back(i);
	}
}
void work(int num,int i)
{
	if(num<0)return ;
	if(num==v[i])ans++;
	else if(num>v[i])
		work(num-v[i],i-1);
	else return;
}
int main()
{
	init();
	while(cin>>a)
	{
		ans=0;
		if(a==0)break;
		int index=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==a)
			{
				ans++;
				index=i-1;
				break;
			}
			else if(v[i]<a)index=i-1;
			else break;
		}
		for(int i = index;i>=0;i--)
		{
			work(a,i);
		}
		printf("%d\n",ans);
	}
}













