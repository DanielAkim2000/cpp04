*This project has been created as part of the 42 curriculum by demane.*

# CPP Module 04

## Description

**CPP Module 04** focuses on subtype polymorphism, abstract classes, and interfaces. The goal is to understand virtual functions, correct destruction through base pointers, deep copies of owned heap data, and designs that cannot be instantiated directly (pure virtual / interfaces).

This module contains four exercises:

| Exercise | Focus |
|----------|--------|
| **ex00 — Polymorphism** | `Animal` / `Dog` / `Cat` + `WrongAnimal` / `WrongCat` without `virtual` |
| **ex01 — I want to be a brain** | Deep-copied `Brain` inside `Dog` / `Cat`; array of animals |
| **ex02 — Abstract class** | `Animal` made abstract (`pure virtual makeSound`) |
| **ex03 — Interface & recap** | Materias, characters, and a materia source |

### Overview

- **ex00** shows that with `virtual makeSound` and a `virtual` destructor, `Dog`/`Cat` sounds are called through `Animal*`. The `Wrong*` hierarchy (non-virtual) calls the base sound instead.
- **ex01** gives each dog/cat a heap-allocated `Brain` (100 ideas). Copy construction / assignment perform a **deep copy**; ideas stay independent after copy. An array of `Animal*` (half dogs, half cats) is deleted without leaks.
- **ex02** turns `Animal` into an abstract class so it can no longer be instantiated.
- **ex03** builds a small materia system: learn/create materias, equip up to 4 slots, use them on a target, unequip without deleting (caller owns the pointer).

## Instructions

### Requirements

- A C++ compiler (`c++` / `g++`) supporting **C++98**
- `make`

### Compilation

```bash
cd ex00   # or ex01 / ex02 / ex03
make
make clean
make fclean
make re
```

Flags used: `-Wall -Wextra -Werror -std=c++98`.

### Execution

All exercises produce a binary named `exec`:

```bash
cd ex00 && make && ./exec
cd ex01 && make && ./exec
cd ex02 && make && ./exec
cd ex03 && make && ./exec
```

Use Valgrind (if available) to verify deep copies and the absence of leaks.

## Classes & components

### Animals (ex00–ex02)

| Component | Role |
|-----------|------|
| `Animal` | Base with `type`; virtual `makeSound`; virtual destructor (pure virtual in ex02) |
| `Dog` / `Cat` | Override `makeSound`; own a `Brain*` from ex01 |
| `WrongAnimal` / `WrongCat` | Same idea **without** `virtual` — wrong polymorphic behavior |
| `Brain` | Array of 100 `ideas`; `setIdea` / `getIdea` |

### Materia system (ex03)

| Component | Role |
|-----------|------|
| `AMateria` | Abstract materia (`clone` pure virtual; `use`) |
| `Ice` / `Cure` | Concrete materias (`"ice"` / `"cure"`) |
| `ICharacter` / `Character` | Named character; inventory of up to 4 materias; `equip` / `unequip` / `use` |
| `IMateriaSource` / `MateriaSource` | Learn up to 4 templates; `createMateria(type)` clones one |

`unequip` only removes the pointer from the inventory; the program must still free that materia when appropriate.

## Resources

### Documentation & references

- [Virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [Abstract class](https://en.cppreference.com/w/cpp/language/abstract_class)
- [Rule of Three / deep copy](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Interfaces via pure virtual classes](https://en.cppreference.com/w/cpp/language/abstract_class)
- 42 subject: *CPP Module 04*

### Use of AI

AI assistance was used for:

- Drafting and formatting this `README.md` according to the 42 curriculum requirements
- Clarifying wording and structuring documentation sections

No AI-generated code was submitted as a substitute for personal implementation. The C++ sources were written and validated by the student.

---

*42 Paris — Common Core*
