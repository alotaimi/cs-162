#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool containsDuplicate (vector<int>& nums){
	bool dope = false;
	sort(nums.begin(),nums.end());
	if(nums.size() <= 1){
		return dope;
	}
	for(int i = 1; i < nums.size(); i++){
			if(nums[i] == nums[i-1]){
				dope = true;
				break;
			}
	}
	return dope;
}