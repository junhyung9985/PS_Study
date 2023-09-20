# [Gold II] 괄호 - 17623 

[문제 링크](https://www.acmicpc.net/problem/17623) 

### 성능 요약

메모리: 2184 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>6개의 문자 ‘<code>(</code>’, ‘<code>)</code>’, ‘<code>{</code>’, ‘<code>}</code>’, ‘<code>[</code>’, ‘<code>]</code>’ 로 이루어진 올바른 괄호 문자열 <code>W</code>에 대하여 정수의 ‘괄호값’을 지정하는 함수 <em>val</em>(<code>W</code>)가 정의되어 있다. 먼저 <u>올바른 괄호 문자열</u>부터 정의해보자.</p>

<p>한 쌍의 괄호로 구성된 길이 2인 문자열, 즉 ‘<code>()</code>’, ‘<code>[]</code>’, ‘<code>{}</code>’은 모두 올바른 괄호 문자열이다. 이것을 단위 괄호라고 한다. <code>X</code>, <code>Y</code>가 올바른 괄호 문자열인 경우, 아래와 같은 작업을 통하여 만들어지는 새로운 문자열은 모두 올바른 괄호 문자열이 된다.</p>

<ol>
	<li><code>XY</code> // 올바른 두 괄호 문자열의 접합(concatenation).</li>
	<li><code>(X)</code>, <code>{X}</code>, <code>[X]</code> // 올바른 괄호 문자열 전체를 다시 괄호로 감쌈.</li>
</ol>

<p>올바른 괄호 문자열과 아닌 예가 다음에 있다. 단 괄호 문자 사이에 공백은 없다.</p>

<ul>
	<li>올바른 예: <code>({}{}[(())])</code>, <code>(())</code>, <code>{}[][(())]</code></li>
	<li>올바르지 못한 예: <code>{[(())]</code>, <code>(([)]))</code>, <code>{{{}}()</code>, <code>)]{}</code></li>
</ul>

<p>이제 괄호값 <em>val</em>()의 계산 방법을 설명한다. 3 종류의 단위 괄호 <code>()</code>, <code>{}</code>, <code>[]</code>의 괄호값은 각각 1, 2, 3으로 정의되어 있다. 즉 문자열이 <code>X</code>=‘<code>()</code>’, <code>Y</code>=‘<code>{}</code>’, <code>Z</code>=‘<code>[]</code>’이면 <em>val</em>(<code>X</code>) = 1, <em>val</em>(<code>Y</code>) = 2, <em>val</em>(<code>Z</code>) = 3이다. 만일 <code>X</code>, <code>Y</code>가 올바른 문자열이라고 할 때 이 둘을 순차적으로 연결한 문자열 <code>Z</code>=<code>XY</code>의 괄호값은 다음과 같이 계산된다.</p>

<ul>
	<li><em>val</em>(<code>Z</code>) = <em>val</em>(<code>X</code>) + <em>val</em>(<code>Y</code>)</li>
</ul>

<p>만일 어떤 올바른 문자열 <code>X</code>가 <code>A</code>=‘<code>(X)</code>’, <code>B</code>=‘<code>{X}</code>’, <code>C</code>=‘<code>[X]</code>’와 같이 <code>()</code>, <code>{}</code>, <code>[]</code>로 둘러싸여 있을 경우에 <code>A</code>, <code>B</code>, <code>C</code>의 괄호값은 다음과 같이 계산된다.</p>

<ul>
	<li><em>val</em>(<code>A</code>) = 2·<em>val</em>(<code>X</code>), <em>val</em>(<code>B</code>) = 3·<em>val</em>(<code>X</code>), <em>val</em>(<code>C</code>) = 5·<em>val</em>(<code>X</code>)</li>
</ul>

<p>그런데 괄호값이 k인 문자열은 유일하지 않다. 예를 들어 ‘<code>[]</code>’, ‘<code>{}()</code>’, ‘<code>()()()</code>’ 모두는 괄호값이 3을 가지는 문자열이다. 다음 표는 올바른 괄호 문자열에 대응하는 괄호값 val(<code>X</code>)의 예를 보여준다.</p>

<table class="table table-bordered" style="width: 50%;">
	<thead>
		<tr>
			<th>올바른 괄호 문자열 <code>X</code></th>
			<th><em>val</em>(<code>X</code>)</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>(()())</code></td>
			<td>2(1+1) = 4</td>
		</tr>
		<tr>
			<td><code>[[[]]]</code></td>
			<td>3×5×5 = 75</td>
		</tr>
		<tr>
			<td><code>[][][]{()}</code></td>
			<td>3+3+3+3(1) = 12</td>
		</tr>
		<tr>
			<td><code>((())[{}])()</code></td>
			<td>2(2+5×2)+1 = 25</td>
		</tr>
	</tbody>
</table>

<p>올바른 괄호 문자열 <code>X</code>를 숫자로도 표현할 수 있다. 괄호 문자열을 숫자로 바꾸는 방법은 각 괄호 문자에 대하여 아래 표와 같이 1에서 6까지의 숫자로 대치해 십진수로 읽은 값이다.</p>

<table class="table table-bordered" style="width: 50%;">
	<thead>
		<tr>
			<th>문자</th>
			<th><code>(</code></th>
			<th><code>)</code></th>
			<th><code>{</code></th>
			<th><code>}</code></th>
			<th><code>[</code></th>
			<th><code>]</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>대치문자</td>
			<td>1</td>
			<td>2</td>
			<td>3</td>
			<td>4</td>
			<td>5</td>
			<td>6</td>
		</tr>
	</tbody>
</table>

<p>괄호 문자열 X를 위에 설명한 방식으로 변환시킨 값을 <em>dmap</em>(<code>X</code>)로 표시한다. 몇몇 올바른 괄호 문자열 <code>X</code>에 대해서 <em>dmap</em>(<code>X</code>)을 나타낸 표가 아래에 있다.</p>

<table class="table table-bordered" style="width: 50%;">
	<thead>
		<tr>
			<th><em>val</em>(<code>R</code>)=3 문자열</th>
			<th><em>dmap</em>(<code>R</code>)</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>()()()</code></td>
			<td>121212</td>
		</tr>
		<tr>
			<td><code>{}()</code></td>
			<td>3412</td>
		</tr>
		<tr>
			<td><code>(){}</code></td>
			<td>1234</td>
		</tr>
		<tr>
			<td><code>[]</code></td>
			<td>56</td>
		</tr>
	</tbody>
	<thead>
		<tr>
			<th><em>val</em>(<code>R</code>)=4 문자열</th>
			<th><em>dmap</em>(<code>R</code>)</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><code>({})</code></td>
			<td>1342</td>
		</tr>
		<tr>
			<td><code>()()()()</code></td>
			<td>12121212</td>
		</tr>
		<tr>
			<td><code>()[]</code></td>
			<td>1256</td>
		</tr>
		<tr>
			<td><code>{}{}</code></td>
			<td>3434</td>
		</tr>
	</tbody>
</table>

<p>여러분은 주어진 정수 N에 대하여 <u><em>val</em>(<code>X</code>) = N을 만족하는 올바른 괄호 문자열</u> 중에서 <u><em>dmap</em>(<code>X</code>) 값이 최소</u>인 <code>X</code>를 찾아서 출력해야 한다. 출력 문자열은 공백 없이 괄호 문자로만 구성되어야 한다.</p>

### 입력 

 <p>첫 번째 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 100) 두 번째 줄부터 T+1번째 줄까지 한 줄에 하나씩 정수 N이 주어진다. (5 ≤ N ≤ 1,000)</p>

### 출력 

 <p>각 테스트케이스마다 <em>val</em>(<code>X</code>) = <code>N</code>을 만족하는 올바른 괄호 문자열 <code>X</code> 중에서 <em>dmap</em>(<code>X</code>)가 최소인 문자열을 찾아서 한 줄에 하나씩 공백 없이 출력한다.</p>

