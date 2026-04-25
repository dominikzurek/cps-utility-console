# CPS Utility Console

[![Python](https://img.shields.io/badge/Python-3.10+-blue.svg)](https://www.python.org/)
[![C++](https://img.shields.io/badge/C++-17-orange.svg)](https://isocpp.org/)
[![Python Tests](https://img.shields.io/badge/pytest-17%20passed-brightgreen.svg)](python/tests/)
[![C++ Tests](https://img.shields.io/badge/Google%20Test-21%20passed-brightgreen.svg)](cpp/tests/)

**Industrial-Grade Command Line Utility for Cyber-Physical Systems**

Dual-implementation (Python + C++) portfolio project demonstrating production-ready embedded systems utilities for robotics and industrial automation.

---

## 🎯 Features

| Function | Description | Use Case |
|----------|-------------|----------|
| **Sensor Statistics** | Mean, min, max, standard deviation | Real-time sensor data analysis |
| **Unit Converter** | Temperature (°C/°F/K) & Pressure (bar/kPa/psi) | Multi-standard system integration |
| **Alarm Threshold Checker** | OK / ALARM_LOW / ALARM_HIGH | Industrial safety monitoring |
| **Low-Pass IIR Filter** | y[k] = α·x[k] + (1-α)·y[k-1] | Noise reduction in sensor streams |

---

## 🚀 Quick Start

### Python Implementation
```bash
cd python
pip install -e . --break-system-packages
python3 -m cps_utility_console.main
```

### C++ Implementation
```bash
cd cpp && mkdir build && cd build
cmake .. && make
./cps_utility_console
```

---

## 📁 Repository Structure
```
cps-utility-console/
├── docs/                   # Complete design documentation
│   ├── design.md          # Architecture, pseudocode, flowcharts
│   ├── requirements.md    # Coursera requirements mapping
│   ├── author.md          # Professional profile
│   ├── testing_strategy.md
│   └── demo_outputs.md
│
├── python/                # Python implementation ✅
│   ├── cps_utility_console/
│   │   ├── main.py
│   │   ├── menu.py
│   │   ├── validators.py
│   │   └── functions/     # 4 core modules
│   ├── tests/             # 17 pytest tests
│   └── README.md
│
└── cpp/                   # C++ implementation ✅
    ├── include/           # 6 header files
    ├── src/               # 7 source files
    ├── tests/             # 21 Google Test tests
    └── CMakeLists.txt
```

---

## 🧪 Testing

### Python — 17 tests
```bash
cd python
pytest tests/ -v
# 17 passed in 0.04s
```

| Module | Tests |
|--------|-------|
| Sensor Statistics | 4 |
| Unit Converter | 5 |
| Alarm Checker | 4 |
| Low-Pass Filter | 4 |

### C++ — 21 tests
```bash
cd cpp && mkdir -p build && cd build
cmake .. && make
./cps_tests
# 21 passed
```

| Module | Tests |
|--------|-------|
| Sensor Statistics | 5 |
| Unit Converter | 6 |
| Alarm Checker | 5 |
| Low-Pass Filter | 5 |

---

## 🎓 Academic Context

**Course:** C++ Programming Fundamentals (Coursera)  
**Project Type:** Capstone — demonstrates industry-grade development practices  
**Goal:** Portfolio piece for robotics/AI engineering positions

### Coursera Requirements Met

✅ CLI menu with 4+ functions
✅ Input validation for all interactions
✅ Clear error messages
✅ Clean code organization
✅ Planning/Design phase (docs/)
✅ Python prototype implementation
✅ C++ production implementation
✅ Testing/Refinement phase (pytest + Google Test)

---

## 👤 Author

**Dominik Żurek**

Mechatronics Engineering Student  
**Certifications:** Microsoft Python Development, Siemens TIA Portal, KUKA Robot Programming

- [GitHub](https://github.com/dominikzurek)
- [LinkedIn](https://www.linkedin.com/in/zurekdom)
- Email: zdominik170@gmail.com

---

## 📄 License

MIT License
