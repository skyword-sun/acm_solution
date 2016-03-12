/*********************
# Code in Linux Mint 17 && G++
# Author: skyword
# Email:  skyword_sun@gmail.com
# Last edited:	2016-03-12 09:16
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
void init()//first we should initial all the prime number and get a bool-table and a vector to store them.
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
/*
for a number num,we should try the maxinum prime number that below num,and try num-prime_now with a less prime number .
and there is another excellent point , every time we always find a solution where prime numbers are found in decreasing order
so ,we will not count 5=3+2 and 5=2+3 as two different solution for 5. that's nice,find a solution in some kind of order,likes
decreasing or increasing ,will help us avoid the duplicate solution.
 */
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













