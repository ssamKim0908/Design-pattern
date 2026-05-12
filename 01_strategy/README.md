```mermaid
classDiagram
    direction LR

    %% 1. 정의 (Context와 Interface를 먼저 써서 왼쪽에 배치 유도)
    class Context {
        -IStrategyCalculator strategy
        +setStrategy(IStrategyCalculator s)
        +calculate(int a, int b) : int
    }

    class IStrategyCalculator {
        <<interface>>
        +calculate(int a, int b) : int
    }

    %% 2. 구현체들
    class Plus { +calculate(int a, int b) : int }
    class Minus { +calculate(int a, int b) : int }
    class Product { +calculate(int a, int b) : int }

    %% 3. 관계 설정
    %% Context와 Interface가 수평으로 연결됩니다.
    Context o-- IStrategyCalculator : 사용(Aggregation)

    %% Interface에서 구현체들로 화살표가 뻗어나갑니다.
    IStrategyCalculator <|.. Plus : 구현
    IStrategyCalculator <|.. Minus : 구현
    IStrategyCalculator <|.. Product : 구현
