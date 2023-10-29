# [Silver III] Suffi$\otimes$ - 30389 

[문제 링크](https://www.acmicpc.net/problem/30389) 

### 성능 요약

메모리: 7528 KB, 시간: 16 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 문자열

### 문제 설명

<p><strong>이 문제는 모든 언어에 대해서 시간 제한과 메모리 제한이 동일하다. 상단의 시간 제한 및 메모리 제한 란을 참조하라.</strong></p>

<p>문자열에 약한 비행씨는 열심히 문자열 알고리즘을 바라보고 있다. LCS, KMP, Rabin-Karp, Aho-Corasick...</p>

<p>Suffix array를 바라보다 머리가 터져버린 비행씨는 머리를 식힐 겸 입력으로 주어진 문자열들의 접미사를 정리하려고 한다. 다만 그냥 정리하면 재미가 없으니, 문자열의 접미사 집합을 XOR하려고 한다.</p>

<p>문자열 $S$의 접미사 집합 $\text{suffix}[S]$은 $S$의 모든 접미사를 원소로 가지는 집합이라 정의하고, 두 집합 $A, B$의 XOR인 $A\otimes B$는 다음과 같이 정의한다.</p>

<p>$$A\otimes B=\{x\mid x\in A\cup B\text{ and }x\not\in A\cap B\}$$</p>

<p>비행씨를 대신하여 주어진 문자열 $S_1,S_2,\cdots,S_N$의 접미사 집합을 전부 XOR한 집합 $(\cdots((\text{suffix}[S_1]\otimes\text{suffix}[S_2])\otimes\text{suffix}[S_3])\cdots\otimes\text{suffix}[S_N])$의 원소의 개수를 구하는 프로그램을 작성해 주자.</p>

### 입력 

 <p>첫째 줄에 정수 $N$이 주어진다. $(1\le N\le 1\,000)$</p>

<p>둘째 줄부터 $N$개의 줄에 한 줄에 하나씩 영어 소문자로만 이루어진 문자열 $S_i$가 주어진다. $(1\le |S_i|\le 50)$</p>

### 출력 

 <p>$(\cdots((\text{suffix}[S_1]\otimes\text{suffix}[S_2])\otimes\text{suffix}[S_3])\cdots\otimes\text{suffix}[S_N])$의 원소의 개수를 출력한다.</p>

<p>공집합의 원소의 개수는 $0$이다.</p>

