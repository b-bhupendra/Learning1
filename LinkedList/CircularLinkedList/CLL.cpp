#include<iostream>
using namespace std;
class cLL{

    class Node{
        public:
        int data;
        Node * next;
        Node(int val = 0,Node *next =nullptr ) : data(val),next(next){} 
    
    }*headPtr;
    
    int count;

    public:
     cLL(){
        headPtr = new Node(0,nullptr);
     }

    void insertAtback(int data){

        if(headPtr->next == nullptr){
            headPtr->next = new Node(data,nullptr);
            Node *tmp = headPtr->next;
            tmp -> next = tmp;
        }
        else{
            Node * head = headPtr->next;
            Node * cur = head->next;

            while(cur->next!=head){
                cur = cur->next;
            }

            cur->next = new Node(data,head);

        }
        
    }

    Node* getLast(){
          Node * head = headPtr->next;
          Node * cur = head->next;

            while(cur->next!=head){
                cur = cur->next;
            }

            
        return cur;
    }
    void insert(int position,int data){
            if(position > count) return;

            if(position == 0){
                Node *last = getLast();
                Node *oldHead = this->headPtr->next;
                Node *newHead = new Node(data,oldHead);
                last->next = newHead;
                this->headPtr->next = newHead;
            }
            else if(position == count){
                Node *last = getLast();
                Node *newNode = new Node(data,last->next);
                last->next = newNode;
                
            }
            else{

                Node * head = headPtr->next;
                Node * cur = head->next;

                for(int i=0;i<position;i++){
                    
                }
            
                return cur;
            }



    }
        
    void display(){
        if(this->headPtr->next == nullptr) return;

          Node * head = headPtr->next;
            Node * cur = head->next;

            cout << endl;

            cout << head->data << " ";
            while(cur!=head){
                cout << cur->data << " ";
                cur = cur->next;
            }

            cout << endl;    

        

    }



};