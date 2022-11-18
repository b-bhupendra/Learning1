#include <iostream>
#include "LL.cpp"
using namespace std;

int main(){
    LinkedList first,second;

    first.insert(1,first.length());
    first.insert(10,first.length());
    first.insert(100,first.length());


    
    // second.insert(1,second.length());
    // second.insert(10,second.length());
    // second.insert(100,second.length());

    // n.insert(0,n.length());
    
    first.Display();
    
    second.Display();
    
    
    
    
    cout << "Display the first list \n";
    first.merge(second);
    first.Display();
  
    return 0;
}