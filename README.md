*This project has been created as part of the 42 curriculum.*

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&height=200&color=0:0B1419,50:1A3A4A,100:2E6F7C&text=Get%20Next%20Line&fontColor=E8F1F2&fontSize=54&fontAlignY=40&desc=Read%20a%20file%20descriptor%2C%20one%20line%20at%20a%20time&descAlignY=62&descSize=15" width="100%" alt="GNL banner"/>
</p>

<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=22&pause=1200&color=7EC8C9&center=true&vCenter=true&width=560&lines=read()+%2B+static+storage;BUFFER_SIZE+tunable;One+line+per+call" alt="typing animation"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-COMMON%20CORE-0B1419?style=for-the-badge" alt="42"/>
  <img src="https://img.shields.io/badge/LANGUAGE-C-1A3A4A?style=for-the-badge&logo=c&logoColor=7EC8C9" alt="C"/>
  <img src="https://img.shields.io/badge/BUFFER__SIZE-configurable-2E6F7C?style=for-the-badge" alt="BUFFER_SIZE"/>
  <img src="https://img.shields.io/badge/FLAGS--Wall%20--Wextra%20--Werror-111111?style=for-the-badge" alt="Flags"/>
</p>

---

## Description

**Get Next Line** returns the next line from a file descriptor on every call.

It must work for any valid `BUFFER_SIZE`, keep leftover bytes between calls, and handle EOF correctly — including a last line without a trailing newline.

**Concepts covered:** file descriptors · `static` variables · dynamic allocation · buffer management

---

## Instructions

### Build

```bash
make        # build get_next_line.a
make clean
make fclean
make re
```

Custom buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c your_main.c -o gnl
```

### Usage

```c
#include "get_next_line.h"

char *line;

line = get_next_line(fd);
while (line)
{
    /* use line */
    free(line);
    line = get_next_line(fd);
}
```

> Always `free()` the returned line.

---

## How it works

```text
┌─────────────┐     read()      ┌──────────────┐
│  File / FD  │ ─────────────── │ static stash │
└─────────────┘   BUFFER_SIZE   └──────┬───────┘
                                       │
                              newline found?
                                       │
                          ┌────────────┴────────────┐
                          ▼                         ▼
                     return line              keep remainder
                     (+ '\n' if any)          for next call
```

1. **Read** chunks with `read()` into a stash  
2. **Append** until a `\n` appears (or EOF)  
3. **Extract** the complete line and return it  
4. **Keep** leftover bytes in a `static` buffer for the next call  
5. At EOF with no data left → return `NULL`

This streams large files without loading everything into memory.

---

## Project structure

```text
gnl/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── Makefile
└── README.md
```

---

## Resources

- [read(2) — Linux man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc(3) / free(3)](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [C memory management — cppreference](https://en.cppreference.com/w/c/memory)

---

## AI usage

AI tools were used only to help structure and polish this README  
(sections, wording, formatting).

No AI was used to write, debug, or implement the project source code.

---

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:0B1419,50:1A3A4A,100:2E6F7C&height=100&section=footer" width="100%" alt="footer"/>
</p>
