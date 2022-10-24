#include "TransformHeader.fx"
#include "RenderOption.fx"

struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
};

struct Output
{
    float4 Pos : SV_POSITION;
    float4 Tex : TEXCOORD;
};


Output Color_VS(Input _Input)
{
    Output NewOutPut = (Output) 0;
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.Tex = _Input.Tex;
    
    return NewOutPut;
}


Texture2D Tex : register(t0);
SamplerState Smp : register(s0);


float4 Color_PS(Output _Input) : SV_Target0
{
    float2 TexPos = _Input.Tex.xy;
    
    float4 Color = Tex.Sample(Smp, TexPos);
    return Color;
}
