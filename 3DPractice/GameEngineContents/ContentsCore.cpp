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


	// RTTI �� Ÿ�� Ÿ�� �������̼�
	CreateLevel<TestLevel1>("TestLevel1");
	CreateLevel<TestLevel2>("TestLevel2");
	ChangeLevel("TestLevel1");
	
	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
	GameEngineGUI::CreateGUIWindow<ContentsManagerGUI>("ContentsManager", nullptr);

	// ���̴� �ε�
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

	// �׽�Ʈ �޽� �ε�
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("Resources");
		Dir.Move("Resources");
		Dir.Move("Mesh");

		GameEngineFBXMesh* Mesh = GameEngineFBXMesh::Load(Dir.PlusFilePath("2Handed.FBX"));
	}


	// ������ ���������� �߰�
	{
		GameEngineMaterial* Material = GameEngineMaterial::Create("Outline");
		Material->SetVertexShader("Outline.hlsl");
		Material->SetPixelShader("Outline.hlsl");
	}

	// ���ٽǿ� �����߰�
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