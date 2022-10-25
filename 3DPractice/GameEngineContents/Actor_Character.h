#pragma once
#include "PickableActor.h"

const float SPEED_PLAYER = 200.0f;

// Ό³Έν :
class Actor_Character : public PickableActor
{
public:
	// constrcuter destructer
	Actor_Character();
	~Actor_Character();

	// delete Function
	Actor_Character(const Actor_Character& _Other) = delete;
	Actor_Character(Actor_Character&& _Other) noexcept = delete;
	Actor_Character& operator=(const Actor_Character& _Other) = delete;
	Actor_Character& operator=(Actor_Character&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	void ActivateGravity();
	void InputController(float _DeltaTime);

private:
	GameEngineTextureRenderer* Renderer;

	GameEngineCollision* Collision;

	float4 MoveDir;
	float MoveSpeed;

	float4 MousePosition;
};

