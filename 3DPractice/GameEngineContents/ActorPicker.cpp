#include "PreCompile.h"
#include "ActorPicker.h"
#include <GameEngineCore/CoreMinimal.h>

#include <GameEngineBase/GameEngineTransform.h>


float4 ActorPicker::PickerAngle = float4::ZERO;
float4 ActorPicker::MouseDir = float4::ZERO;
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
	
	// 카메라와 동일한 위치 
	CamPos = GetLevel()->GetMainCameraActor()->GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition(CamPos);

	// 피킹용 콜리전(Ray) 회전
	float4 MouseVectorFromCam = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	PickerAngle = float4(MouseVectorFromCam.y * GameEngineMath::RadianToDegree * -1,
		MouseVectorFromCam.x * GameEngineMath::RadianToDegree,
		MouseVectorFromCam.z * GameEngineMath::RadianToDegree);

	float4 Rot = GetLevel()->GetMainCameraActor()->GetTransform().GetLocalRotation();
	GetTransform().SetWorldRotation(Rot + PickerAngle);

	// Ray와 충돌확인
	SelectPickedActor();

	// 피킹 오브젝트 클릭체크
	ClickCheck();

	// 마우스 조작
	ClickControl();
}

void ActorPicker::End()
{
}

// 일직선상 엑터들중 가장 가까운거 고름
// 카메라보다는 앞에 있어야함
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
	// FSM으로 분리하는게 좋을듯
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

void ActorPicker::ClickControl()
{
	if (nullptr == ClickedActor)
	{
		return;
	}

	MouseDir = GetLevel()->GetMainCamera()->GetMouseWorldDir();

	// 이동속도
	MouseDir *= 300;

	// x축 이동
	ClickedActor->GetTransform().SetWorldMove({ MouseDir.x, 0, 0 });
}
