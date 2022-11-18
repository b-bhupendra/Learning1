#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direction{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};


char dirC(const int x,const int y){
    if(x == -1 && y == 0)
             return 'U';
    else if (x == 0 && y == -1)
             return 'L';
    else if (x == 0 && y == 1)
             return 'R';
    else if(x == 1 && y == 0)
             return 'D'; 
    else
        return 0;
}



void utils(int i, int j, vector<vector<bool>> &arr, vector<char> &possible, vector<string> &res, vector<vector<int>> &marked){

      
        if( i < 0 || j >= arr.size() || i >= arr.size() || j < 0) return;
 
        if(i == arr.size() - 1 && j == arr.size() -1){
                string n(possible.begin(),possible.end());
                
                res.push_back(n);
                
                return;
        }

          if(marked[i][j] || !arr[i][j] ) return;

        marked[i][j] = 1;  
        for(vector<int> &dir:direction){
                possible.push_back( dirC(dir[0],dir[1]) );
                utils(i+dir[0],j+dir[1],arr,possible,res,marked);
                possible.pop_back();

        }
        marked[i][j] = 0;


}

    vector<string> findAllPaths(vector<vector<bool>> &arr) {
        int n = arr.size();
                
        vector<char> possible;
        vector<string> res;
        vector<vector<int>> marked(n,vector<int>(n,0));
        

            utils(0,0,arr,possible,res,marked);

            return res;
}