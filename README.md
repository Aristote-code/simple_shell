# Simple Shell

Simple Shell is a basic command-line interpreter (shell) program developed by Gahima Aristote as part of the ALX System Engineering & DevOps curriculum. It provides a minimalistic interface for users to interact with the operating system by executing commands.

## Features

- The shell supports running most of the basic commands available in a standard Unix-like shell.
- Command execution with or without arguments.
- Built-in command support.
- Handling of PATH environment variable to locate executable programs.
- Exit the shell with the `exit` command.
- Command history support using the up and down arrow keys.
- Custom prompt displaying the current working directory.

## Getting Started

To use the Simple Shell, follow these steps:

1. Clone the repository to your local machine:

```bash
git clone https://github.com/Aristote-code/simple_shell.git
```

2. Compile the source code:

```bash
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```

3. Run the shell:

```bash
./shell
```

## Usage

Once the shell is running, you can type commands and press Enter to execute them. The shell will display the output of the command, if any.

Example:

```bash
$ ls
file1  file2  directory1
$ pwd
/home/user/simple_shell
```

### Built-in Commands

The Simple Shell has some built-in commands that are executed directly by the shell without invoking external programs. The following built-in commands are supported:

- `exit`: Exit the shell.
- `env`: Print the current environment variables.

## Limitations

The Simple Shell is a basic implementation and has some limitations:

- Advanced shell features like input/output redirection, piping, and background processes are not supported.
- Error handling for incorrect commands or invalid inputs is minimal.

## Contributing

Contributions to Simple Shell are welcome. If you find any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contact

For any questions or inquiries, you can contact Gahima Aristote via email at gahimaaristote1@gmail.com.

## Acknowledgments

The Simple Shell project was developed as part of the ALX System Engineering & DevOps program. Special thanks to our mentors and the ALX team for their guidance and support.