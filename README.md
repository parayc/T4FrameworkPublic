# T4Framework : MMO Action RPG Framework for UE4
``` 
Powerful toolset and Flexible layer solution
``` 

- Supported Engine Versions
  - 4.23
  - Platforms : Win64 only (Binary version)
- Website
  - <https://tech4labs.com/>
  - YouTube
    - <https://www.youtube.com/channel/UCoVNwMxu9CUzc92zGYN4l6A>
  - Twitter
    - <https://twitter.com/Tech4Labs>
  - Sources Repositories (Private)
    - <https://github.com/Tech4Labs/T4Framework>
- Update Notes (Warning: Development Version!!)
  - **[2019.11.25] [M4] Copying //Private to //Deploy (private commit 697c44a)**
	- #99 [버그수정] Rehearsal Conti Editor, Track Section Range 및 Lifecycle 변경 오류 수정
  - **[2019.11.24] [M4] Copying //Private to //Deploy (private commit be5711c)**
	- #97 [기능추가] Environment 블랜딩에 BP_Sky_Sphere 추가
	- #94 [기능추가] Movable Environment Zone 기능 추가
  - **[2019.11.19] [M4] Copying //Private to //Deploy (private commit 17d7a5d)**
	- #95 [기능개선] Rehearsal Editor, Detail Panel 의 DropList ItemData Update UX 개선
  - **[2019.11.17] [M4] Copying //Private to //Deploy (private commit 03ffd2a)**
	- #96 [버그수정] Rehearsal Editor, Preview Viewport 에서의 Player 카메라 충돌 오류 수정 (Bugfix)
  - **[2019.11.16] [M4] Copying //Private to //Deploy (private commit 1767792)**
	- #91 [버그수정] Rehearsal World Editor, 사이즈가 큰 단일 월드 오픈시 발생하는 크래시 수정
	- #87 [버그수정] MapEntityAsset 생성한 후 Rehearsal Entity Editor 를 열 경우 발생하는 크래시 수정
  - **[2019.11.16] [M4] Copying //Private to //Deploy (private commit 5e026c4)**
	- #93 [기능추가] Environment Interpolation 구현 및 Time Lapse 테스트 환경 만들기
  - **[2019.11.12] [M4] Copying //Private to //Deploy (private commit 4716c47)**
	- #92 [기능추가] Environment 설정을 위한 Volume 및 World Editor 편집 기능 추가
	- #90 [기능추가] RehearsalWorld Editor, TOD(Time of day) 기반 시스템 구현
  - **[2019.11.07] [M4] Copying //Private to //Deploy (private commit 328dbe8)**
	- #90 [기능추가] Rehearsal World Editor, PreviewDetail 에서 Prop 더블클릭시 WorldMap 포커스 이동 처리 추가
	- #90 [기능개선] Rehearsal World Editor, MapEntityAsset 교체시 WorldMap 업데이트
	- #83 [버그수정] Rehearsal World Editor 창을 두개 열 경우 발생하던 크래시 수정
  - **[2019.11.06] [M4] Copying //Private to //Deploy (private commit e84d31e)**
	- #90 [내부수정] UE4 4.22.3 => 4.23.1 Migration
  - **[2019.11.05] [M4] Copying //Private to //Deploy (private commit e439e28)**
	- #91 [기능추가] Rehearsal World Editor, World Composition 을 사용하지 않는 월드의 World Grid 처리 추가
  - **[2019.11.04] [M4] Copying //Private to //Deploy (private commit 6a736cb)**
	- #87 [기능추가] Rehearsal Conti Editor 에서 지정한 월드가 자동으로 로딩 되도록 기능 추가
  - **[2019.11.02] [M4] Copying //Private to //Deploy (private commit 9594d94)**
	- #87 [기능추가] 게임(PIE) 또는 Editor 에서의 World 이동 처리 개선 및 Playback 에서의 World Travel 동작 추가
  - **[2019.10.30] [M4] Copying //Private to //Deploy (private commit 3ebd5c1)**
	- #88 [버그수정] 모든 에디터의 리스트뷰 프로퍼티 선택시 에셋이 편집 상태로 변경되는 문제 수정
  - **[2019.10.25] [M4] Copying //Private to //Deploy (private commit 0d6e340)**
	- #84 [기능추가] Rehearsal World Editor, SubLevel Thumbnail 생성 및 저장 기능 개선 (T4WorldAsset)
  - **[2019.10.25] [M4] Copying //Private to //Deploy (private commit 13ffc01)**
	- #85 [버그수정] Rehearsal World Editor, SubLevel 변경시 간헐적으로 발생하는 크래시 수정
  - **[2019.10.24] [M4] Copying //Private to //Deploy (private commit 7a21ab2)**
	- #85 [기능개선] Rehearsal World Editor, SubLevel Detail View 내 SearchBox 및 선택한 Actor 로 포커스 이동 추가
  - **[2019.10.23] [M4] Copying //Private to //Deploy (private commit dec3cb2)**
  	- #86 [기능개선] Rehearsal World Editor, Level Streaming Layer 설정 및 테스트 환경 추가
	- #85 [기능개선] Rehearsal World Editor, PreviewWorld 에 로드된 SubLevel 상세 정보 업데이트 개선
  - **[2019.10.17] [M4] Copying //Private to //Deploy (private commit 27630ff)**
	- #85 [기능개선] Rehearsal World Editor, PreviewWorld 에서 선택된 SubLevel 에 대한 정보 업데이트 처리 추가
	- #83 [기능개선] Rehearsal World Editor, PreviewWorld 에 캐릭터 스폰 기능 추가
  - **[2019.10.17] [M4] Copying //Private to //Deploy (private commit b065148)**
	- #83 [버그수정] Rehearsal World Editor 에서 SubLevel Selection 반복 후 Refresh World 시 발생하는 크래시 수정
  - **[2019.10.16] [M4] Copying //Private to //Deploy (private commit fadad10)**
	- #83 [버그수정] Rehearsal World Editor 기본 레이아웃 추가 (World Composition)
  - **[2019.10.13] [M4] Copying //Private to //Deploy (private commit dae06a9)**
	- #79 [버그수정] Rehearsal Entity Editor 의 Map Level Asset 변경시 발생하는 무한루핑 문제 수정
  - **[2019.10.11] [M4] Copying //Private to //Deploy (private commit 4ea8d38)**
	- #78 [버그수정] 캐릭터의 Costume 교체가 적용되지 않던 문제 수정
	- #78 [버그수정] Costume Entity 에 적용된 Override Material 이 적용되지 않던 문제 수정
  - **[2019.10.10] [M4] Copying //Private to //Deploy (private commit 01e7921)**
	- #79 [기능개선] Rehearsal Editor 뷰포트에 World 로딩 처리 추가 (캐릭터 스폰, 전투 테스트, 버그 수정)
  - **[2019.10.08] [M4] Copying //Private to //Deploy (private commit d540ab9)**
	- #79 [기능추가] Rehearsal Editor 뷰포트에 World 로딩 처리 추가
  - **Older Update Notes**
    - 2019.07 ~ 2019.09 : ReleaseNotes.md
- Contact
  - <info@tech4labs.com> (Twitter: @Tech4Labs)
