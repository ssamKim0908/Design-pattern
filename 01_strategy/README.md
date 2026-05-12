```mermaid
classDiagram
    direction LR

    %% Layer 1: Context & Interface
    class Context {
        -IStrategyCalculator strategy
        +setStrategy(s: IStrategyCalculator)
    }
    class IStrategyCalculator {
        <<interface>>
        +calculate(a, b) int
    }

    %% Layer 2: Concrete Classes
    class Plus
    class Minus
    class Product

    %% Relationships
    Context o-- IStrategyCalculator : strategy
    
    IStrategyCalculator <|.. Plus
    IStrategyCalculator <|.. Minus
    IStrategyCalculator <|.. Product
