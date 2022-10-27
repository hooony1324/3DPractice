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

		for (GameEngineFile& File : Dir.GetAllFile(".FBX"))
		{
			GameEngineFBXMesh* Mesh = GameEngineFBXMesh::Load(File.GetFullPath());

			std::vector<FBXNodeInfo> Nodes = Mesh->CheckAllNode();
		}
		//for (GameEngineDirectory Dir.GetAllFile(".FBX");
		//GameEngineFBXMesh* Mesh = GameEngineFBXMesh::Load(Dir.PlusFilePath("2Handed.FBX"));
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

		Desc.DepthEnable = false;
		Desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		Desc.DepthFunc = D3D11_COMPARISON_LESS;
		Desc.StencilEnable = true;
		Desc.StencilReadMask = 0xff;
		Desc.StencilWriteMask = 0xff;

		Desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		Desc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
		Desc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
		Desc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		Desc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		Desc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_KEEP;
		Desc.BackFace.StencilPassOp = D3D11_STENCIL_OP_REPLACE;
		Desc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		GameEngineDepthStencil::Create("OutlineStencil", Desc);
	}

	// Ű �߰�
	GameEngineInput::GetInst()->CreateKey("M_LeftClick", VK_LBUTTON);


}

void ContentsCore::Update(float _DeltaTime)
{
}

void ContentsCore::End()
{
}