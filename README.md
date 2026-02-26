# 🎯 42 Exams — Rank 2 → 6

> Solutions and practice material for École 42's ranking exam system.

---

## 📖 Overview

The 42 exam system tests mastery under pressure. No internet, no compiler warnings tolerated, and a `grademe` that decides your fate. This repository tracks solutions across **Rank 2 through Rank 6**, from classic C string exercises to complex systems programming in C and C++.

---

## 🗂️ Structure

### [Rank 2](./Rank_2) — C Fundamentals
The foundation: strings, bits, arithmetic, and memory. Four levels of increasing difficulty.

<details>
<summary><strong>Lvl 1</strong> — Basic I/O & string operations</summary>

| Exercise | Description |
|----------|-------------|
| `first_word` | Print the first word of a string |
| `fizzbuzz` | Classic FizzBuzz |
| `ft_putstr` | Write a string to stdout |
| `ft_strcpy` | Copy a string |
| `ft_strlen` | Compute string length |
| `ft_swap` | Swap two integers via pointers |
| `repeat_alpha` | Repeat each letter by its position |
| `rev_print` | Print a string in reverse |
| `rot_13` | ROT13 cipher |
| `rotone` | Shift every letter by one |
| `search_and_replace` | Replace a char in a string |
| `ulstr` | Toggle case for every character |

</details>

<details>
<summary><strong>Lvl 2</strong> — String manipulation & bit operations</summary>

| Exercise | Description |
|----------|-------------|
| `alpha_mirror` | Mirror alphabetical characters |
| `camel_to_snake` | Convert camelCase to snake_case |
| `do_op` | Basic arithmetic from argv |
| `ft_atoi` | String to integer conversion |
| `ft_strcmp` | Compare two strings |
| `ft_strcspn` | Count chars before first match |
| `ft_strdup` | Duplicate a string with malloc |
| `ft_strpbrk` | Find first occurrence of charset |
| `ft_strrev` | Reverse a string in place |
| `ft_strspn` | Count matching prefix chars |
| `inter` | Print intersection of two strings |
| `is_power_of_2` | Bit trick power-of-two check |
| `last_word` | Print the last word |
| `max` | Return max of two ints |
| `print_bits` | Print binary representation of a byte |
| `reverse_bits` | Reverse bits of a byte |
| `snake_to_camel` | Convert snake_case to camelCase |
| `swap_bits` | Swap high and low nibble |
| `union` | Print union of two strings |
| `wdmatch` | Check if word letters appear in order |

</details>

<details>
<summary><strong>Lvl 3</strong> — Memory, linked lists & number bases</summary>

| Exercise | Description |
|----------|-------------|
| `epur_str` | Trim and reduce whitespace |
| `expand_str` | Expand spaces between words |
| `ft_atoi_base` | Base-N string to integer |
| `ft_list_size` | Count nodes in a linked list |
| `ft_range` | Allocate array of ints in range |
| `ft_rrange` | Same, but reversed |
| `hidenp` | Check if string is subsequence |
| `lcm` | Least common multiple |
| `paramsum` | Sum argv params as integers |
| `pgcd` | Greatest common divisor |
| `print_hex` | Print number in hexadecimal |
| `rstr_capitalizer` | Capitalize last letter of each word |
| `str_capitalizer` | Capitalize first letter of each word |
| `tab_mult` | Print multiplication table |

</details>

<details>
<summary><strong>Lvl 4</strong> — Sorting, splitting & linked list manipulation</summary>

| Exercise | Description |
|----------|-------------|
| `fprime` | Print prime factors |
| `ft_itoa` | Integer to string conversion |
| `ft_list_foreach` | Apply function to each list node |
| `ft_list_remove_if` | Remove nodes matching a condition |
| `ft_split` | Split string by delimiter |
| `rev_wstr` | Reverse order of words |
| `rostring` | Rotate words left by one |
| `sort_int_tab` | Sort an integer array |
| `sort_list` | Sort a linked list |

</details>

---

### [Rank 3](./Rank_3) — Mandatory Classics
The two exercises every 42 student must know by heart.

| Exercise | Description |
|----------|-------------|
| `ft_printf.c` | Variadic printf reimplementation |
| `get_next_line.c` | Line-by-line file reading with static buffers |

---

### [Rank 4](./Rank_4) — System Programming
Unix processes, file descriptors, and shell mechanics.

| Exercise | Status | Description |
|----------|--------|-------------|
| `picoshell` | ✅ Verified | Minimal shell with `execve` and `fork` |
| `ft_popen` | ⚠️ Not tested | Reimplement `popen()` with pipes |
| `sandbox` | ⚠️ Not tested | Process isolation via system calls |
| `vbc` | ✅ Verified | Variable-length byte counter |
| `argo` | ⚠️ Not tested | Argument parsing with leak management |

---

### [Rank 5](./Rank_5) — C++ & Algorithms
Advanced data structures, C++ OOP, and algorithmic challenges.

**Level 1**
| Exercise | Description |
|----------|-------------|
| `vect2` | 2D vector class with operator overloading |
| `bigint` | Arbitrary-precision integer arithmetic |
| `polyset` | Polymorphic set using inheritance and templates |

**Level 2**
| Exercise | Description |
|----------|-------------|
| `bsq` | Find the largest square in a 2D map |
| `life` | Conway's Game of Life simulation |

---

### [Rank 6](./Rank_6) — Network Programming
The final frontier: TCP server with `select()`/`poll()` multiplexing.

| File | Description |
|------|-------------|
| `mini_serv.c` | Multi-client TCP server — broadcast messages across connected clients |

---

*"Under pressure, you discover what you actually know."*
