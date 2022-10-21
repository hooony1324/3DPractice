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
}

void Actor_Box::Update(float _DeltaTime)
{
}

void Actor_Box::End()
{
}
