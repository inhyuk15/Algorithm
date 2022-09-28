
[2644번](https://www.acmicpc.net/problem/2644) 같은 경우

bfs든 dfs든 쉽게 풀 수 있다.

그런데 여기서 코드를 어떻게 짜느냐 방식을 바라보면

일단 dfs의 경우 매개변수로 해당 정점에서의 지금까지의 거리를 줌으로써
목적지에 도달하면 답을 얻는 방식으로 못얻으면 -1을 반환하는 식으로 풀 수 있다.


bfs의 경우
이게 지금 말하려고 하는 주제인데


코드에 정점당 지금까지 start에서 걸어온 거리를 기록할 때

visited 배열대신에 dist를 사용할 수 있다.

그리고 이걸 사용할 때
q에 굳이 pair<int,int>로 위치와 지금까지의 거리를 같이 기록할 필요가 없다.
말하자면 데이터가 중복된다는 것이다.


bfs의 순회 방식이 cost가 작은 것부터 큰 순서대로 라는 것을 알면 된다.

dist배열을 사용할 때 현재까지의 거리는 dist[here]에 기록되고
그 다음 거리는 dist[next] = dist[here] + 1 식으로 기록하면 된다.


그래서 진짜 깔끔한 2644번의 bfs 코드는 다음과 같다.

```cpp:2644.cpp
      int bfs(int start, int end) {
          vector<int> dist(n+1, INF);
          queue<int> q;
          q.push(start);
          dist[start] = 0;
          while(!q.empty()) {
              int here = q.front();
              q.pop();
              for(int next = 1; next <=n; next++) {
                  if(adj[here][next]) {
                      if(dist[next] == INF) {
                          dist[next] = dist[here] + 1;
                          q.push(next);
                      }
                  }
              }
          }
          return dist[end] == INF ? -1 : dist[end];
      }

```

이 때 굳이 dist말고 visited<bool>배열을 사용하겟다면 q에 pair로 해당 정점까지의 거리정보도 같이 넣어주면 된다.
  
  
  
  
---

  
[13460번](https://www.acmicpc.net/problem/13460)
  
이 문제는 bfs 문제의 집대성 그 자체이다.
반례 때문에 엄청 오래걸리기도 했는데
이 풀이 방법이 맞다는 확신을 갖고 있었기에 풀 수 있었던 문제이다.

문제 자체에 대해서 일단 신경써야할 부분이 몇개 있는데
1. 공 두개를 a, b라고 둘 때 a move, b move, a move, b move 방식으로 진행한다는 것, 그리고 이 때 움직일 때마다 움직였던 공의 위치를 갱신하는 것
2. 그리고 공이 골인지점에 들어갔을 때 공을 맵 밖으로 이동시키는 것
  
이 정도이다.
  
그보다 bfs에 대해서 확신을 가져야한다고 했는데
일단 간선의 가중치가 하나씩 증가한다는 점에서 bfs, 수의 범위가 매우 작아 4차원 배열이 적용이 가능하다는 점에서 dist[][][][] 배열의 사용 가능성 검증이다.
  
코드가 굉장히 복잡해서 (4차원이고 board 사용하는 문제인 만큼) 기능을 쪼개서 함수로 나누었다.
그런 거 외에는 본질은 단순한 bfs 문제이다.


---
  
[16236번](https://www.acmicpc.net/problem/16236)

이 문제는 그냥 뭐랄까 조건이 졸라 많다..
문제를 꼼꼼하게 읽어야한다.
  
숫자가 작기 때문에 총 20 * 20 번의 목적지에 20 * 20 의 시간복잡도인 bfs를 각각 해도 문제가 없다는 생각을 해야한다.
  
그리고 조건만 잘 맞춰서 bfs...
  
유의해야할 점이 있다면
  
```cpp:16236.cpp
          if(block[hy][hx] != 0 && block[hy][hx] < curSize && (hy != y || hx != x)) {
            if(dist[hy][hx] < minCost) {
                ret.clear();
                ret.push_back({hy, hx});
                minCost = dist[hy][hx];
            }
            else if(dist[hy][hx] == minCost) {
                ret.push_back({hy, hx});
            }
        }
```
  
  다음과 같이 코드를 짜서 최단 거리인 정점들을 모두 구할 수 있다는 것