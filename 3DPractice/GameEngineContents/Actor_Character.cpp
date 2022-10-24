#include "PreCompile.h"
#include "Actor_Character.h"
#include <GameEngineCore/CoreMinimal.h>

Actor_Character::Actor_Character() 
	: MoveSpeed(SPEED_PLAYER)
{
}

Actor_Character::~Actor_Character() 
{
}

void Actor_Character::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("blackcat.png");
	Renderer->GetTransform().SetLocalScale({ 1, 1, 1 });

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 1, 1, 1 });
	Collision->SetCollisionMode(CollisionMode::Ex);
	Collision->ChangeOrder(CollisionGroup::Player);
	Collision->SetDebugSetting(CollisionType::CT_OBB, float4(0.0f, 1.0f, 0.0f, 0.5f));

	GameEngineSoundPlayer SPlayer;
	SPlayer = GameEngineSound::SoundPlayControl("sound_tv_thump.wav");
	SPlayer.Volume(0.1f);

	if (false == GameEngineInput::GetInst()->IsKey("W"))
	{
		GameEngineInput::GetInst()->CreateKey("W", 'W');
		GameEngineInput::GetInst()->CreateKey("A", 'A');
		GameEngineInput::GetInst()->CreateKey("S", 'S');
		GameEngineInput::GetInst()->CreateKey("D", 'D');
		GameEngineInput::GetInst()->CreateKey("SpaceBar", VK_SPACE);

		GameEngineInput::GetInst()->CreateKey("R", 'R');
	}
}

void Actor_Character::Update(float _DeltaTime)
{
	float DeltaTime = abs(_DeltaTime);

	InputController(DeltaTime);
	ActivateGravity();

	if (abs(MoveDir.x) > 0.4f)
	{
		int a = 0;
	}
	GetTransform().SetWorldMove(MoveDir * MoveSpeed * DeltaTime);
}

void Actor_Character::End()
{
}

void Actor_Character::ActivateGravity()
{
	// 바닥이 없으면 (y축)
	bool IsGround = Collision->IsCollision(CollisionType::CT_OBB, CollisionGroup::Map, CollisionType::CT_OBB,
		[=](GameEngineCollision* _This, GameEngineCollision* _Other)
		{
			int a = 0;
			return CollisionReturn::ContinueCheck;
		});


	// 내려간다
	if (false == IsGround)
	{
		MoveDir.y = -1.0f;
	}
	else
	{
		MoveDir.y = 0.0f;
	}
}

void Actor_Character::InputController(float _DeltaTime)
{
	MoveDir = float4::ZERO;


	if (true == GameEngineInput::GetInst()->IsPress("W"))
	{
		MoveDir += float4(0.0f, 0.0f, 1.0f, 0.0f);
	}

	if (true == GameEngineInput::GetInst()->IsPress("A"))
	{
		MoveDir += float4(-1.0f, 0.0f, 0.0f, 0.0f);
	}

	if (true == GameEngineInput::GetInst()->IsPress("S"))
	{
		MoveDir += float4(0.0f, 0.0f, -1.0f, 0.0f);
	}

	if (true == GameEngineInput::GetInst()->IsPress("D"))
	{
		MoveDir += float4(1.0f, 0.0f, 0.0f, 0.0f);
	}

	if (true == GameEngineInput::GetInst()->IsPress("SpaceBar"))
	{
		GetTransform().SetWorldMove({ 0, 10, 0 });
	}

	if (true == GameEngineInput::GetInst()->IsPress("R"))
	{
		Renderer->GetTransform().SetAddWorldRotation({ 0, 360 * abs(_DeltaTime), 0 });
	}


}
