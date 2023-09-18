# [Gold V] 전구 상태 바꾸기 - 30023 

[문제 링크](https://www.acmicpc.net/problem/30023) 

### 성능 요약

메모리: 3964 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 구현

### 문제 설명

<p>$N$개의 전구가 일렬로 세워져 빛나고 있다. 각각의 전구는 <span style="color:#e74c3c;">빨간색</span>, <span style="color:#2ecc71;">초록색</span>, <span style="color:#3498db;">파란색</span> 중 하나의 색으로 빛나고 있다. 지원이는 $N$개의 전구 중 연속한 세 전구를 선택한 후에 그 전구들의 상태를 바꿀 수 있다. 전구의 상태를 바꾼다는 것은 <span style="color:#e74c3c;">빨간색</span>으로 빛나는 전구는 <span style="color:#2ecc71;">초록색</span>으로, <span style="color:#2ecc71;">초록색</span>으로 빛나는 전구는 <span style="color:#3498db;">파란색</span>으로, <span style="color:#3498db;">파란색</span>으로 빛나는 전구는 <span style="color:#e74c3c;">빨간색</span>으로 빛나게 바꾼다는 것이다.</p>

<p>연속한 세 전구의 상태를 바꾸는 과정을 통해 모든 전구가 같은 색으로 빛나게 하려면 이 과정을 최소 몇 번 수행해야 하는지 구해보자.</p>

### 입력 

 <p>첫째 줄에 전구의 개수 $N(3\le N\le 100\, 000)$이 주어진다.</p>

<p>둘째 줄에 각각의 전구가 어떤 색으로 빛나고 있는지를 의미하는 길이가 $N$인 문자열 $S$가 주어진다. $S$의 $i$번째 문자는 $i$번째 전구가 어떤 색으로 빛나고 있는지를 의미한다. $S$는 알파벳 대문자 <span style="color:#e74c3c;"><code>R</code></span>, <span style="color:#2ecc71;"><code>G</code></span>, <span style="color:#3498db;"><code>B</code></span>로 이루어져 있으며, <span style="color:#e74c3c;"><code>R</code></span>은 빨간색을, <span style="color:#2ecc71;"><code>G</code></span>는 초록색을, <span style="color:#3498db;"><code>B</code></span>는 파란색을 의미한다.</p>

### 출력 

 <p>모든 전구가 같은 색으로 빛나게 하기 위해 연속한 세 전구의 상태를 바꾸는 과정을 최소 몇 번 수행해야 하는지 출력한다.</p>

<p>만약 모든 전구가 같은 색으로 빛나게 할 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다.</p>

