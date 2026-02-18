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

## Test Breakdown

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

## Test Categories

| Category | Count | Purpose |
|----------|-------|---------|
| Happy Path | 7 | Normal operation with valid inputs |
| Edge Cases | 6 | Boundary conditions (single value, α=0/1) |
| Error Cases | 4 | Invalid inputs that should raise exceptions |

---

## C++ Implementation *(Planned)*

Basic smoke tests using Google Test or Catch2:
- Verify each function compiles and runs
- Test one happy path per function
- Test one error case per function

Estimated: ~8 tests for C++ (reduced scope vs Python)