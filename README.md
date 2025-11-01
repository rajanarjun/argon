# Argon
A simple, statically-typed programming language inspired by Python and C syntax, with a minimal compiler built from scratch in C++ and an LLVM-based backend for code generation.

## Progress
Currently working on the **lexical analyzer (lexer)**.

- **Ingest source code** — *Completed*
- **Token definitions** — *Completed*
- **Lexer** — *In progress*
- **Parser** — *Planned*
- **AST + Semantic analysis** — *Planned*
- **LLVM IR generation** — *Planned*
- **Code emission and linking** — *Planned*
- **Implement standard functions and library** — *Planned*

## Dependencies
- Written in **C++20**
- Built with **CMake**
- Currently uses only the **C++ Standard Library (STL)**
- Planned: **LLVM backend** for code generation

## Example Syntax
*Note*: Syntax is experimental and may change as development progresses.

```argon
# variable declaration and initialization
let x = num(12)
let y = dec(99.9)
let c = alp('c')
let s = text("hello")

# printing to console
print(x)

# conditional
if (x > 0):
    print("positive")
elseif (x == 0):
    print("equal to zero")
else:
    print("non-positive")
end
```

## License
MIT License — see `LICENSE` file.
