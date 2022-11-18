#include<iostream>
using namespace std;

int main(){

    int x = -10;
    int count;
    cin >> count;
    for(int i=0;i<count;i++) x >>= 1;

    cout << x <<endl;

    return 0;
}