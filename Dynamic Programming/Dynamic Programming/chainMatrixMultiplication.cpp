    #include <bits/stdc++.h>
    using namespace std;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<string> vstr;

    vvi chainMatrixMultiplication(vi &p)
    {
        int n = p.size()-1;
        vvi m ( n+1, vi(n+1,0)), s(n+1,vi(n+1,0));
        for (int i = 0; i < n; i++)
            m[i][i] = 0;

        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i <= n - l +1; i++)
            {
                int j = i + l - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k < j ; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }

        return m;
    }

    int main()
    {
        vi p;
        p = {4, 10, 3, 12, 20, 7};
        vvi m = chainMatrixMultiplication(p);

        for (int i = 1; i< p.size(); i++)
        {
            for (int j = 1; j<p.size(); j++)
            {
                cout <<( (m[i][j] == INT_MAX)? -1 : m[i][j]) << "\t";

            }
            cout<<endl;
        }
        return 0;
    }