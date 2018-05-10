# minishell

A 42 Silicon Valley project to create a Unix-like shell in c

## Project Scope

As a first attempt at creating a 'shell' command system, this project only allows the input of simple commands.

In a later project, 21sh,

## Installation and Running

Step 1: Clone the repository

```
git clone https://github.com/Dorfnox/minishell.git minishell
```

Step 2: cd into the repo directory and run 'make':

```
cd minishell && make
```

Step 3: run the executable:

```
./minishell
```

## Commands

The minishell can run any system executables located in the PATH environmental variable, as well as some simple builtins.

### Builtin Commands

Builtin commands include:

Displaying environmental variables using 'env':
```
env
```

Setting evironmental variables using 'setenv':
```
setenv FOO="BAR BAR this is an environmental variable now BAR BAR"
```

Un-setting evironmental variables using 'unsetenv':
```
unsetenv FOO
```

Echoing text to the standard output using 'echo':
```
echo Hey there $FOO "what is the meaning of life?"
```

Changing the working directory using 'cd':
```
cd ..
```

By default, the minishell does not allow editing of important environmental variables such as PATH or HOME, however by using 'byp' (bypass), you can override this setting:
```
byp
```

## Authors

* **Brendan Pierce** - *Program creator* - [Brendan Pierce](https://github.com/Dorfnox/)

## License

This project is not licensed.

## Acknowledgments

* Fellow coders at 42!
