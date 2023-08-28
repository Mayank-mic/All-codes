// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.




class Node{
    public:
    int val;
    Node* next;

  
    Node(int x){
        val = x;
        next=NULL;
    }

    Node(int x, Node* link){
        val = x;
        next = link;
    }

};



class MyHashSet {
    vector<Node* > t;
    int size = 1000; 
public:

    MyHashSet() {
        for(int i=0;i<1000;++i){
            Node* n = new Node(-1);
            t.push_back(n);
        }
    }

    int hash(int key){
        return key%size;
    }
    
    void add(int key) {

        Node* id = t[hash(key)];

        while(id->next!=NULL){
            if(id->val==key) return;
            id=id->next;
        }

        if(id->val==key) return;

        id->next = new Node(key);

    }
    
    void remove(int key) {

        Node* id = t[hash(key)];

        if(id->next==NULL) return;

        while(id->next!=NULL){
            if(id->next->val==key) break;
            id=id->next;
        }

        if(id->next==NULL) return;
        Node* temp = id->next;

        if(temp->next!=NULL) id->next = temp->next;
        else id->next=NULL;

        delete temp;

    }
    
    bool contains(int key) {
        Node* id = t[hash(key)];

        while(id!=NULL){
            if(id->val==key) return true;
            id=id->next;
        }

        return false;

    }
};
