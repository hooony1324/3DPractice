#include "PreCompile.h"
#include "Actor_Plane.h"
#include <GameEngineCore/CoreMinimal.h>

Actor_Plane::Actor_Plane() 
{
}

Actor_Plane::~Actor_Plane() 
{
}

void Actor_Plane::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("patrickstar.png");
	Renderer->GetTransform().SetLocalScale(float4::ONE);

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalScale());
	Collision->SetDebugSetting(CollisionType::CT_OBB, float4(0.2f, 0.2f, 0.2f, 0.25f));
	Collision->ChangeOrder(CollisionGroup::Map);
}

void Actor_Plane::Update(float _DeltaTime)
{
}

void Actor_Plane::End()
{
}
