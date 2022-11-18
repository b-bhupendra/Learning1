#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "solution.cpp"

class Runner
{
    int t;
    vector<vector<vector<bool>>> arr;

public:
    void takeInput()
    {

        cin >> t;
        arr.resize(t);

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;
            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                arr[tc][i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    bool x;
                    cin>>x;
                    arr[tc][i][j]=x;
                    
                }
            }
        }
    }

    vector<vector<vector<bool>>> getCopy()
    {
        vector<vector<vector<bool>>> arrCopy = arr;

        return arrCopy;
    }

    void execute()
    {
        vector<vector<vector<bool>>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arrCopy[i]);
        }
    }
    

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<string> ans = findAllPaths(arr[i]);
            
            sort(ans.begin(),ans.end());
            for (string i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}