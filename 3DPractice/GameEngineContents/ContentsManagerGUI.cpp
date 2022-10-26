#include "PreCompile.h"
#include "ContentsManagerGUI.h"
#include <GameEngineCore/CoreMinimal.h>

#include "TestLevel2.h"
#include "ActorPicker.h"

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

	{
		float4 Pos = _Level->GetMainCamera()->GetTransform().GetWorldPosition();
		std::string Name = "MainCameraWorldPos : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}

	{
		float4 Pos = _Level->GetMainCamera()->GetMouseWorldDir();
		std::string Name = "GetMouseWorldDir : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}

	ImGui::Text("");
	{
		float4 Pos = _Level->GetMainCameraActor()->GetTransform().GetLocalRotation();
		std::string Name = "MainCameraRotation : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}


	ImGui::Text("");
	{
		float4 Pos = _Level->GetMainCamera()->GetMouseScreenPosition();
		std::string Name = "GetMouseScreenPosition : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}

	{
		float4 Pos = _Level->GetMainCamera()->GetMouseWorldPosition();
		std::string Name = "GetMouseWorldPosition : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}

	

	ImGui::Text("");
	{
		float4 Pos = ActorPicker::PickerAngle;
		std::string Name = "PickerAngle : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
		ImGui::Text(Name.c_str());
	}

	ImGui::Text("");
	{
		size_t Num = ActorPicker::PickedActors.size();
		std::string Name = "PickedActorsNum : " + std::to_string(Num);
		ImGui::Text(Name.c_str());
	}
	{
		GameEngineActor* Actor = ActorPicker::PickedActor;
		if (nullptr == Actor)
		{
			ImGui::Text("There is no Picked Actor");
		}
		else
		{
			float4 Pos = Actor->GetTransform().GetWorldPosition();
			std::string Name = "PickedActor : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
			ImGui::Text(Name.c_str());
		}

	}
	{
		GameEngineActor* Actor = ActorPicker::ClickedActor;
		if (nullptr == Actor)
		{
			ImGui::Text("There is no Clicked Actor");
		}
		else
		{
			float4 Pos = Actor->GetTransform().GetWorldPosition();
			std::string Name = "ClickedActor : " + std::to_string(Pos.x) + " | " + std::to_string(Pos.y) + " | " + std::to_string(Pos.z);
			ImGui::Text(Name.c_str());
		}
	}
	{
		float4 Vec = ActorPicker::MouseDir;
		std::string String = "MouseDir : " + std::to_string(Vec.x) + " | " + std::to_string(Vec.y) + " | " + std::to_string(Vec.z);
		ImGui::Text(String.c_str());
	}

}
