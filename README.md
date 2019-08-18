# T4Framework : MMO Action RPG Framework for UE4
``` 
Powerful toolset and Flexible layer solution
``` 

- Features
  - UE4 지원 버전
    - 4.22
  - 기능 소개
    - <https://tech4labs.com/T4Framework_Features/>
  - 문의
    - SoonBo Noh (<niceofer@hotmail.com>, @Tech4Labs)
- Repositories
  - UE4 Marketplace
    - 준비중...(2019.10)
  - GitHub 공개 저장소
    - <https://github.com/Tech4Labs/T4FrameworkPublic>
  - GitHub 비공개 저장소 (Professional License)
    - <https://github.com/Tech4Labs/T4Framework>
- Warning
  - 2019.10 월 정식 버전 배포 예정입니다. 개발 버전이므로 테스트 용도로 만 사용해주시기 바랍니다.
- Release Notes
  - **[2019.08.18] [M3] Copying //Private to //Deploy (private commit dfb9608)**
    - #68 [기능추가] Conti Editor 의 ToolBar 메뉴에 Action Playback 컨트롤 메뉴 노출 
	- #68 [기능개선] 현재 스폰된 C/S 오브젝트를 모두 despawn 할 수 있는 기능 추가
  - **[2019.08.15] [M3] Copying //Private to //Deploy (private commit c1858ff)**
    - #68 [기능추가] 각종 디버깅 메세지 출력을 위한 Gameplay HUD 처리 추가 
	- #68 [기능개선] Action Playback 플레이/녹화 시 HUD 에 파일명 및 시간 표시 추가
  - **[2019.08.14] [M3] Copying //Private to //Deploy (private commit c5406f6)**
    - #68 [버그수정] LevelEditor Mode 에서 캐릭터 스폰 후 강제 종료 시 발생하는 크래시 수정
	- #68 [기능추가] Action playback (Replay) 기능 추가 (1차 완료 상태로 Console command 로 동작)
  - **[2019.08.11] [M3] Copying //Private to //Deploy (private commit 7329c65)**
    - #65 [버그수정] Conti Editor 에서 Action Copy&Paste 시 발생하는 크래시 수정
  - **[2019.08.10] [M3] Copying //Private to //Deploy (private commit f5d51c2)**
    - #67 [버그수정] Conti Editor 에서 Test Entity 변경이 즉시 반영되지 않는 문제 수정
    - #66 [버그수정] Content Table 업데이트가 즉시 반영되지 않는 문제 수정
  - **[2019.08.09] [M3] Copying //Private to //Deploy (private commit 1c4953d)**
    - #63 [버그수정] NPC AI 의 방향 전환이 정상적으로 동작하지 않던 문제 수정
    - #63 [버그수정] Dedicated Server 에서 Projectile 이 동작하지 않던 문제 및 크래시 수정
  - **[2019.08.08] [M3] Copying //Private to //Deploy (private commit 4738783)**
    - #63 [기능추가] Projectile Action 추가 (Ranged attack)
  - **[2019.08.06] [M3] Copying //Private to //Deploy (private commit 8b08316)**
    - #62 [리팩토링] T4Engine 플러그인 내 포멧 관련 코드를 T4Asset 모듈로 이전
  - **[2019.07.31] [M2] Copying //Private to //Deploy (private commit 11c94d9)**
    - #60 [기능추가] 리허설 콘티 에디터 기능 개선 및 전투 테스트 기능 추가
  - **[2019.07.27] [M2] Copying //Private to //Deploy (private commit 99469fd)**
    - #61 [기능추가] 프로젝트 또는 T4Gameplay 모듈의 GameInstance/Mode 를 선택해서 플레이 할 수 있도록 기능 추가 (레벨 에디터 => Play => 'T4Gameplay Enabled' )
  - **[2019.07.26] [M2] Copying //Private to //Deploy (private commit fc55aa5)**
    - #59 [기능개선] 리허설 툴 실행중 PIE 진입시 뷰포트 멈춤 현상 대응
    - #54 [버그수정] Decal Action 사용중 강제종료(툴 & PIE)시 발생하는 "Array has changed during ranged-for iteration!" ensure 수정
