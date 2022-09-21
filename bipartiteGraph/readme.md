### Bipartite Graph(이분 그래프)


## Bipartiteness Check: Graph 의 각 vertex 를 두 가지 color 로 색칠한다 할 때, 같은 색깔로 칠해진
## 두 vertex 사이에 edge 가 없는 경우, 해당 graph 를 bipartite graph 라 한다.

- Graph traversal 을 이용해 graph 가 bipartite graph 인지 쉽게 체크 가능.
- 두color를각각A 와B라할때,시작vertex는A로,시작vertex의neighborhood는색깔
B 로, 그 neighborhood 는 다시 색깔 A 로 반복해서 색칠해 나간다.
- 색칠 도중 같은 색깔로 칠해진 adjacent 한 두 vertex 를 발견한 경우, 해당 graph 는 bipartite
graph 가 아니다.


백준 1707
https://www.acmicpc.net/problem/1707


