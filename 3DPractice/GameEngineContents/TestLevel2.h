#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class TestLevel2 : public GameEngineLevel
{
public:
	static GameEngineActor* Player;
public:
	// constrcuter destructer
	TestLevel2();
	~TestLevel2();

	// delete Function
	TestLevel2(const TestLevel2& _Other) = delete;
	TestLevel2(TestLevel2&& _Other) noexcept = delete;
	TestLevel2& operator=(const TestLevel2& _Other) = delete;
	TestLevel2& operator=(TestLevel2&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	void ResourcesLoad();
	std::vector<GameEngineActor*> LevelActors;

	void FollowMainCamToPlayer(float _DeltaTime);
};

