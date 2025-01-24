class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /*
          題目: 給一個有向圖表，節點數為n，找出圖表中所有safe node
          所謂safe node即為: 
            1.他自己已是終點，沒有任何向外路徑，或者
            2.他的所有向外路徑連接到的節點都是safe node, 那他也會是safe node
            
          也就是所有自這節點出發的路徑都不可以有循環路徑，自循環也不可以
        */
        int n=graph.size();
        vector<vector<int>> inGraph(n);
        vector<int> outDegree(n,0);
        vector<int> safe(n,0);

        //建立反向表，及出度表
        for(int i=0;i<n;i++){
            outDegree[i]=graph[i].size();  //紀錄每個點有多少向外路徑
            for(int& out:graph[i])
                inGraph[out].push_back(i); //紀錄每個節點有哪些向內路徑
        }

         //先找出已是終點的節點   
        queue<int> q;
        for(int i=0;i<n;i++)
            if(outDegree[i]==0){  //也就是沒有任何向外路徑
                safe[i]=1;        //那他就是safe node
                q.push(i);        //把它塞進q中，拿來當作BFS的起點
            }
        
        //BFS
        while(!q.empty()){ 
            int node=q.front();  
            q.pop();
            for(int upNode:inGraph[node]){  //掃描q 中的safe node他所有的向內路徑連接到的上游節點(upNode)
                if(--outDegree[upNode]==0){ //upNode去除node當出口後是否還有其他出口，因為我們只會把safe node 塞進q裡，所以這邊的node一定都是safe node
                    safe[upNode]=1;         //如果沒有其他出口了，代表他的所有出口都是safe node，自然他也是safe node
                    q.push(upNode);
                }
            }   
        }

        //回傳結果，由於題目指定要按照順序，所以只好這樣傳
        vector<int> res;
        for(int i=0;i<n;i++)
            if(safe[i])
                res.push_back(i);
        
        return res;
    }
};
