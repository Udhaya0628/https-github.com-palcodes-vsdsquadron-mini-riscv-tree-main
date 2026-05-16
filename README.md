# Writing down my understandings and screenshots

---

# What is a firmware library?

A firmware library is a collection of reusable functions and definitions used to interact with hardware in embedded systems. Firmware libraries provide an abstraction layer between the hardware registers and the application code.

Instead of directly accessing low-level hardware registers every time, developers can use APIs such as `gpio_init()`, `gpio_write()`, and `gpio_read()` to control peripherals easily.

Firmware libraries improve:
- Code readability
- Reusability
- Portability
- Maintainability

They also help organize embedded firmware projects in a structured way.

Example:
- `gpio.h` contains API declarations
- `gpio.c` contains implementations
- `main.c` uses the APIs

This separation is commonly used in real embedded firmware development.

![Memory Map](memorymap.png)

---

# Why are APIs important?

APIs provide a simple and developer-friendly way to access hardware functionality.

Without APIs, application code would need to directly manipulate hardware registers, which increases complexity and reduces readability.

APIs help by:
- Hiding hardware complexity
- Improving code modularity
- Making firmware reusable across projects
- Simplifying debugging and maintenance

In embedded systems, APIs allow developers to write application logic without worrying about low-level implementation details.

For example:
- `gpio_write(pin, value)` can internally control registers
- But the application developer only uses the function call

This makes firmware development cleaner and more scalable.

---

# What was understood from the lab code?

From this lab, I understood how embedded firmware libraries are structured.

The project was divided into:
- `gpio.h` → API declarations
- `gpio.c` → function implementations
- `main.c` → application logic

The GPIO APIs had a consistent structure:
- `gpio_init()`
- `gpio_write()`
- `gpio_read()`

The lab demonstrated:
- Separation of interface and implementation
- Firmware modularity
- Reusable API-based design
- Simulation of GPIO behavior without actual hardware

This structure is commonly followed in embedded firmware projects.

---

# Program Execution Screenshot

![Program Output](output.png)

---

# Conclusion

This task helped me understand:
- Firmware basics
- API-oriented embedded programming
- Firmware library structure
- GCC compilation process
- Basic Git and GitHub workflow

The development environment was successfully configured and the firmware simulation program executed correctly.![alt text](<Screenshot 2026-05-14 212127.png>)