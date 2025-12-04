#include "../include/ide.h"
#include <iostream>

EditorUI::EditorUI(TextEditor* ed, LanguageManager* lm) : editor(ed), langManager(lm) {
}

void EditorUI::render() {
    std::cout << "\n=== Complex Multi-Language IDE ===" << std::endl;
    std::cout << "Modern UI similar to Visual Studio Code" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    showMenuBar();
    showToolBar();
    showFileExplorer();
    showCodeEditor();
    showStatusBar();
}

void EditorUI::handleInput() {
    std::cout << "Handling user input..." << std::endl;
    // In a real implementation, this would handle keyboard and mouse events
}

void EditorUI::showMenuBar() {
    std::cout << "\n[FILE] [EDIT] [VIEW] [RUN] [TOOLS] [HELP]" << std::endl;
}

void EditorUI::showToolBar() {
    std::cout << "[New File] [Open] [Save] [Save As] [Undo] [Redo] [Cut] [Copy] [Paste]" << std::endl;
}

void EditorUI::showStatusBar() {
    Language currentLang = editor->getLanguage();
    LanguageInfo langInfo = langManager->getLanguageInfo(currentLang);
    std::cout << "\nStatus: Ready | Language: " << langInfo.name 
              << " | Lines: 1 | Position: 1:1" << std::endl;
}

void EditorUI::showFileExplorer() {
    std::cout << "\n[Explorer]\n  ├── src/\n  │   ├── main.cpp\n  │   ├── editor.cpp\n  │   └── language_support.cpp\n  ├── include/\n  │   └── ide.h\n  └── start-now" << std::endl;
}

void EditorUI::showCodeEditor() {
    std::cout << "\n[Code Editor - " << langManager->getLanguageInfo(editor->getLanguage()).name << "]" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "// Welcome to the Complex Multi-Language IDE" << std::endl;
    std::cout << "// This is a modern code editor similar to Visual Studio Code" << std::endl;
    std::cout << "// Currently supporting 8 programming languages:" << std::endl;
    std::cout << "// C++, Python, JavaScript, Java, C#, Ruby, PHP, Go" << std::endl;
    std::cout << std::endl;
    std::cout << "int main() {" << std::endl;
    std::cout << "    std::cout << \"Hello, World!\" << std::endl;" << std::endl;
    std::cout << "    return 0;" << std::endl;
    std::cout << "}" << std::endl;
}

IDEApp::IDEApp() : editor(nullptr), langManager(nullptr), ui(nullptr) {
}

IDEApp::~IDEApp() {
    if (ui) delete ui;
    if (editor) delete editor;
    if (langManager) delete langManager;
}

void IDEApp::initialize() {
    std::cout << "Initializing IDE components..." << std::endl;
    
    editor = new TextEditor();
    langManager = new LanguageManager();
    ui = new EditorUI(editor, langManager);
    
    std::cout << "IDE initialized successfully!" << std::endl;
    std::cout << "Supported languages: ";
    auto langs = langManager->getSupportedLanguages();
    for (size_t i = 0; i < langs.size(); ++i) {
        std::cout << langManager->getLanguageInfo(langs[i]).name;
        if (i < langs.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl << std::endl;
}

void IDEApp::run() {
    std::cout << "Running IDE application..." << std::endl;
    ui->render();
    
    // Simulate running the main event loop
    std::cout << "\nIDE is now running. Press any key to continue..." << std::endl;
    // In a real implementation, this would be the main event loop
}

void IDEApp::shutdown() {
    std::cout << "\nShutting down IDE..." << std::endl;
    std::cout << "Goodbye! Thanks for using Complex Multi-Language IDE." << std::endl;
}