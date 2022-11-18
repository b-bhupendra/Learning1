#include<iostream>
#include "CLL.cpp"
using namespace std;

int main(){
cLL first;
for(int i=0;i<10;i++){
    first.insertAtback(i);
}

first.display();

return 0;
}