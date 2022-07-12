// HLSL : High Level Shader Language

texture map;

sampler samp
{
	Texture = map;
};

float4 Color;

float4 main(float2 uv : TEXCOORD) : SV_TARGET
{
	return tex2D(samp, uv) * Color;
}

technique tech
{
	pass p0
	{
		PixelShader = compile ps_2_0 main();
	}
}