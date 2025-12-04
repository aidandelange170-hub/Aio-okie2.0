#include "../include/ide.h"
#include <fstream>
#include <iostream>

TextEditor::TextEditor() : content(""), currentLanguage(Language::CPP), isModified(false) {
}

void TextEditor::setContent(const std::string& text) {
    content = text;
    isModified = true;
}

std::string TextEditor::getContent() const {
    return content;
}

void TextEditor::setLanguage(Language lang) {
    currentLanguage = lang;
}

Language TextEditor::getLanguage() const {
    return currentLanguage;
}

bool TextEditor::isContentModified() const {
    return isModified;
}

void TextEditor::saveFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        isModified = false;
        std::cout << "File saved: " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
    }
}

void TextEditor::loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        content = "";
        std::string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        isModified = false;
        std::cout << "File loaded: " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file for reading: " << filename << std::endl;
    }
}

void TextEditor::highlightSyntax() {
    // Basic syntax highlighting implementation
    std::cout << "Applying syntax highlighting for: ";
    switch (currentLanguage) {
        case Language::CPP:
            std::cout << "C++" << std::endl;
            break;
        case Language::PYTHON:
            std::cout << "Python" << std::endl;
            break;
        case Language::JAVASCRIPT:
            std::cout << "JavaScript" << std::endl;
            break;
        case Language::JAVA:
            std::cout << "Java" << std::endl;
            break;
        case Language::CSHARP:
            std::cout << "C#" << std::endl;
            break;
        case Language::RUBY:
            std::cout << "Ruby" << std::endl;
            break;
        case Language::PHP:
            std::cout << "PHP" << std::endl;
            break;
        case Language::GOLANG:
            std::cout << "Go" << std::endl;
            break;
    }
}