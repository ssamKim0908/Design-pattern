classDiagram
    %% 1. 인터페이스 및 클래스 정의
    class IStrategyCalculator {
        <<interface>>
        +calculate(a: int, b: int) int
    }

    class Plus {
        +calculate(a: int, b: int) int
    }

    class Minus {
        +calculate(a: int, b: int) int
    }

    class Product {
        +calculate(a: int, b: int) int
    }

    class Context {
        -calculation: IStrategyCalculator
        +setCalculation(c: IStrategyCalculator) void
        +calculate(a: int, b: int) int
    }

    %% 2. 관계 정의 (화살표 문법)
    
    %% 구현 (Implements) : 점선 + 빈 화살표
    IStrategyCalculator <|.. Plus : implements
    IStrategyCalculator <|.. Minus : implements
    IStrategyCalculator <|.. Product : implements

    %% 집합 (Aggregation) : 빈 마름모 + 실선
    Context o-- IStrategyCalculator : strategy
