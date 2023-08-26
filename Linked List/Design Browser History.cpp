// You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:

// BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
// void visit(string url) Visits url from the current page. It clears up all the forward history.
// string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
// string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.





class Node{
    public:
    string Url;
    Node* next=NULL;
    Node* prev=NULL;

    Node(string &url){
        this->Url = url;
    }
};



class BrowserHistory {
    Node* curr =  NULL;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* node = new Node(url);
        curr->next=node;
        node->prev=curr;
        curr=node;
    }
    
    string back(int steps) {
        
        while(curr->prev && steps--){
            curr=curr->prev;
        }
        return curr->Url;
    }
    
    string forward(int steps) {
        while(curr->next && steps--){
            curr=curr->next;
        }
        return curr->Url;
    }
    
};
