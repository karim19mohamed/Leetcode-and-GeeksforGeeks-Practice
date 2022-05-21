class Node{
public:
    int val;
    Node* nxt;
    Node* prev;
    Node(){
        val = 0;
        nxt = nullptr;
        prev = nullptr;
    }
    Node(int n){
        val = n;
        nxt = nullptr;
        prev = nullptr;
    }
};
class MyLinkedList {
    Node* TAIL;
    Node* HEAD;
public:
    MyLinkedList() {
        HEAD = new Node();
        TAIL = HEAD;
    }
    
    int get(int index) {
        int tmp = 0;
        Node* cur = HEAD;
        while(tmp!=index && cur!=TAIL){
            cur = cur->nxt;
            ++tmp;
        }
        return (cur!=TAIL)? cur->val : -1;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        tmp->nxt = HEAD;
        HEAD->prev = tmp;
        HEAD = tmp;
    }
    
    void addAtTail(int val) {
        TAIL->val = val;
        Node* tmp = new Node();
        tmp->prev = TAIL;
        TAIL->nxt = tmp;
        TAIL = tmp;
    }
    
    void addAtIndex(int index, int val) {
        int cnt = 0;
        Node* cur = HEAD;
        Node* pre_cur = HEAD;
        while(cnt!=index && cur!=TAIL){
            pre_cur = cur;
            cur = cur->nxt;
            ++cnt;
        }
        if (cnt<index && cur==TAIL)
            return;
        if (cur==TAIL){
            addAtTail(val);
        }else if (cur==HEAD){
            addAtHead(val);
        }else{
            Node* tmp = new Node(val);
            tmp->nxt = cur;
            cur->prev = tmp;
            pre_cur->nxt = tmp;
            tmp->prev = pre_cur;
        }
    }
    
    void deleteAtIndex(int index) {
        int cnt = 0;
        Node* cur = HEAD;
        Node* pre_cur = HEAD;
        while(cnt!=index && cur!=TAIL){
            pre_cur = cur;
            cur = cur->nxt;
            ++cnt;
        }
        if (cur==TAIL)
            return;
        if (cur->nxt==TAIL){
            Node* tmp = TAIL;
            TAIL = cur;
            delete tmp;
        }else if (cur==HEAD){
            Node* tmp = HEAD;
            HEAD = HEAD->nxt;
            HEAD->prev = nullptr;
            delete tmp;
        }else{
            pre_cur->nxt = cur->nxt;
            cur->nxt->prev = pre_cur;
            delete cur;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */