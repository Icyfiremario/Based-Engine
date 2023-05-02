#include "MixerManager.hpp"

MixerManager::MixerManager()
{}

MixerManager::~MixerManager()
{}

void MixerManager::PlaySFX(std::string id)
{
    sfx = Game::assets->GetSfx(id);
    Mix_PlayChannel(1, sfx, 0);
}