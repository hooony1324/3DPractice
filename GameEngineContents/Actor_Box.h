#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Actor_Box : public GameEngineActor
{
public:
	// constrcuter destructer
	Actor_Box();
	~Actor_Box();

	// delete Function
	Actor_Box(const Actor_Box& _Other) = delete;
	Actor_Box(Actor_Box&& _Other) noexcept = delete;
	Actor_Box& operator=(const Actor_Box& _Other) = delete;
	Actor_Box& operator=(Actor_Box&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	GameEngineTextureRenderer* Renderer;
	float4 ResultColor;
};

