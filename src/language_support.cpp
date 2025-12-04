#include "../include/ide.h"
#include <iostream>

LanguageManager::LanguageManager() {
    initializeLanguages();
}

void LanguageManager::initializeLanguages() {
    // Initialize C++ language
    LanguageInfo cppInfo;
    cppInfo.name = "C++";
    cppInfo.extension = ".cpp";
    cppInfo.color = "#005977";
    cppInfo.keywords = {"#include", "int", "char", "float", "double", "bool", "true", "false", 
                        "if", "else", "for", "while", "do", "switch", "case", "break", 
                        "continue", "return", "void", "class", "struct", "public", "private", 
                        "protected", "static", "const", "virtual", "new", "delete", "try", 
                        "catch", "throw", "namespace", "using", "template", "typename"};
    languages[Language::CPP] = cppInfo;

    // Initialize Python language
    LanguageInfo pythonInfo;
    pythonInfo.name = "Python";
    pythonInfo.extension = ".py";
    pythonInfo.color = "#306998";
    pythonInfo.keywords = {"def", "class", "if", "elif", "else", "for", "while", "break", 
                           "continue", "return", "import", "from", "as", "try", "except", 
                           "finally", "with", "lambda", "and", "or", "not", "is", "in", 
                           "True", "False", "None", "global", "nonlocal", "del", "pass", 
                           "yield", "assert", "raise"};
    languages[Language::PYTHON] = pythonInfo;

    // Initialize JavaScript language
    LanguageInfo jsInfo;
    jsInfo.name = "JavaScript";
    jsInfo.extension = ".js";
    jsInfo.color = "#F0DB4F";
    jsInfo.keywords = {"var", "let", "const", "function", "if", "else", "for", "while", 
                       "do", "switch", "case", "break", "continue", "return", "try", 
                       "catch", "finally", "throw", "new", "this", "typeof", "instanceof", 
                       "in", "of", "class", "extends", "super", "import", "export", 
                       "default", "async", "await", "true", "false", "null", "undefined"};
    languages[Language::JAVASCRIPT] = jsInfo;

    // Initialize Java language
    LanguageInfo javaInfo;
    javaInfo.name = "Java";
    javaInfo.extension = ".java";
    javaInfo.color = "#ED8B00";
    javaInfo.keywords = {"abstract", "assert", "boolean", "break", "byte", "case", "catch", 
                         "char", "class", "const", "continue", "default", "do", "double", 
                         "else", "enum", "extends", "final", "finally", "float", "for", 
                         "goto", "if", "implements", "import", "instanceof", "int", 
                         "interface", "long", "native", "new", "package", "private", 
                         "protected", "public", "return", "short", "static", "strictfp", 
                         "super", "switch", "synchronized", "this", "throw", "throws", 
                         "transient", "try", "void", "volatile", "while", "true", "false", "null"};
    languages[Language::JAVA] = javaInfo;

    // Initialize C# language
    LanguageInfo csharpInfo;
    csharpInfo.name = "C#";
    csharpInfo.extension = ".cs";
    csharpInfo.color = "#239120";
    csharpInfo.keywords = {"abstract", "as", "base", "bool", "break", "byte", "case", "catch", 
                           "char", "checked", "class", "const", "continue", "decimal", "default", 
                           "delegate", "do", "double", "else", "enum", "event", "explicit", 
                           "extern", "false", "finally", "fixed", "float", "for", "foreach", 
                           "goto", "if", "implicit", "in", "int", "interface", "internal", 
                           "is", "lock", "long", "namespace", "new", "null", "object", "operator", 
                           "out", "override", "params", "private", "protected", "public", "readonly", 
                           "ref", "return", "sbyte", "sealed", "short", "sizeof", "stackalloc", 
                           "static", "string", "struct", "switch", "this", "throw", "true", 
                           "try", "typeof", "uint", "ulong", "unchecked", "unsafe", "ushort", 
                           "using", "virtual", "void", "volatile", "while"};
    languages[Language::CSHARP] = csharpInfo;

    // Initialize Ruby language
    LanguageInfo rubyInfo;
    rubyInfo.name = "Ruby";
    rubyInfo.extension = ".rb";
    rubyInfo.color = "#CC342D";
    rubyInfo.keywords = {"BEGIN", "END", "__ENCODING__", "__FILE__", "__LINE__", "alias", 
                         "and", "begin", "break", "case", "class", "def", "defined?", "do", 
                         "else", "elsif", "end", "ensure", "false", "for", "if", "in", 
                         "module", "next", "nil", "not", "or", "redo", "rescue", "retry", 
                         "return", "self", "super", "then", "true", "undef", "unless", 
                         "until", "when", "while", "yield"};
    languages[Language::RUBY] = rubyInfo;

    // Initialize PHP language
    LanguageInfo phpInfo;
    phpInfo.name = "PHP";
    phpInfo.extension = ".php";
    phpInfo.color = "#777BB4";
    phpInfo.keywords = {"abstract", "and", "array", "as", "break", "callable", "case", "catch", 
                        "class", "clone", "const", "continue", "declare", "default", "die", 
                        "do", "echo", "else", "elseif", "empty", "enddeclare", "endfor", 
                        "endforeach", "endif", "endswitch", "endwhile", "eval", "exit", 
                        "extends", "final", "finally", "for", "foreach", "function", "global", 
                        "goto", "if", "implements", "include", "include_once", "instanceof", 
                        "insteadof", "interface", "isset", "list", "namespace", "new", "or", 
                        "print", "private", "protected", "public", "require", "require_once", 
                        "return", "static", "switch", "throw", "trait", "try", "unset", 
                        "use", "var", "while", "xor", "yield"};
    languages[Language::PHP] = phpInfo;

    // Initialize Go language
    LanguageInfo goInfo;
    goInfo.name = "Go";
    goInfo.extension = ".go";
    goInfo.color = "#00ADD8";
    goInfo.keywords = {"break", "case", "chan", "const", "continue", "default", "defer", "else", 
                       "fallthrough", "for", "func", "go", "goto", "if", "import", "interface", 
                       "map", "package", "range", "return", "select", "struct", "switch", 
                       "type", "var", "true", "false", "iota", "nil"};
    languages[Language::GOLANG] = goInfo;
}

LanguageInfo LanguageManager::getLanguageInfo(Language lang) const {
    auto it = languages.find(lang);
    if (it != languages.end()) {
        return it->second;
    }
    // Return C++ info as default if language not found
    return languages.at(Language::CPP);
}

std::vector<Language> LanguageManager::getSupportedLanguages() const {
    std::vector<Language> result;
    for (const auto& pair : languages) {
        result.push_back(pair.first);
    }
    return result;
}