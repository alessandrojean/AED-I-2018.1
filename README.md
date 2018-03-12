# AED-I-2018.1
![Year](https://img.shields.io/badge/year-2018.1-blue.svg?style=flat-square) ![id](https://img.shields.io/badge/id-MCTA001--13-yellowgreen.svg?style=flat-square) ![tpi](https://img.shields.io/badge/T--P--I-2--2--4-lightgrey.svg?style=flat-square) ![Last class](https://img.shields.io/badge/last_class-2018.03.12-green.svg?style=flat-square) ![Language](https://img.shields.io/badge/language-C-yellow.svg?style=flat-square) ![IDE](https://img.shields.io/badge/IDE-VSCode-orange.svg?style=flat-square)

Algorithms written in the classes of Algorithms and Data Structures I (Algoritmos e Estruturas de Dados I) at Federal University of ABC (UFABC).

## Classes

- **19/02/2018** *(Laboratory)*: [Subject introduction](classes/laboratory/2018.02.19/part-1/). [Introduction to the C
programming language](classes/laboratory/2018.02.19/part-2/).
- **21/02/2018** *(Theory)*: [Dynamic arrays](classes/theory/2018.02.21/).
- **26/02/2018** *(Theory)*: [Linked lists](classes/theory/2018.02.26/).
- **28/02/2018** *(Theory)*: [Basic notions about Algorithmic Complexity](classes/theory/2018.02.28/).
- **05/03/2018** *(Laboratory)*: [Linked list practical exercise](practical/2018.03.05/).
- **07/03/2018** *(Theory)*: [Basic notions about Algorithmic Complexity *(continuation)*](classes/theory/2018.03.07).
- **12/03/2018** *(Laboratory)*: [Stacks and Queues](classes/laboratory/2018.03.12/). [Stack practical exercise](practical/2018.03.12/).

## Build instructions

Use the following commands to compile any `.c` file in this repository.

```bash
# Assuming you have the GNU C Compiler in
# your PATH, but can be MinGW or the Visual
# Studio compiler too if you are under an 
# Windows environment.

# Compiles the file in the bin folder.
gcc file.c -o bin/file
# If the compiler complain about the folder,
# create it using the command below, and
# run the command above again.
mkdir bin
# Run the program.
./bin/file
```

If you use [Visual Studio Code](https://code.visualstudio.com), you can
setup your envinroment using 
[tasks](https://code.visualstudio.com/docs/editor/tasks) 
and the Microsoft official 
[C/C++ extension](https://code.visualstudio.com/docs/languages/cpp), that allows you to debug and lint your code.

## License

    The MIT License (MIT)

    Copyright (c) 2018 Alessandro Jean

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.