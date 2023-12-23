#include "Keyboard.h"

// Определяем метод "pressKey", который принимает строку "key" в качестве аргумента.
//  Внутри метода мы проверяем, зарегистрирована ли клавиша "key" в словаре "keymap" с помощью функции "count".
//  Если клавиша не найдена, генерируется исключение с текстом "Unknown key pressed".
//  Затем имя клавиши добавляется в конец вектора "history".
//  В конце вызывается функция-действие, связанная с этой клавишей.
void Keyboard::pressKey(const std::string& key)
{
    assert(keymap.count(key) && "Unknown key pressed");
    history.push_back(key);
    keymap[key].first();
}

//Определяем метод "undo". Если история не пуста, последнее действие извлекается из вектора "history".
//  Текст "Undo action for key: ..." 
// выводится в консоль, а затем вызывается функция-действие, 
//связанная с этой клавишей. После этого элемент удаляется из вектора "history".
void Keyboard::undo()
{
    if (!history.empty())
    {
        std::cout << "Undo action for key: " << history.back() << "\n";
        keymap[history.back()].second();
        history.pop_back();
    }
}

// Определяем метод "isKeyRegistered", который принимает строку "key" в качестве аргумента.
//  Метод возвращает значение true, если клавиша "key" есть в словаре "keymap", и false в противном случае.
//  Функция "count" возвращает количество элементов с заданным ключом, 
// поэтому если результат функции больше 0, значит, клавиша зарегистрирована.
bool Keyboard::isKeyRegistered(const std::string& key) const
{
    return keymap.count(key) > 0;
}