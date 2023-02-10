# 42-course-Minishell
The best bash 🔥

The minishell project was done in collaboration with <a href="https://github.com/EmmanuelTomiyoshi">Emmanuel Tomiyoshi</a>. 

# Introduction

Minishell is a 42 school team project to create a basic shell program in C.
In it, it was necessary to implement redirections of elements and pipes, as well as expansions of environment variables and the internal commands cd, echo, env, exit, export, pwd and unset.
This project allows you to travel back in time and go back to the problems that people faced when Windows didn't exist. The complexity of this protection is not only in the difficulty of code development, but also in the ability to know when to stop, as the minishel is almost infinite. This project allows you to travel back in time and go back to the problems people faced when Windows didn't exist.

# Features implemented

Minishell supports:

- Prompt display
- Command history (up and down arrows)
- System executables available from the environment (ls, cat, grep, etc.)
- Local executables (./minishell)
- Builtin commands :
  - echo (and option -n)
  - cd (with only a relative or absolute path)
  - pwd (no options)
  - export (no options)
  - unset (no options)
  -env (no options or arguments)
  - exit (with exit number but no other options)
- Pipes | which redirect output from one command to input for the next
- Redirections:
  -  *>* redirects output
  - *>>* redirects output in append mode
  - < redirects input
  - << DELIMITER displays a new prompt, reads user input until reaching DELIMITER, redirects user input to command input (does not update history)
- Environment variables ($ followed by a sequence of characters) that expand to their values.
$? expands to the exit status of the most recently executed foreground pipeline.
- User keyboard signals:
  - ctrl-c displays a new prompt line.
  - ctrl-d exits minishell
  - ctrl-\ does nothing
  
## usage

Git clone the project:
```sh
https://github.com/leaozim/42-course-Minishell.git
```
To compile, use make
```sh
cd 42-course-Minishell && make
```
Run the program
```sh
./minishell
```
