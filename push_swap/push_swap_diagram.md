graph TD
    A[Start] --> B[Initialize variables]
    B --> C[Create sorted_index_arr]
    C --> D[Find sorted_f_h_index and sorted_s_h_index]
    D --> E{While loop: i < argc/2 and not in good order}
    E --> F{Check x vs sorted_f_h_index i }
    F -->|x == sorted_f_h_index i | G[Push to stack B]
    F -->|x < sorted_f_h_index i | H[Inner while loop]
    F -->|x > sorted_f_h_index i | I[Reverse rotate stack A]
    G --> J[Decrease indexes]
    H --> K{Check conditions}
    K -->|Condition met| L[Push or swap]
    K -->|Condition not met| M[Rotate stack A]
    L --> N[Update indexes and counters]
    M --> O[Update x]
    I --> P[Update x]
    N --> Q[Manage buffer]
    O --> Q
    P --> R[Push to stack B]
    R --> S[Decrease indexes]
    Q --> E
    S --> E
    E -->|Loop ends| T[End]
