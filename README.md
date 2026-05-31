# PIPEX

A C program that replicates the shell pipe mechanism, connecting two commands through a pipe.


## About

In bash, the `|` operator connects the output of one command to the input of another. 
Pipex replicates this behavior in C by creating a pipe and two child processes — one reads from an input file and executes the first command, the other executes the second command and writes the result to an output file.

It uses custom utility functions instead of the standard C library.


## Functions
### Process functions
| Function | Description |
|----------|-------------|
| `run_pipex` | Creates the pipe and forks two child processes |
| `child_process` | Opens the input file, redirects stdin/stdout and executes cmd1 |
| `child_process2` | Opens the output file, redirects stdin/stdout and executes cmd2 |

### Execution functions
| Function | Description |
|----------|-------------|
| `execute_command` | Resolves the command path and runs it with `execve` |
| `find_command_path` | Searches through PATH directories to find the executable |
| `get_paths` | Extracts and splits the PATH variable from the environment |
| `get_env` | Looks up a variable by name in the environment array |

### Utils
| Function | Description |
|----------|-------------|
| `open_file` | Opens a file with error handling |
| `ft_error` | Prints an error message and exits the program |
| `ft_free` | Frees a null-terminated array of strings |


## Usage

```bash
git clone https://github.com/sarabezz/pipex.git
cd pipex
make
```

Run it like a shell pipe:
```bash
./pipex file1 cmd1 cmd2 file2
```

Which is equivalent to:
```bash
< file1 cmd1 | cmd2 > file2
```

Example:
```bash
./pipex input.txt "cat" "wc -l" output.txt
```


## Key concepts

- `pipe()` — creates a unidirectional channel between two file descriptors for inter-process communication
- `fork()` — duplicates the current process to create two independent child processes
- `execve()` — replaces the child process image with the command to execute
- `dup2()` — redirects stdin/stdout to the pipe or files instead of the terminal
- PATH resolution — searches through the environment's PATH directories to find the executable
- File descriptor management — careful closing of unused ends of the pipe to avoid blocking


## Project info 

| | |
|---|---|
| Language | C |
| School | 42 Madrid |
| Status | ✅ Completed |
