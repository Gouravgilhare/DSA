#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


int main() {
	
	vector<vector<int>>mat;
	vector<int>rows;
	string str,num;
	getline(cin,str); // taking input as string because it give values as string;
	for( auto a : str){
		if(isdigit(a)){
			num += a;
		}else{
			if(!num.empty()){

				rows.push_back(stoi(num));
				num="";
			}
			if(a == '}'){
				if(!rows.empty())
					{
						mat.push_back(rows);
						rows.clear();
					}
			}
		}
	}
		int celeIndex=-1;;
		int up=0,down=mat[0].size()-1;
		
		while(up<down){
				if(mat[up][down] == 1) 
				up++;
				else if(mat[down][up] == 1) 
				down--;
				else{
					up++;down--;
				}

		}

		if(up>down) celeIndex=-1;
		for(int i= 0 ; i<mat[0].size()-1; i++){
			if(up == i)continue;
			if(mat[up][i] == 0 && mat[i][up]==1 )
			{

			}else{
				celeIndex=-1;
				cout<<celeIndex;
				break;
			}
		}

		celeIndex=up;
		cout<<celeIndex;

	return 0;	
}
