#include <unordered_map>
#include <string>

class SymbolTable {
    std::unordered_map<std::string, std::string> symbols; // {nombre: tipo}
public:
    void addSymbol(const std::string& name, const std::string& type) {
        symbols[name] = type;
    }
    
    std::string getType(const std::string& name) {
        return symbols.count(name) ? symbols[name] : "";
    }
    
    bool exists(const std::string& name) {
        return symbols.count(name) > 0;
    }
};
