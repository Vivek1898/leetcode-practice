class SnapshotArray {
public:

vector<map<int,int ,greater<int>>> mp;
int id=0;
    SnapshotArray(int length) {
        mp.resize(length);
    }
    
    void set(int index, int val) {
        mp[index][id]=val;
    }
    
    int snap() {
    return id++;
}
    
    int get(int index, int snap_id) {
        auto i=mp[index].lower_bound(snap_id);
        return i->second;
    }
};