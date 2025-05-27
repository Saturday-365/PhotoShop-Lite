#include <string>
#include <sstream>

std::string convertPath(const std::string& path) {
    std::stringstream result;
    for (char c : path) {
        if (c == '/') {
            result << "\\\\";
        } else {
            result << c;
        }
    }
    return result.str();
}

#include <iostream>

int main() {
    std::string originalPath = "C:/QT_Program/PhotoShop-Lite/request";
    std::string convertedPath = convertPath(originalPath);
    
    std::cout << "Original path: " << originalPath << std::endl;
    std::cout << "Converted path: " << convertedPath << std::endl;
    
    return 0;
}