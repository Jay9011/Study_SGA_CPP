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

float4 Modulate2X(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
        return destColor * srcColor * 2;
    
    return srcColor;
}

float4 Add(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
        return destColor + srcColor;
    
    return srcColor;
}

float4 AddSmooth(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
		return destColor + srcColor - (destColor * srcColor);
    
    return srcColor;
}

float4 AddSigned(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
		return destColor + srcColor - 0.5;
    
    return srcColor;
}

float4 AddSigned2X(float2 uv : TEXCOORD) : SV_TARGET
{
    float4  srcColor = tex2D( srcSamp, uv);
    
    float2 rainbowUV = (uv - uvStart) / (uvEnd - uvStart);
    
    float4 destColor = tex2D(destSamp, rainbowUV);
    
    if (srcColor.a > 0.0f)
		return (destColor + srcColor - 0.5) * 2;
    
    return srcColor;
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

        PixelShader = compile ps_2_0 Modulate2X();
    }

    pass p2
    {
		AlphaBlendEnable = true;
		BlendOp = Add;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 Add();
    }

    pass p3
    {
		AlphaBlendEnable = true;
		BlendOp = Add;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 AddSmooth();
    }

    pass p4
    {
		AlphaBlendEnable = true;
		BlendOp = Add;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 AddSigned();
    }

    pass p5
    {
		AlphaBlendEnable = true;
		BlendOp = Add;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

        PixelShader = compile ps_2_0 AddSigned2X();
    }

}