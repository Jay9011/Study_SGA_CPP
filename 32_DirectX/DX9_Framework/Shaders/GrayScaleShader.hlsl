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
    
    result.rgb = result.r * 0.3f + result.g * 0.59f + result.b * 0.11f;
    
    return result * Color;
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
}