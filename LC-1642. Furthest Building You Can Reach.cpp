//max priority queue
class Solution {
public:
//here we are using maxheap that will store our max diff at any time bricks negative we replace max diff by laddere if available
//and add back our maxdiff into bricks.
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int>maxHeap;
        int i=0,diff=0;
        for(;i<heights.size()-1;i++){
             diff=heights[i+1]-heights[i];
             if(diff<=0){
                 continue;
             }
             bricks-=diff;
             maxHeap.push(diff);
             if(bricks < 0){
                 bricks+=maxHeap.top();
                 maxHeap.pop();
                 ladders--;
             }
             if(ladders<0) break;
        }
        return i;
    }
};