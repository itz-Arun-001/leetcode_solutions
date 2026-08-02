class Node{
    public:
        string data;
        Node* next;
        Node* prev;
        Node(string u)
        {
            data=u;
            next=nullptr;
            prev=nullptr;
        }
        Node(string u,Node* n,Node* p)
    {
        data=u;
        next=n;
        prev=p;
    }
        
};
class BrowserHistory {
public:
    Node* url;

    BrowserHistory(string homepage) {
        url=new Node(homepage);
        
    }
    
    void visit(string url1) {
        //Node* curr=url;
        Node* visited=new Node(url1);
        url->next=visited;
        visited->prev=url;
        url=url->next;
      //  url=curr;
        
    }
    
    string back(int steps) {
        while(steps && url->prev)
        {
            url=url->prev;
            steps--;

        }
        return url->data;
        
    }
    
    string forward(int steps) {
        while(steps&&url->next!=nullptr)
        {
            steps--;
            url=url->next;
        }
        return url->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */