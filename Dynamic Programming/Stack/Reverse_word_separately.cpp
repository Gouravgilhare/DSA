#include <iostream>
#include <vector>
using namespace std;


void reverse(string &str){
	vector<char>st;

	int i=0;
	while(i < str.size()){
		st.push_back(str[i]);
		i++;
	}int top= st.size()-1;
	i=0;
	while(i<str.size()){
		str[i]= st[top];
		st.pop_back();
		i++;
		top--;
	}

}

int main() {
	string str1,str2;
	cin>>str1>>str2;

	reverse(str1);
	reverse(str2);

	cout<<str1<<" "<<str2;

return 0;
}




#include <iostream>
#include <vector>
using namespace std;


void reverse(string &str){
	vector<char>st;

	int i=0;
	while(i < str.size()){
		st.push_back(str[i]);
		i++;
	}int top= st.size()-1;
	i=0;
	while(i<str.size()){
		str[i]= st[top];
		st.pop_back();
		i++;
		top--;
	}

}

int main() {
	string str1,str2;
	cin>>str1>>str2;

	reverse(str1);
	reverse(str2);

	cout<<str1<<" "<<str2;

return 0;
}
