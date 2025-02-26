#include "headers/BitcoinExchange.hpp"

//
// In c++ fds are automatically closed when they leave the current scope.
//

void    std_errore(const std::string err) {
    std::cerr << err << std::endl;
    exit(1);
}

bool fileExists(const std::string &filename) {
    std::ifstream file(filename.c_str());
    return file.is_open();
}

bool isFileEmpty(const std::string &filename) {
    std::ifstream file(filename.c_str(), std::ios::binary | std::ios::ate);
    if (!file.is_open()) return false;
    return file.tellg() == 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) std_errore(WRONG_N_ARGS);
    std::string filename(argv[1]);
    if (!fileExists(filename)) std_errore(NO_FILE);
    if (isFileEmpty(filename)) std_errore(EMPTY_FILE);
    BitcoinExchange exchange;
    exchange.parseFile(argv[1]);
    std::cout << "Valid dates:" << std::endl;
    exchange.printData();
    exchange.printExchange("data.csv");
    return 0;
}
