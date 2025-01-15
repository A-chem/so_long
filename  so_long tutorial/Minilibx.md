**MiniLibX** is a small library used to create graphical applications, mostly in educational projects like **42 School**. It helps you make windows, draw shapes, and handle user input (like keyboard or mouse actions). It provides easy-to-use functions that let you work with graphics without having to deal with complex graphics systems directly.

When using **MiniLibX** on macOS, the library interacts with [[AppKit]] and [[OpenGL]] to create windows and render graphics

- **Window Creation**: MiniLibX calls functions from **AppKit** to create a window. This window will be managed by the operating system, allowing user interaction like resizing or closing.
    
- **Graphics Rendering**: Once the window is created, MiniLibX uses **OpenGL** to render graphical content in that window. OpenGL provides efficient ways to draw shapes, load images, or render animations.
    
- **Event Handling**: AppKit listens for events like key presses, mouse movements, or window closing. MiniLibX provides a way to handle these events, letting you define custom behavior for each type of event.

[[Quartz]] is the foundation of everything. It's the actual system in macOS that handles pixels and graphics rendering. But you **don’t interact with Quartz directly** in most cases.

 **AppKit** is built on top of Quartz. It makes it easier to create and manage windows, handle user input, and so on. So, when you want to open a window, you use **AppKit** functions.

 **OpenGL** sits on top of Quartz as well. It provides a powerful and easy way to draw complex graphics on the screen, like 2D shapes or 3D models.

**MiniLibX** abstracts (hides) all the complexity of Quartz, AppKit, and OpenGL. It lets you use simple functions to:
	 Create a window with **AppKit**.
	 Draw on that window using **OpenGL**.
    
You don’t need to worry about the lower-level details of how **Quartz** is being used, because **MiniLibX** takes care of that for you.

### Why don’t you need to deal with **Quartz** directly?

Quartz is the core system that works under everything, but it’s very low-level, meaning it requires a lot of detailed code to do even simple tasks like drawing on the screen. Instead of making you write all that low-level code, **MiniLibX** uses Quartz for you under the hood. You just use **AppKit** for window management and **OpenGL** for drawing.

MiniLibX abstracts all that complexity, so you don't need to worry about Quartz. You just call **MiniLibX** functions to create a window and draw, and **MiniLibX** handles all the behind-the-scenes Quartz details for you.


How MiniLibX Works

## How does **MiniLibX** work?
#### **1. Starting the Program**

You write a MiniLibX program in C and start it with the `mlx_init()` function:

`void *mlx = mlx_init();`

- **What Happens Internally**:
    **1. MiniLibX Initializes Its Internal Data Structures**

- MiniLibX needs to manage:
    - The connection to macOS’s [[Graphics system]].
    - Any windows you create.
    - Input events (like key presses or mouse clicks).
    - The rendering process (drawing shapes, images, or pixels).

To do this:

1. **Allocate Memory**:
    - MiniLibX creates internal data structures to store information about your program's windows, rendering settings, and user input hooks.
2. **Set Up OpenGL**:
    - MiniLibX initializes an OpenGL context. This is like setting up a "workspace" for the [[GPU]] to draw things later.
3. **Prepare AppKit Communication**:
    - MiniLibX sets up the connection with AppKit, which is macOS’s framework for handling windows and user input.

---

**2. MiniLibX Connects to AppKit**

When `mlx_init()` runs:

1. **Connection Request**:
    
    - MiniLibX sends a request to AppKit to establish a connection.  
        Think of this as saying, "Hey AppKit, I’m going to create and manage some windows. Can we talk?"
2. **Context Setup**:
    
    - AppKit prepares its resources for this program. It ensures MiniLibX has permission to create windows and receive events.
3. **OpenGL and AppKit Coordination**:
    
    - AppKit ensures that OpenGL rendering will work within its windows. This is important because OpenGL doesn’t manage windows directly—it only handles drawing.

---

 **3. AppKit Communicates with the WindowServer**

- **What is the WindowServer?**
    - The WindowServer is a core macOS service responsible for managing all the windows on the screen.
    - Every application (e.g., Finder, Safari, your MiniLibX program) talks to the WindowServer to display its windows.

When AppKit sets up its connection to the WindowServer:

1. **Register the Application**:
    - AppKit tells the WindowServer that your MiniLibX program wants to create a window.
2. **Reserve Resources**:
    - The WindowServer allocates memory and resources for any windows your program might create.
3. **Input Handling**:
    - The WindowServer prepares to route events (like keyboard or mouse inputs) from your MiniLibX windows back to your program.

---

**What Happens If `mlx_init()` Fails?**

If something goes wrong during initialization:

1. **No AppKit Connection**:
    - If MiniLibX cannot connect to AppKit, it won’t be able to create windows. The program might crash or return an error.
2. **No OpenGL Support**:
    - If OpenGL is not available or fails to initialize, MiniLibX cannot draw graphics, and your program will fail to run

#### **2. Creating a Window**

When you call `mlx_new_window()`, MiniLibX creates a new window on your screen:

`void *win = mlx_new_window(mlx, 800, 600, "My Window");`

- **What Happens Internally**:
    1. **Request to AppKit**:
    
    - MiniLibX calls `mlx_new_window()` and passes the window size (800x600) and the window title ("My Window").
    - This request is forwarded by MiniLibX to AppKit, which is responsible for managing the graphical interface on macOS.
2. **Interaction with WindowServer**:
    
    - AppKit communicates with the **WindowServer**, which is the system component that manages the layout and visibility of all open windows in the macOS environment.
    - The WindowServer allocates the necessary resources (memory, graphical buffers) for the new window and ensures that it is ready to be displayed on the screen.
    - It then makes the window visible, so users can interact with it.
3. **Quartz Compositor**:
    
    - The [[Quartz Compositor]] is responsible for composing the various elements of the graphical interface and ensuring that everything is drawn correctly.
    - It handles the layering of windows, making sure the new window appears on top of or below other windows as necessary, and ensures no conflicts in the visual overlap.
    - It also manages transparency, animations, and other effects related to how the windows are displayed.

In summary, MiniLibX acts as an intermediary that calls higher-level functions (like `mlx_new_window()`) to interact with macOS’s AppKit, which then interacts with the WindowServer and the Quartz Compositor to manage window creation, visibility, and layering.

---


#### **3. Drawing Something**

You use MiniLibX’s drawing functions to put graphics in the window. For example:

`mlx_pixel_put(mlx, win, 400, 300, 0xFF0000);`

- **What Happens Internally**:
    - **MiniLibX Converts the Command into OpenGL Instructions**:
    
    - When you call `mlx_pixel_put()`, which requests that a pixel be drawn on the screen, MiniLibX translates this command into OpenGL commands. OpenGL is a powerful graphics library that interfaces directly with the GPU to perform rendering tasks.
    - In this case, `mlx_pixel_put(mlx, win, 400, 300, 0xFF0000)` will translate the request to OpenGL instructions that represent drawing a single red pixel at coordinates (400, 300).
- **OpenGL Sends Instructions to the GPU**:
    
    - OpenGL communicates with the **GPU (Graphics Processing Unit)**, which is responsible for rendering graphics on the screen. OpenGL tells the GPU to place the red pixel at the specified location (400, 300).
    - The color value `0xFF0000` represents red in RGB format (with 8 bits for each color channel). It is passed to the GPU as the color to be applied to the pixel.
- **FrameBuffer Storage**:
    
    - The [[framebuffer]] is a region of memory used to store an image (or frame) that is being prepared to be displayed on the screen.
    - The GPU writes the red pixel at coordinates (400, 300) into the framebuffer. Essentially, the framebuffer is a 2D array of pixel data (colors) that represent the current screen contents.
- **Quartz Compositor Reads the Framebuffer**:
    
    - After OpenGL finishes drawing the pixel to the framebuffer, the **Quartz Compositor** (as part of macOS's windowing system) takes over.
    - The Quartz Compositor reads the framebuffer to retrieve the current image content, including the red pixel you just drew.
    - It then composites this data into the final image that will be displayed on the screen. The compositing process ensures that the image appears properly, with window layering, transparency, and other effects applied.
- **Final Image Display**:
    
    - Once the Quartz Compositor has composed the final image, it sends this data to the screen for display. The result is the graphical output you see, with the red pixel at position (400, 300) on the window.

---
 When you call `mlx_pixel_put()`, the command is passed through several layers of the graphics stack:

- MiniLibX converts the command into OpenGL instructions.
- OpenGL communicates with the GPU to update the framebuffer with the pixel.
- The Quartz Compositor reads the framebuffer, compositing the image for display.
- Finally, the image is shown on the screen.
#### **4. Displaying Graphics**

Once the pixel is drawn, the **Quartz Compositor** ensures it appears correctly on the screen:

- **What Happens Internally**:
    1. **Framebuffer Creation**: Your program draws to the framebuffer, where each pixel is stored.
    2. **Compositing**: The Quartz Compositor combines your framebuffer with other windows and UI elements, applying any necessary effects or transformations.
    3. **GPU Rendering**: The composited image is sent to the GPU, which finalizes the rendering process.
    4. **Display**: The GPU renders the final image to the screen, updating what is visible to the user.

---

#### **5. Handling User Input**

MiniLibX allows you to handle keyboard and mouse input using hooks. For example:

`mlx_key_hook(win, my_key_function, NULL); mlx_loop(mlx);`

- **What Happens Internally**:
    1. The `mlx_key_hook()` function sets up a callback for key presses.
    2. The `mlx_loop()` function listens for events.
    3. When a key is pressed, the **WindowServer** detects it and sends the event to your program via AppKit.
    4. MiniLibX executes your callback function (`my_key_function`).

---
## **MiniLibX** functions
### **1. Initialization**

#### `mlx_init`

- **Prototype**: `void *mlx_init();`
- **Purpose**:
	- `mlx_init` establishes a connection with the graphical server 
	- It sets up the MiniLibX library for further use, allowing you to create windows, handle events, and manage graphical elements.
	- When `mlx_init` is called, it initializes the necessary resources and returns a pointer that represents the MiniLibX instance.
	- This pointer will be passed as an argument to most other MiniLibX functions, like `mlx_new_window`, `mlx_new_image`, and `mlx_hook`.
- **Returns**: 
	- **Success:** Returns a pointer to the initialized MiniLibX instance.
	- **Failure:** Returns `NULL` if the initialization fails. This might happen if the connection to the graphical server cannot be established.

---

### **2. Window Management**

#### `mlx_new_window`

- **Prototype**: `void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);`
- **Purpose**: Creates a new window with the specified dimensions and title.
- **Parameters**:
    - `mlx_ptr`: The pointer returned by `mlx_init` that represents the MiniLibX instance.
    - `width`: The desired width of the window in pixels.
    - `height`: The desired height of the window in pixels.
    - `title`: Title of the window.
- **Returns**: 
	- A pointer to the created window, which is required for other window-related functions.
	- Returns `NULL` if the window creation fails.

### `mlx_clear_window`

- **Prototype**: `int mlx_clear_window(void *mlx_ptr, void *win_ptr);`
- **Purpose**: 
	- Clears the content of the specified window. This is useful when you want to redraw or refresh the window's content.
- **Parameters**:
    - `mlx_ptr`: MiniLibX instance pointer.
    - `win_ptr`: The pointer to the window to be cleared.

### `mlx_destroy_window`

- **Prototype**: `int mlx_destroy_window(void *mlx_ptr, void *win_ptr);`
- **Purpose**: 
	- Closes the specified window and frees any resources associated with it.
- **Parameters**:
    - `mlx_ptr`: MiniLibX instance pointer.
    - `win_ptr`: The pointer to the window to be destroyed.

---

## **3. Drawing Functions**

### `mlx_pixel_put`

- **Prototype**: `int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);`
- **Purpose**: Draws a single pixel at the specified `(x, y)` coordinates in the given window.
- **Parameters**:
    - `mlx_ptr`: Pointer to the MiniLibX instance initialized with `mlx_init`.
    - `win_ptr`: Pointer to the window where the pixel will be drawn. This is created with `mlx_new_window`.
    - `x, y`: 
	    Coordinates of the pixel, measured in pixels.
		- The origin `(0, 0)` is at the **top-left corner** of the window.
		- `x` increases as you move right, and `y` increases as you move down.
	- `color`:
		Hexadecimal value representing the color of the pixel.
		- Format: `0xRRGGBB` (e.g., `0xFF0000` for red, `0x00FF00` for green, `0x0000FF` for blue)
- **Performance**: Slow for many pixels; better to use images for efficiency.
- **Returns**
	- Always returns `0`, but no meaningful error handling is provided in MiniLibX
- **Performance Considerations**
	- **Inefficiency for Large Drawings**:
	    - `mlx_pixel_put` is relatively **slow**, especially for drawing many pixels.
	    - For better performance, use images (`mlx_new_image`, `mlx_put_image_to_window`) to manipulate and display large groups of pixels efficiently.

---

### **4. Image Management**

#### **`mlx_xpm_file_to_image()`**

- **Prototype**: `void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);`
- **Purpose**: Loads an image from a file (XPM format) and converts it into a format that MiniLibX can work with.
- **Parameters**:
    - `mlx_ptr`: The MLX instance pointer.
    - `filename`: Path to the XPM image file.
    - `width`: A pointer to an integer where the width of the image will be stored.
    - `height`: A pointer to an integer where the height of the image will be stored.
- **Return Type**: `void *` — A pointer to the image object, which can be used to render the image on the window.


#### `mlx_put_image_to_window()`

- **Prototype**: `int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`
- **Purpose**: Displays the loaded image on the window at a specified position (X, Y coordinates).
- **Parameters**:
    - `mlx_ptr`: The MLX instance pointer.
    - `win_ptr`: The window pointer where the image will be displayed.
	- `img_ptr`: The image pointer obtained from `mlx_xpm_file_to_image()`.
	- `x`: The X-coordinate on the window where the image will be placed.
	- `y`: The Y-coordinate on the window where the image will be placed.
- **Return Type**: `int` — Returns `0` on success, non-zero on failure.
#### `mlx_new_image`

- **Prototype**: `void *mlx_new_image(void *mlx_ptr, int width, int height);`
- **Purpose**: Creates a new blank image of specified dimensions for pixel manipulation.
- **Parameters**:
    - `mlx_ptr`: The MiniLibX instance pointer, obtained from `mlx_init`.
	- `width, height`: Dimensions of the image in pixels.
- **Returns**: 
	- A pointer to the created image.
	- Returns `NULL` if the image creation fails.

#### `mlx_get_data_addr`

- **Prototype**: `char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);`
- **Purpose**: Provides access to the raw pixel data of the image for direct manipulation.
- **Parameters**:
    - `img_ptr`: The pointer to the image created with `mlx_new_image`.
	- `bits_per_pixel`: Pointer to an integer where the number of bits per pixel will be stored (e.g., 32 for RGBA).
	- `size_line`: Pointer to an integer where the number of bytes per row of pixels will be stored.
	- `endian`: Pointer to an integer where the endian-ness of the image will be stored:
		- `0` = Little-endian.
		- `1` = Big-endian.
- **Returns**: A pointer to the image's data.

### `mlx_destroy_image`

- **Prototype**: `int mlx_destroy_image(void *mlx_ptr, void *img_ptr);`
- **Purpose**: Frees resources associated with an image.
- **Parameters**:
    - `mlx_ptr`: MiniLibX instance pointer.
    - `img_ptr`: Image pointer.

---

## **5. Event Handling**

### `mlx_loop`

- **Prototype**: `int mlx_loop(void *mlx_ptr);`
- **Purpose**: Starts the event loop, keeping the program running to listen for events.
- **Parameters**:
    - `mlx_ptr`: MiniLibX instance pointer.
- **Behavior**: This function blocks indefinitely and waits for user events (e.g., keyboard or mouse input).

### `mlx_hook`

- **Prototype**: `int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param);`
- **Purpose**: Sets a callback function for a specific event type.
- **Parameters**:
    - `win_ptr`: Window pointer.
    - `x_event`: The event type (e.g., key press, mouse click).
    - `x_mask`: Bitmask for the event (e.g., `1L<<0` for key press).
    - `funct_ptr`: Pointer to the callback function.
    - `param`: Additional parameter passed to the callback function.

**Common Events**:

- `2`: Key Press.
- `3`: Key Release.
- `4`: Mouse Button Press.
- `5`: Mouse Button Release.
- `6`: Mouse Movement.
- `17`: Window Close.

### `mlx_loop_hook`

- **Prototype**: `int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);`
- **Purpose**: Sets a callback function that runs on every iteration of the event loop.
- **Parameters**:
    - `mlx_ptr`: MiniLibX instance pointer.
    - `funct_ptr`: Callback function.
    - `param`: Additional parameter passed to the callback function.

### `mlx_key_hook`

- **Prototype**: `int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);`
- **Purpose**: Simplifies event handling for key presses by directly assigning a callback.
- **Parameters**:
    - `win_ptr`: The window pointer created by `mlx_new_window()`.
    - `funct_ptr`: Callback function for key presses.
    - `param`:A pointer to data that will be passed to the callback function.

#### **`mlx_mouse_hook()`**

 - **Prototype**: `int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);`
- **Purpose**: Registers a function to be called whenever a mouse button is pressed.
- **Parameters**:
    - `win_ptr`: The window pointer created by `mlx_new_window()`.
    - `funct_ptr`: A pointer to the callback function that will handle the mouse events.
    - `param`: A pointer to data that will be passed to the callback function.
- **Return Type**: `int` — Returns `0` on success.
---

## **6. Colors**

MiniLibX represents colors using 32-bit integers in the format `0xRRGGBB` or `0xAARRGGBB`:

- `RR`: Red channel.
- `GG`: Green channel.
- `BB`: Blue channel.
- `AA` (optional): Alpha channel (transparency).

---

## **7. Keyboard and Mouse**

MiniLibX allows interaction via keyboard and mouse.

- **Key Codes**: Check key codes for your system to handle specific key inputs.
    - Example: Escape key on macOS is `53`.
- **Mouse Codes**: Mouse buttons are numbered (e.g., `1` for left-click, `2` for right-click).

---

## **8. Utility Functions**

### `mlx_string_put`

- **Prototype**: `int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);`
- **Purpose**: Puts a string of text on the window at a specified position.
- **Parameters**:
    - `mlx_ptr`: The MLX instance pointer.
    - `win_ptr`: The window pointer.
    - `x`: The X-coordinate where the text will start.
    - `y`: The Y-coordinate where the text will start.
    - `color`: The color of the text (in hexadecimal format, like `0xFFFFFF` for white).
    - `string`: The string of text to display.
- **Return Type**: `int` — Returns `0` on success.


---

## **9. Cleanup**

Always free resources before exiting your program:

1. Destroy windows (`mlx_destroy_window`).
2. Destroy images (`mlx_destroy_image`).
3. Exit the program gracefully.