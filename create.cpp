#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define ull int
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=100;
char c[N],tmp[N];
const int LH=1e6+7,S1=16,S2=10,MS2=(1<<S2)-1;
struct Node{
	int nxt;
	unsigned long long v;
};
struct DATA{
	Node*data[S1];
	int now,used[S1];
	DATA(){now=0,memset(used,0,sizeof(used));}
	inline Node&operator[](long long x){
		int x1=x>>S2,x2=x&MS2;
		if (!used[x1]){
			data[x1]=new Node[MS2+1];
			used[x1]=1;
			cerr<<"Enlarge "<<x1<<endl;
		}
		return data[x1][x2];
	}
};
struct Hash{
	DATA T;
	long long lt;
	int last[LH];
	Hash(){lt=0,memset(last,0,sizeof(last));}
//	inline bool count(unsigned long long x){
//		int ha=x%LH;
//		for (long long i=last[ha];i;i=T[i].nxt){
//			if (T[i].v==x) return 1;
//		}
//		return 0;
//	}
	inline long long insert(unsigned long long x){
		int ha=x%LH,*lst=&last[ha];
		for (long long i=*lst;i;lst=&T[i].nxt,i=*lst){
			if (T[i].v==x) return i;
		}
		*lst=++lt;
		T[lt].v=x,T[lt].nxt=0;
	}
};
const int Hstd=2,Huser=1;
Hash stdh[Hstd],userh[Huser];
long long smod[Hstd]={1000000007,1000000003};
long long umod[Huser]={998244353};
long long sbas[Hstd]={31,131};
long long ubas[Huser]={107};
inline bool std_gethash(int l,int r){
	for (int i=0;i<Hstd;++i){
		long long ans=0;
		for (int j=l;j<=r;++j){
			ans=(sbas[i]*ans+c[j])%smod[i];
		}
		long long tip=stdh[i].insert(ans);
		if (tip) return tip;
	}
	return 0;
}
inline bool user_gethash(int l,int r){
	for (int i=0;i<Huser;++i){
		long long ans=0;
		for (int j=l;j<=r;++j){
			ans=(ubas[i]*ans+c[j])%umod[i];
		}
		long long tip=userh[i].insert(ans);
		if (tip) return tip;
	}
	return 0;
}
const int nowlen=20;
const int M=10+26;
char ch[M];
int main(){
	srand((unsigned long long)new char);
	srand(rand()*rand());
	for (int i=0;i<10;++i) ch[i]='0'+i;
	for (int i=0;i<26;++i) ch[10+i]='a'+i;
	freopen("tmp","w",stdout);
	int cnt=0;
	long long flag;
	while (!flag){
		++cnt;
		for (int i=1;i<=nowlen;++i) c[i]=ch[rand()%M];
		long long fstd=std_gethash(1,nowlen),fuser=user_gethash(1,nowlen);
		if (!fstd&&fuser){
			flag=fuser;
			break;
		}
		printf("%s\n",c+1);
		if (!(cnt&((1<<20)-1))) cerr<<cnt<<endl;
		if (cnt==(1<<23)){
			freopen("result.out","w",stdout);
			printf("-1\n");
			fclose(stdout);
			exit(233);
		}
	}
	fclose(stdout);
	cerr<<"----"<<flag<<' '<<cnt<<endl;
	freopen("tmp","r",stdin);
	for (int i=1;i<=flag;++i) scanf("%s",tmp);
	fclose(stdin);
	freopen("result.out","w",stdout);
	printf("2\n/%s\n/%s\n",tmp,c+1);
	fclose(stdout);
	return 0;
}
