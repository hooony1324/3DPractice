#pragma once
#include <GameEngineCore/GameEngineLevel.h>


// Ό³Έν :
class TestLevel1 : public GameEngineLevel
{
public:
	// constrcuter destructer
	TestLevel1();
	~TestLevel1();

	// delete Function
	TestLevel1(const TestLevel1& _Other) = delete;
	TestLevel1(TestLevel1&& _Other) noexcept = delete;
	TestLevel1& operator=(const TestLevel1& _Other) = delete;
	TestLevel1& operator=(TestLevel1&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	void LevelStartEvent() override;
	void LevelEndEvent() override;

private:
	void ResourcesLoad();
	std::vector<GameEngineActor*> LevelActors;
};

