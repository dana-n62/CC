*This project has been created as part of the 42 curriculum by \<dna2>.*

---

## Description

Minitalk is a small inter-process communication program built in C. It consists of two programs — a **server** and a **client** — that exchange data using exclusively UNIX signals.

The client takes a server PID and a string as arguments, encodes each character into a sequence of bits, and transmits them one by one to the server using only `SIGUSR1` and `SIGUSR2`. The server reconstructs the bits back into characters and prints the received string to the terminal.

The core challenge of this project is encoding and decoding data at the bit level, managing signal timing to prevent dropped signals, and handling the stateless nature of UNIX signal handlers.

---

## Instructions

### Running

**Step 1 — Start the server in one terminal:**
```bash
./server
```
The server will print its PID on startup:
```
Server PID: 12345
```

**Step 2 — Send a message from another terminal:**
```bash
./client 12345 "Hello 42!"
```

The server will print the received message:
```
Hello 42!


## How It Works

- The client converts each character of the string into its 8-bit binary representation
- Each bit is sent as a signal: `SIGUSR1` for `1`, `SIGUSR2` for `0`
- The server reconstructs each character bit by bit using a static accumulator
- When the null terminator `\0` is received, the server prints a newline and resets — ready for the next client

---

## Resources

### Documentation
- `man sigaction` — sigaction structure and usage
- `man signal` — signal overview
- `man kill` — sending signals between processes
- `man getpid` — retrieving process IDs
- `man usleep` — microsecond sleep
- `man pause` — suspending process until signal

### References
- [POSIX Signals — Linux man pages](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Bitwise operations in C — cppreference](https://en.cppreference.com/w/c/language/operator_arithmetic)
- [42 Norm](https://github.com/42School/norminette)

### AI Usage

Claude (claude.ai) was used as a **guided learning tool** throughout this project. Specifically:

- To understand the difference between `signal()` and `sigaction()` and when to use each
- To learn and practice bitwise operations — extracting and reconstructing bits from characters
- To debug logic errors in the signal handler (bit counter, accumulator reset)
- To understand async-signal-safety and why `write()` must be used instead of `printf()` inside handlers
- To structure and write the Makefile correctly

All code was written independently. AI was used to explain concepts, review logic, and ask comprehension questions — not to generate code directly.
