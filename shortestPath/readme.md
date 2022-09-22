### 최단 거리 구하기


[bfs 주의점](https://github.com/inhyuk15/Algorithm/tree/main/shortestPath/bfs/12851)

다익스트라와 bfs의 가장 큰 차이점은 간선의 가중치가 1보다 크냐 1이냐이다.
정확히는 bfs는 가중치가 모두 같을 때만 사용이 가능하다. ( 가중치만큼 나누면 1이기 때문)

이 점이 왜 중요하냐면 bfs의 동작방식이 가중치가 작은 걸 모두 순회한 다음 그 다음 크기의 가중치 ( 기존 가중치 + 1 ) 인 정점을 순회하기 때문이다.


시간복잡도는 bfs는 O(V), 다익스트라는 O(VlgE)

당연히 queue보다 prioirty_queue를 사용하는 다익스트라가 조금 더 느리다.




---




[백준 1238](https://www.acmicpc.net/problem/1238)
코드 : https://github.com/inhyuk15/Algorithm/tree/main/shortestPath/bfs/1238

본 문제같은 경우 

일단 기본적으로

## 단방향 그래프의 경우
## x2v에서 v2x를 구하고 싶은 경우

간선을 뒤짚는 발상은 정말 좋은 발상이다.


아무튼 그거랑 별개로 다시 주제로 돌아가서




이 문제를 처음에 bfs와 dijkstra의 섞은 방식을 적용했다.
다시 말해서 dijkstra에 priority_queue 대신에 queue를 사용했다.

이 문제에서 간선의 가중치는 다 다르다.
그런데 왜 queue가 통했는가이다.

이유는 이 문제에서 queue에 들어가는 정점이 한번만 방문되지 않았기 때문이다.
일반적인 bfs와 다르게 이 풀이는 bfs라기도 dijkstra라기도 애매하다.
결국 정점 v에서 정점 x로의 최단 거리를 구하기만 하면 됐고 몇번이든
마치 벨만포드의 완화시키는 방식으로 정점 v에서 정점 x까지의 최단거리를 찾아내었다.

확실히하자면 이 문제는 dijkstra에 속한다.