#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>s;
		if(s == "1" || s == "4" || s == "78") cout<<"+"<<endl;
		else{
			if(s[s.size() - 2] == '3' && s[s.size() - 1] == '5') cout<<"-"<<endl;
			else{
				if(s[0] == '9' && s[s.size() - 1] == '4') cout<<"*"<<endl;
				else{
					if(s[0] == '1' && s[1] == '9' && s[2] == '0') cout<<"?"<<endl;
				}
			}
		}
	}
	return 0;
}