
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