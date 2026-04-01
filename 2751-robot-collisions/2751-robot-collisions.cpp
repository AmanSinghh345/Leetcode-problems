class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0); 
        
    
        sort(ids.begin(), ids.end(), [&](int id1, int id2) {
            return positions[id1] < positions[id2];
        });
        
        vector<int> st; 
        
        for (int id : ids) {
            if (directions[id] == 'R') {
        
                st.push_back(id);
            } else {
            
                while (!st.empty() && healths[id] > 0 && directions[st.back()] == 'R') {
                    int top_id = st.back();
                    
                    if (healths[top_id] > healths[id]) {
                        
                        healths[top_id] -= 1;
                        healths[id] = 0; 
                    } else if (healths[top_id] < healths[id]) {

                        healths[id] -= 1;
                        healths[top_id] = 0; 
                        st.pop_back(); 
                    } else {
                        
                        healths[id] = 0;
                        healths[top_id] = 0;
                        st.pop_back();
                    }
                }
                
                if (healths[id] > 0) {
                    st.push_back(id);
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        
        return result;
    }
};