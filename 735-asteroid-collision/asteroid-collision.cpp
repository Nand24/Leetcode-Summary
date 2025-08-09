class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>=0){

                
                    st.push(asteroids[i]);
                
            }
            else{
               bool destroyed=false;
               while(!st.empty() && st.top()>0){
                // tabhi ldai hogi
                   if(abs(asteroids[i])>st.top()){
                    st.pop();

                   }
                   else if(abs(asteroids[i])==st.top()){
                    st.pop();
                    destroyed=true;
                    break;
                   }
                    else{
                    destroyed=true;
                    break;
                   }

               }

               if(destroyed==false){
                // no ladai and hence no collision
                st.push(asteroids[i]);
               }
             
            }  
            
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};