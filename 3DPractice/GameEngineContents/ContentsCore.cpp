#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TestLevel1.h"
#include "GameEngineContents/TestLevel2.h"

#include "ContentsManagerGUI.h"

#pragma comment(lib, "GameEngineBase.lib")

ContentsCore::ContentsCore() 
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{

	GameEngineTime::SetLimitFrame(60);


	// RTTI �� Ÿ�� Ÿ�� �������̼�
	CreateLevel<TestLevel1>("TestLevel1");
	CreateLevel<TestLevel2>("TestLevel2");
	ChangeLevel("TestLevel1");
	
	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
	GameEngineGUI::CreateGUIWindow<ContentsManagerGUI>("ContentsManager", nullptr);

	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("Resources");
		Dir.Move("Resources");
		Dir.Move("Mesh");

		GameEngineFBXMesh* Mesh = GameEngineFBXMesh::Load(Dir.PlusFilePath("2Handed.FBX"));

	}
}

void ContentsCore::Update(float _DeltaTime)
{
}

void ContentsCore::End()
{
}