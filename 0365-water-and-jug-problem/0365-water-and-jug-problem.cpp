class Solution {
    int x,y,target;
    set<pair<int,int>>visited;
    bool solver(int dx, int dy){
        if(dx+dy==target){
            return true;
        }
        // bool val=false;
        vector<pair<int, int>> dirs = {
                {x, dy},
                {dx, y},
                {0, dy},
                {dx, 0},
                {dx - min(dx, y - dy), dy + min(dx, y - dy)},
                {dx + min(dy, x - dx), dy - min(dy, x - dx)} 
        };
        for(auto [nx,ny]:dirs){
            if(visited.count({nx,ny})==0){
                visited.insert({nx,ny});
                if(solver(nx,ny)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y){
            return false;
        }
        this->x=x;
        this->y=y;
        this->target=target;
        visited.insert({0,0});
        return solver(0,0);
    }
};