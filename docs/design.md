# CPS Utility Console — Design Document

**Author:** Dominik Żurek  
**Date:** 2026-02-17  
**Version:** 1.0  
**Course:** C++ Programming Fundamentals (Coursera)

---

## 1. System Overview

CPS Utility Console is a command-line tool providing four essential
utilities for Cyber-Physical Systems engineering. Implemented in both
Python (prototype) and C++ (production target).

---

## 2. Architecture
```
┌─────────────────────────────────────┐
│           CLI Entry Point           │
│              main.py                │
└──────────────┬──────────────────────┘
               │
┌──────────────▼──────────────────────┐
│           Menu Router               │
│              menu.py                │
└──┬───────┬──────────┬───────────┬───┘
   │       │          │           │
┌──▼──┐ ┌──▼──┐ ┌─────▼───┐ ┌────▼────┐
│ F1  │ │ F2  │ │   F3    │ │   F4    │
│Stats│ │Conv.│ │ Alarm   │ │ Filter  │
└──┬──┘ └──┬──┘ └─────┬───┘ └────┬────┘
   │       │          │           │
┌──▼───────▼──────────▼───────────▼───┐
│         Input Validator             │
│           validators.py             │
└─────────────────────────────────────┘
```

---

## 3. Main Menu Flow
```
START
  │
  ▼
Display Menu
  │
  ├─ [1] Sensor Statistics
  ├─ [2] Unit Converter
  ├─ [3] Alarm Threshold Checker
  ├─ [4] Low-Pass IIR Filter
  └─ [5] Exit
  │
  ▼
Get User Input
  │
  ├─ Invalid? → Show Error → Back to Menu
  │
  └─ Valid?
       │
       ├─ 1-4 → Run Function → Show Result → Back to Menu
       │
       └─ 5 → Print Goodbye → EXIT
```

---

## 4. Function Specifications

### F1 — Sensor Statistics

**Purpose:** Compute descriptive statistics for a sensor reading array.

**Pseudocode:**
```
FUNCTION sensor_stats(samples: list[float]) -> dict:
    VALIDATE len(samples) >= 1
    VALIDATE all values are finite numbers

    mean   = sum(samples) / len(samples)
    min_v  = min(samples)
    max_v  = max(samples)
    variance = sum((x - mean)^2 for x in samples) / len(samples)
    stddev = sqrt(variance)

    RETURN {mean, min, max, stddev}
```

**Edge Cases:**
- Empty list → raise ValueError
- Single element → stddev = 0.0
- All identical values → stddev = 0.0
- Non-numeric input → raise TypeError

---

### F2 — Unit Converter

**Purpose:** Convert between temperature and pressure units.

**Pseudocode:**
```
FUNCTION convert_temperature(value: float, from: str, to: str) -> float:
    VALIDATE from and to in ["C", "F", "K"]
    VALIDATE if to == "K": result >= 0

    Convert to Celsius first (base unit):
        F → C: (value - 32) * 5/9
        K → C: value - 273.15

    Convert Celsius to target:
        C → F: value * 9/5 + 32
        C → K: value + 273.15

    RETURN result

FUNCTION convert_pressure(value: float, from: str, to: str) -> float:
    VALIDATE from and to in ["bar", "kPa", "psi"]
    VALIDATE value >= 0

    Conversion factors (to bar as base):
        kPa → bar: value / 100
        psi → bar: value / 14.5038

    RETURN result
```

**Edge Cases:**
- Temperature below absolute zero → raise ValueError
- Negative pressure → raise ValueError
- Same unit conversion → return original value
- Unknown unit string → raise ValueError

---

### F3 — Alarm Threshold Checker

**Purpose:** Classify sensor reading against safety thresholds.

**Pseudocode:**
```
FUNCTION check_alarm(value: float,
                     low: float,
                     high: float) -> str:
    VALIDATE low < high
    VALIDATE all inputs are finite numbers

    IF value < low:
        RETURN "ALARM_LOW"
    ELSE IF value > high:
        RETURN "ALARM_HIGH"
    ELSE:
        RETURN "OK"
```

**Edge Cases:**
- low >= high → raise ValueError
- value == low → OK (boundary inclusive)
- value == high → OK (boundary inclusive)
- Non-numeric input → raise TypeError

---

### F4 — Low-Pass IIR Filter

**Purpose:** Smooth noisy sensor signal using 1st-order IIR filter.

**Algorithm:** `y[k] = α·x[k] + (1-α)·y[k-1]`

**Pseudocode:**
```
FUNCTION lowpass_filter(samples: list[float],
                        alpha: float) -> list[float]:
    VALIDATE len(samples) >= 1
    VALIDATE 0.0 <= alpha <= 1.0

    output = []
    y_prev = samples[0]        # Initialize with first sample

    FOR x in samples:
        y = alpha * x + (1 - alpha) * y_prev
        output.append(y)
        y_prev = y

    RETURN output
```

**Edge Cases:**
- alpha = 0.0 → output is constant (all = first sample)
- alpha = 1.0 → no filtering (output = input)
- Empty list → raise ValueError
- alpha outside [0,1] → raise ValueError

---

## 5. Input Validation Strategy

All user inputs pass through `validators.py` before reaching business logic.
```
Raw Input (string)
      │
      ▼
  Strip whitespace
      │
      ▼
  Type check (can convert to float/int?)
      │
      ├─ NO  → ValueError: "Invalid input: expected number"
      │
      └─ YES
           │
           ▼
       Range check (domain-specific)
           │
           ├─ FAIL → ValueError: "Value out of range: ..."
           │
           └─ PASS → Return typed value
```

---

## 6. Test Plan

| Function | Happy Path | Edge Cases | Error Cases |
|----------|-----------|------------|-------------|
| Sensor Stats | N=5 normal values | N=1, all equal | Empty, non-numeric |
| Unit Converter | C→F, bar→kPa | Same unit | Below abs. zero |
| Alarm Checker | value in range | value==boundary | low >= high |
| IIR Filter | alpha=0.5, N=10 | alpha=0, alpha=1 | Empty, alpha>1 |

---

## 7. Module Dependencies
```
main.py
  └── menu.py
        ├── validators.py
        ├── sensor_stats.py
        ├── unit_converter.py
        ├── alarm_checker.py
        └── lowpass_filter.py
```

No circular dependencies. Each module independently testable.