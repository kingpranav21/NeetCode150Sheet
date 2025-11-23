Apporach -1 :

TC->O(nlogn + mlogm), SC->O(n+m)
```

bool isAnagram(string s, string t) {
				if(t.size()!=s.size())return false;
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        return s==t;
}
```

Approach-2:

TC: O(n+m), SC:O(1)

```
bool isAnagram(string s, string t) {
        if (t.size() != s.size())
            return false;
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        return smap == tmap;
  }
```


Approach-3: 

TC: O(n+m), SC:O(1)

```
bool isAnagram(string s, string t) {
        vector<int>ascii(26,0);
        for(int i=0;i<s.size();i++){
            ascii[s[i]-'a']++;
            ascii[t[i]-'a']--;
        }

        for(auto it: ascii){
            if(it>0)return false;
        }
        return true;
    }
```