#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/ECS.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"
#include "AssetManager.hpp"
#include "MixerManager.hpp"
#include <sstream>


Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

SDL_Rect Game::camera = {0, 0, 800, 640};

AssetManager* Game::assets = new AssetManager(&manager);
MixerManager* mixer = new MixerManager;

SDL_Color FGColor = { 255, 0, 0, 0 };
SDL_Color BGColor = { 0, 0, 0, 0 };

bool Game::isRunning = false;

auto& player(manager.addEntity());
auto& positionLabel(manager.addEntity());
auto& facingLabel(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        //std::cout << "Subsystems Initialised!..." << std::endl;
        PLOGI << "Subsystems Initialised!...";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            //std::cout << "Window created!" << std::endl;
            PLOGI << "Window created!";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            //std::cout << "Renderer created!" << std::endl;
            PLOGI << "Renderer created!";
        }

        isRunning = true;
        
    }

    if(TTF_Init() == -1)
    {
        //std::cout << "Error : SDL_TTF" << std::endl;
        PLOGE << "Error : SDL_TTF";
    }
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4069) == -1)
    {
        //std::cout << "Error: SDL_Mixer" << std::endl;
        PLOGE << "Error: SDL_Mixer";
    }

    SDL_ShowCursor(SDL_DISABLE);
    

    assets->AddTexture("terrain", "assets/terrain_ss.png");
    assets->AddTexture("player", "assets/player_anims.png");
    assets->AddTexture("ball", "assets/ball.png");
    assets->AddTexture("Laser", "assets/laser.png");
    assets->AddFont("arial", "assets/arial.ttf", 16);
    assets->AddSfx("Shoot", "assets/Shoot.wav");
    assets->AddOST("Main", "assets/loz.wav");

    map = new Map("terrain", 3, 32);
    map->LoadMap("assets/map.map", 25, 20);

    //init game objects (player, enemies, map, etc)

    player.addComponent<TransformComponent>(800.0f, 640.0f, 32, 32, 2);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addComponent<StatsComponent>(20, 0, 10, true);
    player.addComponent<WeaponComponenet>(20, 999, 2, "Laser");
    //player.addComponent<StatsUI>();
    //player.getComponent<StatsUI>().HPBar(10, 35, 128, 32, FGColor, BGColor);
    player.addGroup(groupPlayers);

    SDL_Color white = {255, 255, 255, 255};
    positionLabel.addComponent<UILable>(10, 10, "Bababooey", "arial", white);
    facingLabel.addComponent<UILable>(10, 25, "Bababooey", "arial", white);

    assets->CreateProjectile(Vector2D(600, 600), Vector2D(1, 0), 200, 2, "ball");
    mixer->PlayMusic("Main");

}


auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

void Game::handleEvents()
{
    
    
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::update()
{

    SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = player.getComponent<TransformComponent>().posititon;

    std::stringstream PostitionStream;
    std::stringstream FacingStream;

    PostitionStream << "Player position: " << playerPos;
    FacingStream << "Facing: " << player.getComponent<TransformComponent>().Facing;

    positionLabel.getComponent<UILable>().SetLabelText(PostitionStream.str(), "arial");
    facingLabel.getComponent<UILable>().SetLabelText(FacingStream.str(), "arial");

    manager.refresh();
    manager.update();

    for (auto& c : colliders)
    {
        SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
        if(Collision::AABB(cCol, playerCol))
        {
            player.getComponent<TransformComponent>().posititon = playerPos;
        }
    }

    for (auto& p : projectiles)
    {
        if(Collision::AABB(player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            //std::cout << "Hit player!" << std::endl;
            PLOGV << "hit player";
            p->destroy();
        }
    }

    camera.x = player.getComponent<TransformComponent>().posititon.x - 400;
    camera.y = player.getComponent<TransformComponent>().posititon.y - 320;

    if(camera.x < 0)
    {
        camera.x = 0;
    }
    if(camera.y < 0)
    {
        camera.y = 0;
    }
    if(camera.x > camera.w)
    {
        camera.x = camera.w;
    }
    if(camera.y > camera.h)
    {
        camera.y = camera.h;
    }

}



void Game::render()
{
    SDL_RenderClear(renderer);
    for(auto& t : tiles) { t->draw(); }
    for(auto& c: colliders) { c->draw(); }
    for(auto& p : players) { p->draw(); }
    for(auto& p : projectiles) { p->draw(); }
    positionLabel.draw();
    facingLabel.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    SDL_Quit();
    //std::cout << "Game cleaned" << std::endl;
    PLOGI << "Game cleaned";
}