#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int num1, num2, answer, correctAnswer;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    correctAnswer = num1 * num2;

    std::cout << "Какой результат " << num1 << " умноженный на " << num2 << "? ";
    std::cin >> answer;

    if (answer == correctAnswer) {
        std::cout << "Правильно" << std::endl;
    }
    else {
        std::cout << "Не правильно" << correctAnswer << "." << std::endl;
    }

    return 0;
}