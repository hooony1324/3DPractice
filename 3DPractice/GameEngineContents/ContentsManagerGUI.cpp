#include "PreCompile.h"
#include "ContentsManagerGUI.h"
#include <GameEngineCore/CoreMinimal.h>

#include "TestLevel2.h"

ContentsManagerGUI::ContentsManagerGUI() 
{
}

ContentsManagerGUI::~ContentsManagerGUI() 
{
}

void ContentsManagerGUI::Initialize(GameEngineLevel* _Level)
{
}

void ContentsManagerGUI::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{

	if (nullptr != TestLevel2::Player)
	{
		float4 Pos = TestLevel2::Player->GetTransform().GetWorldPosition();
		std::string Name = "PlayerPos : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}


}
