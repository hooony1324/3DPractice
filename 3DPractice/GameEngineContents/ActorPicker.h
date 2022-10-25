#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 : MapEditor레벨 전용으로 객체를 여러개 생성하면 안됨
class ActorPicker : public GameEngineActor
{
public:
	static float4 PickerAngle;
	static std::set<GameEngineActor*> PickedActors;
	static GameEngineActor* PickedActor;
	static GameEngineActor* ClickedActor;

public:
	// constrcuter destructer
	ActorPicker();
	~ActorPicker();

	// delete Function
	ActorPicker(const ActorPicker& _Other) = delete;
	ActorPicker(ActorPicker&& _Other) noexcept = delete;
	ActorPicker& operator=(const ActorPicker& _Other) = delete;
	ActorPicker& operator=(ActorPicker&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	float4 CamPos;
	GameEngineCollision* Collision_Ray;

	void SelectPickedActor();
	void ClickCheck();
};

