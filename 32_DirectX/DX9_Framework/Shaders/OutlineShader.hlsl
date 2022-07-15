texture map;

sampler samp
{
	Texture = map;
};

float4 Color;
float2 ImageSize;
int    Weight;

float4 main(float2 uv : TEXCOORD) : SV_TARGET
{
	int count = 0;
	
	for (float y = -1.0f; y < 1.0f; y++)
	{
		for (float x = -1.0f; x < 1.0f; x++)
		{
			float2 offset = float2(x, y) / ImageSize;
			float4 result = tex2D(samp, uv + offset);
			
			if(result.a > 0.0f)
				count++;
		}
	}
	
	if (count > 0 && count < 1 + Weight)
	{
		return Color;
	}
	
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