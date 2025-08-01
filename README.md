# C++ Template

A simple VScode C++ "Hello, World!" template using CMake.

## First-Time Setup on Windows

This template is configured to use the g++ compiler. For the VS Code linter (`clangd`) to work correctly on Windows, you must tell it where to find your g++ compiler.

1.  Open the `.vscode/settings.json` file.
2.  Replace the placeholder path `C:/PATH/TO/YOUR/gcc/bin/g++.exe` with the absolute path to your `g++.exe`.
3.  Restart clangd language server.

## Building and Running

1.  **Build Cmake:**
    ```
    Run the task in VScode called CMake Build
    ```

2.  **Build The Project:**
    ```
    Press f5 or ctrl f5. It should prompt you to choose a target (windows or mac). You can build and configure the project for release and debug.
    ```
