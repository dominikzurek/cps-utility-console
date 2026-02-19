# Testing Strategy

## Python Implementation

### Test Framework
- **pytest** — Industry-standard Python testing framework
- **Coverage:** 100% functional coverage (all 4 modules tested)

### Test Execution
```bash
cd python
pytest tests/ -v
```

Expected output:
```
17 passed in 0.04s
```

---

## Python Test Breakdown

### Sensor Statistics (4 tests)
- `test_compute_stats_normal` — Normal case with 5 samples
- `test_compute_stats_single_value` — Edge case: single sample
- `test_compute_stats_all_equal` — Edge case: all identical values
- `test_compute_stats_empty_list` — Error case: empty input

### Unit Converter (5 tests)
- `test_temperature_c_to_f` — Temperature conversion C→F
- `test_temperature_k_to_c` — Temperature conversion K→C
- `test_temperature_invalid_unit` — Error case: invalid unit
- `test_pressure_bar_to_kpa` — Pressure conversion bar→kPa
- `test_pressure_negative` — Error case: negative pressure

### Alarm Checker (4 tests)
- `test_alarm_ok` — Normal case: value in range
- `test_alarm_low` — Edge case: value below threshold
- `test_alarm_high` — Edge case: value above threshold
- `test_alarm_invalid_thresholds` — Error case: low ≥ high

### Low-Pass Filter (4 tests)
- `test_filter_alpha_1` — Edge case: α=1.0 (no filtering)
- `test_filter_alpha_0` — Edge case: α=0.0 (maximum smoothing)
- `test_filter_empty_list` — Error case: empty input
- `test_filter_alpha_out_of_range` — Error case: α outside [0,1]

---

## C++ Implementation

### Test Framework
- **Google Test 1.14.0** — Industry-standard C++ testing framework
- **Coverage:** 100% functional coverage (all 4 modules tested)

### Test Execution
```bash
cd cpp && mkdir -p build && cd build
cmake .. && make
./cps_tests
```

Expected output:
```
21 passed
```

---

## C++ Test Breakdown

### Sensor Statistics (5 tests)
- `SensorStats.BasicMean` — Normal case: mean of 5 samples
- `SensorStats.MinMax` — Normal case: min and max values
- `SensorStats.StdDev` — Normal case: standard deviation
- `SensorStats.SingleSample` — Edge case: single sample
- `SensorStats.EmptyThrows` — Error case: empty input

### Unit Converter (6 tests)
- `UnitConverter.CelsiusToFahrenheit` — Temperature C→F
- `UnitConverter.CelsiusToKelvin` — Temperature C→K
- `UnitConverter.InvalidUnitThrows` — Error case: invalid unit
- `UnitConverter.BelowAbsoluteZeroThrows` — Error case: below 0K
- `UnitConverter.BarToKpa` — Pressure BAR→KPA
- `UnitConverter.NegativePressureThrows` — Error case: negative pressure

### Alarm Checker (5 tests)
- `AlarmChecker.OK` — Normal case: value in range
- `AlarmChecker.AlarmLow` — Edge case: value below threshold
- `AlarmChecker.AlarmHigh` — Edge case: value above threshold
- `AlarmChecker.InvalidThresholdThrows` — Error case: low > high
- `AlarmChecker.EqualThresholdsThrow` — Error case: low == high

### Low-Pass Filter (5 tests)
- `LowpassFilter.SameAsInputWhenAlphaOne` — Edge case: α=1.0
- `LowpassFilter.ConstantWhenAlphaZero` — Edge case: α=0.0
- `LowpassFilter.OutputSameLength` — Normal case: output length
- `LowpassFilter.EmptyThrows` — Error case: empty input
- `LowpassFilter.InvalidAlphaThrows` — Error case: α outside [0,1]

---

## Summary

| Implementation | Framework | Tests | Result |
|----------------|-----------|-------|--------|
| Python | pytest | 17 | ✅ passed |
| C++ | Google Test | 21 | ✅ passed |
| **Total** | | **38** | **✅ all passed** |