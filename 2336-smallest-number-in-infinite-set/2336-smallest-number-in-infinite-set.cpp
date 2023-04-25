class SmallestInfiniteSet {
public:
   
   vector<int> v;
    SmallestInfiniteSet() {
        v.resize(1001,true);
    }
    
    int popSmallest() {
        int i=1;
        while(v[i]!=true)
        {
            i++;
        }
        v[i]=false;
        return i;
       
    }
    
    void addBack(int num) {
        if(v[num]!=true)
        {
           v[num]=true;
        }
    }
};