#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#include<unordered_map>
#define ull unsigned long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=100;
unordered_map<int,int> tip;
unordered_map<ull,int> tip2;
char c[N],tmp[N];
int nowlen,flag;
inline int getHash(){
	int ans=0;
	for (int i=1;i<=nowlen;++i){
		ans=(37ll*ans+c[i]-'a'+1)%1926081700000;
	}
	return ans;
}
inline ull getHash2(){
	ull ans=0;
	for (int i=1;i<=nowlen;++i){
		ans=ans*31+c[i];
	}
	return ans;
}
int lt;
const int M=26;
char ch[M];
//const int FL=1000000;
//char ftmp[FL][N];
int main(){
	srand((unsigned long long)new char);
	srand(rand()*rand());
	for (int i=0;i<26;++i) ch[i]='a'+i;
	freopen("tmp","w",stdout);
	nowlen=5;
	string ttt;
	while (!flag){
	//	ttt.clear();
		for (int i=1;i<=nowlen;++i) c[i]=ch[rand()%M];//,ttt.push_back(c[i]);
		ull h=getHash(),h2=getHash2();
		++lt;
		if (tip.count(h)&&!tip2.count(h2)){
//			fclose(stdout);
			flag=tip[h];
//			freopen("tmp","r",stdin);
//			for (int i=1;i<=flag;++i) scanf("%s",tmp);
//			fclose(stdin);
//			freopen("tmp","a",stdout);
//			if (strcmp(tmp,c+1)==0) flag=0;
//			if (flag)
			break;
		}
		tip[h]=lt;
		tip2[h2]=lt;
		printf("%s\n",c+1);
		if (!(lt&((1<<20)-1))) cerr<<lt<<endl;
		if (lt==(1<<21)){
			freopen("result.out","w",stdout);
			printf("-1\n");
			fclose(stdout);
			exit(-1);
		}
	}
	fclose(stdout);
	cerr<<"----"<<flag<<' '<<lt<<endl;
	freopen("tmp","r",stdin);
	for (int i=1;i<=flag;++i) scanf("%s",tmp);
	fclose(stdin);
	freopen("result.out","w",stdout);
	printf("%s\n%s\n",tmp,c+1);
	fclose(stdout);
//	nowlen=1<<10;
//	tmp[1]='1';
//	for (int i=1;i<=nowlen;i<<=1){
//		for (int j=1;j<=i;++j) c[j]=tmp[j],tmp[j+i]=c[j]^1;
//		cout<<c+1<<endl;
//	}
//	cout<<getHash()<<endl;
//	for (int i=1;i<=nowlen;++i) c[i]^=1;
//	cout<<getHash()<<endl;
//	cout<<c+1;
	return 0;
}
