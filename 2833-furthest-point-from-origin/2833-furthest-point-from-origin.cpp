class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntL=0,cntR=0;
        for(int i=0;i<(int)moves.size();i++){
            if(moves[i]=='L') cntL++;
            else if(moves[i]=='R') cntR++;
        }
        if(cntR>cntL){
            swap(cntL,cntR);
        }
        int blank=(int)moves.size()-(cntL+cntR);
        return blank+cntL-cntR;
    }
};