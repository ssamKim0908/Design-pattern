```mermaid
classDiagram
    direction LR
    class IStrategyCalculator {
        <<interface>>
        +calculate(int a, int b) int
    }
    class Plus {
        +calculate(int a, int b) int
    }
    class Context {
        -IStrategyCalculator strategy
        +setStrategy(IStrategyCalculator s)
    }
    
    IStrategyCalculator <|.. Plus : implements
    Context o-- IStrategyCalculator : strategy
