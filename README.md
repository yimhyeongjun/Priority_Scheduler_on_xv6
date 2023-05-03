# Priority_Scheduler_on_xv6

## 개요
xv6 운영체제 상에 새로운 스케줄러를 구현하는 프로젝트이다.
새로운 스케줄러는 프로세스 실행 흐름에서 새로 생성된 프로세스가 우선적으로 스케줄링 될 수 있도록 가중치를 부여하는 스케줄러이다.
<br><br>

## Priority Scheduler Rule
>1. 각 process에는 priority와 weight를 부여한다.
>2. 스케줄러가 호출될 때마다 priority는 갱신된다.
>3. priority 갱신은 다음 규칙을 따른다. new_priority = old_priority + (time_slice/weight)
>4. weight는 프로세스 생성 순서에 따라 1부터 차례로 증가한다.
>5. ptable에는 RUNNABLE한 프로세스 중 가장 낮은 priority를 저장하고 있는 멤버 변수가 존재한다.
>6. 스케줄러는 priority가 가장 낮은 프로세스부터 수행한다.

<br><br>

## Priority Scheduler Implementation
![image](https://user-images.githubusercontent.com/64363668/235943522-bbd0dab0-3dda-4cdb-884d-5353b60f19c6.jpeg)
