#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
#define ld long double
ld gc(string s){
	vector<ld>v;int Icnt=0;
	int n=s.length();
	s+="__________";
	for(int i=0;i<n;i++)
	{
		//Input
		if(s[i]=='?'){ld input;cin>>input;v.push_back(input);}

		//Nums
		if('0'<=s[i]&&s[i]<='9'){
			string t="";
			while(s[i]!='_'){t+=s[i];i++;}
			v.push_back((ld)stoi(t));
		}

		//Calculating
		if(s[i]=='+'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(pop2+pop1);
		}
		if(s[i]=='-'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(pop2-pop1);
		}
		if(s[i]=='*'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(pop2*pop1);
		}
		if(s[i]=='/'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(pop2/pop1);
		}
		if(s[i]=='%'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back((int)pop2%(int)pop1);
		}
		if(s[i]=='&'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back((int)pop2&(int)pop1);
		}
		if(s[i]=='|'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back((int)pop2|(int)pop1);
		}
		if(s[i]=='^'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back((int)pop2^(int)pop1);
		}
		if(s[i]=='~'){
			ld pop1=v[v.size()-1];
			v.pop_back();v.push_back(~(int)pop1);
		}
		
		//Math
		if(s[i]=='v'){
			ld pop1=v[v.size()-1];
			v.pop_back();v.push_back(sqrt(pop1));
		}
		if(s[i]=='p'&&s[i+1]=='o'&&s[i+2]=='w'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(pow(pop2,pop1));
		}
		if(s[i]=='m'&&s[i+1]=='i'&&s[i+2]=='n'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(min(pop1,pop2));
		}
		if(s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='x'){
			ld pop1=v[v.size()-1],pop2=v[v.size()-2];
			v.pop_back();v.pop_back();v.push_back(max(pop1,pop2));
		}

		//Internal processings
		if(s[i]=='P'){
			if(Icnt==1){	
				cout<<(int)v[v.size()-1]<<endl;
			}else{
				cout<<v[v.size()-1]<<endl;
			}
		}
		if(s[i]=='I')Icnt^=1;
		if(s[i]=='R'){
			ld tmp=v[v.size()-1];
			v[v.size()-1]=v[v.size()-2];v[v.size()-2]=tmp;
		}
		if(s[i]=='E'){
			ld tmp=v[v.size()-1];
			v[v.size()-1]=v[0];v[0]=tmp;
		}
		if(s[i]=='D'){
			v.pop_back();
		}
		if(s[i]=='C'){
			ld tmp=v[v.size()-1];
			v.push_back(tmp);
		}
		if(s[i]=='i'&&s[i+1]=='f'){
			if(s[i+2]=='<'){
				int bcnt=0;
				string ifYes="";
				string ifNo="";
				while(bcnt<2){
					i++;
					if(s[i]=='(')continue;
					if(s[i]==')'){bcnt++;continue;}
					if(bcnt==0)ifYes+=s[i];
					if(bcnt==1)ifNo+=s[i];
				}
				if(v[v.size()-2]<v[v.size()-1]){
					s.insert(i+1,ifYes);
					n+=ifYes.length();
				}else{
					s.insert(i+1,ifNo);
					n+=ifYes.length();
				}
			}
			else if(s[i+2]=='>'){
				int bcnt=0;
				string ifYes="";
				string ifNo="";
				while(bcnt<2){
					i++;
					if(s[i]=='(')continue;
					if(s[i]==')'){bcnt++;continue;}
					if(bcnt==0)ifYes+=s[i];
					if(bcnt==1)ifNo+=s[i];
				}
				if(v[v.size()-2]>v[v.size()-1]){
					s.insert(i+1,ifYes);
					n+=ifYes.length();
				}else{
					s.insert(i+1,ifNo);
					n+=ifYes.length();
				}
			}
			else if(s[i+2]=='='&&s[i+3]=='='){
				int bcnt=0;
				string ifYes="";
				string ifNo="";
				while(bcnt<2){
					i++;
					if(s[i]=='(')continue;
					if(s[i]==')'){bcnt++;continue;}
					if(bcnt==0)ifYes+=s[i];
					if(bcnt==1)ifNo+=s[i];
				}
				if(v[v.size()-2]==v[v.size()-1]){
					s.insert(i+1,ifYes);
					n+=ifYes.length();
				}else{
					s.insert(i+1,ifNo);
					n+=ifYes.length();
				}
			}
			else if(s[i+2]=='!'&&s[i+3]=='='){
				int bcnt=0;
				string ifYes="";
				string ifNo="";
				while(bcnt<2){
					i++;
					if(s[i]=='(')continue;
					if(s[i]==')'){bcnt++;continue;}
					if(bcnt==0)ifYes+=s[i];
					if(bcnt==1)ifNo+=s[i];
				}
				if(v[v.size()-2]!=v[v.size()-1]){
					s.insert(i+1,ifYes);
					n+=ifYes.length();
				}else{
					s.insert(i+1,ifNo);
					n+=ifYes.length();
				}
			}
		}
		
		//None
		if(s[i]=='_')continue;
	}
	return v[v.size()-1];
}

signed main(){
	string s;cin>>s;
	gc(s);
	return 0;
}
