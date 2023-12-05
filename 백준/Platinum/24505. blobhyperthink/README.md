# [Platinum IV] blobhyperthink - 24505 

[문제 링크](https://www.acmicpc.net/problem/24505) 

### 성능 요약

메모리: 136220 KB, 시간: 976 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 세그먼트 트리

### 문제 설명

<p>BOJ에 있는 문제를 본 블롭은 쉬는 시간에 이런 문제를 생각해 냈다.</p>

<blockquote>
<p>길이가 $N$인 수열 $A$에서 다음 조건에 맞는 $(i, \ j)$ 쌍의 개수를 구하자!</p>

<ul>
	<li>$i \lt j$이고 $A_i \lt A_j$이다.</li>
</ul>
</blockquote>

<p>이 문제는 블롭에게 너무 쉬웠고, 블롭은 쌍의 원소 수를 세 개로 늘렸다. 하지만, 아직 이 문제는 블롭에게 너무 쉬웠고, 블롭은 쌍의 원소 수를 네 개로 늘렸다. <strong>...</strong></p>

<p>하지만, 아직 이 문제는 블롭에게 너무 쉬웠고, 블롭은 쌍의 원소 수를 열 개로 늘렸다. 하지만, 아직 이 문제는 블롭에게 너무 쉬웠고, 블롭은 쌍의 원소 수를 열한 개로 늘렸다. 이제 이 문제는 블롭에게 너무 어려워서 풀 수 없었다!</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3edecc05-2c59-4459-b844-35cd01f63cfe/-/preview/" style="display: inline-block; max-width: 384px;"></p>

<p>블롭을 위해 다음 조건을 만족하는 $(i,\ j,\ k,\ l,\ m,\ o,\ p,\ q,\ r,\ s,\ t)$ 쌍의 개수를 $10^9+7$로 나눈 나머지를 구하자.</p>

<ul>
	<li>$i \lt j \lt k \lt l \lt m \lt o \lt p \lt q \lt r \lt s \lt t$이고, $A_i \lt A_j \lt A_k \lt A_l \lt A_m \lt A_o \lt A_p \lt A_q \lt A_r \lt A_s \lt A_t$이다.</li>
</ul>

### 입력 

 <p>첫째 줄에 수열의 길이 $N$이 주어진다.</p>

<p>둘째 줄에 수열의 원소를 나타내는 $N$개의 정수 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>첫째 줄에 조건에 맞는 쌍의 개수를 $10^9+7$로 나눈 나머지를 출력한다.</p>

