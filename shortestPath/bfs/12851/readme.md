## bfs 코드 짤 때 고려할 것

bfs는 보통 최단거리, 최단시간 그런 것과 관련이 있다.
동작과정을 확실하게 이해하면 코드가 어떻게 돌아가는 지 알 수 있다.


보통 bool타입의 visited 배열을 선언해서
방문한 점은 다시 방문안하게 끔 한다.
그런데 단순히 queue에 int값만 넣는게 아닌 최단 경로에서 각 정점에서의 거리를 구해야할 때
queue<pair<int,int>> q;
로 선언하여 {point, cost}를 쌍으로 기록해놓는다

그리고 동시에 dist배열을 선언하여 visited 배열을 대신함과 동시에 정점 방문시 최단거리를 기록해서 최적화를 시킬 수 있다.

이점은 다익스트라랑 비슷하다.
하지만 다익스트라랑 다르게 

bfs는 queue에 원소를 넣은 순서가 다익스트라보다 더 직접적으로 반영된다는 점에 주목해야한다.
각 정점의 거리가 1보다 크면 안된다는 것이다.

이 점이 다익스트라랑 가장 큰 차이점이다.




## bfs 최적화


12851 이 문제의 경우

bfs코드 안에서 주어진 목적지에 도달했을 때

```cpp:12851.cpp
        while(!q.empty()) {
            int here = q.front().first;
            int cost = q.front().second;
            // cout << here << endl;
            q.pop();
            if(here == k) {
                if(cost <= pathTime) {
                    pathCnt++;
                    pathTime = cost;
                }
                else break;
            }

```
다음과 같이 계속 while문을 반복하게 끔 했다.

그런데 이것은 bfs의 동작방식을 이해했다면

저 if문을 처음만났을 때 이미 queue에는 위치가 here인 pathTime이 cost보다 작거나 같을 수 있는 pair가 모두 넣어졌다는 걸 이해할 수 있다.

앞으로 while문에서 만날 것들은 모두 cost가 지금의 cost보다 크거나 같은 것만 나오기 때문이다.



그래서 저 문장은 안에 while문을 한번 더 넣는 식으로 바꿀 수 있다.

```cpp:12851.cpp
        while(!q.empty()) {
            int here = q.front().first;
            int cost = q.front().second;
            // cout << here << endl;
            q.pop();
            if(here == k) {
                pathCnt++;
                while(!q.empty()) {
                    int here = q.front().first;
                    q.pop();
                    if(here == k) pathCnt++;
                }
                return {cost, pathCnt};
            }
```


솔직히 그렇게 큰 유의미한 변화 없지만
적당히 시간단축이 된다.