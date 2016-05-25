class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    numSet.insert(number);
	    return;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto num : numSet){
	        int gap = value - num;
	        if(gap == num){
	            if(numSet.count(num) >= 2)
	                return true;
	        }else{
	            if(numSet.find(gap) != numSet.end())
	                return true;
	        }
	    }
	    
	    return false;
	}
	
private:
    unordered_multiset<int> numSet;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);