class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows==1 || numRows >= s.size())return s;
        vector<string>rows(numRows);

        int currRow = 0;
        bool goingDown = true;

        for(char &c : s){
            rows[currRow] += c;

            if(currRow == 0) goingDown = true;
            else if(currRow == numRows-1){
                goingDown = false;
            }

            if(goingDown)currRow++;
            else currRow--;
        }

        string ans;

        for(auto a : rows){
            ans +=a;
        }

        return ans;



    }
};