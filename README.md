# AED-I-2018.1
![Year][year] ![Id][id] ![T-P-I][tpi] ![Last class][last-class]
![Language][language] ![IDE][ide]

Algorithms written in the classes of Algorithms and Data Structures I (Algoritmos e Estruturas de Dados I) at Federal University of ABC (UFABC).

[year]: https://img.shields.io/badge/year-2018.1-blue.svg?style=flat-square
[id]: https://img.shields.io/badge/id-MCTA001--13-yellowgreen.svg?style=flat-square
[tpi]: https://img.shields.io/badge/T--P--I-2--2--4-lightgrey.svg?style=flat-square
[last-class]: https://img.shields.io/badge/last_class-2018.04.23-green.svg?style=flat-square
[language]: https://img.shields.io/badge/language-C-yellow.svg?style=flat-square
[ide]: https://img.shields.io/badge/IDE-VSCode-orange.svg?style=flat-square

## Classes

- **19/02/2018** *(Laboratory)*: [Subject introduction]. [Introduction to the C
programming language].
- **21/02/2018** *(Theory)*: [Dynamic arrays].
- **26/02/2018** *(Theory)*: [Linked lists].
- **28/02/2018** *(Theory)*: [Basic notions about Algorithmic Complexity].
- **05/03/2018** *(Laboratory)*: [Linked list practical exercise].
- **07/03/2018** *(Theory)*: [Basic notions about Algorithmic Complexity *(continuation)*].
- **12/03/2018** *(Laboratory)*: [Stacks and Queues]. [Stack practical exercise].
- **14/03/2018** *(Theory)*: [Search algorithms and Binary Search Trees].
- **19/03/2018** *(Laboratory)*: [Binary Search Tree practical exercise].
- **21/03/2018** *(Theory)*: Review of exercises.
- **26/03/2018** *(Laboratory)*: **[First test]**.
- **28/03/2018** *(Theory)*: [AVL Tree].
- **02/04/2018** *(Laboratory)*: [Second Binary Search Tree practical exercise].
- **04/04/2018** *(Theory)*: [AVL Tree *(continuation)*].
- **09/04/2018** *(Laboratory)*: [AVL Tree practical exercise].
- **16/04/2018** *(Laboratory)*: [Basic sorting algorithms]. [Linked list sort practical exercise].
- **18/04/2018** *(Theory)*: [Mergesort and Quicksort].
- **23/04/2018** *(Laboratory)*: [Mergesort in Linked List practical exercise].

[Subject introduction]: classes/laboratory/2018.02.19/part-1/
[Introduction to the C programming language]: classes/laboratory/2018.02.19/part-2/
[Dynamic arrays]: classes/theory/2018.02.21/
[Linked lists]: classes/theory/2018.02.26/
[Basic notions about Algorithmic Complexity]: classes/theory/2018.02.28/
[Linked list practical exercise]: practical/2018.03.05/
[Basic notions about Algorithmic Complexity *(continuation)*]: classes/theory/2018.03.07/
[Stacks and Queues]: classes/laboratory/2018.03.12/
[Stack practical exercise]: practical/2018.03.12/
[Search algorithms and Binary Search Trees]: classes/theory/2018.03.14/
[Binary Search Tree practical exercise]: practical/2018.03.19/
[First test]: tests/test-01/
[AVL Tree]: classes/theory/2018.03.28/
[Second Binary Search Tree practical exercise]: practical/2018.04.02/
[AVL Tree *(continuation)*]: classes/theory/2018.04.04/
[AVL Tree practical exercise]: practical/2018.04.09/
[Basic sorting algorithms]: classes/laboratory/2018.04.16/
[Linked list sort practical exercise]: practical/2018.04.16/
[Mergesort and Quicksort]: classes/theory/2018.04.18/
[Mergesort in Linked List practical exercise]: practical/2018.04.23/

## Build instructions

Use the following commands to compile any `.c` file in this repository.

```bash
# Assuming you have the GNU C Compiler in
# your PATH, but can be MinGW or the Visual
# Studio compiler too if you are under an 
# Windows environment.

# Compiles the file in the bin folder.
$ gcc file.c -o bin/file
# If the compiler complain about the folder,
# create it using the command below, and
# run the command above again.
$ mkdir bin
# Run the program.
$ ./bin/file
```

If you use [Visual Studio Code](https://code.visualstudio.com), you can
setup your envinroment using 
[tasks](https://code.visualstudio.com/docs/editor/tasks) 
and the Microsoft official 
[C/C++ extension](https://code.visualstudio.com/docs/languages/cpp), that allows you to debug and lint your code.

If you want to compile any markdown file with LaTeX, you need
to run:

```bash
# Assuming you have Python in your PATH.

# Install readme2tex.
$ pip install readme2tex
# Generate the README with the LaTeX equations
# in an separated svg folder.
$ python -m readme2tex --output README.md INPUT.md
```

After that, you need to replace and correct the svg folder from the root
path of the repository to the relative path of the folder in the output file.

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