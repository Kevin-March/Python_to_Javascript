#include <string>

class TypeChecker {
public:
    static std::string inferType(const std::string& value) {
        if (value == "true" || value == "false") return "bool";
        if (value.find('"') != std::string::npos) return "string";
        if (value.find('.') != std::string::npos) return "float";
        return "int"; // Por defecto
    }
};