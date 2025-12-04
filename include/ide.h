#ifndef IDE_H
#define IDE_H

#include <string>
#include <vector>
#include <map>

// Enum for supported programming languages
enum class Language {
    CPP,
    PYTHON,
    JAVASCRIPT,
    JAVA,
    CSHARP,
    RUBY,
    PHP,
    GOLANG
};

// Structure to hold language information
struct LanguageInfo {
    std::string name;
    std::string extension;
    std::string color;
    std::vector<std::string> keywords;
};

class TextEditor {
private:
    std::string content;
    Language currentLanguage;
    bool isModified;

public:
    TextEditor();
    void setContent(const std::string& text);
    std::string getContent() const;
    void setLanguage(Language lang);
    Language getLanguage() const;
    bool isContentModified() const;
    void saveFile(const std::string& filename);
    void loadFile(const std::string& filename);
    void highlightSyntax();
};

class LanguageManager {
private:
    std::map<Language, LanguageInfo> languages;

public:
    LanguageManager();
    LanguageInfo getLanguageInfo(Language lang) const;
    std::vector<Language> getSupportedLanguages() const;
    void initializeLanguages();
};

class UIComponent {
public:
    virtual void render() = 0;
    virtual void handleInput() = 0;
};

class EditorUI : public UIComponent {
private:
    TextEditor* editor;
    LanguageManager* langManager;

public:
    EditorUI(TextEditor* ed, LanguageManager* lm);
    void render() override;
    void handleInput() override;
    void showMenuBar();
    void showToolBar();
    void showStatusBar();
    void showFileExplorer();
    void showCodeEditor();
};

class IDEApp {
private:
    TextEditor* editor;
    LanguageManager* langManager;
    EditorUI* ui;

public:
    IDEApp();
    ~IDEApp();
    void initialize();
    void run();
    void shutdown();
};

#endif // IDE_H