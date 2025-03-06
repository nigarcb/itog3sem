// Подключаем заголовочный файл для работы с вводом-выводом (cin, cout)
#include <iostream>
// Подключаем заголовочный файл для работы со строками (std::string)
#include <string>

// Определяем функцию findNumberInAscii, которая принимает строку text (по ссылке, чтобы не копировать)
// и число number типа long long (для поддержки больших чисел). Функция возвращает строку с результатом.
std::string findNumberInAscii(const std::string& text, long long number) {
    // Создаем пустую строку asciiSequence, куда будем записывать числовую запись текста
    std::string asciiSequence;
    // Проходим по каждому символу c в строке text с помощью цикла for-each
    for (char c : text) {
        // Преобразуем символ c в его ASCII-код (int) с помощью static_cast,
        // затем преобразуем этот код в строку с помощью std::to_string и добавляем к asciiSequence
        asciiSequence += std::to_string(static_cast<int>(c));
    }
    // Выводим получившуюся числовую запись текста для отладки или информации
    std::cout << "ASCII text: " << asciiSequence << std::endl;
    
    // Преобразуем искомое число number в строку numberStr для поиска в asciiSequence
    std::string numberStr = std::to_string(number);
    
    // Ищем первое вхождение numberStr в asciiSequence с помощью метода find.
    // Метод возвращает индекс (тип size_t) или std::string::npos, если подстрока не найдена
    size_t index = asciiSequence.find(numberStr);
    
    // Проверяем, найдено ли вхождение (index != std::string::npos означает "найдено")
    if (index != std::string::npos) {
        // Если найдено, формируем строку с результатом: "Число [число] встречается с индекса [индекс]"
        return "Число " + numberStr + " встречается с индекса " + std::to_string(index);
    } else {
        // Если не найдено, возвращаем сообщение об отсутствии числа в числовой записи
        return "Число " + numberStr + " не встречается в числовой записи текста";
    }
}

// Точка входа в программу - функция main, возвращает int (0 при успешном завершении)
int main() {
    // Объявляем переменную text типа std::string для хранения введенного текста
    std::string text;
    // Объявляем переменную numberStr типа std::string для чтения числа как строки
    std::string numberStr;
    // Объявляем переменную number типа long long для хранения числа после преобразования
    long long number;

    // Начинаем бесконечный цикл, который будет прерываться только при вводе "exit"
    while (text != "exit") {
        // Выводим приглашение к вводу текста, указывая, как выйти из программы
        std::cout << "Write your text. If you want to leave, write 'exit'" << std::endl;
        // Считываем строку текста с помощью std::getline, которая читает всю строку, включая пробелы
        std::getline(std::cin, text);
        
        // Проверяем, ввел ли пользователь "exit". Если да, выходим из цикла с помощью break
        if (text == "exit") break;

        // Выводим приглашение к вводу числа
        std::cout << "Write your number" << std::endl;
        // Считываем число как строку в numberStr с помощью std::getline
        std::getline(std::cin, numberStr);
        
        // Начинаем блок try для обработки возможных ошибок при преобразовании строки в число
        try {
            // Преобразуем строку numberStr в число типа long long с помощью std::stoll
            number = std::stoll(numberStr);
            // Вызываем функцию findNumberInAscii с введенным текстом и числом, выводим результат
            std::cout << findNumberInAscii(text, number) << std::endl;
        // Если произошла ошибка (например, ввели не число), ловим исключение
        } catch (const std::exception& e) {
            // Выводим сообщение об ошибке, если преобразование не удалось
            std::cout << "Ошибка: введите корректное число" << std::endl;
        }
    }

    // Возвращаем 0, сигнализируя об успешном завершении программы
    return 0;
}