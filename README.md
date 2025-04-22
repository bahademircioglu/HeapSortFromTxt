# HeapSortFromTxt

C++ Heap Sort from Text File

## Overview

Reads integers from a text file, prompts for `k`, then sorts and displays the top `k` numbers using heap sort.

## Features

- Reads data from plain text (`numbers_example.txt`)  
- Implements heap sort algorithm  
- Prompts user for the number of results (`k`)  

## Prerequisites

- C++ compiler (GCC, Clang, MSVC)  
- C++11 support

## Installation

```bash
git clone https://github.com/bahademircioglu/HeapSortFromTxt.git
cd HeapSortFromTxt
```

## Build & Run

```bash
g++ Source.cpp -o heapsort
./heapsort numbers_example.txt
```

Follow prompts to enter `k`.

## Project Structure

```
HeapSortFromTxt/
├── Source.cpp
├── numbers_example.txt
├── LICENSE (GPL-3.0)
└── README.md
```

## Contributing

Please fork and send pull requests for improvements.

## License

GPL‑3.0 License.
