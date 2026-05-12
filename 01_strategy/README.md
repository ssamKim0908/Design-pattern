```mermaid
graph TD
    %% 레이아웃 방향 설정 (Top-Down)
    
    subgraph "Definition Layer"
        direction LR
        Context[Context] --- Interface{{"<< interface >> <br/> IStrategyCalculator"}}
    end

    subgraph "Implementation Layer"
        direction TB
        Plus[Plus]
        Minus[Minus]
        Product[Product]
    end

    %% 연결 관계
    Interface -.-> Plus
    Interface -.-> Minus
    Interface -.-> Product

    %% 스타일링 (클래스처럼 보이게)
    style Context fill:#f9f,stroke:#333
    style Interface fill:#fff,stroke:#333
    style Plus fill:#eef,stroke:#333
    style Minus fill:#eef,stroke:#333
    style Product fill:#eef,stroke:#333
