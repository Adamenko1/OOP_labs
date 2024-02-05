// Импортируем необходимые файлы
#include "OSControlFactory.h"
#include "LinControlFactory.h"
#include "WindowsControlFactory.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Введите название ОС" << std::endl;
	std::string OS;
	std::cin >> OS;
	ControlFactory* factory = nullptr;
	if (OS == "Linux") {
		factory = new LinControlFactory();
	}
	else if (OS == "Windows") {
		factory = new WindowsControlFactory();
	}
	else if (OS == "MacOS") {
		factory = new OSControlFactory();
	}
	Label* label = factory->createLabel();
	TextBox* textBox = factory->createTextBox();
	ComboBox* comboBox = factory->createComboBox();
	Button* button = factory->createButton();

	label->setText("Label");
	std::cout << label->getText() + "\n";

	textBox->setText("TextBox");
	std::cout << textBox->getText() + "\n";

	std::vector<std::string> items = { "item1", "item2" };
	comboBox->setItems(items);
	comboBox->setSelectedIndex(0);
	for (std::string item : comboBox->getItems()) {
		std::cout << item << '\n';
	}
	std::cout << comboBox->getSelectedIndex() << '\n';

	button->setText("Button");
	std::cout << button->getText() + "\n";
	button->setOnClick();
	button->click();

	//Возвращаем код успешного завершения программы
	return 0;
}