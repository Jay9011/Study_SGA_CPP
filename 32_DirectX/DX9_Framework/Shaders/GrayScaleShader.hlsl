texture map;

sampler samp
{
    Texture = map;
};

float4 Color;

float4 main(float2 uv : TEXCOORD) : SV_TARGET
{
    float4 result = tex2D(samp, uv);
    
    result.rgb = (result.r + result.g + result.b) / 3;

    return result * Color;
}

float4 GrayScale(float2 uv : TEXCOORD) : SV_TARGET
{
    float4 result = tex2D(samp, uv);
    
    //result.rgb = result.r * 0.3f + result.g * 0.59f + result.b * 0.11f;
	result.rgb = dot(result.rgb, float3(0.3f, 0.59f, 0.11f));
    
    return result * Color;
}

float4 Sepia(float2 uv : TEXCOORD) : SV_TARGET
{
    float4 result = tex2D(samp, uv);

	float4 sepia = result;
    
	sepia.r = dot(result.rgb, float3(0.393f, 0.769f, 0.189f));
	sepia.g = dot(result.rgb, float3(0.349f, 0.686f, 0.168f));
	sepia.b = dot(result.rgb, float3(0.272f, 0.534f, 0.131f));
    
    return sepia * Color;
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

    pass p1
    {
        AlphaBlendEnable = true;
        BlendOp = Add;
        SrcBlend = SrcAlpha;
        DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 GrayScale();
    }

    pass p2
    {
        AlphaBlendEnable = true;
        BlendOp = Add;
        SrcBlend = SrcAlpha;
        DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 Sepia();
    }

}