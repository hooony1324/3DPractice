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
	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 1, 1, 1 });
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
	}
}

void Actor_Character::Update(float _DeltaTime)
{
	InputController(_DeltaTime);


	GetTransform().SetWorldMove(MoveDir * MoveSpeed * _DeltaTime);
}

void Actor_Character::End()
{
}

void Actor_Character::ActivateGravity()
{
	// 바닥이 없으면 (y축)
	


	// 내려간다
}

void Actor_Character::InputController(float _DeltaTime)
{
	MoveDir = float4::ZERO;


	if (true == GameEngineInput::GetInst()->IsPress("W"))
	{
		MoveDir += float4::FORWARD;
	}

	if (true == GameEngineInput::GetInst()->IsPress("A"))
	{
		MoveDir += float4::LEFT;
	}

	if (true == GameEngineInput::GetInst()->IsPress("S"))
	{
		MoveDir += float4::BACK;
	}

	if (true == GameEngineInput::GetInst()->IsPress("D"))
	{
		MoveDir += float4::RIGHT;
	}

}
