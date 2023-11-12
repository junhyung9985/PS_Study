# [Silver II] Sudoku - 30649 

[문제 링크](https://www.acmicpc.net/problem/30649) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 문제 설명

<p>Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9 × 9 grid with digits from 1 to 9 in such a way that the following statements hold:</p>

<ul>
	<li>Each row contains exactly one occurrence of each digit from 1 to 9.</li>
	<li>Each column contains exactly one occurrence of each digit from 1 to 9.</li>
	<li>Each of the nine 3 × 3 subgrids contains exactly one occurrence of each digit from 1 to 9.</li>
</ul>

<p>For a given not yet finished sudoku grid, determine if there is a mistake in it.</p>

<p>Note: It is not necessary to check whether the sudoku grid is solvable.</p>

### 입력 

 <p>The input describes the sudoku grid.</p>

<p>The characters ’|’, ’-’ and ’+’ frame the 3 × 3 subgrids.</p>

<p>The character ’.’ represents an empty cell.</p>

<p>All the other characters in the input will be digits from ’1’ to ’9’.</p>

<p>See the examples for clarification.</p>

### 출력 

 <p>Output the word <code>GRESKA</code> if there is a mistake in the sudoku board. Otherwise, output the word <code>OK</code>.</p>

