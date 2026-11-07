class LinkedList {
private:
    class Node {
        public: 
            int value;
            Node* next;

            Node(){
                value = 0;
                next = nullptr;
            }

            Node(int aVal, Node* nextNode){
                value = aVal;
                next = nextNode;
            }
    };

    int size;
    Node* head;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index > size - 1)
            return -1;
        
        Node* curr = head; 
        for(int i = 0; i < index; i++){
            curr = curr->next;
        }

        if(curr != nullptr){
            return curr->value;
        } else {
            return -1;
        }
    }

    void insertHead(int val) {
        Node* newHead = new Node(val, head);
        head = newHead;
        size++;
    }
    
    void insertTail(int val) {
      //when size == 0,
      if(head == nullptr){
        head = new Node(val, nullptr);
        size++;
        return;
      }

      //traversal & instertion
      Node* curr = head;
      while(curr->next != nullptr){
        curr = curr->next;
      }

      curr->next = new Node(val, nullptr);
      size++;
    }

    bool remove(int index) {

        if (index < 0 || index >= size|| head == nullptr){
            return false;
        }

        if(index == 0 && head != nullptr){
            Node* toDelete = head;
            head = head-> next;
            delete toDelete;
            size--;
            return true;
        }  

        Node* prev = head;
        for(int i = 0; i < index - 1; i++){
            prev = prev->next;
        }
        Node* remove = prev->next; //Node at index

        if(remove != nullptr){

            prev->next = remove->next; //removed the connection
            delete remove; //no memory leak
            remove = nullptr;

            size--;
            return true;
        } else {
            return false;
        }
    
    }

    vector<int> getValues() {
        vector<int> values;
        Node* curr = head;

        while(curr != nullptr){
            Node* add = curr;
            values.push_back(add->value);
            curr = curr->next;
        }

        return values;
    }
};
