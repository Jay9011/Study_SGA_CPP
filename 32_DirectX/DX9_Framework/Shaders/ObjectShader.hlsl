//HLSL : High Level Shader Language

texture map;

sampler samp
{
	Texture = map;
};

float4 main(float2 uv : TEXCOORD) : SV_TARGET
{
	return tex2D(samp, uv);
}

technique tech
{
	pass p0
	{
		AlphaBlendEnable = true;
		BlendOp = Add;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

		PixelShader = compile ps_2_0 main();
	}
}