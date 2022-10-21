#pragma once
#include <GameEngineCore/GameEngineGUI.h>

// Ό³Έν :
class ContentsManagerGUI : public GameEngineGUIWindow
{
public:
	// constrcuter destructer
	ContentsManagerGUI();
	~ContentsManagerGUI();

	// delete Function
	ContentsManagerGUI(const ContentsManagerGUI& _Other) = delete;
	ContentsManagerGUI(ContentsManagerGUI&& _Other) noexcept = delete;
	ContentsManagerGUI& operator=(const ContentsManagerGUI& _Other) = delete;
	ContentsManagerGUI& operator=(ContentsManagerGUI&& _Other) noexcept = delete;

protected:
	void Initialize(class GameEngineLevel* _Level) override;
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;

private:

};

