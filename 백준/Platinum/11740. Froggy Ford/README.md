# [Platinum V] Froggy Ford - 11740 

[문제 링크](https://www.acmicpc.net/problem/11740) 

### 성능 요약

메모리: 19292 KB, 시간: 68 ms

### 분류

데이크스트라, 기하학, 그래프 이론

### 문제 설명

<p>Fiona designs a new computer game Froggy Ford. In this game, a player helps a frog to cross a river using stone fords. Frog leaps from the river’s shore to the first stone ford, than to the second one and so on, until it reaches the other shore. Unfortunately, frog is pretty weak and its leap distance is quite limited. Thus, a player should choose the optimal route — the route that minimizes the largest leap required to traverse the route.</p>

<table class="table">
	<tbody>
		<tr>
			<td style="text-align:center"><img alt="" src="" style="height:200px; width:280px"></td>
			<td style="text-align:center"><img alt="" src="" style="height:199px; width:282px"></td>
		</tr>
		<tr>
			<td style="text-align:center">Optimal route</td>
			<td style="text-align:center">Optimal route with added stone</td>
		</tr>
	</tbody>
</table>

<p>Fiona thinks that this game is not challenging enough, so she plans to add a possibility to place a new stone in the river. She asks you to write a program that determines such a location of the new stone that minimizes the largest leap required to traverse the optimal route.</p>

### 입력 

 <p>The first line of the input file contains two integers w — the width of the river and n — the number of stones in it (1 ≤ w ≤ 10<sup>9</sup>, 0 ≤ n ≤ 1000).</p>

<p>Each of the following n lines contains two integers x<sub>i</sub>, y<sub>i</sub> — the coordinates of the stones (0 < x<sub>i</sub> < w, −10<sup>9</sup> ≤ yi ≤ 10<sup>9</sup>). Coordinates of all stones are distinct. River shores have coordinates x = 0 and x = w.</p>

### 출력 

 <p>Write to the output file two real numbers x<sub>+</sub> and y<sub>+</sub> (0 < x<sub>+</sub> < w, −10<sup>9</sup> ≤ y<sub>+</sub> ≤ 10<sup>9</sup>) — the coordinates of the stone to add. This stone shall minimize the largest leap required to traverse the optimal route. If a new stone cannot provide any improvement to the optimal route, then an arbitrary pair of x<sub>+</sub> and y<sub>+</sub> satisfying the constraints can be written, even coinciding with one of the existing stones. Your answer shall be precise up to three digits after the decimal point.</p>

