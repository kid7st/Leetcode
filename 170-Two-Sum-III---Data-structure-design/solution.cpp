class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    index[number] = nums.size();
	    nums.push_back(number);
	    return;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(int i = 0; i < nums.size(); i++){
	        int rest = value - nums[i];
	        if(index.find(rest) != index.end() && index[rest] != i)
	            return true;
	    }
	    
	    return false;
	}
	
private:
    vector<int> nums;
    unordered_map<int, int> index;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);