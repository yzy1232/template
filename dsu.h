#include<vector>
template<typename T>
class dsu {
private:
    std::vector<T> fa;
public:
    dsu(size_t s) {
        fa.resize(s + 1);
        for(int i = 1; i <= s; ++i) {
            fa[i] = i;
        }
    }
    inline int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    inline void merge(int x, int y) {
        fa[find(x)] = find(y);
    }
    ~dsu() {}
};