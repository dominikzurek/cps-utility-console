# Requirements

## Coursera Capstone — Mapping

| Requirement | Implementation |
|-------------|---------------|
| CLI menu with min. 4 functions | 4 functions + Exit in main loop |
| Min. 4 separate utility functions | Sensor Stats, Unit Converter, Alarm Checker, IIR Filter |
| Input validation for all interactions | Centralized `validators.py` / `validators.cpp` |
| Clear error and operation messages | Descriptive messages for every error and result |
| Good code organization + comments | Modular structure, separated I/O from logic |
| Planning/Design phase | `docs/design.md` — pseudocode + ASCII flowcharts |
| Implementation phase | Python prototype → C++ production |
| Testing/Refinement phase | pytest (Python) + basic tests (C++) |

---

## Function Specifications

### F1 — Sensor Statistics
- **Input:** N float values (min. 1)
- **Output:** mean, min, max, stddev
- **Validation:** non-empty, numeric, finite values

### F2 — Unit Converter
- **Temperature:** Celsius ↔ Fahrenheit ↔ Kelvin
- **Pressure:** bar ↔ kPa ↔ psi
- **Validation:** known units, above absolute zero, non-negative pressure

### F3 — Alarm Threshold Checker
- **Input:** value, low threshold, high threshold
- **Output:** `OK` / `ALARM_LOW` / `ALARM_HIGH`
- **Validation:** low < high, all numeric

### F4 — Low-Pass IIR Filter
- **Algorithm:** `y[k] = α·x[k] + (1-α)·y[k-1]`
- **Input:** list of floats, α ∈ [0.0, 1.0]
- **Validation:** non-empty list, alpha in range

---

## Non-Functional Requirements

- Clean separation of I/O from business logic
- Each module independently testable
- Consistent error messages across both implementations
- Python: type hints on all functions
- C++: header/source separation, CMake build