/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ControlSettingsButtons
*/

#include "ControlSettingsButtons.hpp"

ControlSettingsButtons::ControlSettingsButtons(std::pair<std::size_t, std::size_t> position, std::pair<std::size_t, std::size_t> dimension, RGBA_t color, std::vector<std::shared_ptr<Player>> players)
{
    std::shared_ptr<SingleCharacterTextInput> leftInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<SingleCharacterTextInput> rightInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<SingleCharacterTextInput> upInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<SingleCharacterTextInput> downInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<SingleCharacterTextInput> bombInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<SingleCharacterTextInput> pauseInput = std::make_shared<SingleCharacterTextInput>();
    std::shared_ptr<Button> p1 = std::make_shared<Button>();
    std::shared_ptr<Button> p2 = std::make_shared<Button>();
    std::shared_ptr<Button> p3 = std::make_shared<Button>();
    std::shared_ptr<Button> p4 = std::make_shared<Button>();
    std::shared_ptr<Button> leftDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> rightDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> upDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> downDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> bombDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> pauseDisplay = std::make_shared<Button>();
    std::shared_ptr<Button> exclamation1Display = std::make_shared<Button>();
    std::shared_ptr<Button> exclamation2Display = std::make_shared<Button>();
    std::shared_ptr<Button> exclamation3Display = std::make_shared<Button>();
    std::shared_ptr<Button> exclamation4Display = std::make_shared<Button>();

    leftInput = leftInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 5, position.second + dimension.second / 16 * 6, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");
    rightInput = rightInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 9, position.second + dimension.second / 16 * 6, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");
    upInput = upInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 5, position.second + dimension.second / 16 * 9, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");
    downInput = downInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 9, position.second + dimension.second / 16 * 9, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");
    bombInput = bombInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 5, position.second + dimension.second / 16 * 12, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");
    pauseInput = pauseInput->setupSingleCharacterTextInput(position.first + dimension.first / 16 * 9, position.second + dimension.second / 16 * 12, dimension.first / 8, dimension.second / 8, BUTTONCOLOR, "");

    p1 = p1->setupButton(position.first + dimension.first / 16, position.second + dimension.second / 16, dimension.first / 16 * 2, dimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "P1", MenuScreens::UNDEFINED);
    p2 = p2->setupButton(position.first + dimension.first / 16 * 5, position.second + dimension.second / 16, dimension.first / 16 * 2, dimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "P2", MenuScreens::UNDEFINED);
    p3 = p3->setupButton(position.first + dimension.first / 16 * 9, position.second + dimension.second / 16, dimension.first / 16 * 2, dimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "P3", MenuScreens::UNDEFINED);
    p4 = p4->setupButton(position.first + dimension.first / 16 * 13, position.second + dimension.second / 16, dimension.first / 16 * 2, dimension.second / 16 * 3, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "P4", MenuScreens::UNDEFINED);

    leftDisplay = leftDisplay->setupButton(position.first + dimension.first / 16, position.second + dimension.second / 16 * 6, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "<", MenuScreens::UNDEFINED);
    rightDisplay = rightDisplay->setupButton(position.first + dimension.first / 16 * 12, position.second + dimension.second / 16 * 6, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, ">", MenuScreens::UNDEFINED);
    upDisplay = upDisplay->setupButton(position.first + dimension.first / 16, position.second + dimension.second / 16 * 9, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "^", MenuScreens::UNDEFINED);
    downDisplay = downDisplay->setupButton(position.first + dimension.first / 16 * 12, position.second + dimension.second / 16 * 9, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "v", MenuScreens::UNDEFINED);
    bombDisplay = bombDisplay->setupButton(position.first + dimension.first / 16, position.second + dimension.second / 16 * 12, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "`o", MenuScreens::UNDEFINED);
    pauseDisplay = pauseDisplay->setupButton(position.first + dimension.first / 16 * 12, position.second + dimension.second / 16 * 12, dimension.first / 16 * 3, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "P", MenuScreens::UNDEFINED);

    exclamation1Display = exclamation1Display->setupButton(position.first + dimension.first / 16 * 1.5, position.second - dimension.second / 16 * 2, dimension.first / 16, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "!", MenuScreens::UNDEFINED);
    exclamation2Display = exclamation2Display->setupButton(position.first + dimension.first / 16 * 5.5, position.second - dimension.second / 16 * 2, dimension.first / 16, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "!", MenuScreens::UNDEFINED);
    exclamation3Display = exclamation3Display->setupButton(position.first + dimension.first / 16 * 9.5, position.second - dimension.second / 16 * 2, dimension.first / 16, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "!", MenuScreens::UNDEFINED);
    exclamation4Display = exclamation4Display->setupButton(position.first + dimension.first / 16 * 13.5, position.second - dimension.second / 16 * 2, dimension.first / 16, dimension.second / 16 * 2, BUTTONCOLOR, CLICKEDBUTTONCOLOR, "!", MenuScreens::UNDEFINED);

    leftDisplay->setClickable(false);
    rightDisplay->setClickable(false);
    upDisplay->setClickable(false);
    downDisplay->setClickable(false);
    bombDisplay->setClickable(false);
    pauseDisplay->setClickable(false);
    exclamation1Display->setClickable(false);
    exclamation2Display->setClickable(false);
    exclamation3Display->setClickable(false);
    exclamation4Display->setClickable(false);

    exclamation1Display->setDisplay(false);
    exclamation2Display->setDisplay(false);
    exclamation3Display->setDisplay(false);
    exclamation4Display->setDisplay(false);

    this->_textInputs.push_back(leftInput);
    this->_textInputs.push_back(rightInput);
    this->_textInputs.push_back(upInput);
    this->_textInputs.push_back(downInput);
    this->_textInputs.push_back(bombInput);
    this->_textInputs.push_back(pauseInput);

    this->_playerObjects.push_back(p1);
    this->_playerObjects.push_back(p2);
    this->_playerObjects.push_back(p3);
    this->_playerObjects.push_back(p4);

    this->_displayObjects.push_back(leftDisplay);
    this->_displayObjects.push_back(rightDisplay);
    this->_displayObjects.push_back(upDisplay);
    this->_displayObjects.push_back(downDisplay);
    this->_displayObjects.push_back(bombDisplay);
    this->_displayObjects.push_back(pauseDisplay);
    this->_displayObjects.push_back(exclamation1Display);
    this->_displayObjects.push_back(exclamation2Display);
    this->_displayObjects.push_back(exclamation3Display);
    this->_displayObjects.push_back(exclamation4Display);

    this->_position.first = position.first;
    this->_position.second = position.second;
    this->_dimension.first = dimension.first;
    this->_dimension.second = dimension.second;
    this->_color = color;
    this->_selectedTextInput = -1;
    this->_selectedPlayer = 0;
    this->_players = players;
}

ControlSettingsButtons::ControlSettingsButtons()
{
}

ControlSettingsButtons::~ControlSettingsButtons()
{
}

std::shared_ptr<ControlSettingsButtons> ControlSettingsButtons::setupControlSettingsButtons(std::size_t x, std::size_t y, std::size_t w, std::size_t h, RGBA_t color, std::vector<std::shared_ptr<Player>> players)
{
    std::pair<std::size_t, std::size_t> buttonPosition;
    std::pair<std::size_t, std::size_t> buttonDimension;
    std::shared_ptr<ControlSettingsButtons> tmpButton;

    buttonPosition.first = x;
    buttonPosition.second = y;
    buttonDimension.first = w;
    buttonDimension.second = h;
    tmpButton = std::make_shared<ControlSettingsButtons>(buttonPosition, buttonDimension, color, players);
    return (tmpButton);
}

int ControlSettingsButtons::getSelectedTextInput(std::pair<std::size_t, std::size_t> mousePosition)
{
    std::size_t i = 0;

    for (std::shared_ptr<GameObject> elem : this->_textInputs) {
        if (mousePosition.first >= elem->getPosition().first && mousePosition.first <=  elem->getPosition().first + elem->getDimension().first && mousePosition.second >= elem->getPosition().second && mousePosition.second <= elem->getPosition().second + elem->getDimension().second) {
            elem->setColor((RGBA_t){78, 0, 22, 190});
            if (_pressed == 1) {
                elem->setColor((RGBA_t){78, 0, 22, 255});
            }
            if (_pressed == 2) {
                _pressed = 0;
                return (i);
            }
            continue;
        }
        elem->setColor((RGBA_t){78, 0, 22, 128});
        i++;
    }
    return (-1);
}

std::size_t ControlSettingsButtons::getSelectedPlayer(std::shared_ptr<int> window)
{
    for (std::size_t i = 0; i != this->_playerObjects.size(); i++) {
        if (this->_playerObjects.at(i)->engine(window).first == 1) {
            return (i);
        }
    }
    return (-1);
}

std::pair<int, MenuScreens> ControlSettingsButtons::engine(std::shared_ptr<int> window)
{
    // sf::Vector2i IrrlichtMousePosition = sf::Mouse::getPosition(*window);
    std::pair<std::size_t, std::size_t> mousePosition;
    int selectedTextReturn = 0;
    int selectedPlayerReturn = 0;

    // mousePosition.first = IrrlichtMousePosition.x;
    // mousePosition.second = IrrlichtMousePosition.y;
    selectedTextReturn = getSelectedTextInput(mousePosition);
    selectedPlayerReturn = getSelectedPlayer(window);
    if (selectedTextReturn != -1) {
        this->_selectedTextInput = selectedTextReturn;
    }
    if (selectedPlayerReturn != -1) {
        this->_selectedPlayer = selectedPlayerReturn;
        this->setTextInputs(_players.at(_selectedPlayer)->getControler()->getKeys());
    }
    for (std::shared_ptr<GameObject> elem : this->_displayObjects) {
        elem->engine(window);
    }
    return (std::make_pair<int, MenuScreens>(0, MenuScreens::UNDEFINED));
}

void ControlSettingsButtons::display(std::shared_ptr<int> window)
{
    // sf::RectangleShape rect(sf::Vector2f(this->_dimension.first, this->_dimension.second));

    // rect.setFillColor(sf::Color(this->_color.r, this->_color.g, this->_color.b, this->_color.a));
    // rect.setPosition(sf::Vector2f(this->_position.first, this->_position.second));
    // window->draw(rect);
    // for (std::shared_ptr<GameObject> elem : this->_playerObjects) {
    //     elem->display(window);
    // }
    // for (std::shared_ptr<GameObject> elem : this->_textInputs) {
    //     elem->display(window);
    // }
    // for (std::shared_ptr<GameObject> elem : this->_displayObjects) {
    //     elem->display(window);
    // }
}

void ControlSettingsButtons::checkAssignedInput(int selectedPlayer, int selectedTextInput)
{
    // std::shared_ptr<PlayerControler> controler;
    // std::vector<irr::EKEY_CODE> keysTmp;
    // irr::EKEY_CODE checkedKey = dynamic_cast<SingleCharacterTextInput *>(this->_textInputs.at(selectedTextInput).get())->getKey();
    // bool displayed = false;

    // for (std::size_t j = 0; j != this->_players.size(); j++) {
    //     displayed = false;
    //     controler = this->_players.at(j)->getControler();
    //     keysTmp = controler->getKeys();
    //     for (std::size_t i = 0; i != keysTmp.size(); i++) {
    //         if (keysTmp.at(i) == checkedKey){
    //             if (j != selectedPlayer) {
    //                 keysTmp.at(i) = irr::EKEY_CODE::Unknown;
    //             }
    //             else if (i != selectedTextInput) {
    //                 keysTmp.at(i) = irr::EKEY_CODE::Unknown;
    //             }
    //         }
    //         if (keysTmp.at(i) == irr::EKEY_CODE::Unknown) {
    //             displayed = true;
    //         }
    //     }
    //     dynamic_cast<Button *>(this->_displayObjects.at(TextInputs::Pause + j + 1).get())->setDisplay(displayed);
    //     controler->setKeys(keysTmp);
    // }
}

int ControlSettingsButtons::event(std::shared_ptr<Event> event)
{
    // switch (event->type) {
    //     case sf::Event::MouseButtonPressed :
    //         this->_pressed = 1;
    //         break;
    //     case sf::Event::MouseButtonReleased :
    //         this->_pressed = 2;
    //         break;
    // }
    // for (std::shared_ptr<GameObject> elem : this->_playerObjects) {
    //     elem->event(event);
    // }
    // if (_selectedTextInput != -1) {
    //     if (this->_textInputs.at(_selectedTextInput)->event(event)) {
    //         this->_players.at(_selectedPlayer)->setControler(getModifiedInput());
    //         checkAssignedInput(_selectedPlayer, _selectedTextInput);
    //         this->setTextInputs(_players.at(_selectedPlayer)->getControler()->getKeys());
    //         this->_selectedTextInput = -1;
    //     }
    // }
    // for (std::shared_ptr<GameObject> elem : this->_displayObjects) {
    //     elem->event(event);
    // }
    return (0);
}

void ControlSettingsButtons::setTextInputs(std::vector<irr::EKEY_CODE> controlerMap)
{
    for (std::size_t i = 0; i != this->_textInputs.size(); i++) {
        // dynamic_cast<SingleCharacterTextInput *>(this->_textInputs.at(i).get())->setString(Irrlicht::sfKeyToChar(controlerMap.at(i)));
        // dynamic_cast<SingleCharacterTextInput *>(this->_textInputs.at(i).get())->setKey(controlerMap.at(i));
    }
}

std::vector<irr::EKEY_CODE> ControlSettingsButtons::getModifiedInput()
{
    std::vector<irr::EKEY_CODE> keys;

    for (std::size_t i = 0; i != this->_textInputs.size(); i++) {
        keys.push_back(dynamic_cast<SingleCharacterTextInput *>(this->_textInputs.at(i).get())->getKey());
    }
    return (keys);
}
