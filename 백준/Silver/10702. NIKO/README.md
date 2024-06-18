# [Silver I] NIKO - 10702 

[문제 링크](https://www.acmicpc.net/problem/10702) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 이분 매칭, 브루트포스 알고리즘, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 문제 설명

<p>It is the year 2018, Russia. History repeats itself and the not-so-young football coach Niko is leading the national team in a clash with Brazil.</p>

<p>Choosing a formation is the first step when it comes to preparing the strategy for a football game. A formation can be represented with three integers O, V and N, where O denotes the number of defensive players, V denotes the number of midfielders and N denotes the number of offensive players. It is evident that it must hold O + V + N = 10.</p>

<p>After choosing a formation, the coach needs to carefully choose the players because not every player is a defensive wizard or a world class striker. The coach knows his players very well. He knows which line suits each player. Setting a player in a line he doesn’t know how to play would be tactical suicide.</p>

<p>The coach and his team of expertise have put together a list of formations that can be taken into consideration against Brazil, but in all their expertise they didn’t have time to determine the formations which they have suitable players for. Help them!</p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 10), the number of formations taken into consideration.</p>

<p>Each of the following N lines contains the formation given as O-V -N. The numbers O, V i N are positive integers and it holds O + V + N = 10.</p>

<p>The following line contains the integer M (10 ≤ M ≤ 22), the number of players who want to join the national team.</p>

<p>The ith of the following M lines contains the list of lines that the ith player can play in. Letter ‘O’ denotes defense, letter ‘V’ midfield positions and letter ‘N’ offense.</p>

### 출력 

 <p>Output exactly N lines. The ith line of output should be “DA” if the coach has suitable players for the ith formation from the input, or “NE” if he doesn’t.</p>

