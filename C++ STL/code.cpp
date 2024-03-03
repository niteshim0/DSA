template<typename T>
class Seg{
    int n;
    vector<T> seg;
    T get(T x,T y){
     return x + y;
    }
    void _update(int i,int l,int r,int idx,T val){
        if(l == r) {seg[i] += val; return;}
        int mid = (l + r) / 2;
        if(idx<=mid) _update(2*i+1,l,mid,idx,val);
        else _update(2*i+2,mid+1,r,idx,val);
        seg[i] = get(seg[2*i+1],seg[2*i+2]);
    }
    T _query(int i,int l,int r,int ll,int rr){
        if(l>r) return 0;
        if(r < ll || l > rr) return 0;
        if(ll<=l && rr>=r) return seg[i];
        int mid = (l + r) / 2;
        return get(_query(2*i+1,l,mid,ll,rr),_query(2*i+2,mid+1,r,ll,rr));
    }
    public:
    Seg(int _n){
        n = _n;
        seg.resize(4*n,0);
    }
    void update(int idx,T val){ _update(0,0,n,idx,val); }
    T query(int l,int r){ return _query(0,0,n,l,r); }
};



class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++) st.insert(nums[i]);
        map<int,int> mp;
        int c = 0;
        for(auto i : st) mp[i] = c++;
        Seg<int> seg1(c), seg2(c);
        seg1.update(mp[nums[0]], 1);
        seg2.update(mp[nums[1]], 1);
        vector<int> a = {nums[0]}, b = {nums[1]};
        for(int i=2;i<n;i++){
            int x = seg1.query(mp[nums[i]] + 1, c - 1), y = seg2.query(mp[nums[i]] + 1, c - 1);
            if(x > y) {
                a.push_back(nums[i]);
                seg1.update(mp[nums[i]], 1);
            }
            else if(x < y){
                b.push_back(nums[i]);
                seg2.update(mp[nums[i]], 1);
            }
            else {
                if(a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    seg1.update(mp[nums[i]], 1);
                }
                else{
                    b.push_back(nums[i]);
                seg2.update(mp[nums[i]], 1);
                }
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};