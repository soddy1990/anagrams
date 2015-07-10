#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

typedef pair<string, string> Pair;

bool mycompare(const Pair &a, const Pair &b){
	int i = 0;
	while(i<(int)a.first.length() && i<(int)b.first.length()){
		if(a.first.at(i) == b.first.at(i)){
			i++;
			continue;
		}
		return a.first.at(i) < b.first.at(i);
	}
	return a.first.length()<b.first.length();
}

bool myStrEqual(const string &a, const string &b){
	if(a.length() != b.length())
		return false;
	int i = 0;
	while(i<(int)a.length()){
		if(a.at(i) != b.at(i)){
			break;
		}
		i++;
	}

	return i == a.length();
}


vector<string> anagrams(vector<string>& strs) {

	vector<Pair> work;
	int n = strs.size();
	vector<string> re;
	if(n <= 1){
		return re;
	}
	int null_str = 0;

	for(int i = 0; i < n; i++){
		int strn = strs[i].size();
		if(strn == 0){
			null_str++;
			continue;
		}
		string temp;
		int count[26];
		for(int k = 0; k<26; k++){
			count[k] = 0;
		}
		for(int j = 0; j<strn; j++){
			char char_count = strs[i].at(j);
			count[char_count - 97]++;
		}
		for(int k = 0; k<26; k++){
			if(count[k] == 0){
				continue;
			}
			temp += (k+97);
			string count_str;
			count_str = count[k];
			temp += count_str;
		}
		Pair mypair;
		mypair.first = temp;
		mypair.second = strs[i];
		work.push_back(mypair);
	}
	if(null_str != 0){
		for(int i = 0; i<null_str; i++){
			Pair mypair;
			mypair.first = "";
			mypair.second = "";
			work.push_back(mypair);
		}
	}
	sort(work.begin(), work.end(), mycompare);
	string last = work[0].first;
	int start = 0;
	for(int i = 1; i<work.size(); i++){
		if(myStrEqual(work[i].first,last)){
			continue;
		}else{
			if(i-start > 1){
				for(int j = start; j<i; j++){
					re.push_back(work[j].second);
				}
			}
			start = i;
			last = work[i].first;
		}
	}
	if(myStrEqual(work[work.size()-1].first,last)){
		if(work.size()-start > 1){
			for(int j = start; j<work.size(); j++){
				re.push_back(work[j].second);
			}
		}
	}

	return re;
}



void main(){
	//int a = 18;
	//itoa(a);
	vector<string> strs;
	string temp;
	temp = "";
	strs.push_back(temp);
	strs.push_back(temp);

	vector<string> re = anagrams(strs);
	for(int i = 0; i < re.size(); i++){
		cout<<re[i].c_str()<<endl;
	}
	//sort(strs.begin(), strs.end(),mycompare);
	getchar();
}