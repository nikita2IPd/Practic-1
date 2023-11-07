#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Функция для генерации случайного символа
char generateRandomChar() {
    const std::string validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%&*+?";
    int randomIndex = rand() % validChars.length();
    return validChars[randomIndex];
}

// Функция для генерации пароля заданной длины
std::string generatePassword(int length) {
    std::string password;
    for (int i = 0; i < length; i++) {
        password += generateRandomChar();
    }
    return password;
}

// Функция для проверки пароля
bool isPasswordValid(const std::string& password) {
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (isupper(c)) {
            hasUppercase = true;
        }
        else if (islower(c)) {
            hasLowercase = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '?') {
            hasSpecialChar = true;
        }
    }

    return hasUppercase && hasLowercase && hasSpecialChar;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // Инициализация генератора случайных чисел

    int passwordLength;
    std::cout << "Введите длину пароля: ";
    std::cin >> passwordLength;

    std::string password = generatePassword(passwordLength);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    if (isPasswordValid(password)) {
        std::cout << "Пароль действителен." << std::endl;
    }
    else {
        std::cout << "Пароль недействителен." << std::endl;
    }

    return 0;
}