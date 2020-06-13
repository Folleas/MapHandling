/*
** EPITECH PROJECT, 2020
** include
** File description:
** soundboard
*/

using namespace	sf;
using namespace	std;

class SoundBoard {
public:
        void PauseGameMusic(Music *ingame);
        void PlayGameMusic(Music *ingame);
        void ChangeGameVolume(Music *ingame, int );
        void RestartGameMusic(Music *ingame);
        void StopLoopGame(Music *ingame);
        void StopGameMusic(Music *ingame);
        void PlayMenuMusic(Music *menu);
        void StopMenuMusic(Music *menu);
        void ChangeMenuVolume(Music *menu, int );
        void PlayExplosion(Sound *explo);
        void PlayButton(Sound *button);
        void PlayPause(Sound *button);
        void PlayPowerUp(Sound *button);
        void PlayGameOver(Sound *button);
        void PitchSound(Sound *button, float value);
        void PitchMusic(Music *ingame, float value);

        Music ingame;
        Music menu;
        Sound explo;
        Sound button;
        Sound gameover;
        Sound pause;
        Sound powerup;
};
