#include "PreCompile.h"
#include "Actor_Box.h"
#include <GameEngineCore/CoreMinimal.h>

Actor_Box::Actor_Box() 
{
}

Actor_Box::~Actor_Box() 
{
}

void Actor_Box::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetPipeLine("Color");
	Renderer->SetMesh("Box");

	ResultColor = float4(0.5f, 1.0f, 1.0f, 1.0f);
	Renderer->GetShaderResources().SetConstantBufferLink("ResultColor", ResultColor);

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 1, 1, 1 });
	Collision->ChangeOrder(CollisionGroup::Map);
	Collision->SetDebugSetting(CollisionType::CT_OBB, float4( 0.0f, 1.0f, 0.0f, 0.5f ));

	GetTransform().SetWorldScale({ 100, 100, 100 });

	CreatePickingCollision(Collision->GetTransform().GetWorldScale());
}

void Actor_Box::Update(float _DeltaTime)
{

	CheckPickingRay();
}

void Actor_Box::End()
{
}
