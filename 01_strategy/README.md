```mermaid
classDiagram
    direction TB

    %% [Layer 1: Context && Interface]
    class Context {
        -IStrategyCalculator strategy
        +setStrategy(IStrategyCalculator s)
        +calculate(int a, int b) int
    }

    class IStrategyCalculator {
        <<interface>>
        +calculate(int a, int b) int
    }

    %% [Layer 2: Concrete Strategies]
    class Plus {
        +calculate(int a, int b) int
    }
    class Minus {
        +calculate(int a, int b) int
    }
    class Product {
        +calculate(int a, int b) int
    }

    %% 관계 정의
    Context o-- IStrategyCalculator : 사용(Aggregation)
    IStrategyCalculator <|.. Plus : 구현
    IStrategyCalculator <|.. Minus : 구현
    IStrategyCalculator <|.. Product : 구현
