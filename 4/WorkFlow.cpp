#include "Workflow.h"// Включаем файл "Workflow.h"

// Определяем функцию "keypress", которая принимает строку "key" в качестве аргумента. 
// Внутри функции вызывается метод "pressKey" объекта "keyboard"
// чтобы нажать клавишу. Затем выполняется задержка в 1 секунду с использованием функции "sleep_for" из библиотеки "chrono".
void Workflow::keypress(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // добавляем задержку, чтобы действия были заметны
}

//Определяем функцию "undo", которая не принимает аргументы.
// Внутри функции вызывается метод "undo" объекта "keyboard", 
// чтобы отменить предыдущее действие нажатия клавиши. 
// Затем выполняется задержка в 1 секунду.
void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Определяем функцию "perform", которая выполняет все действия в рабочем процессе 
//  Внутри цикла перебираются все элементы вектора "actions"
//  и выполняется каждая функция-действие. Затем выполняется задержка в 1 секунду.
void Workflow::perform()
{
    for (const auto& action : actions)
    {
        action();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Определяем функцию "addAction",
//  которая принимает аргумент "action" типа Action 
//  Внутри функции добавляем "action" в конец вектора "actions".
void Workflow::addAction(const Action& action)
{
    actions.push_back(action);
}