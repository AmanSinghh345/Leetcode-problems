class Solution {
public:
    void heap(priority_queue<pair<double,int>>& mh,vector<vector<int>>& classes,int index){
        double curr_avg=(double)classes[index][0]/classes[index][1];
        double new_avg=((double)classes[index][0]+1)/(classes[index][1]+1);
        double possible_increment=new_avg-curr_avg;
        mh.push(make_pair(possible_increment,index));
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>> mh;
        for(int i=0;i<n;i++) 
           heap(mh,classes,i);
           while(extraStudents--){
            pair<double,int> current=mh.top();
            mh.pop();
            //Add 1 
            int index=current.second;
            classes[index][0]++;
            classes[index][1]++;
            heap(mh,classes,index);
           }
           double avg=0.0;
           int total=0;
           for(int i=0;i<n;i++) avg+=(double)classes[i][0]/classes[i][1];
           return avg/n;
    }
};