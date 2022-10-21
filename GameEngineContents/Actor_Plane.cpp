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
	Renderer->GetTransform().SetLocalScale({100, 100, 1});

}

void Actor_Plane::Update(float _DeltaTime)
{
}

void Actor_Plane::End()
{
}
