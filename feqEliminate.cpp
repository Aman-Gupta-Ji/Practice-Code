int func(){
	int n=sizeof(str)/sizeof(char);
	vector<int> freq(26,0);
	for(int i=0;i<str[i]!='\0';i++){
			freq[str[i]-'a']++;
	}
	int maxi=0;
	char c;
	for(int i=0;i<26;i++){
		if(freq[i]<maxi)
		{
			maxi=freq[i];
			c=(char)(i-'a');
		}
	}
	for(int i=0;i<str[i]!='\0';i++){
		if(str[i]==c){
				
		}
	}
}