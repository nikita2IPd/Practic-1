#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

bool checkPassword(const std::string& password) {
    bool hasLowerCase = false;
    bool hasUpperCase = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (islower(c)) {
            hasLowerCase = true;
        }
        else if (isupper(c)) {
            hasUpperCase = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '?') {
            hasSpecialChar = true;
        }
    }

    return hasLowerCase && hasUpperCase && hasSpecialChar;
}

std::string generatePassword(int length) {
    std::string password;
    std::string specialChars = "!@#$%&*+?";

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i) {
        int type = rand() % 3; // 0 - lowercase, 1 - uppercase, 2 - special char

        if (type == 0) {
            password += static_cast<char>((rand() % 26) + 'a');
        }
        else if (type == 1) {
            password += static_cast<char>((rand() % 26) + 'A');
        }
        else if (type == 2) {
            password += specialChars[rand() % specialChars.length()];
        }
    }

    return password;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string password;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (checkPassword(password)) {
        std::cout << "Пароль действительный." << std::endl;
    }
    else {
        std::cout << "Пароль недействительный." << std::endl;
    }

    int length;
    std::cout << "Введите длину пароля для генерации: ";
    std::cin >> length;

    std::string generatedPassword = generatePassword(length);
    std::cout << "Сгенерированный пароль: " << generatedPassword << std::endl;

    return 0;
}
