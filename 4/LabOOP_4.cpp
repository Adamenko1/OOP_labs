#include "Workflow.h"
#include "Keyboard.h"

int main()
{
    SetConsoleOutputCP(1251); // Программа начинается с установки кодировки консоли, чтобы корректно отображать русский текст
    Keyboard keyboard; //Затем создается объект класса Keyboard

    // Далее происходит регистрация клавиш "A", "Ctrl+C" и "Ctrl+V" и их связывание с определенными действиями, которые выводят сообщения в консоль
    keyboard.registerKey("A", []() { std::cout << "Key A pressed\n"; }, []() { std::cout << "Key A action undone\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C pressed\n"; }, []() { std::cout << "Ctrl+C action undone\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V pressed\n"; }, []() { std::cout << "Ctrl+V action undone\n"; });


    //Создается объект класса Workflow и добавляются в него действия: нажатие клавиш "A", "Ctrl+C" и "Ctrl+V", а также отмена последних двух действий
    Workflow workflow(keyboard);


    workflow.addAction([&]() { workflow.keypress("A"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+C"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+V"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });

    //Запускается рабочий процесс, в ходе которого в консоль выводятся сообщения о нажатии клавиш и отмене действий
    std::cout << "Начало работы...\n";
    workflow.perform();

    // Меняем действия, связанные с нажатием клавиш и повторно запускаем рабочий процесс
    std::cout << "\nПереназначение клавиш и перезапуск процесса...\n";
    keyboard.registerKey("A", []() { std::cout << "Key A теперь выводит это сообщение\n"; }, []() { std::cout << "Undo action for A\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C теперь ничего не делает\n"; }, []() { std::cout << "Undo action for Ctrl+C\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V теперь говорит привет\n"; }, []() { std::cout << "Undo action for Ctrl+V\n"; });

    //Снова выводятся сообщения о нажатии клавиш и отмене действий, но уже в соответствии с новыми определениями.
    workflow.perform();

    // Проверяется, зарегистрирована ли клавиша "Ctrl+V", и в случае положительного результата выводится соответствующее сообщение
    if (keyboard.isKeyRegistered("Ctrl+V"))
    {
        std::cout << "Клавиша Ctrl+V зарегистрирована в системе\n";
    }

    return 0;
}