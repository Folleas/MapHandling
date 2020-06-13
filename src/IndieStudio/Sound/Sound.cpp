/*
** EPITECH PROJECT, 2020
** sound
** File description:
** board
*/

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Sound.hpp"
#include <iostream>

using namespace std;
using namespace sf;

void SoundBoard::PauseGameMusic(Music *ingame)
{
    ingame->pause();
}

void SoundBoard::StopGameMusic(Music *ingame)
{
    ingame->stop();
}

void SoundBoard::RestartGameMusic(Music *ingame)
{
    ingame->stop();
    ingame->play();
}

void SoundBoard::PlayGameMusic(Music *ingame)
{
    if (!ingame->openFromFile("SoundBank/InGame.wav")) {
	cout << "Can't find the music file" << endl;
        exit (84);
    }
    ingame->play();
    ingame->setLoop(true);
}

void SoundBoard::PlayMenuMusic(Music *menu)
{
    if (!menu->openFromFile("SoundBank/LaunchMenu.wav")) {
	cout << "Can't find the music file" << endl;
        exit (84);
    }
    menu->setLoop(true);
    menu->play();
}

void SoundBoard::StopMenuMusic(Music *menu)
{
    menu->stop();
}

void SoundBoard::PlayExplosion(Sound *explo)
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("SoundBank/ExploBomb.wav")) {
        cout << "Can't find the sound's file" << endl;
        exit (84);
    }
    explo->setBuffer(buffer);
    explo->play();
}

void SoundBoard::PlayGameOver(Sound *gameover)
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("SoundBank/GameOver.wav")) {
        cout << "Can't find the sound's file" << endl;
        exit (84);
    }
    gameover->setBuffer(buffer);
    gameover->play();
}

void SoundBoard::PlayButton(Sound *button)
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("SoundBank/ButtonClick.wav")) {
        cout << "Can't find the sound's file" << endl;
        exit (84);
    }
    button->setBuffer(buffer);
    button->play();
}

void SoundBoard::PlayPowerUp(Sound *powerup)
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("SoundBank/PowerUp.wav")) {
        cout << "Can't find the sound's file" << endl;
        exit (84);
    }
    powerup->setBuffer(buffer);
    powerup->play();
}

void SoundBoard::PlayPause(Sound *pause)
{
    SoundBuffer buffer;

    if (!buffer.loadFromFile("SoundBank/PauseLaunched.wav")) {
        cout << "Can't find the sound's file" << endl;
        exit (84);
    }
    pause->setBuffer(buffer);
    pause->play();
}

void SoundBoard::StopLoopGame(Music *ingame)
{
    ingame->setLoop(false);
}

void SoundBoard::ChangeGameVolume(Music *ingame, int volume)
{
    ingame->setVolume(volume);
}

void SoundBoard::ChangeMenuVolume(Music *ingame, int volume)
{
    ingame->setVolume(volume);
}

void SoundBoard::PitchSound(Sound *button, float value)
{
    button->setPitch(value);
}

void SoundBoard::PitchMusic(Music *ingame, float value)
{
    ingame->setPitch(value);
}
