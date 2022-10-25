#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TestLevel1.h"
#include "GameEngineContents/TestLevel2.h"

#include "ContentsManagerGUI.h"
#include <GameEngineCore/GameEngineDepthStencil.h>

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


	// RTTI 런 타임 타입 인포메이션
	CreateLevel<TestLevel1>("TestLevel1");
	CreateLevel<TestLevel2>("TestLevel2");
	ChangeLevel("TestLevel1");
	
	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
	GameEngineGUI::CreateGUIWindow<ContentsManagerGUI>("ContentsManager", nullptr);

	// 쉐이더 로드
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("ContentsShader");
		Dir.Move("ContentsShader");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile("hlsl");

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineShader::AutoCompile(Shaders[i].GetFullPath());
		}
	}

	// 테스트 메쉬 로드
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("Resources");
		Dir.Move("Resources");
		Dir.Move("Mesh");

		GameEngineFBXMesh* Mesh = GameEngineFBXMesh::Load(Dir.PlusFilePath("2Handed.FBX"));
	}


	// 렌더링 파이프라인 추가
	{
		GameEngineMaterial* Material = GameEngineMaterial::Create("Outline");
		Material->SetVertexShader("Outline.hlsl");
		Material->SetPixelShader("Outline.hlsl");
	}

	// 스텐실용 버퍼추가
	{
		D3D11_DEPTH_STENCIL_DESC Desc = { 0 };

		Desc.DepthEnable = TRUE;
		Desc.StencilEnable = TRUE;
		Desc.StencilReadMask = 0xFF;
		Desc.FrontFace.StencilFunc = D3D11_COMPARISON_NOT_EQUAL;
		Desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		GameEngineDepthStencil::Create("OutlineStencil", Desc);
	}

}

void ContentsCore::Update(float _DeltaTime)
{
}

void ContentsCore::End()
{
}