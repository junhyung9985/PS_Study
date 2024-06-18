# [Gold III] Dragon Maze (Large) - 12273 

[문제 링크](https://www.acmicpc.net/problem/12273) 

### 성능 요약

메모리: 2288 KB, 시간: 16 ms

### 분류

너비 우선 탐색, 데이크스트라, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 최단 경로

### 문제 설명

<p>You are the prince of Dragon Kingdom and your kingdom is in danger of running out of power. You must find power to save your kingdom and its people. An old legend states that power comes from a place known as Dragon Maze. Dragon Maze appears randomly out of nowhere without notice and suddenly disappears without warning. You know where Dragon Maze is now, so it is important you retrieve some power before it disappears.</p>

<p>Dragon Maze is a rectangular maze, an <strong>N</strong> x <strong>M</strong> grid of cells. The top left corner cell of the maze is (0,0) and the bottom right corner is (<strong>N</strong>-1, <strong>M</strong>-1). Each cell making up the maze can be either a dangerous place which you never escape after entering, or a safe place that contains a certain amount of power. The power in a safe cell is automatically gathered once you enter that cell, and can only be gathered once. Starting from a cell, you can walk up/down/left/right to adjacent cells with a single step.</p>

<p>Now you know where the entrance and exit cells are, that they are different, and that they are both safe cells. In order to get out of Dragon Maze before it disappears, you must walk from the entrance cell to the exit cell taking as few steps as possible. If there are multiple choices for the path you could take, you must choose the one on which you collect as much power as possible in order to save your kingdom.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow.</p>

<p>Each test case starts with a line containing two integers <strong>N</strong> and <strong>M</strong>, which give the size of Dragon Maze as described above. The second line of each test case contains four integers <strong>en</strong><strong><sub>x</sub></strong>, <strong>en</strong><strong><sub>y</sub></strong>, <strong>ex</strong><strong><sub>x</sub></strong>, <strong>ex</strong><strong><sub>y</sub></strong>, describing the position of entrance cell <strong>(en</strong><strong><sub>x</sub></strong><strong>, en</strong><strong><sub>y</sub></strong><strong>)</strong> and exit cell <strong>(ex</strong><strong><sub>x</sub></strong><strong>, ex</strong><strong><sub>y</sub></strong><strong>)</strong>. Then <strong>N</strong> lines follow and each line has <strong>M</strong> numbers, separated by spaces, describing the <strong>N x M</strong> cells of Dragon Maze from top to bottom. Each number for a cell is either -1, which indicates a cell is dangerous, or a positive integer, which indicates a safe cell containing a certain amount of power.</p>

<p>Limits</p>

<ul>
	<li>The amount of power contained in each cell will not exceed 10,000.</li>
	<li>1 ≤ <strong>T</strong> ≤ 30.</li>
	<li>0 ≤ <strong>en</strong><strong><sub>x</sub></strong>, <strong>ex</strong><strong><sub>x</sub></strong> < <strong>N</strong>.</li>
	<li>0 ≤ <strong>en</strong><strong><sub>y</sub></strong>, <strong>ex</strong><strong><sub>y</sub></strong> < <strong>M</strong>.</li>
	<li><span style="line-height:1.6em">1 ≤ </span><strong style="line-height:1.6em">N</strong><span style="line-height:1.6em">, </span><strong style="line-height:1.6em">M</strong><span style="line-height:1.6em"> ≤ 100.</span></li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1). If it's possible for you to walk from the entrance to the exit, y should be the maximum total amount of power you can collect by taking the fewest steps possible. If you cannot walk from the entrance to the exit, y should be the string "Mission Impossible." (quotes for clarity). Please note that the judge requires an exact match, so any other output like "mission impossible." or "Mission Impossible" (which is missing the trailing period) will be judged incorrect.</p>

