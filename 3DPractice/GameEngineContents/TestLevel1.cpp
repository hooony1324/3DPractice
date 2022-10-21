#include "PreCompile.h"
#include "TestLevel1.h"
#include <GameEngineCore/CoreMinimal.h>

#include "Actor_Plane.h"
#include "Actor_Box.h"

TestLevel1::TestLevel1()
{
}

TestLevel1::~TestLevel1()
{
}

void TestLevel1::Start()
{



}



void TestLevel1::Update(float _DeltaTime)
{
}



void TestLevel1::End()
{
}

void TestLevel1::LevelStartEvent()
{
	ResourcesLoad();
}

void TestLevel1::LevelEndEvent()
{
	for (GameEngineActor* Actor : LevelActors)
	{
		Actor->Death();
	}
}

void TestLevel1::ResourcesLoad()
{
	// 텍스쳐 리소스 로드
	GameEngineDirectory Dir;
	Dir.MoveParentToExitsChildDirectory("Resources");
	Dir.Move("Resources");

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

		// 엑터 생성
		GameEngineActor* Plane = CreateActor<Actor_Plane>();
		Plane->GetTransform().SetWorldScale({ 100, 100, 20 });
		Plane->GetTransform().SetWorldPosition({ -200, -200, 0 });
		LevelActors.push_back(Plane);
	}

	


	for (int i = 0; i < 100; i++)
	{
		GameEngineActor* Box = CreateActor<Actor_Box>();
		Box->GetTransform().SetWorldScale({ 100, 100, 100 });
		float4 Move = float4(cosf(i * 30.0f * GameEngineMath::DegreeToRadian) * i * 50, sinf(i * 30.0f * GameEngineMath::DegreeToRadian) * i * 50);
		Box->GetTransform().SetWorldMove(Move);
		LevelActors.push_back(Box);
	}
}
