# school-1337 — Basic Simple Projects

You can see all subject files and exercise sheets in the `all_subjects/`.

These are my first 6 basic 1337/42 C projects. Each project is self-contained and includes a Makefile. To build a project, run `make` inside its folder.

Number of projects: 6

Projects (folders):
1. `libft/` — common C helpers (strings, memory, lists).
2. `ft_printf/` — simple printf implementation.
3. `get_next_line/` — read a line from a file descriptor (bonus supports multiple fds).
4. `minitalk/` — client/server messaging using UNIX signals.
5. `push_swap/` — sort numbers with stack operations; includes `checker`.
6. `so_Long/` — small 2D game using XPM images (requires MinilibX/X11).

How to use (very short):

1) Build a single project (run inside repo root):

```bash
make -C libft
```

2) Build all projects (simple loop):

```bash
for d in ft_printf get_next_line libft minitalk push_swap so_Long; do
  make -C "$d" || exit 1
done
```

3) Examples — build + run:

- libft

```bash
make -C libft
# Result: libft/libft.a (static library) or object files
```

- ft_printf

```bash
make -C ft_printf
# Check example mains in the folder or link with your program
```

- get_next_line

```bash
make -C get_next_line
# Use the function in a small test program that opens a file and calls get_next_line
```

- minitalk

```bash
make -C minitalk
# Terminal 1: ./server (prints PID)
# Terminal 2: ./client <PID> "Hello"
```

- push_swap

```bash
make -C push_swap
./push_swap 3 2 1 0 -1   # prints operations to sort
# Validate with checker (reads operations from stdin):
# echo -e "sa\nra" | ./checker 3 2 1 0 -1
```

- so_Long

```bash
make -C so_Long
./so_long maps/map.ber   # needs MinilibX / X11; run in a graphical session
```

Notes:
- Use `gcc` or `cc` and `make` available on your system.
- `so_Long` usually requires additional system libraries (X11, MinilibX). If it fails to build/run, install X11 development packages for your distro.