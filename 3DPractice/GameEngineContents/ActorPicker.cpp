#include "PreCompile.h"
#include "ActorPicker.h"
#include <GameEngineCore/CoreMinimal.h>

#include <GameEngineBase/GameEngineTransform.h>


float4 ActorPicker::PickerAngle = float4::ZERO;
std::set<GameEngineActor*> ActorPicker::PickedActors;
GameEngineActor* ActorPicker::PickedActor = nullptr;
GameEngineActor* ActorPicker::ClickedActor = nullptr;

ActorPicker::ActorPicker() 
{
}

ActorPicker::~ActorPicker() 
{
}

void ActorPicker::Start()
{
	Collision_Ray = CreateComponent<GameEngineCollision>();
	Collision_Ray->GetTransform().SetWorldScale({ 0.00002f, 0.00002f, 100000 });
	Collision_Ray->ChangeOrder(CollisionGroup::Ray);
	Collision_Ray->SetDebugSetting(CollisionType::CT_OBB, float4(1.0f, 0, 0, 0.2f));
}

void ActorPicker::Update(float _DeltaTime)
{
	
	// ī�޶�� ������ ��ġ 
	CamPos = GetLevel()->GetMainCameraActor()->GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition(CamPos);

	// ��ŷ�� �ݸ���(Ray) ȸ��
	float4 MouseVectorFromCam = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	PickerAngle = float4(MouseVectorFromCam.y * GameEngineMath::RadianToDegree * -1,
		MouseVectorFromCam.x * GameEngineMath::RadianToDegree,
		MouseVectorFromCam.z * GameEngineMath::RadianToDegree);

	float4 Rot = GetLevel()->GetMainCameraActor()->GetTransform().GetLocalRotation();
	GetTransform().SetWorldRotation(Rot + PickerAngle);

	// Ray�� �浹Ȯ��
	SelectPickedActor();

	// ��ŷ ������Ʈ Ŭ��üũ
	ClickCheck();
}

void ActorPicker::End()
{
}

// �������� ���͵��� ���� ������ ��
// ī�޶󺸴ٴ� �տ� �־����
void ActorPicker::SelectPickedActor()
{
	if (0 == PickedActors.size())
	{
		PickedActor = nullptr;
		return;
	}

	GameEngineActor* Nearest = nullptr;
	for (GameEngineActor* Actor : PickedActors)
	{
		if (nullptr == Nearest)
		{
			Nearest = Actor;
		}
		else
		{
			Nearest = Nearest->GetTransform().GetWorldPosition().z < Actor->GetTransform().GetWorldPosition().z
				? Nearest : Actor;
		}
	}
	PickedActor = Nearest;
	Nearest = nullptr;

}

void ActorPicker::ClickCheck()
{
	if (nullptr == PickedActor)
	{
		return;
	}

	if (true == GameEngineInput::GetInst()->IsDown("M_LeftClick"))
	{
		ClickedActor = PickedActor;
		return;
	}

	if (true == GameEngineInput::GetInst()->IsFree("M_LeftClick"))
	{
		ClickedActor = nullptr;
		return;
	}

}
