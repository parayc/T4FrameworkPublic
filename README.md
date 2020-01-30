# T4Framework : MMO Action RPG Framework for UE4
``` 
Powerful toolset and Flexible layer solution
``` 

- Information
  - Supported Engine Versions
    - 4.24 (Binary Build : 4.24.2)
  - Website
    - <https://tech4labs.com/>
  - YouTube
    - <https://www.youtube.com/channel/UCoVNwMxu9CUzc92zGYN4l6A>
  - Twitter
    - <https://twitter.com/Tech4Labs>
  - Sources Repositories (Private)
    - <https://github.com/Tech4Labs/T4Framework>
- Current Milestone
  - M5
    - 2020.01.06 ~ 2020.03.13
    - Goal
      - 게임 콘텐츠 제작을 위한 기반 기능 및 툴 개발
        - 캐릭터(Entity) 제작 및 스킬(Conti) 툴 개선 (상시)
        - 게임 오브젝트 Spawn, Combat/Interaction AI 등의 게임 디자인 관련 컨텐츠 툴 개발
          - NPC, Monster, FieldObject, DropItem
      - 테크 데모 만들기
  - Update Notes (Warning: Development Version)
    - **[2020.01.30] [M5] Copying //Private to //Deploy (private commit 49e91cd)**
	  - #117 [기능추가] Aiming 스킬 타겟 위치에 Indicator 및 시전자에게 사용될 Aiming Conti 출력 처리 추가
	  - #117 [기능추가] Rehearsal Editor, Viewport 내 Playback Speed (TimeScale) 기능 추가
	  - #114 [버그수정] Conti Editor, NPC AI Test 에서 Game Die 로직이 동작하지 않도록 수정
	  - #111 [버그수정] Entity Editor, AnimSet 의 AnimLayer 에 AnimSequence Asset 설정이 안되던 문제 수정
    - **[2020.01.29] [M5] Copying //Private to //Deploy (private commit bf29ab6)**
	  - #116 [버그수정] 연속기를 사용하는 무기(Sword, Magic)의 설정과 다른 스킬이 사용되던 문제 수정
	  - #111 [기능추가] Entity Editor, AnimSet Details 에서 AnimSequence 의 AnimNotify 를 표시하도록 추가
	  - #114 [내부수정] 전투 테스트용 GridLevel 추가
	  - #116 [버그수정] PIE 에서 카메라 회전시 마우스 위치 및 움직임이 튀는 문제 수정
    - **[2020.01.28] [M5] Copying //Private to //Deploy (private commit f38f9a3)**
	  - #116 [기능개선] Editor Constant NameTable 의 Description 을 한국어(KOR)에서 영어(EN)로 변경
	  - #111 [버그수정] Entity Editor, Character AnimSection 이름 변경이 되지 않던 문제 수정
	  - #111 [버그수정] Entity Editor, Weapon AnimSection 추가, 변경이 되지 않던 문제 수정
    - **[2020.01.26] [M5] Copying //Private to //Deploy (private commit 8491c81)**
	  - #111 [버그수정] 캐릭터 로딩 시점에 장착한 무기가 화면에 보이지 않던 문제 수정
	  - #116 [기능추가] Left Shift 키를 이용해 CombatMode (SubStance) 전환을 할 수 있도록 추가
	  - #116 [버그수정] Dedicated Server 에서 무기 교체가 정상적으로 보이지 않던 문제 수정
    - **[2020.01.25] [M5] Copying //Private to //Deploy (private commit e33b38b)**
	  - #111 [버그수정] 캐릭터 무기 교체시 랜덤하게 이전 무기가 계속 출력되는 문제 수정 (Editor & PIE)
    - **[2020.01.24] [M5] Copying //Private to //Deploy (private commit 2fa9458)**
	  - #111 [버그수정] Entity Editor, AnimSet AnimLayer Tab 의 선택 표시 오류 수정
	  - #111 [기능추가] Stance 전환 및 Weapon 교체 연출 기능 추가
    - **[2020.01.23] [M5] Copying //Private to //Deploy (private commit b3d701c)**
	  - #111 [기능추가] Entity Editor, AnimSet 별 테스트 무기를 장착, 저장할 수 있도록 기능 추가
	  - #111 [기능개선] Entity Editor, AnimSet AnimLayer 편집 UI 를 MultiBoxBuiilder 로 변경
    - **[2020.01.22] [M5] Copying //Private to //Deploy (private commit c57a561)**
	  - #111 [기능추가] 캐릭터 Stance/SubStance 전환 연출(애니메이션) 처리 추가
	  - #111 [기능추가] Entity Editor 에 'Toggle Simulation' 을 통한 InGame 테스트 환경 지원
	  - #115 [버그수정] Rehearsal Editor 오픈시 간헐적으로 발생하는 FSceneView ViewMatrices 오류 수정
    - **[2020.01.20] [M5] Copying //Private to //Deploy (private commit a94b1d6)**
	  - #111 [버그수정] Entity AnimSet 업데이트 후 특정 Stance 애니메이션 출력 이상 문제 수정
	  - #113 [버그수정] Normal Attack 1회 사용후 이동 불가 문제 수정
	  - #113 [버그수정] PIE(Game) 에서 Aiming 스킬 사용시 마우스 움직임이 끊어지던 문제 수정
    - **[2020.01.19] [M5] Copying //Private to //Deploy (private commit 6f0cc58)**
	  - #115 [버그수정] Dedicated Server & Multiple PIE 사용시 발생하는 크래시 수정
	  - #113 [버그수정] PIE(Game) 에서 Aiming Attack 이 정상적으로 동작하지 않던 문제 수정
	  - #114 [버그수정] Rehearsal Editor 툴바의 DespawnAll 실행시 발생하는 크래시 수정
    - **[2020.01.18] [M5] Copying //Private to //Deploy (private commit 10a380f)**
	  - #113 [기능추가] 공격 타겟팅시 Outline 표시 및 마우스 커서 변경
	  - #113 [기능개선] Miss 판정 Projectile 이동에 장애물(캐릭터) 발생시 굴절 처리 추가
	  - #115 [기능추가] PostProcess Outline 효과 및 MPC(Material Parameter Collection) 추가 (Example)
    - **[2020.01.16] [M5] Copying //Private to //Deploy (private commit dce4150)**
	  - #113 [기능추가] GameSkillData bAiming 과 bLockOn 프로퍼티 기반 캐릭터 Aiming 동작 추가 (C/S)
    - **[2020.01.14] [M5] Copying //Private to //Deploy (private commit 238c643)**
	  - #112 [기능개선] Conti Editor, 툴바에 Sandbag NPC Spawn 기능 추가
	  - #112 [기능추가] Projectile Collision 설정 및 Arrow Hit Attached 기능 추가
    - **[2020.01.12] [M5] Copying //Private to //Deploy (private commit a98a8f2)**
	  - #110 [기능개선] Weapon Entity 의 Stance 설정이 무기 교체시 자동으로 반영되도록 기능 추가
	  - #109 [버그수정] Combat SubStance 상태에서의 LockOn 이동 시작 애니메이션이 튀는 문제 개선
    - **[2020.01.10] [M5] Copying //Private to //Deploy (private commit 912b676)**
	  - #110 [기능추가] Weapon Entity 에 Particle System 을 사용할 수 있도록 추가
    - **[2020.01.08] [M5] Copying //Private to //Deploy (private commit 05fbea7)**
	  - #109 [기능추가] SubStance 별 MoveSpeed 를 설정할 수 있도록 추가
	  - #109 [버그수정] NPC 이동 애니메이션이 비정상적으로 출력되던 문제 수정
	  - #108 [기능추가] Weapon GameData 에 N개의 Weapon Entity Asset 을 지정할 수 있도록 추가
	  - #106 [기능추가] NPC Archer 동작 및 에셋 추가
    - **[2020.01.07] [M5] Copying //Private to //Deploy (private commit 5b7ffc9)**
	  - #108 [기능추가] 장착 무기에 대한 Fade In/Out 처리 추가 (Material Opacity)
	  - #106 [버그수정] Conti Editor, Preview Player 에 대한 Stance 리스트 출력 오류 수정
    - **[2020.01.06] [M5] Copying //Private to //Deploy (private commit 201c20d)**
	  - #107 [기능추가] Entity Editor, 장착 무기에 대한 애니메이션 시스템 구현
	  - #107 [버그수정] Conti Editor, PlayerSettingEditor 의 GameData 출력이 정상적이지 않던 문제 수정
    - **[2019.12.26] [M5] Copying //Private to //Deploy (private commit 593b858)**
	  - #106 [기능추가] Skeletal Mesh Item Equip 기능 추가 (Bow 대응)
	  - #106 [기능추가] 전투/비전투 애니메이션 처리를 위한 SubStance 기능 추가 및 툴 테스트 기능 추가
	  - #106 [버그수정] Entity Editor, AnimSection/BlendSpace Name 의 DropList Item 변경 오류 수정
    - **[2019.12.25] [M5] Copying //Private to //Deploy (private commit 9f13885)**
	  - #106 [기능추가] Entity Editor, AnimSet Detail Panel 에 편집 캐릭터의 Stance 변경 기능 추가
	  - #106 [버그수정] Entity Editor, BlendSpace Item 삭제시 발생하는 Debug assert 수정
	  - #106 [버그수정] Entity Editor, Stance 변경 시 AnimSet Detail Panel 이 업데이트되지 않던 문제 수정
	  - #105 [버그수정] AT4GameObject 의 DebugString 에 쓰레기 값이 저장되던 문제 수정 
    - **[2019.12.24] [M5] Copying //Private to //Deploy (private commit 2781351)**
	  - #106 [기능개선] Entity Editor, DropItem Mesh 수정 즉시 반영 및 Offset/Rotation 프로퍼티 추가
	  - #105 [기능개선] Entity Editor, Preview Viewport 에 카메라 스피드, 썸네일 업데이트 메뉴 추가
	  - #105 [버그수정] Console 커맨드 중복 등록 Warning 제거
	  - #105 [버그수정] Entity Editor, Stance 변경 후 AnimSet Detail Panel 비정상 출력 문제 수정
	  - #105 [버그수정] Entity Editor, Fullbody Skeletal Mesh 변경이 즉시 반영되지 않던 문제 수정
	  - #105 [버그수정] Entity Editor, Composite Part 추가시 잘못된 MsgBox 출력 문제 수정
	  - #105 [내부수정] 불필요한 로직, 에셋 관련 Warning 일괄 수정
    - **[2019.12.23] [M5] Copying //Private to //Deploy (private commit 4018e53)**
	  - #105 [내부수정] T4Framework.uproject 에서 T4FrameworkExample.uproject 로 변경
	  - #105 [내부수정] 로그 정보 및 출력 보강 ('소스명 (라인): 함수명' 으로 통일)
      - #105 [내부수정] T4Asset 에 대한 TypeAction Name 및 Color 설정 추가
      - #105 [내부수정] 테스트용 에셋을 Examples 폴더로 이동 및 불필요한 에셋 삭제
    - **[2019.12.22] [M5] Copying //Private to //Deploy (private commit 13d9543)**
      - #105 [내부수정] 사용하지 않는 테스트용 에셋 삭제
      - #105 [내부수정] 배포 가능한 T4Framework 패키지 만들기 (/Game/Tech4Labs => T4Framework)
  - Older Update Notes
    - 2019.10 ~ 2019.12 : [`UpdateNotes_2019_10-2019_12.md`](./UpdateNotes_2019_10-2019_12.md)
    - 2019.07 ~ 2019.09 : [`UpdateNotes_2019_07-2019_09.md`](./UpdateNotes_2019_07-2019_09.md)
- Contact
  - <niceofer@hotmail.com> (Twitter: @Tech4Labs)
