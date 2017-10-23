给一个String数组，中间会有重复的string，返回离得最近的重复string，比如说{"we", "work", "at", "no", "work", "no"},
重复的是"work"和"no"，"work"相隔了3，"no"相隔了2，那么就返回"work"，如果有相同的就返回最后出现的string


vector<int> find(vector<string>& words){
    unordered_map<string,vector<int>> maps;
    vector<int>result;
    for (int i = words.size()-1; i >= 0; --i){
        vector<int>tmp;
        pair<unordered_map<string,vector<int>>::iterator,bool> p = maps.emplace(words[i],tmp);
        if (p.second){
            maps[words[i]].push_back(i);
            maps[words[i]].push_back(i);
            maps[words[i]].push_back(INT_MAX);
            maps[words[i]].push_back(i);
        }
        if (!p.second){
            if(maps[words[i]][3] - i <= maps[words[i]][2]){

                maps[words[i]][2] = maps[words[i]][3] - i;

                maps[words[i]][1] = maps[words[i]][3];
                maps[words[i]][0] = i;
                maps[words[i]][3] = i;
            }
            else{
                maps[words[i]][3] = i;
            }
        }
    }
    int minV = INT_MAX;
    for (auto a : maps){
        minV = min(a.second[2],minV);
    }
    cout << minV << endl;
    for (unordered_map<string,vector<int>>::iterator it = maps.begin(); it != maps.end(); ++it){
        if (minV == it->second[2]) {
            result.push_back(it->second[0]);
            result.push_back(it->second[1]);
        }
    }
    return result;
}
