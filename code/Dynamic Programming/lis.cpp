#include "header.h"
template<class T>
vector<T> index_path_lis(vector<T>& nums) {
	int n = nums.size();
	vector<T> sub; 
		vector<int> subIndex;
	vector<T> path(n, -1); 
	for (int i = 0; i < n; ++i) {
	    if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
		path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
		sub.push_back(nums[i]);
		subIndex.push_back(i);
	    } else {
		int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
		path[i] = idx == 0 ? -1 : subIndex[idx - 1];
		sub[idx] = nums[i];
		subIndex[idx] = i;
	    }
	}
	vector<T> ans;
	int t = subIndex[subIndex.size() - 1];
	while (t != -1) {
	    ans.push_back(t);
	    t = path[t];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
// Length only
template<class T>
int length_lis(vector<T> &a) {
	set<T> st;
	typename set<T>::iterator it;
	for (int i = 0; i < a.size(); ++i) {
		it = st.lower_bound(a[i]);
		if (it != st.end()) st.erase(it);
		st.insert(a[i]);
	}
	return st.size();
}
