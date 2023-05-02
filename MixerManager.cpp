#include "MixerManager.hpp"

MixerManager::MixerManager()
{}

MixerManager::~MixerManager()
{}

void MixerManager::PlaySFX(std::string id)
{
    sfx = Game::assets->GetSfx(id);
    Mix_PlayChannel(-1, sfx, 0);
}

void MixerManager::PlayMusic(std::string id)
{
    music = Game::assets->GetOST(id);
    Mix_PlayMusic(music, -1);
}