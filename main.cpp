#include <iostream>

template <typename T>class Elem {
public:
    T value;
    Elem *next = NULL;
    Elem(T x){
        value = x;
    }
    void print(){
        std::cout << value << std::endl;
    }
};

template <typename T>
class Queue {
    Elem <T>*first = NULL;
    void push(T x, Elem <T>*);
public:
    Queue(){}
    Queue(T x){
        first = new Elem <T>(x);
    }
    void push(T x);
    T peek();
    bool isClear();
    T pop();
};

template <typename T>
bool Queue<T>::isClear(){
    if(!first){ return false;}
    return true;
}

template <typename T>
T Queue<T>::pop(){
    T temp = peek();
    first = first->next;
    return temp;
}

template <typename T>
void Queue<T>::push(T x){
    if(!first){first = new Elem <T>(x); return;}
    push(x, first);
    return;
}

template <typename T>
T Queue<T>::peek(){
    if(isClear()){
        return first->value;
    }else{
        printf("Error: Queue is clear");
        exit(1);
    }
}

template <typename T>
void Queue<T>::push(T x, Elem <T>*p){
    if(!p->next){p->next = new Elem <T>(x); return;}
    push(x, p->next);
    return;
}

int main(){
    Queue <char>q;
    q.push('a');
    q.push('b');
    q.push('c');
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.peek() << std::endl;
    std::cout << q.pop() << std::endl;
   // std::cout << q.peek() << std::endl;
    //std::cout << q.peek() << std::endl;
    return 0;
}

