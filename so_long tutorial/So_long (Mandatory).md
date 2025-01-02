### **1. Map Parsing**

#### **Map Format and Validations:**

The map is a 2D grid, which will be represented in a `.ber` file. It contains five possible characters:

- `1`: Wall
- `0`: Free space
- `C`: Collectible
- `E`: Exit
- `P`: Player's starting position

**The map must adhere to these rules**:

- **Rectangular shape**: All rows must be the same length.
- **Surrounded by walls**: The outermost characters in the grid must be walls (`1`).
- **One exit (`E`)**: There must be exactly one exit on the map.
- **At least one collectible (`C`)**: There must be at least one collectible item.
- **One starting position (`P`)**: The player's start position should be represented by `P`.
- **Valid path from start to exit**: Ensure there is a way for the player to move from the start position (`P`) to the exit (`E`), collecting any collectibles along the way.
- **No duplicate characters**: If there are multiple `P`s or `E`s, the map is invalid.

#### **Steps for map validation**:

- Open the map file and read its contents.
- Check for rectangular shape by verifying that all rows are of the same length.
- Ensure the outer boundary of the map consists of `1` (walls).
- Parse through the map to count the occurrences of `P`, `E`, and `C`. If there are any duplicates or missing essential elements, throw an error.
- Implement a **flood fill algorithm** to check if there is a valid path from `P` to `E`. This can be done using Depth-First Search (DFS) or Breadth-First Search (BFS).