# [Platinum II] A Star not a Tree? - 4360 

[문제 링크](https://www.acmicpc.net/problem/4360) 

### 성능 요약

메모리: 2040 KB, 시간: 4 ms

### 분류

경사 하강법

### 문제 설명

<p>Luke wants to upgrade his home computer network from 10mbs to 100mbs. His existing network uses 10base2 (coaxial) cables that allow you to connect any number of computers together in a linear arrangement. Luke is particulary proud that he solved a nasty NP-complete problem in order to minimize the total cable length.</p>

<p>Unfortunately, Luke cannot use his existing cabling. The 100mbs system uses 100baseT (twisted pair) cables. Each 100baseT cable connects only two devices: either two network cards or a network card and a hub. (A hub is an electronic device that interconnects several cables.) Luke has a choice: He can buy 2N-2 network cards and connect his N computers together by inserting one or more cards into each computer and connecting them all together. Or he can buy N network cards and a hub and connect each of his N computers to the hub. The first approach would require that Luke configure his operating system to forward network traffic. However, with the installation of Winux 2007.2, Luke discovered that network forwarding no longer worked. He couldn't figure out how to re-enable forwarding, and he had never heard of Prim or Kruskal, so he settled on the second approach: N network cards and a hub.</p>

<p>Luke lives in a loft and so is prepared to run the cables and place the hub anywhere. But he won't move his computers. He wants to minimize the total length of cable he must buy.</p>

### 입력 

 <p>The first line of input contains a positive integer N <= 100, the number of computers. N lines follow; each gives the (x,y) coordinates (in mm.) of a computer within the room. All coordinates are integers between 0 and 10,000.</p>

### 출력 

 <p>Output consists of one number, the total length of the cable segments, rounded to the nearest mm.</p>

