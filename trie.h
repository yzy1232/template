#include<vector>
#include<string>
class Trie {
private:
    struct node {
        bool is_root = 0;
        int visited = 0;
        int cnt = 0;//单词个数统计
        int next[26];
    };
    std::vector<node> trie;
    int cnt = 0;
public:
    Trie(size_t s) {trie.resize(s);}
    void insert(std::string s) {
        int curr = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(!trie[curr].next[tolower(s[i]) - 'a'])trie[curr].next[tolower(s[i]) - 'a'] = ++cnt;
            curr = trie[curr].next[tolower(s[i]) - 'a'];
            trie[curr].cnt++;
        }
        trie[curr].is_root = true;
    }
    int find(std::string s) {
        int curr = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(!trie[curr].next[tolower(s[i]) - 'a'])return 0;
            curr = trie[curr].next[tolower(s[i]) - 'a'];
        }
        if(!trie[curr].is_root)return 0;
        trie[curr].visited++;
        return trie[curr].visited;
    }
};