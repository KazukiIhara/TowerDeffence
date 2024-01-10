#include "SceneManager.h"

cSceneManager::cSceneManager()
{
	Init();
}

cSceneManager::~cSceneManager()
{

}

void cSceneManager::Init()
{
	currentScene = Game;
	nextScene = Game;
	prevScene = Game;
}

void cSceneManager::Update()
{

}

void cSceneManager::Draw()
{
}
