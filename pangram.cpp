#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


int main(void) {
	string s;
	getline(cin,s);

	int freq[26]={0};
	int len=s.length();
	for(int i=0;i<len;i++) {
		char ch=s[i];
		if(isalpha(ch)) {
			ch=tolower(ch);
			freq[ch-'a']++;
		}
	}
	string miss="";
	bool ispan=true;
	for(int i=0;i<26;i++) {
		if(freq[i]==0) {
			ispan=false;
			miss.push_back((char)(i+'a'));
		}
	}
	if(ispan)
		cout<<"YES "<<s<<" is a pangram"<<endl;
	else
		cout<<"NO "<<s<<" is not a pangram missing characters are "<<miss<<endl;
	return 0;
}