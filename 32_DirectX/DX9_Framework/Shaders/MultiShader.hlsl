texture srcMap;

sampler srcSamp
{
    Texture = srcMap;
};

texture destMap;

sampler destSamp
{
    Texture = destMap;
};

float2 uvStart;
float2 uvEnd;

float4 main(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
        return destColor * srcColor;
    
    return srcColor;
}

technique tech
{
    pass p0
    {
        PixelShader = compile ps_2_0 main();
    }
}