class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mp.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(int num : set){
	        if(set.find(value - num) != set.end())
	            return true;
	    }
	    return false;
	}
	
private:
    unordered_set<int> set;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);