# CPS Utility Console

**Industrial-Grade Command Line Utility for Cyber-Physical Systems**

Dual-implementation (Python + C++) portfolio project demonstrating
production-ready embedded systems utilities for robotics and industrial automation.

## Features

1. **Sensor Statistics** — mean / min / max / stddev for N samples
2. **Unit Converter** — temperature (°C/°F/K) and pressure (bar/kPa/psi)
3. **Alarm Threshold Checker** — OK / ALARM_LOW / ALARM_HIGH
4. **Low-Pass IIR Filter** — 1st-order: y[k] = α·x[k] + (1-α)·y[k-1]

## Repository Structure
```
cps-utility-console/
├── docs/      # Design documents, pseudocode, requirements
├── python/    # Python implementation with pytest
└── cpp/       # C++ implementation with CMake
```

## Quick Start

### Python
```bash
cd python
pip install -e .
python -m cps_utility_console
```

### C++
```bash
cd cpp && mkdir build && cd build
cmake .. && make
./cps_utility_console
```

## Author

**Dominik Żurek** | [GitHub](https://github.com/dominikzurek)

## Academic Context

Capstone project — *C++ Programming Fundamentals* (Coursera)
Designed to meet industry standards for robotics/AI engineering positions.

## License

MIT License