class MyCircularDeque {
public:
    int arr[1001];
    int front, rear, size, capacity;

    MyCircularDeque(int k) {
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }
    bool insertFront(int value) {
        if(size == capacity) return false;
        front = (front - 1 + capacity) % capacity;
        if(size == 0) rear = front;
        arr[front] = value;
        size++;
        return true;
    }
    bool insertLast(int value) {
        if(size == capacity) return false;
        rear = (rear + 1) % capacity;
        if(size == 0) front = rear;
        arr[rear] = value;
        size++;
        return true;
    }
    bool deleteFront() {
        if(size == 0) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    bool deleteLast(){
        if(size==0) 
        return false;
        rear =(rear-1+capacity) % capacity;
        size--;
        return true;
    }

    int getFront(){
        return size== 0 ? -1 : arr[front];
    }

    int getRear(){
        return size== 0 ? -1 : arr[rear];
    }
    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        return size==capacity;
    }
};
