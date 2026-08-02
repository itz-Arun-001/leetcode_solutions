class Node{
    //public:
        String data;
        Node next;
        Node prev;
        Node(String u)
        {
            data=u;
            next=null;
            prev=null;
        }
        Node(String u,Node n,Node p)
    {
        data=u;
        next=n;
        prev=p;
    }
        
}class BrowserHistory {

//public:
    Node url;
    public BrowserHistory(String homepage) {
        url=new Node(homepage);

        
    }
    
    public void visit(String url1) {
        Node visited=new Node(url1);
        url.next=visited;
        visited.prev=url;
        url=url.next;
        
    }
    
    public String back(int steps) {
        while(steps!=0&&url.prev!=null)
        {
            steps--;
            url=url.prev;
        }
        return url.data;
        
    }
    
    public String forward(int steps) {
        while(steps!=0&&url.next!=null)
        {
            steps--;
            url=url.next;
        }
        return url.data;
        
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */