Approach -1 :

TC-> O(n^2) 
```
bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
```


Approach -2:
TC-> O(nlogn), SC -> O(n) worst case
```
bool containsDuplicate(vector<int>& nums) {
      sort(begin(nums),end(nums));
      for(int i=0;i<size(nums)-1;i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
      }
      return false;
    }
```

Approach-3:
TC->O(n) , SC->O(n)

```
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>uset(begin(nums), end(nums));
        return uset.size()<nums.size() ? true : false;
    }
```

```
bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>uset;
        for(auto num: nums){
            if(uset.count(num)){
                return true;
            }
            uset.insert(num);
        }
        return false;
    }
```

