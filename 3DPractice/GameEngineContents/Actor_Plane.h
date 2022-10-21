#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Actor_Plane : public GameEngineActor
{
public:
	// constrcuter destructer
	Actor_Plane();
	~Actor_Plane();

	// delete Function
	Actor_Plane(const Actor_Plane& _Other) = delete;
	Actor_Plane(Actor_Plane&& _Other) noexcept = delete;
	Actor_Plane& operator=(const Actor_Plane& _Other) = delete;
	Actor_Plane& operator=(Actor_Plane&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	GameEngineTextureRenderer* Renderer;
	float4 ResultColor;

	GameEngineCollision* Collision;
};

