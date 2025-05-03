// Question 4: Given a number n, the task is to find the largest perfect cube that can be formed by deleting minimum digits(possibly 0) from the number. 
// X is called a perfect cube if X = Y3 for some Y.
// Examples: 
 
// Input : 4125
// Output : 125


#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

vs generatePreProcessedCubes(int n){

    vs preProcessedcubes;

    for(int i =1; i<= n; i++){
        preProcessedcubes.push_back(to_string(i*i*i));
    }

    return preProcessedcubes;
}
string matchTheStringUntil(string num , vs perfectCube){

    reverse(perfectCube.begin(), perfectCube.end());   // reverse the string because we want to match from rear digits

    int numOfDigits = perfectCube.size();

    for(int i = 0; i< numOfDigits ; i++){
        
        string cube = perfectCube[i];
        int digitsInCube = cube.size();
        int index = 0;
        int digitsInNum = num.length();
        for(int   j = 0 ; j< digitsInNum; j++){

            if(num[j] == cube[index]){
                index++;
            }

            if(digitsInCube == index){
                return cube;
            }
        }


    }



}
void perfectCube( int n){

    vs perfectCubes = generatePreProcessedCubes(n);  // calling the preProcesscubes
  

    string num = to_string(n);

    string ans = matchTheStringUntil(num, perfectCubes);


    cout<< " number : "<<n<<"\nperfect cube after removeing : "<<ans;
}

int main(){

    int num;
    
    cout<<endl;
    num = 4125;
    perfectCube (num);



    return 0;
}
