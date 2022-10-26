#pragma once

#pragma warning(disable : 4996)
#include <PxPhysicsAPI.h>


// Ό³Έν :
class GameEnginePhysX
{
public:
	// constrcuter destructer
	GameEnginePhysX();
	~GameEnginePhysX();

	// delete Function
	GameEnginePhysX(const GameEnginePhysX& _Other) = delete;
	GameEnginePhysX(GameEnginePhysX&& _Other) noexcept = delete;
	GameEnginePhysX& operator=(const GameEnginePhysX& _Other) = delete;
	GameEnginePhysX& operator=(GameEnginePhysX&& _Other) noexcept = delete;

protected:

private:

};

