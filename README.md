
# CPP-Evaluator - Expression Evaluator  

Welcome to **CPP-Evaluator**, a simple and friendly mathematical expression evaluator that can handle both **integers** and **floating-point numbers**.  
CPP-Evaluator is designed to evaluate arithmetic expressions and ensure valid inputs with error handling for common mistakes like consecutive operators and mismatched parentheses.

---

## Features  
- **Basic Arithmetic Operations**: Supports addition (+), subtraction (-), multiplication (*), and division (/).  
- **Floating-Point Support**: Handles decimal numbers with precision.  
- **Operator Precedence and Parentheses**: Follows the standard order of operations (PEMDAS/BODMAS).  
- **Input Validation**: Detects and rejects invalid expressions, including:
  - Consecutive operators like `++`, `--`, or `**`.  
  - Mismatched parentheses (e.g., `(5 + 3))`).  
  - Unsupported characters (only numbers, `+`, `-`, `*`, `/`, and parentheses are allowed).  

---

## 🚀 How to Use  
1. Clone the repository:  
   ```bash
   git clone https://github.com/Kishmat/CPP-Evaluator.git
   cd CPP-Evaluator
   ```
2. Compile the C++ code:  
   ```bash
   make
   ```
3. Run the program:  
   ```bash
   ./program.exe
   ```

4. Enter expressions to evaluate and see the result! Type `exit` to quit the program.

---

## Example  

**Input:**  
```
> (10 + 2) * 3 - 4 / 2  
= 34

> 5.5 + 2.3  
= 7.8 

```

---

## Limitations  
1. **No Advanced Operators**: Currently supports only basic arithmetic (`+`, `-`, `*`, `/`). Exponentiation (`^`, `**`) is not yet supported.  
2. **No Functions**: Functions like `sin()`, `cos()`, or `sqrt()` are not implemented.  
3. **No Complex Error Recovery**: While input validation works well, it might not give detailed hints for complex invalid expressions.

---

## Future Improvements  
- Add support for exponentiation and advanced mathematical operators.  
- Implement trigonometric and logarithmic functions.  
- Improve the error messages to provide more helpful hints.  
