<img width="1536" height="1024" alt="PracticeZomboid" src="https://github.com/user-attachments/assets/fd6481fb-1a7e-41f1-8f3c-6db24bf9b39f" />

> ## 언리얼 게임 포트폴리오
>- 언리얼 엔진 5.5
>- 블루프린트 기반 프로젝트
>- Project Zomboid 게임을 타겟팅하여 3D로 제작

#### 게임 내용
1. 도심에서 좀비를 피해 생존
2. 좀비 시체 또는 도심의 진열대에서 아이템을 획득
3. 무기 또는 소모형 아이템을 사용 가능

#### 조작법
**Enhanced Input System을 사용하여 조작**
>이동 : WSAD로 이동

![방향키 입력_확대](https://github.com/user-attachments/assets/cd306c57-3e58-4dd8-84ba-564df78f0f5b)

>회전 : 마우스 방향으로 캐릭터 회전

![마우스 입력_확대](https://github.com/user-attachments/assets/4d6b49f3-859b-4854-b60a-f925bcfa67e5)

>공격 : 마우스 왼쪽 클릭 시

1. 맨손 공격

    ![캐릭터 공격(맨손)](https://github.com/user-attachments/assets/c9eaa8fe-d606-4c0a-afa7-3e84e4adc0c4)

2. 근접무기 공격

    ![캐릭터 공격(근접무기)](https://github.com/user-attachments/assets/01fc83e9-ac8a-4950-8a41-58f187db07ac)

3. 총기 공격

    ![캐릭터 공격(권총)](https://github.com/user-attachments/assets/26fec3cf-c04a-4752-b1ce-4d1281af4f4c)
<br>
>무기 상태값에 따른 애니메이션 몽타주 세팅으로 조절<br>
<img width="945" height="459" alt="image" src="https://github.com/user-attachments/assets/7af0936e-445a-423e-917c-07c94d8384f4" />


#### 상호작용
![보관함 상호작용](https://github.com/user-attachments/assets/2da0af60-45e2-4167-ae73-ceaa80045434)
![좀비 시체 상호작용](https://github.com/user-attachments/assets/6e1fef99-e24a-4cac-bec7-435c88abf159)

>상호작용 가능한 액터가 일정 거리 내에 있을 경우 상호작용 가능

마우스 커서 위치의 타겟 물체 획득 후 Post Process에 등록된 머터리얼(아웃라인) 활성

 -> 텍스처 상하좌우 이동하여 마스킹
(Set Render Custom Depth로 활성화)


#### AI Perception
>듣기와 시야 센싱으로 타겟팅<br>
>근접 거리의 경우 거리로 타겟 추가 체크<br>
>Behavior Tree에서 타겟 체크 서비스 등록하여 타겟 검색(Get Known Perceived Actors)<br>
<img width="600" height="400" alt="image" src="https://github.com/user-attachments/assets/0313a221-d321-406e-91a5-182c53774f66" />

