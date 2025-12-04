# Complex Multi-Language IDE

A sophisticated code editor built with C++ that supports multiple programming languages with a modern UI similar to Visual Studio Code.

## Features

- **Multi-Language Support**: Supports 8 programming languages:
  - C++
  - Python
  - JavaScript
  - Java
  - C#
  - Ruby
  - PHP
  - Go

- **Modern UI**: Interface designed to resemble Visual Studio Code with:
  - File explorer panel
  - Code editor area
  - Menu and toolbar
  - Status bar
  - Syntax highlighting

- **Core Functionality**:
  - File creation and editing
  - Syntax highlighting for all supported languages
  - File saving and loading
  - Language detection

## Getting Started

### Prerequisites

- C++17 compatible compiler
- CMake 3.10 or higher
- Make

### Building the Project

```bash
# Clone or navigate to the project directory
cd /workspace

# Build the project
cmake .
make
```

### Running the IDE

Use the start-now script to launch the application:

```bash
./start-now
```

Or run directly:
```bash
./build/ide_app
```

## Architecture

The IDE is built with a modular architecture:

- `TextEditor`: Core editor functionality
- `LanguageManager`: Handles language-specific features
- `EditorUI`: Modern UI components similar to VS Code
- `IDEApp`: Main application class

## Languages Supported

Each language includes:
- Syntax highlighting
- Keyword recognition
- File extension association
- Color coding

## Usage

The IDE provides a VS Code-like experience with:
- File explorer on the left
- Main code editing area
- Status bar at the bottom
- Menu and toolbar for actions

## File Structure

```
/workspace/
├── src/                    # Source files
│   ├── main.cpp            # Main application entry point
│   ├── editor.cpp          # Text editor implementation
│   ├── language_support.cpp # Language support functionality
│   └── ui_components.cpp   # UI components
├── include/                # Header files
│   └── ide.h               # Main header file
├── build/                  # Build output directory
├── CMakeLists.txt          # Build configuration
├── start-now               # Launch script
└── README.md               # This file
```

## License

This project is licensed under the terms provided in the LICENSE file.