<h1 align="center">🔍 Sorting Analyzer</h1>
<p align="center">
  Compare popular sorting algorithms with visual charts, metrics, and real performance data.
</p>

<p align="center">
  <img src="https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%202025-07-13%20184543.png" width="700" alt="Landing Page">
</p>

---

## 🚀 Features

- 🧮 Compare multiple sorting algorithms
- ⏱️ Tracks execution time, comparisons, and swaps
- 📊 Interactive Chart.js graphs
- 🏆 Highlights best-fit algorithm
- 🌙 Light/Dark mode support (toggle)
- ⚙️ Python + C++ backend integration
- 💥 Handles up to 1000+ element arrays

---

## 📦 Tech Stack

| Frontend  | Backend        | Charting      | Language Support |
|-----------|----------------|---------------|------------------|
| HTML/CSS/JS | Python + Flask | Chart.js      | Python & C++     |

---

## 🔧 Setup & Usage


### 1️⃣ Clone the repository
```
git clone https://github.com/yourusername/sorting-analyzer.git
cd sorting-analyzer
```

### 2️⃣ Compile C++ backend
```
g++ sort.cpp -o sort
```
### 3️⃣ Run the Flask bridge
```
python bridge.py
```
### 4️⃣ Open the interface
```
# Use Live Server or open index.html directly in a browser
```

## 🖼️ UI Walkthrough

### 🏠 Home / Landing Page
> Overview of the Sorting Analyzer interface.
![Homepage](https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%20(432).png)

---

### ⌨️ Array Input Bar
> Enter any custom array (comma-separated) to analyze sorting performance.
![Input Bar](https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%20(429).png)

---

### 📊 Sorting Performance Chart
> Visual comparison of algorithms based on execution time, comparisons, and swaps.
![Chart](https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%20(435).png)

---

### 🏆 Best Sorting Algorithm
> Automatically highlights the most efficient algorithm for your input.
![Best Algorithm](https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%20(434).png)

---

### 📋 Algorithm Details Section
> View time complexity, space usage, sorted output, and metrics for any algorithm.
![Algorithm Details](https://github.com/Priya-C-016/Sorting-Analyzer/blob/main/images/Screenshot%20(431).png)

# Porject Structure
sorting-analyzer/
├── sort.cpp         # Sorting logic in C++
├── bridge.py        # Python bridge (calls C++ and returns JSON)
├── index.html       # Main frontend UI
├── output.html      # (optional) output display file
├── result.json      # Output JSON of sorting metrics
├── assets/          # Screenshots for README
└── README.md        # This file

# Contributing
Pull requests and issues are welcome!
If you want to add more algorithms or visualization modes, feel free to fork and PR.

<h3 align="center">✨ Happy Sorting! ✨</h3>
