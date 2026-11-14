class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;
        while(index > 0 && temp) {
            temp = temp->next;
            index--;
        }
        return temp ? temp->val : -1;
    }

    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void addAtTail(int val) {
        Node* n = new Node(val);
        if(!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = n;
    }

    void addAtIndex(int index, int val) {
        if(index <= 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        while(--index && temp)
            temp = temp->next;
        if(!temp) return;
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || !head) return;
        if(index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while(--index && temp->next)
            temp = temp->next;
        if(temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }
};
