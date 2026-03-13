*This project has been created as part of the 42 curriculum by dna2.*

## Description

**so_long** is a small 2D game built in C using the MiniLibX graphics library. The project focuses on fundamental game development concepts including graphics rendering, event handling, map validation, and pathfinding algorithms.

### Goal

Create a playable top-down game where the player must:
- Collect all collectibles on the map
- Navigate to the exit
- Avoid obstacles (walls)
- Complete the level in the minimum number of moves

### Technical Overview

The project demonstrates:
- **2D graphics rendering** using MiniLibX
- **Flood fill algorithm** for path validation
- **Event-driven programming** with keyboard input handling
- **Memory management** in C with proper allocation/deallocation
- **Map parsing and validation** from `.ber` files
- **Collision detection** and game state management

---

## Instructions

### Prerequisites

- **Linux** operating system (tested on Ubuntu)
- **MiniLibX** library
- **GCC** compiler
- **Make** build tool

### Compilation

The project compiles using make

### Execution

Run the game with a valid map file:
```bash
./so_long maps/valid_simple_map.ber
```
### Map Format

Maps must be `.ber` files containing:
- `1` - Walls
- `0` - Empty space (floor)
- `P` - Player starting position (exactly one)
- `C` - Collectible (at least one)
- `E` - Exit (exactly one)

**Map Requirements:**
- Rectangular shape
- Surrounded by walls (`1`)
- Valid path from player to all collectibles and exit
- Maximum size: fits on screen (typically 30×30 tiles max)

**Example valid map:**

1111111111111
1000000000001
1P00C00C000E1
1000000000001
1111111111111
```

### Controls

- `W` or `↑` - Move up
- `A` or `←` - Move left
- `S` or `↓` - Move down
- `D` or `→` - Move right
- `ESC` - Exit game
- Click `X` button - Close window

### Game Rules

1. Collect all collectibles (`C`)
2. Navigate to the exit (`E`)
3. Exit is only accessible after collecting all items
4. Move counter displays in terminal
5. Win message appears upon completion

---

## Features

### Implemented Features

 **Map Validation System**
- File extension checking (`.ber`)
- Rectangular map validation
- Wall enclosure verification
- Character validation (P, E, C counts)
- Flood fill pathfinding algorithm

 **Graphics Engine**
- MiniLibX integration
- Sprite-based rendering
- Window management
- Image loading (XPM format)

 **Gameplay Mechanics**
- Smooth keyboard controls (WASD)
- Collision detection
- Collectible system
- Win condition checking
- Move counter

 **Memory Management**
- No memory leaks (valgrind verified)
- Proper cleanup on exit
- Safe memory allocation patterns

 **Error Handling**
- Comprehensive validation
- User-friendly error messages
- Clean program termination

### Technical Highlights

**Flood Fill Algorithm:**
Implemented recursive flood fill to validate that all collectibles and the exit are reachable from the player's starting position.

**Memory Optimization:**
Resolved MiniLibX memory corruption by adding padding to game structure - a common issue when interfacing with external graphics libraries.

**Event-Driven Architecture:**
Clean separation between game logic, rendering, and input handling using MiniLibX hooks.

---


## Resources

- https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181 <br>
- https://www.pcmag.com/encyclopedia/term/x-window <br>
- https://www.youtube.com/watch?v=bYS93r6U0zg <br>
- https://gontjarow.github.io/MiniLibX/mlx.html <br>
- https://askubuntu.com/questions/7881/what-is-the-x-server <br>
- (most useful)https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx<br>

### Tools Used

- **Valgrind** - Memory leak detection and debugging
- **Norminette** - 42 coding standard checker
- **GDB** - Debugging
- **VS Code** - Development environment

### AI Usage

AI (Claude) was used as a **teaching assistant and debugging partner** throughout this project:

**Tasks AI Assisted With:**
- **Conceptual Understanding:** Explaining MiniLibX functions, flood fill algorithm, and memory management patterns
- **Debugging Guidance:** Step-by-step debugging methodology for memory corruption and coordinate system issues
- **Code Review:** Identifying logic errors in flood fill implementation and rendering loops
- **Best Practices:** Norm compliance, proper error handling, and clean code architecture

**Parts AI Helped With:**
- Understanding the flood fill algorithm logic and recursive implementation
- Debugging the MiniLibX memory corruption issue (led to padding solution)
- Clarifying x/y coordinate mapping between map arrays and screen positions
- Explaining event-driven programming with MiniLibX hooks

**What Was NOT Done by AI:**
- All code was written by hand (AI provided guidance, not copy-paste solutions)
- Map validation logic designed independently
- Game mechanics and movement system implemented from scratch
- Debugging process conducted personally with AI as a guide

**Learning Approach:**
AI was used in a Socratic teaching method - asking guiding questions, explaining concepts, and helping trace through logic rather than providing direct solutions. This ensured deep understanding of every component.

**Prompt Used:**
act like a guiding teacher, walk me through steps to build the given project step by step with explanation of key concepts to be acquired, also questions to test my understanding. start with explaining the complete journey, then the  guide one by one where you should wait for my confirmation to move to the next step. don't present any code, i want to build the code by myself. the outcome should be a fully functioning code ready to be submitted along with a readme.md file.after we're done ask me to upload the code so you can evaluate it like a 42school molunitte would

---

## Known Limitations

- Maps larger than screen resolution are rejected
- Only supports `.xpm` image format
- Single-player only
- No animation or sprite rotation

---

