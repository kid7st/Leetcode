class Solution {
    vector<int> split(const string &s, char delim)
    {
        stringstream ss(s);
        string item;
        vector<int> elems;
        while(getline(ss, item, delim))
        {
            elems.push_back(atoi(item.c_str()));
        }
        return elems;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1=split(version1, '.');
        vector<int> ver2=split(version2, '.');
        int size = min(ver1.size(), ver2.size()), idx = 0;
        for (; idx < size; idx++)
        {
            if (ver1[idx] < ver2[idx]) return -1;
            if (ver1[idx] > ver2[idx]) return  1;
        }
        if (ver1.size() < ver2.size())
        {
            while(!ver2[idx] && idx < ver2.size()) idx++;
            if (idx < ver2.size()) return -1;
        }
        if (ver1.size() > ver2.size())
        {
            while(!ver1[idx] && idx < ver1.size()) idx++;
            if (idx < ver1.size()) return  1;
        }
        return 0;
    }
};