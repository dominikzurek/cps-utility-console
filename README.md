# CPS Utility Console

[![Python](https://img.shields.io/badge/Python-3.10+-blue.svg)](https://www.python.org/)
[![C++](https://img.shields.io/badge/C++-17-orange.svg)](https://isocpp.org/)
[![Tests](https://img.shields.io/badge/tests-17%20passed-brightgreen.svg)](python/tests/)

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

### C++ Implementation *(Coming Soon)*

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
├── python/                # Python prototype (COMPLETE ✅)
│   ├── cps_utility_console/
│   │   ├── main.py
│   │   ├── menu.py
│   │   ├── validators.py
│   │   └── functions/     # 4 core modules
│   ├── tests/             # 17 pytest tests
│   └── README.md
│
└── cpp/                   # C++ production target (In Progress)
    ├── include/
    ├── src/
    ├── tests/
    └── CMakeLists.txt
```

---

## 🧪 Testing

Python implementation has **100% functional coverage**:

```bash
cd python
pytest tests/ -v
# 17 passed in 0.04s
```

Test breakdown:
- Sensor Statistics: 4 tests
- Unit Converter: 5 tests
- Alarm Checker: 4 tests
- Low-Pass Filter: 4 tests

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
✅ Implementation phase (Python + C++)  
✅ Testing/Refinement phase (pytest suite)

---

## 👤 Author

**Dominik Żurek**

Electronics Technician @ Grupa Kęty S.A. | Mechatronics Engineering Student  
**Certifications:** Microsoft Python Development, Siemens TIA Portal, KUKA Robot Programming

**Career Goal:** Transition from industrial automation to robotics software engineering

- [GitHub](https://github.com/dominikzurek)
- [LinkedIn](https://www.linkedin.com/in/zurekdom)
- Email: zdominik170@gmail.com

---

## 📄 License

MIT License
