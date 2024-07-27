#include <bits/stdc++.h> 
class Deque
{
    class Node{
        public :
        int data;
        Node *prev;
        Node *next;

        Node(int n){
            data = n;
            prev = next = NULL;
        }
        ~Node(){
          delete next;
          delete prev;
        }
    };
public:
    // Initialize your data structure.
    int size, cnt=0 ;
    Node* front;
    Node* back;
    Deque(int n)
    {
        size = n;
        front = back = NULL;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {       
        if(isFull()) return false;
        Node* newNode = new Node(x);

        cnt++;
        if(!front){
            front = back = newNode;
        }
        else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()) return false;
        Node* newNode = new Node(x);

        cnt++;
        if(!back){
            front = back = newNode;
        }
        else{
            back->next = newNode;
            newNode->prev = back;
            back = newNode;  
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()) return -1;

        int val = front->data;
        cnt--;

        Node* temp = front;
        front = front->next;
        
        temp->next = NULL;
        temp->prev = NULL;

        delete temp;

        return val;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()) return -1;

        int val = back->data;
        cnt--;

        Node* temp = back;
        back = back->prev;
        
        if(cnt == 0){
            front=back=NULL;
        }
        temp->next = NULL;
        temp->prev = NULL;

        delete temp;

        return val;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()) return -1;

        int val =  front->data;
        return val;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) return -1;

        int val =  back->data;
        return val;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(cnt == 0) return true;

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(cnt ==  size){
            return true;
        }
        return false;
    }
};
