# [Gold II] Escape Room - 19606 

[문제 링크](https://www.acmicpc.net/problem/19606) 

### 성능 요약

메모리: 63420 KB, 시간: 416 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 문제 설명

<p>You have to determine if it is possible to escape from a room. The room is an M-by-N grid with each position (cell) containing a positive integer. The rows are numbered 1, 2, . . . , M and the columns are numbered 1, 2, . . . , N. We use (r, c) to refer to the cell in row r and column c.</p>

<p>You start in the top-left corner at (1, 1) and exit from the bottom-right corner at (M, N). If you are in a cell containing the value x, then you can jump to any cell (a, b) satisfying a × b = x. For example, if you are in a cell containing a 6, you can jump to cell (2, 3).</p>

<p>Note that from a cell containing a 6, there are up to four cells you can jump to: (2, 3), (3, 2), (1, 6), or (6, 1). If the room is a 5-by-6 grid, there isn’t a row 6 so only the first three jumps would be possible.</p>

### 입력 

 <p>The first line of the input will be an integer M (1 ≤ M ≤ 1000). The second line of the input will be an integer N (1 ≤ N ≤ 1000). The remaining input gives the positive integers in the cells of the room with M rows and N columns. It consists of M lines where each line contains N positive integers, each less than or equal to 1 000 000, separated by single spaces.</p>

### 출력 

 <p>Output <code>yes</code> if it is possible to escape from the room. Otherwise, output <code>no</code>.</p>

