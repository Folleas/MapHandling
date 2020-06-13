/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <irrlicht.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(void)
{
    irr::IrrlichtDevice* device = irr::createDevice(    // creation du device
        irr::video::EDT_OPENGL,                           // API = OpenGL
        irr::core::dimension2d<irr::u32>(640,480),        // taille fenetre 640x480p
        32);                                              // 32 bits par pixel
    irr::video::IVideoDriver* driver =                  // creation du driver video
        device->getVideoDriver ();
    irr::scene::ISceneManager* sceneManager =           // creation du scene manager
        device->getSceneManager ();
    device->getCursorControl ()-> setVisible (false);   // rend le curseur invisible

    /* MODELE */

    // irr::scene::IAnimatedMeshSceneNode *sydney =        // cree un scene node nomme sydney
    //   sceneManager->addAnimatedMeshSceneNode (          // via le scene manager
    //     sceneManager->getMesh ("../irrlicht-1.8.4/media/sydney.md2"));          // en chargeant le mesh "sydney.md2"

    // sydney->setMaterialFlag(
    //   irr::video::EMF_LIGHTING, false);
    // sydney->setMaterialTexture(
    //   0, driver->getTexture("../irrlicht-1.8.4/media/sydney.bmp"));

    // sydney->setMD2Animation(irr::scene::EMAT_STAND);    // joue l'animation STAND en boucle


    /* CONTROL */

    /*  irr::SKeyMap keyMap[5];                             // re-assigne les commandes
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
    keyMap[0].KeyCode = irr::KEY_KEY_Z;                 // z
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
    keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
    keyMap[2].KeyCode = irr::KEY_KEY_Q;                 // q
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
    keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d
    keyMap[4].Action = irr::EKA_JUMP_UP;                // saut
    keyMap[4].KeyCode = irr::KEY_SPACE;                 // barre espace
    */

    scene::IAnimatedMesh* model;
    sceneManager->getParameters()->setAttribute(irr::scene::COLLADA_CREATE_SCENE_INSTANCES, true);
    model = smgr->getMesh("mesh.dae");
    // CAMERA
    sceneManager->addCameraSceneNode(0, irr::core::vector3df(0,180,0), irr::core::vector3df(0,15,0));

        /* RENDU */

    while (device->run()) {                             // la boucle de rendu
        driver->beginScene(true, true,                    // demarre le rendu
        irr::video::SColor(0,255,255,255));
        sceneManager->drawAll ();                         // calcule le rendu
        driver->endScene ();                              // affiche le rendu
    }

    device->drop ();                                    // libere la memoire
    return 0;
}

// int main()
// {
//     IndieStudio indie;
//     indie.runIndieStudio();
// }