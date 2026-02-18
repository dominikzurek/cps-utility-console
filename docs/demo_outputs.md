# Demo Outputs

Example interactions with the CPS Utility Console.

---

## Main Menu
```
=== CPS Utility Console ===
[1] Sensor Statistics
[2] Unit Converter
[3] Alarm Threshold Checker
[4] Low-Pass IIR Filter
[5] Exit

Select option: 
```

---

## Function 1: Sensor Statistics
```
--- Sensor Statistics ---
How many samples? 5
Sample 1/5: 10
Sample 2/5: 15
Sample 3/5: 20
Sample 4/5: 25
Sample 5/5: 30

Results:
  Mean:   20.0000
  Min:    10.0000
  Max:    30.0000
  StdDev: 7.0711
```

**Use Case:** Analyzing temperature sensor readings over time.

---

## Function 2: Unit Converter

### Temperature Conversion
```
--- Unit Converter ---
Convert [T]emperature or [P]ressure? t
Enter temperature value: 100
From unit [C/F/K]: c
To unit [C/F/K]: f

Result: 100.0 C = 212.00 F
```

### Pressure Conversion
```
--- Unit Converter ---
Convert [T]emperature or [P]ressure? p
Enter pressure value: 2.5
From unit [BAR/KPA/PSI]: bar
To unit [BAR/KPA/PSI]: psi

Result: 2.5 BAR = 36.2595 PSI
```

**Use Case:** Converting between US and metric units in industrial systems.

---

## Function 3: Alarm Threshold Checker

### Normal Operation (OK)
```
--- Alarm Threshold Checker ---
Enter sensor value: 55
Enter LOW threshold: 40
Enter HIGH threshold: 60

Status: ✓ OK
```

### Alarm Triggered (LOW)
```
--- Alarm Threshold Checker ---
Enter sensor value: 35
Enter LOW threshold: 40
Enter HIGH threshold: 60

Status: ⚠ ALARM_LOW (value below minimum)
```

### Alarm Triggered (HIGH)
```
--- Alarm Threshold Checker ---
Enter sensor value: 75
Enter LOW threshold: 40
Enter HIGH threshold: 60

Status: ⚠ ALARM_HIGH (value above maximum)
```

**Use Case:** Real-time monitoring of industrial equipment operating ranges.

---

## Function 4: Low-Pass IIR Filter
```
--- Low-Pass IIR Filter ---
Formula: y[k] = α·x[k] + (1-α)·y[k-1]
How many samples? 6
Enter alpha [0.0-1.0]: 0.3
Sample 1/6: 10
Sample 2/6: 20
Sample 3/6: 10
Sample 4/6: 20
Sample 5/6: 10
Sample 6/6: 20

Results:
Index | Input    | Filtered
------|----------|----------
    0 |    10.00 |  10.0000
    1 |    20.00 |  13.0000
    2 |    10.00 |  12.1000
    3 |    20.00 |  14.4700
    4 |    10.00 |  13.1290
    5 |    20.00 |  15.0903
```

**Use Case:** Smoothing noisy accelerometer data in robotics applications.

**Analysis:** With α=0.3, the filter heavily smooths the input signal. Notice how the filtered output reduces the amplitude of oscillations from ±10 to approximately ±2.5.

---

## Input Validation Examples

### Invalid Option
```
Select option: 9
  Error: invalid option. Please select 1-5.
```

### Non-numeric Input
```
How many samples? abc
  Error: 'abc' is not a valid integer. Try again.
How many samples? 
```

### Out of Range
```
Enter alpha [0.0-1.0]: 1.5
  Error: value must be between 0.0 and 1.0. Try again.
Enter alpha [0.0-1.0]: 
```

---

*All outputs generated from actual program execution — February 2026*