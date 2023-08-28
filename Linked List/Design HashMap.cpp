// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.



class Node{
    public:
        int key;
        int val;
        Node* link;


        Node(int Key, int Val)
        {
            key=Key;
            val = Val;
            link = NULL;
        }

        Node(int Key, int Val, Node* Link)
        {
            key = Key;
            val = Val;
            link = Link;
        }
};



class MyHashMap {
public:
    vector<Node* > t;
    int size = 1000;


    MyHashMap() {
        for(int i=0;i<1000;++i){
            Node* temp = new Node(-1, -1);
            t.push_back(temp); 
        }
    }


    int hash(int key){
        return key%size;
    }
    
    void put(int key, int value) {

        int id = hash(key);

        Node* node_i = t[id];

        while(node_i->link!=NULL){
            if(node_i->link->key==key){
                node_i->link->val=value;
                return;
            }
            node_i = node_i->link;
        }
        node_i->link = new Node(key, value);
    }
    
    int get(int key) {
        int id = hash(key);
        Node* node_i = t[id];

        while(node_i->link!=NULL){
            if(node_i->link->key==key)
            {
                return node_i->link->val;
            }
            node_i=node_i->link;
        }
        return -1;
    }
    
    void remove(int key) {

        int id = hash(key);
        Node* node_i = t[id];

        if(node_i->link==NULL) return;

        while(node_i->link!=NULL)
        {
            if(node_i->link->key==key) break;
            node_i=node_i->link;
        }

        if(node_i->link==NULL) return;
        Node* temp = node_i->link;

        if(temp->link!=NULL) node_i->link = temp->link;
        else node_i->link=NULL;

        delete temp;
        
    }
};
