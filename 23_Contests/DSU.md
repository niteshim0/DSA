```c++
class DSU{
public:

    vector<int> parent, size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a,int b){

        int ra = find(a);
        int rb = find(b);

        if(ra == rb) return;

        if(size[ra] < size[rb])
            swap(ra,rb);

        parent[rb] = ra;
        size[ra] += size[rb];
    }
};
```