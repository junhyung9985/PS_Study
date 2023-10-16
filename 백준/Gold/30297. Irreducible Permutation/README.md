# [Gold IV] Irreducible Permutation - 30297 

[문제 링크](https://www.acmicpc.net/problem/30297) 

### 성능 요약

메모리: 4976 KB, 시간: 56 ms

### 분류

애드 혹, 해 구성하기

### 문제 설명

<p>A permutation is called <em>irreducible</em> if none of its prefixes forms a permutation, except the permutation itself. For example, $[2,3,1]$ and $[4,1,2,3]$ are irreducible while $[2,1,3]$ and $[1,3,2]$ are not.</p>

<p>You are given a permutation $P$ of length $N$. In one operation, you can choose any two adjacent indices and swap their values.</p>

<p>Find the minimum number, and the corresponding sequence, of operations to transform $P$ into an irreducible permutation. It can be shown that you can always make given permutation irreducible.</p>

### 입력 

 <p>The first line contains a single integer $T$ --- the number of test cases.</p>

<p>The first line of each test case contains a single integer $N$.</p>

<p>The second line of each test case contains $N$ space-separated integers $P_1,\ldots ,P_N$ $(1\le P_i\le N)$.</p>

### 출력 

 <p>For each test case, print two lines:</p>

<p>On the first line, print $K$ --- the minimum number of operations that can make $P$ irreducible.</p>

<p>On the second line, print $K$ space-separated integers $S_1,\ldots ,S_K$ where $S_i$ and $S_i+1$ are the indices you intend to swap. If there are multiple solutions, you may print any.</p>

<p>Note that the operations are performed sequentially in the same order specified by your output.</p>

