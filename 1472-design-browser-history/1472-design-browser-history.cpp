
class BrowserHistory {
public:
    //Inbuilt Double linked list
    list<string> history;
    list<string> ::iterator it;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        //starting from the first node
        it = history.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        //clearing the forward history
        history.erase(del,history.end());
        //after deleting the forward history,insert the new url and point the iterator to it.
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it != history.begin() && steps--){
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        //here .end() points to the next to last so decrement one time to point to last node else give RTE
        while((it != (--history.end())) && steps--){
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */