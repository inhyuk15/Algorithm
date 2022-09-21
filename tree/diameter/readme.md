### 트리의 지름

트리의 지름은 탐색 두번으로 해결 가능하다는 게 웰노운이다.

임의의 정점 a에 대해 가장 먼 정점 b를 구하고 (1)

정점 b와 가장 먼 정점 c와의 거리 (2) 가 트리의 지름이다.

증명은 생략한다.



(1)을 위해서 dfs를 이용할 때
전역변수로 정점 b를 두고
재귀적으로 도는 dfs에 대해 매개변수로 정보를 두개를 준다.
하나는 현재 위치, 그리고 다른 하나는 현재까지의 거리이다.

그래서 leaf에 도달할 때, 현재 재귀호출을 거쳐 계산해온 지금까지의 거리가 최대거리인지 체크하고
지금까지 거리가 제일 크면 그 때의 길이 메모, 그리고 그 때의 정점을 메모한다.
그렇게 최종적으로 얻게 되는 정점이 정점 b가 된다.

``` cpp:treeDiameter.cpp
      int startPoint = -1;
      int t;
      // here 에서 가장 먼 점 반환
      int dfs(int here, int curDist) {
          visited[here] = true;
          if(curDist > t) {
              t = curDist;
              startPoint = here;
          }

```



(2)는 dfs의 전형적인 패턴이다.
a에서 b까지의 최대거리는
dfs에 두개의 매개변수, 현재의 위치와 지금까지의 거리를 줌으로 구할 수 있다.



```cpp:treeDiameter.cpp
          int ret = curDist;
          for(int i =0; i < adj[here].size(); i++) {
              int next = adj[here][i].first;
              if(!visited[next]) {
                  int dist = adj[here][i].second;
                  int nextDist = dfs(next, curDist + dist);
                  if(ret < nextDist) {
                      ret = nextDist;
                  }
              }
          }
          return ret;
      }

```

이 패턴은 lis를 재귀로 풀려고 한다면 사용할 수 있다. 그때는 이제 메모이제이션을 사용하겠지만



