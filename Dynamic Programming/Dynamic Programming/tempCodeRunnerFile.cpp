#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 

bool isSafe(vvi&board, int row, int col)
{
    int n = board.size();


    //checking col in previos row
    for(int  i = 0 ; i< row ; i++){
        if(board[i][col]== 1)return false;
    }
    

    //checking uppper triangle
    for(int i=row-1 ,j=col-1 ;i>= 0 && j>= 0; i--, j--)
  {
    if(board[i][j]== 1) return false;
  }
    //checking lower triangle
    for(int i=row-1 ,j=col+1 ;i>= 0 && j<n; i--, j++)
  {
    if(board[i][j]== 1) return false;
  }

  return true;

}

bool placingQueens(vvi&board,  int row){
    
    int size = board.size();

    if (row == size) return 1;
    for(int i = 0; i<size; i++){
        if(isSafe(board,row, i)){
            board[row][i]= 1;
            if(placingQueens(board, row+1))
                return true;
            board[row][i]=0;
        }
    }

    return false;
}


vi Nqueens(int n){

      if(n == 2 || n == 3) return {-1}; // no solutions exist
    vvi board(n,vi(n,0));

    if(placingQueens(board, 0)){
        vi ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j]){
                    ans.push_back(j+1);
                }
            }
        }
        return ans;   
    }
    return {-1};
}
 
 
int main()
{
    int n;
    cin >> n;
    vi ans = Nqueens(n);
    for(auto a :ans ){
        cout<<a<<" ";
    }
 
return 0;
}