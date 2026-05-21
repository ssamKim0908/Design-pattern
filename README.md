# Design Patterns in C++

『**Head First Design Patterns**』 학습 내용을 **C++** 로 구현한 실습 Repository입니다.

## 개발 환경

| 항목 | 내용 |
| --- | --- |
| OS | WSL2 · Ubuntu 22.04 |
| Language | C++17 |

## AI 활용
- 원칙: 코드를 직접 작성하였습니다.
- AI 활용: AI는 질문, 새로운 기술에 대한 구현 방법을 물어보는 방식으로 활용했습니다. 예) Thread pool 구현 방법

## 디자인 패턴

진행 상태 — ✅ 완료 · 🚧 작성 중 · ⬜ 예정

| # | 패턴 | 분류 | 상태 | 디렉터리 |
| :-: | --- | --- | :-: | --- |
| 01 | **Strategy** | Behavioral | ✅ | [`01_strategy/`](./01_strategy) |
| 02 | **Observer** | Behavioral | ✅ | [`02_observer/`](./02_observer) | 
| 03 | **Decorator** | Structural | ✅ | [`03_decorator/`](./03_decorator) | 
| 04 | **Factory** | Creational | ✅ | [`04_factory/`](./04_factory) | 
| 05 | **Singleton** | Creational | ⬜ | - | 
| 06 | **Command** | Behavioral | ✅ | [`06_command/`](./06_command) |
| 07 | **Adapter & Facade** | Structural | 🚧 | [`07_adapter/`](./07_adapter) |
| 08 | **Template Method** | Behavioral | ⬜ | - |
| 09 | **Iterator & Composite** | Behavioral | ⬜ | - |
| 10 | **State** | Behavioral | ⬜ | - |
| 11 | **Proxy** | Structural | ⬜ | - |
| 12 | **Compound Patterns** | - | ⬜ | - |


## 디렉터리 구조

```
.
├── 00_default/        # 패턴 디렉터리의 기본 템플릿
├── 01_strategy/       # 각 패턴 구현
├── diagram/           # 각 패턴의 UML 클래스 다이어그램 (SVG)
├── common.mk          # 공통 빌드 설정
└── common_header.hpp  # 공통 헤더 (iostream, memory, vector ...)
```
