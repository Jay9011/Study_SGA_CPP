texture map;

sampler samp
{
	Texture = map;
};

matrix world;
matrix view;
matrix projection;

struct VertexInput
{
	float4 pos : POSITION;
	float2 uv  : TEXCOORD;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
	float2 uv  : TEXCOORD;
};

VertexOutput VS (VertexInput input)
{
	VertexOutput output;
	
	output.pos = mul(input.pos, world);
	output.pos = mul(output.pos, view);
	output.pos = mul(output.pos, projection);
	
	output.uv  = input.uv;
	
	return output;
}

float4 PS(VertexOutput input) : SV_Target
{
	float2 uv = input.uv;
	
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

		VertexShader = compile vs_2_0 VS();
		 PixelShader = compile ps_2_0 PS();
	}
}