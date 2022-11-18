#include <iostream>
using namespace std;
/*
To be implemented

Display - recursive and literal done
count Nodes done
Sum of all the element done
Maximum Element in Linked List done
Searching in linked List 
    improvising linked List 
        Transposing 
        Move to first

Insert 
    front , back ,at middle
        done
Delete done

Check Sorted done

///
Remove Duplicates - in sorted linked list 


using hash map we can remove all the duplicates;
can try
some day 

//////
Reversing Linked List - Recursive / iteration done


Concatenating 2 LL
Merging 2 linked list

checkLoop in LL


// sum 

// count 

These three must be implemented within delete insert


*/

class LinkedList{
    class Node
        {
            public:
            int data;
            Node *next;
            Node(int data =8888,Node *next=nullptr):data(data),next(next){}

        }*headptr;

        int count,sum;
    
    public:
        
        LinkedList(){ 
            headptr = new Node();
            sum = 0;
         
            count = 0;

        }




        void Display(){
            Node *curr = headptr ->next;
            cout <<endl;
            int ctr = 0;
            while(curr){ 
                    cout << curr->data << " ";
                    curr = curr->next;
                    ctr++;
            }
            cout << "Counter here is " << ctr <<endl;
        }

        int length(){ return this->count;}

        int getLargest(){
            
            Node *curr = headptr ->next;
            int large = INT_MIN;
            while(curr){ 
                    if(large < curr->data){
                        large = curr->data;
                    }

                    curr = curr->next;
            }
            return large;
        }

        int getSum(){
            return this->sum;
        }

        
       
        void insert(int data, int pos){

            if(pos > this->count +1) return;

            Node *prev=nullptr, *cur = this->headptr->next;


            for(size_t i=0;i<pos  && cur;i++){
                prev = cur;
                cur = cur->next;
            }

            Node *temp = new Node(data);
            
            temp->next = cur;

            if(! prev){
                
                this->headptr->next = temp;


            }
            else{
                prev->next = temp;
            }
            this->sum += data;
            this->count++;
        }

        
        void removeFrom(int pos){

            if(pos < 0 || pos > this->count +1) return;
            int data = 0;
            Node *prev=nullptr, *cur = this->headptr->next;

            for(size_t i=0;i<pos && cur->next;i++){
                prev = cur;
                cur = cur->next;
            }

            
            if(!prev){
                Node *store = cur->next;
                this->headptr->next = store;
                data = cur->data;
                delete cur;
            }
            else{
                prev->next = cur->next;
                data = cur->data;
                delete cur;
            }
            this->sum -= data;
            this->count--;
        }

        bool checkSorted(){
        

            Node *prev=nullptr, *cur = this->headptr->next;
            if(!cur){
                return true;
            }

            for(;cur->next;){
                prev = cur;

                cur = cur->next;
                if(prev->data > cur->data){
                    return false;
                }

            }

            return true;
        
        }

        Node * reverseR(Node *prev=nullptr,Node *cur =nullptr){

                if(cur){
                    Node * ret = reverseR(cur,cur->next);
                    cur->next = prev;
                    return ret;
                }
                else
                {
                    return prev;
                }

        }   

        void reverse(){
            this->headptr->next = this->reverseR(nullptr,this->headptr->next);
        }
        Node * getHead(){
            return this->headptr->next;
        }

        void operator+(LinkedList &other){
            Node *prev=nullptr,*cur = this->headptr->next;

            

            while(cur){
                prev=cur;
                cur= cur->next;
            }

            if(!prev){
               
                this->headptr->next = other.getHead();
            }else{
                prev->next = other.getHead();
            }
            
            

        }


        
         void merge(LinkedList &other){
            Node *nh=new Node(9090);
            Node *newHead = nh;
            Node *h1 = this->getHead();
            Node *h2 = other.getHead();
            cout <<"\n Merging going on \n ";

            cout << "Head of first one " << h1->data <<endl;
            cout << "Head of second one " << h2->data <<endl;

            int wtf = 0;
            while(h1 && h2){

                if(h1->data  < h2->data){
                    
                    nh->next = new Node(h1->data,nullptr);
                    h1 = h1->next;
                    nh = nh->next;
                }
                else{
                    
                    nh->next =new Node(h2->data,nullptr);
                    h2 = h2->next;
                    nh = nh->next;

                }

            }

            while(h1){
                   nh->next = new Node(h1->data,nullptr);
                    h1 = h1->next;
                    nh = nh->next;
            }
             while(h2){
                   nh->next = new Node(h2->data,nullptr);
                    h2 = h2->next;
                    nh = nh->next;
              }
        
           this->headptr= newHead;
           
            cout <<  "The first value is" << this->headptr->next->data <<endl; 
        }
};