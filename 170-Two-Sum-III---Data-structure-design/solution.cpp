class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mp[number] += 1;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto pair : mp){
	        int num = pair.second;
	        if(num == value - num && mp[num] >= 2)
	            return true;
	        if(mp.find(value - num) != mp.end())
	            return true;
	    }
	    
	    return false;
	}
	
private:
    unordered_map<int> mp;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);