#include <bits/stdc++.h>

using namespace std;

template<class T>
class Multiset {
  vector<T>v;
 public:
  Multiset() {};
  Multiset(const Multiset &that) {
    v = that.v;
  }
  void operator= (const Multiset &that) {
    v = that.v;
  }
  int Size() const {
    return v.size();
  }
  void Insert(const T& x) {
    v.push_back(x);
  }
  void Erase(const T& x) {
    for(auto it = begin(v); it != end(v); ++ it) {
      if(*it == x) {
        v.erase(it);
        return;
      }
    }

  }
  int operator[] (const T& x) const {
    int many = 0;
    for(const auto& it : v)
      if(it == x)
        ++many;
    return many;
  }

  bool Find(const T& x) {
    if((*this)[x] > 0)
      return true;
    return false;
  }
  void EraseAll(const T& x) {
    int last = 0;
    for(int i = 0; i < (int)v.size(); ++ i) {
      if(v[i] != x) {
        v[last] = v[i];
        last++;
      }
    }
    while((int)v.size() > last) {
      v.pop_back();
    }
  }
  int Distinct() const {
    int many = 0;
    for(int i = 0; i < (int)v.size(); ++ i) {
      bool found = false;
      for(int j = i - 1; j >= 0 && !found; --j)
        if(v[j] == v[i])
          found = true;
      if(!found) ++ many;
    }
    return many;
  }
  ~Multiset() {
    vector<T>().swap(v);
  }
};

int main() {

  Multiset<int>S;
  srand(time(0));

  const int L = 5252, Size = 5000;
  vector<int>my;
  vector<int>ap(L + 1);
  for(int i = 1; i <= Size; ++i) {
    int x = rand() % L;
    my.push_back(x);
    S.Insert(x);
    ++ ap[x];
  }

  for(int i = 0; i < L; ++i) {
    assert(ap[i] == S[i]);
    S.EraseAll(i);
  }

  assert(!S.Size());
  return 0;
}
