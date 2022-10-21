#include "PreCompile.h"
#include "TestLevel2.h"

#include "Actor_Plane.h"
#include "Actor_Character.h"

TestLevel2::TestLevel2() 
{
}

TestLevel2::~TestLevel2() 
{
}

void TestLevel2::Start()
{
	GetMainCamera()->SetProjectionMode(CAMERAPROJECTIONMODE::PersPective);
}

void TestLevel2::Update(float _DeltaTime)
{
	FollowMainCamToPlayer();
}

void TestLevel2::End()
{
}

void TestLevel2::LevelStartEvent()
{
	ResourcesLoad();
}

void TestLevel2::LevelEndEvent()
{
	for (GameEngineActor* Actor : LevelActors)
	{
		Actor->Death();
	}
}

void TestLevel2::ResourcesLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToExitsChildDirectory("Resources");
	Dir.Move("Resources");

	// �ؽ��� ���ҽ� �ε�
	{
		GameEngineDirectory TextureDir(Dir);
		TextureDir.Move("Texture");

		for (GameEngineFile& File : TextureDir.GetAllFile(".png"))
		{
			if (nullptr == GameEngineTexture::Find(File.GetFileName()))
			{
				GameEngineTexture::Load(File.GetFullPath());
			}
		}
	}


	// ���� ���ҽ� �ε�
	{
		GameEngineDirectory SoundDir(Dir);
		SoundDir.Move("Sound");

		for (GameEngineFile& File : SoundDir.GetAllFile())
		{
			if (nullptr == GameEngineSound::FindRessource(File.GetFileName()))
			{
				GameEngineSound::LoadRessource(File.GetFullPath());
			}
		}
	}


	// ���� ����/����
	GameEngineActor* Plane = CreateActor<Actor_Plane>();
	Plane->GetTransform().SetWorldScale({ 1000, 1000, 20 });
	Plane->GetTransform().SetWorldRotation({ 70, 0, 0 });

	Player = CreateActor<Actor_Character>();
	Player->GetTransform().SetWorldScale({ 40, 80, 40 });
	Player->GetTransform().SetWorldPosition({ 0, 90, 0 });

	LevelActors.push_back(Plane);
	LevelActors.push_back(Player);
}

void TestLevel2::FollowMainCamToPlayer()
{
	GetMainCamera()->GetTransform().SetWorldPosition(Player->GetTransform().GetWorldPosition() + float4(0, 40, 0));
}