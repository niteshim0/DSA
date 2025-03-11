// https://leetcode.com/problems/intersection-of-two-arrays/description/

/*1.Brute Force : - Use set to find intersection.*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  set<int> s1;
  set<int> s2;
  for(int &x : nums1){
      s1.insert(x);
  }
  vector<int> ans;
  for(int &x : nums2){
      if(s1.find(x)!=s1.end() && s2.find(x) == s2.end()){
          ans.push_back(x);
          s2.insert(x);
      }
  }
  return ans;
}
//Time Complexity : O(Nlogn)
//Space Complexity: O(N1 + N2)

/*Optimal Approach : Use the same two pointer approach.*/

vector<int> findArrayIntersection(vector<int> &a, int n, vector<int> &b, int m)
{
	// Write your code here.
	vector<int> ans;
	int i = 0,j = 0;
	while(i<n && j < m){
	    if(a[i]<b[j]){
			i++;
		}else if(a[i]>b[j]){
			j++;
		}else if(a[i] == b[j]){
			ans.push_back(a[i]);
			i++;
			j++;
		}
	}
	return ans;

}
//Time Complexity : O(N+M)
//Space Complexity : O(1)