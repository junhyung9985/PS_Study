# [Platinum III] 좀비 떼가 전역 때보다 먼저 오다니 - 19643 

[문제 링크](https://www.acmicpc.net/problem/19643) 

### 성능 요약

메모리: 2020 KB, 시간: 1672 ms

### 분류

백트래킹, 휴리스틱

### 문제 설명

<p>사수 킬로와 부사수 헥토는 탄약고 초소 근무를 하고 있었다. 사주경계 도중, 좀비 떼가 다가오는 것을 발견한 킬로는 서둘러 지휘통제실을 호출했으나 무슨 일인지 연락이 닿지 않는다.</p>

<p>탄약고 초소 길의 길이는 <em>L</em> m이며, 탄약고 초소로부터 <em>i</em> m 떨어진 길 위에 있는 좀비의 체력은 <em>Z<sub>i</sub></em>이다. 체력이 0 이하가 된 좀비는 영구적으로 죽는다.</p>

<p>킬로는 자신이 개인화기 사격으로 좀비 떼를 저지할 테니 헥토에게 탄약을 운반할 것을 지시했다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2c4ee10d-f1e1-4c62-bee2-01f1eb8eae55/-/preview/"></p>

<p>특급전사 킬로의 조준사격은 탄약고 초소 길 위의 좀비가 아무리 멀리 있다 하더라도 맨 앞의 좀비에게 반드시 명중한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/018a8767-a8bd-4897-b5fe-ce179986b002/-/preview/"></p>

<p>또한, 맨 앞의 좀비를 두고 다른 좀비를 조준 사격할 수 없다. 즉, 위와 같은 조준 사격은 할 수 없다.</p>

<p>킬로는 좀비가 1 m 이동하는 동안 한 종류의 개인화기만 한 번 사격할 수 있다.</p>

<p>헥토는 탄약을 운반하느라 바빠서 사격할 수 없다.</p>

<p>사용할 수 있는 개인화기의 종류는 다음과 같다.</p>

<ul>
	<li>돌격소총 (B1)</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/13b24a49-f448-4ba9-96e3-bbe5a598a7c2/-/preview/"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f0b4a821-cc9f-420b-a6ab-84e67062a261/-/preview/"></p>

<p>맨 앞의 좀비의 체력을 <em>B1<sub>power</sub></em> 낮춘다.</p>

<p>남은 살상력이 뒤에 있는 좀비에게 이월되지 않는다. 예를 들어, 3 m에서 적중한 소총탄의 남은 살상력 6이 4 m의 좀비에게 이월되는 일은 없다.</p>

<p>소총탄은 탄약고에 매우 많아 제한 없이 사용할 수 있다.</p>

<ul>
	<li>산탄총 (B2)</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/aab0b50d-7ae8-4a17-ab5e-eca5271e10c4/-/preview/"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c7af4d8b-c517-448a-b68a-e8d08cbbdbf7/-/preview/"></p>

<p>맨 앞의 좀비의 체력을 <em>B2<sub>power</sub></em> 낮춘다.</p>

<p>남은 살상력이 뒤에 있는 좀비에게 이월되지 않는다. 예를 들어, 3 m에서 적중한 산탄의 남은 살상력 6이 4 m의 좀비에게 이월되는 일은 없다.</p>

<p>산탄은 <em>B2<sub>ammo</sub></em>발 있다.</p>

<ul>
	<li>저격 소총 (B3)</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/900b2c6b-7a87-4bc5-9a78-6778092d96a2/-/preview/"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1283fce5-2c63-47f7-a276-6b5b5970095c/-/preview/"></p>

<p>최초 명중한 곳으로부터 <em>B3<sub>length</sub></em> m 내에 모인 좀비의 체력을 각 1 m마다 <em>B3<sub>power</sub></em>씩 낮춘다. </p>

<p>대구경탄의 살상력은 최초 명중한 곳으로부터 <em>B3<sub>length </sub></em>m 내에서만 유효하다. 남은 살상력은 물론이고, 남은 관통 거리가 뒤에 있는 좀비에게 이월되지 않는다. 예를 들어, 6 m에 좀비가 없었으므로 관통 거리 1 m가 남아 8 m의 좀비에게 이월되는 일은 없다.</p>

<p>대구경탄은 <em>B3<sub>ammo</sub></em>발 있다.</p>

<p>킬로와 헥토는 탄약고 초소로부터 1 m 떨어진 길 위의 좀비를 사격 후에도 제압하지 못한다면 사망한다.</p>

<p>과연 킬로와 헥토는 살아남을 수 있을까?</p>

### 입력 

 <p>첫 번째 줄에 탄약고 초소 길의 길이를 나타내는 정수 <em>L</em> (1 ≤ <em>L</em> ≤ 18)이 주어진다. </p>

<p>두 번째 줄에 소총탄의 살상력을 나타내는 정수 <em>B1<sub>power</sub></em> (1 ≤ <em>B1<sub>power</sub></em> ≤ 100)가 주어진다. </p>

<p>세 번째 줄에 산탄의 살상력을 나타내는 정수 <em>B2<sub>power</sub></em> (<em>B1<sub>power</sub></em> < <em>B2<sub>power</sub></em> ≤ 500)와 산탄의 개수 <em>B2<sub>ammo</sub></em> (0 ≤ <em>B2<sub>ammo</sub></em> ≤ 9)가 빈칸을 사이에 두고 주어진다.</p>

<p>네 번째 줄에 대구경탄의 살상력을 나타내는 정수 <em>B3<sub>power</sub></em> (1 ≤ <em>B3<sub>power</sub></em> ≤ 500)와 대구경탄의 유효 관통 거리를 나타내는 정수 <em>B3<sub>length</sub></em> (2 ≤ <em>B3<sub>length</sub></em> ≤ 18), 대구경탄의 개수 <em>B3<sub>ammo</sub></em> (0 ≤ <em>B3<sub>ammo</sub></em> ≤ 9)가 빈칸을 사이에 두고 주어진다.</p>

<p>다섯 번째 줄부터 <em>L</em>개의 줄에 걸쳐서 정수가 하나씩 주어진다. 이 때 <em>i</em> (1 ≤ <em>i</em> ≤ <em>L</em>)번째 정수는 탄약고 초소에서 <em>i</em> m 떨어진 곳의 좀비의 체력 <em>Z<sub>i</sub></em> (0 ≤ <em>Z<sub>i</sub></em> ≤ 500)이다. <em>Z<sub>i</sub></em>가 0인 경우 <em>i</em> m 떨어진 곳에 좀비가 없다는 뜻이다.</p>

### 출력 

 <p>킬로와 헥토가 살아남을 수 있다면 <span style="color:#e74c3c;"><code><span style="background-color:#ecf0f1;">YES</span></code></span>, 살아남을 수 없다면 <span style="color:#e74c3c;"><code><span style="background-color:#ecf0f1;">NO</span></code></span>를 출력한다.</p>

