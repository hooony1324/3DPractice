#include "PreCompile.h"
#include "TestLevel2.h"

#include "Actor_Plane.h"
#include "Actor_Character.h"

GameEngineActor* TestLevel2::Player = nullptr;

TestLevel2::TestLevel2() 
{
}

TestLevel2::~TestLevel2() 
{
}

void TestLevel2::Start()
{

}

void TestLevel2::Update(float _DeltaTime)
{
	FollowMainCamToPlayer(_DeltaTime);
}

void TestLevel2::End()
{
}

void TestLevel2::LevelStartEvent()
{
	ResourcesLoad();

	GetMainCamera()->SetProjectionMode(CAMERAPROJECTIONMODE::PersPective);
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

	// 텍스쳐 리소스 로드
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


	// 사운드 리소스 로드
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


	// 엑터 생성/관리
	GameEngineActor* Plane = CreateActor<Actor_Plane>();
	Plane->GetTransform().SetWorldScale({ 2000, 2000, 20 });
	Plane->GetTransform().SetWorldRotation({ 90, 0, 0 });

	Player = CreateActor<Actor_Character>();
	Player->GetTransform().SetWorldScale({ 100, 80, 40 });
	Player->GetTransform().SetWorldPosition({ 0, 90, 0 });

	LevelActors.push_back(Plane);
	LevelActors.push_back(Player);
}

void TestLevel2::FollowMainCamToPlayer(float _DeltaTime)
{
	if (true == GetMainCameraActor()->IsFreeCameraMode())
	{
		return;
	}

	// 이동
	float DeltaTime = abs(_DeltaTime);

	float4 PlayerPos = Player->GetTransform().GetWorldPosition() + float4(0, 80, -800);
	float4 CamPos = GetMainCameraActor()->GetTransform().GetWorldPosition();

	float4 NextCamPos = float4::Lerp(CamPos, PlayerPos, DeltaTime * 4.5f);

	GetMainCameraActor()->GetTransform().SetWorldPosition(NextCamPos);

	// 바라보기
	
}
