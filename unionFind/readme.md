### 유니온파인드 정리




find, merge 둘 다 시간복잡도 log n
n개의 원소에 대해 대략 nlog n


다음과 같이 rank를 이용해서 시간복잡도가 n까지 증가되는 걸 log n으로 줄일 수 있음

cnt배열을 이용해 자식 원소 개수 세기 가능

```cpp:unionfind.cpp
      int parent[55];
      int rankk[55];
      int cnt[55];
      int find(int u) {
          if(u == parent[u]) return u;
          return find(parent[u]);
      }

      void merge(int u, int v) {
          u = find(u);
          v = find(v);
          if(u == v) return;
          if(rankk[u] > rankk[v]) swap(u, v);
          parent[u] = v;
          cnt[v] += cnt[u];
          if(rankk[u] == rankk[v]) rankk[v]++;
      }
```



근데 다음과 같이 부모를 강제시켜야할 경우가 있을 경우
최적화 빼고 그냥 작성하는것도 편함

```cpp:1043.cpp
      void merge(int u, int v) {
          u = find(u);
          v = find(v);
          if(u == v) return;
          if(truth[v]) parent[u] = v;
          else parent[v] = u;
      }
```

