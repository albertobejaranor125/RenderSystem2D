// RenderSystem2D.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Entity.h"
#include "Components.h"
#include "System.h"
#include "LoggerSystem.h"
#include "RenderSystem.h"
#include "MapLoader.h"
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main()
{
    /*system("cls");
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Entity> entities;
    Entity hero;
    hero.AddComponent(std::make_shared<Name>(Name{ "Hero" }));
    hero.AddComponent(std::make_shared<Position>(Position{ 0,0 }));
    hero.AddComponent(std::make_shared<Health>(Health{ 100,100 }));
    auto animation = std::make_shared<Animation>();*/
    /*animation->states["idle"] = {0, 1, 2};
    animation->states["walk"] = { 3, 4, 5 };*/
    /*animation->currentState = "idle";
    animation->frameTime = 1.0f;
    animation->currentFrame = 0;
    animation->timer = 0;
    hero.AddComponent<Animation>(animation);
    auto input = std::make_shared<Input>();
    input->lastComand = "Idle";
    hero.AddComponent(input);
    hero.AddComponent(std::make_shared<Collider>(Collider{ 2,2 }));
    entities.push_back(hero);
    Entity orc;
    orc.AddComponent(std::make_shared<Name>(Name{ "Orc" }));
    orc.AddComponent(std::make_shared<Position>(Position{ 1,1 }));
    orc.AddComponent(std::make_shared<Collider>(Collider{ 2,2 }));
    orc.AddComponent(std::make_shared<Health>(Health{ 100,100 }));
    auto animation2 = std::make_shared <Animation>();
    animation2->currentState = "idle";
    animation2->frameTime = 1.0f;
    animation2->currentFrame = 0;
    animation2->timer = 0;
    orc.AddComponent<Animation>(animation2);
    entities.push_back(orc);
    MovementSystem moveSystem;
    HealthSystem healthSystem;
    LoggerSystem logger;
    AnimationSystem animationSystem;
    InputSystem inputSystem;
    CollisionSystem collisionSystem;
    RenderSystem renderSystem;
    for (int i = 0; i < 5; i++) {
        std::cout << "\nFrame " << i + 1 << std::endl;
        moveSystem.Update(entities);
        logger.Log("MovementSystem updated.");
        healthSystem.Update(entities);
        logger.Log("HealthSystem updated.");
        animationSystem.Update(entities, 1.5f);
        logger.Log("AnimationSystem updated");
        inputSystem.Update(hero);
        logger.Log("InputSystem updated.");
        collisionSystem.Update(entities);
        logger.Log("CollisionSystem updated.");
        renderSystem.Draw(entities);
        logger.Log("RenderSystem updated");
        std::cout << "\n";
    }*/
    /*Tilemap tilemap;
    tilemap.width = 10;
    tilemap.height = 5;
    tilemap.grid.resize(tilemap.height, std::vector<Tile>(tilemap.width, {'.',true}));
    tilemap.grid[2][3] = { '#', false };
    tilemap.grid[2][4] = { '#', false };
    tilemap.grid[2][5] = { '#', false };
    tilemap.grid[4][1] = { '~', false };
    tilemap.grid[4][2] = { '~', false };
    TilemapSystem renderer;
    renderer.Render(tilemap);
    logger.Log("TilemapSystem updated.");*/
    /*Tilemap tilemap = LoadMapFromFile("map.txt");
    TilemapSystem renderer;
    renderer.Render(tilemap);*/
    //system("cls");
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<Entity> entities;
    Tilemap map = LoadMapFromFile("map.txt");
    Entity player;
    player.AddComponent(std::make_shared<Name>(Name{ "Hero" }));
    player.AddComponent(std::make_shared<Position>(Position{ 1, 1 }));
    entities.push_back(player);
    MovementSystem mover;
    RenderSystem renderer;
#ifdef  _WIN32
    system("cls");
#else
    system("clear");
#endif //  _WIN32

    for (int i = 0; i < 10; ++i) {
        std::cout << "\nTurn " << i + 1 << ":\n";
        mover.Update(entities);
        renderer.Draw(entities, map);
    }
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
