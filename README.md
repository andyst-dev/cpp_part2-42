# cpp_part2

A repository gathering the second five 42 C++ modules, from `cpp05` to `cpp09`.
This project consists of working through the more advanced part of the C++98 modules, with each module introducing a new set of concepts such as exceptions, casts, templates, STL containers, iterators, and algorithms.

`cpp_part2` was designed to continue the C++ learning path with more abstract tools and more standard-library-heavy exercises, moving from object-oriented structure toward generic programming and container-based problem solving.

## Features
- Covers the second five 42 C++ modules: `cpp05` to `cpp09`
- Multiple standalone exercises with dedicated Makefiles
- Progressive introduction to exceptions, casts, templates, and STL usage
- Focus on class design, generic code, containers, and algorithmic problem solving

## Project structure
- `cpp05/` — exceptions, bureaucrats, forms, and execution workflows
- `cpp06/` — scalar conversion, serialization, and runtime type identification
- `cpp07/` — function templates, iteration templates, and templated arrays
- `cpp08/` — STL containers, iterators, and algorithm-based exercises
- `cpp09/` — container-driven practical programs using maps, stacks, vectors, and sequence processing

## Module overview

### cpp05
This module focuses on exceptions and class interactions built around bureaucrats and forms.
It introduces grade validation, error handling, and execution rules between related classes.

Included exercises:
- `ex00` — `bureaucrat`: grade-bounded bureaucrat class with custom exceptions
- `ex01` — `form`: signed forms with grade constraints
- `ex02` — `aform`: executable abstract-form hierarchy with specific concrete forms
- `ex03` — `intern`: form factory through an `Intern` class

Main topics:
- exception handling
- validation through class invariants
- interaction between classes
- abstract base classes
- concrete derived forms

### cpp06
This module focuses on C++ casts and runtime type handling.
It introduces explicit conversions, serialization through integer representation, and dynamic type identification.

Included exercises:
- `ex00` — `convert`: scalar literal conversion to `char`, `int`, `float`, and `double`
- `ex01` — `serialize`: pointer serialization and deserialization with `uintptr_t`
- `ex02` — `identify`: runtime identification of derived types from a base class

Main topics:
- scalar conversion
- static and reinterpret-style casts
- pointer serialization
- runtime type identification
- polymorphic base usage

### cpp07
This module introduces templates through generic functions and classes.
It focuses on reusable code that works across different types without rewriting the same logic.

Included exercises:
- `ex00` — `templates`: generic `swap`, `min`, and `max`
- `ex01` — `iter`: function template applied to each element of an array
- `ex02` — `array`: templated dynamic array class

Main topics:
- function templates
- class templates
- generic iteration
- reusable type-independent logic
- template implementation in headers / `.tpp`

### cpp08
This module focuses on STL containers, iterators, and algorithms.
It is the point where using the standard library becomes part of the expected solution itself.

Included exercises:
- `ex00` — `easyfind`: search utility over integer containers
- `ex01` — `span`: bounded integer container with shortest and longest span calculations
- `ex02` — `mutant`: stack-like container exposing iterators

Main topics:
- STL containers
- iterators
- standard algorithms
- exception handling in container logic
- container extension patterns

### cpp09
This module focuses on practical STL-based programs.
It uses standard containers to solve small real problems around parsing, evaluation, and performance comparison.

Included exercises:
- `ex00` — `btc`: bitcoin exchange value lookup from a CSV database
- `ex01` — `RPN`: reverse polish notation evaluator
- `ex02` — `PmergeMe`: merge-insert style sorting comparison across containers

Main topics:
- STL containers in real programs
- parsing structured input
- associative lookup
- stack-based evaluation
- sequence manipulation and comparison

## Notes
This repository groups several C++ modules in a single place instead of exposing one project per repository.
Because of that, each module keeps its own exercise layout and Makefiles.

## Usage
Build and run the exercise you want to inspect.
Examples:

```bash
cd cpp05/ex00 && make && ./bureaucrat
cd cpp06/ex00 && make && ./convert 42.0f
cd cpp09/ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

## Learning outcomes
This repository continues the C++98 learning path with more advanced language features and standard library usage.
It helped build solid foundations in:
- exception handling
- abstract class design
- explicit casting
- runtime type identification
- function and class templates
- STL containers and iterators
- algorithmic problem solving with standard library tools
