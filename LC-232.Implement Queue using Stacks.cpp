//using 2 stack 
class MyQueue {
    stack<int>s1,s2;
public:
//diagram of Recode_-1 solution
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int popped=s1.top();
        s1.pop();
        return popped;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//using array  pointer
class MyQueue {
public:
//Using a pointer to an integer array (int *arr;), you can dynamically allocate memory for the array at runtime using new int[size]; in the class constructor. This allows you to create an array of integers of a size specified by the size variable.
int size;
int *arr;
int front,rear;
    MyQueue() {
        size=1000;
        arr=new int[size];
        front=0;
        rear=0;
    }
    
    void push(int x) {
        if(rear==size-1){
            return;
        }else{
            arr[rear]=x;
            rear++;
        }
    }
    
    int pop() {
        //why we use front==rear?
        if(front==rear){
            return -1;
        }else{
            int element=arr[front];
            front++;
            return element;
        }
    }
    
    int peek() {
        if(front==rear){
            return -1;
        }else{
       return arr[front];
        }
    }
    
    bool empty() {
        if(front==rear){
            return true;
        }else{
            return false;
        }
    //     return front == rear; // Queue is empty if front and rear are at the same position
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
