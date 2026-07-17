# CPP-Module

C++ exercises from 42's **C++ Modules** curriculum (`CPP00` → `CPP09`). Each module covers a different set of C++ concepts, and each exercise (`exXX`) inside a module is an independent, self-contained program with its own `Makefile`, source files, and binary — there is no shared build system across the repo.

All exercises are written in **C++98** and compiled with `-Wall -Wextra -Werror`.

## Repository layout

```
.
├── CPP00 .. CPP09/     # One folder per module
│   └── exXX/            # One folder per exercise, each with its own Makefile
├── Test/                  # Scratch/experiment files, not part of any graded exercise
└── README.md
```

## Build & run

Every exercise is built independently from inside its own folder:

```bash
cd CPPXX/exYY
make
./<binary-name> [arguments]
```

(see the tables below for each exercise's binary name and expected arguments)

---

## CPP00 — C++ basics: namespaces, classes, member functions, static/const

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `megaphone` | Prints every argument passed on the command line in uppercase; if run with no arguments, prints a default "loud" message. |
| `ex01` | `phonebook` | A `PhoneBook` of up to 8 `Contact`s. Interactive `ADD` / `SEARCH` / `EXIT` commands; `SEARCH` lists a truncated table and lets you display one contact in full. |

## CPP01 — Memory allocation, references, pointers to members, switch

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `zombie` | Compares heap-allocated (`newZombie`) vs. stack-allocated (`randomChump`) `Zombie` objects. |
| `ex01` | `zombies` | `zombieHorde()` allocates an array of zombies on the heap with a single `new[]`. |
| `ex02` | `brain` | Demonstrates that a variable, a reference to it, and a pointer to it all refer to the same memory address. |
| `ex03` | `violation` | `HumanA` holds its `Weapon` by **reference**, `HumanB` by **pointer** (settable after construction), illustrating the practical difference. |
| `ex04` | `writefile` | `./writefile <filename> <s1> <s2>` — replaces every occurrence of `s1` with `s2` in the file and writes the result to `<filename>.replace`. |
| `ex05` | `harl` | `Harl::complain(level)` prints the message for exactly one of `DEBUG` / `INFO` / `WARNING` / `ERROR`, dispatched via a pointer-to-member-function table. |
| `ex06` | `harlFilter` | Same as `ex05`, but a complaint at a given level also cascades through all higher-severity levels (e.g. `WARNING` also prints `ERROR`). An unrecognized level prints a fallback message instead of crashing. |

## CPP02 — Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

A fixed-point number class (`Fixed`), built up in three stages:

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `fixed` | `Fixed` in Orthodox Canonical Form (default/copy constructor, destructor, `operator=`) storing a fixed-point value as a raw `int` with 8 fractional bits. |
| `ex01` | `fixed` | Adds `int`/`float` converting constructors, `toInt()` / `toFloat()`, and `operator<<`. |
| `ex02` | `fixed` | Adds the full comparison and arithmetic operator set (`+ - * /`, `++`/`--` pre/post, `< > <= >= == !=`) plus static `min()`/`max()`. |

## CPP03 — Inheritance

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `claptrap` | Base `ClapTrap` class with hit points, energy points and attack damage; `attack()`, `takeDamage()`, `beRepaired()`. |
| `ex01` | `scavtrap` | `ScavTrap` publicly inherits `ClapTrap`, with its own stats and an extra `guardGate()` ability. |
| `ex02` | `fragtrap` | `FragTrap` publicly inherits `ClapTrap` alongside `ScavTrap`, with its own stats and a `highFivesGuys()` ability. |

## CPP04 — Polymorphism, abstract classes, interfaces

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `animal` | `Animal`/`Dog`/`Cat` use a **virtual** `makeSound()` to show correct runtime polymorphism, contrasted with `WrongAnimal`/`WrongCat`, where `makeSound()` is *not* virtual and calling it through an `Animal*`/`WrongAnimal*` resolves at compile time instead. |
| `ex01` | `animalwithbrain` | `Dog` and `Cat` each own a `Brain*` (100 "ideas"); constructors/destructors and the copy semantics manage this dynamically allocated member correctly (deep copy, no leaks/double frees). |
| `ex02` | `aanimal` | `Animal` becomes the abstract `AAnimal` with a pure virtual `makeSound()`, turning it into a proper interface — it can no longer be instantiated directly. |

## CPP05 — Repetition and exceptions

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `Bureaucrat` | `Bureaucrat` has a name and a grade (1 = highest, 150 = lowest); `incrementGrade()`/`decrementGrade()` throw `GradeTooHighException` / `GradeTooLowException` at the bounds. |
| `ex01` | `Form` | Adds a `Form` with a grade required to sign it and a grade required to execute it; `Bureaucrat::signForm()` attempts to sign, catching and reporting any exception. |
| `ex02` | `PRSform` | `Form` becomes the abstract `AForm` (pure virtual `executeAction()`), with three concrete forms — `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` — each with its own sign/execute grade requirements. |
| `ex03` | `intern` | Adds `Intern::makeForm(name, target)`, a small factory that builds the correct concrete `AForm` from a string name, throwing `FormNotFoundException` for an unknown one. |

## CPP06 — C++ casts

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `scalarconverter` | `./scalarconverter <literal>` — detects whether the input is a `char`, `int`, `float` or `double` literal and prints its representation in all four types, handling under/overflow and special float/double values (`nan`, `inf`). |
| `ex01` | `serializer` | `Serializer::serialize`/`deserialize` convert a `Data*` to and from a `uintptr_t` via `reinterpret_cast`, then confirm the round trip recovers the original pointer. |
| `ex02` | `identify` | Randomly instantiates one of `A`, `B`, `C` (all deriving from `Base`) behind a `Base*`, then identifies the real type at runtime using `dynamic_cast` on both a pointer and a reference. |

## CPP07 — Templates

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `whatever` | Template `swap()`, `min()`, and `max()` functions that work with any comparable type. |
| `ex01` | `iter` | Template `iter(array, size, f)` applies a function `f` to every element of an array of any type. |
| `ex02` | `array` | A template `Array<T>` container: fixed size at construction, bounds-checked `operator[]` (throws `IndexOutOfRangeException`), proper deep-copy semantics. |

## CPP08 — Templated containers & introduction to the STL

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `easyfind` | Template `easyfind(container, value)` returns an iterator to `value` in any STL container that supports `find`, throwing if it isn't present. |
| `ex01` | `span` | `Span` stores up to N `int`s and computes the shortest and longest span between any two stored values. |
| `ex02` | `mutantstack` | `MutantStack<T>` — a `std::stack` subclass that additionally exposes `begin()`/`end()` (and reverse variants), making it iterable like a normal container. |

## CPP09 — STL containers & algorithms

| Exercise | Binary | Description |
|---|---|---|
| `ex00` | `btc` | Looks up a BTC exchange rate for each date in an input file against a `std::map`-backed database (using `lower_bound` to find the closest earlier date), with full date/value validation. |
| `ex01` | `RPN` | `./RPN "<expression>"` — evaluates a Reverse Polish Notation expression using a `std::stack`. |
| `ex02` | `PmergeMe` | Implements the Ford-Johnson (merge-insertion) sort algorithm on a sequence of positive integers, run against both `std::vector` and `std::deque`, with timing comparison. |

This module has its own, much more detailed [CPP09/README.md](CPP09/README.md) covering the algorithms (including a full derivation of the Jacobsthal sequence used in `PmergeMe`), complexity analysis, and STL functions used — worth a look if you want the deep dive.

---

## Notes

- Every exercise uses `-std=c++98 -Wall -Wextra -Werror`, in line with 42's requirements for this project.
- The `Test/` folder holds standalone scratch files used to experiment with STL containers, casts, etc. — they aren't part of any graded exercise.
