class DSU{
private:
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);   //每個節點最初的高度都是1
        for(int i=0;i<n;i++)//初始化，每個節點都是自己的復節點
            parent[i]=i;
    }
    int find(int x){    //路徑壓縮
        if(parent[x]!=x)
            parent[x]=find(parent[x]); //一路找到根節點
        return parent[x];
    }
    bool unite(int x, int y){
        int rootX=find(x), rootY=find(y); //找到兩個節點所在集合的根結點
        if(rootX==rootY)    // 如果已經在同一個集合裡了，形成環
            return false;
        //rank union, 讓兩個集合合併
        if(rank[rootX]>rank[rootY]) //如果x 的rank大於y，那就讓y 合併到x裡
            parent[rootY]=rootX;
        else if(rank[rootX]<rank[rootY])//如果y 的rank大於x，那就讓x 合併到y裡
            parent[rootX]=rootY;
        else{//如果x 的rank等於y，那就讓y 合併到x裡，但xrank++(樹的高度長高)
            parent[rootY]=rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        for(auto& e:edges){
            int u=e[0], v=e[1];
            if(!dsu.unite(u,v))
                return e;
        }
        return {};
    }
};
