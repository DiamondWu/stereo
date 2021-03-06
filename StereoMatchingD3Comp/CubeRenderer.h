﻿#pragma once

#include "Direct3DBase.h"
#include "CostVolumeRenderer.h"
#include "MeanImagesRenderer.h"

struct ModelViewProjectionConstantBuffer
{
	DirectX::XMFLOAT4X4 model;
	DirectX::XMFLOAT4X4 view;
	DirectX::XMFLOAT4X4 projection;
};

struct VertexPositionTexel
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 tex;
};

// This class renders a simple spinning cube.
ref class CubeRenderer sealed : public Direct3DBase
{
public:
	CubeRenderer();

	// Direct3DBase methods.
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;
	
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);

private:
	void Render(ID3D11ShaderResourceView * * resource);

	bool m_loadingComplete;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_sampler;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture1;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture1View;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_texture2;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture2View;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_indexBuffer;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pixelShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_constantBuffer;

	CostVolumeRenderer * m_costVolumeRenderer;
	MeanImagesRenderer * m_meanImagesRenderer;
	
	uint32 m_indexCount;

	Microsoft::WRL::ComPtr<ID3D11Buffer> m_constantParameterBuffer;
	bool m_sameImage;
};
