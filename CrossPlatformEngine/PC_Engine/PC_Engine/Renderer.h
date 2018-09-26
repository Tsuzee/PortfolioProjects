//Darren Farr
#pragma once

#include <vector>
#include "DXCore.h"
#include <DirectXMath.h>
#include "SimpleShader.h"
#include "../../SharedCode/Vertex.h"
#include "../../SharedCode/Entity.h"
#include "../../SharedCode/Camera.h"
#include "../../SharedCode/Scene.h"
#include "../../SharedCode/Lights.h"

// Renders a scene using DirectX11
class Renderer
{
public:
	Renderer();
	~Renderer();

	void Init(Camera*, ID3D11Device*, ID3D11DeviceContext*, ID3D11RenderTargetView*, IDXGISwapChain*, ID3D11DepthStencilView*, unsigned int width, unsigned int height);
	void Resized(ID3D11DepthStencilView*, ID3D11RenderTargetView*, unsigned int width, unsigned int height);
	void Draw(float, float);

	void SetShaders(SimpleVertexShader*, SimplePixelShader*, SimpleVertexShader*, SimplePixelShader*,
		SimpleVertexShader*, SimplePixelShader*, SimplePixelShader*, SimplePixelShader*, SimpleVertexShader*, SimplePixelShader*);

	void SetScene(Scene*);

private:
	void setWidthHeight(unsigned int width, unsigned int height, ID3D11DepthStencilView* depthStencilView);
	void SetPixelShaderUp(SimplePixelShader*, std::vector<Entity*>, int);
	void CreateAdditionalRSStates();

	unsigned int mWidth, mHeight;
	
	Camera* Cam;
	Scene* currentScene;
	
	ID3D11Device* mDevice;
	ID3D11DeviceContext* context;
	ID3D11RenderTargetView* backBufferRTV;
	IDXGISwapChain* swapChain;
	ID3D11DepthStencilView* mDepthStencilView;
	
	// Shaders
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;
	SimpleVertexShader* vertexShaderNormalMap;
	SimplePixelShader* pixelShaderNormalMap;
	SimpleVertexShader* skyVS;
	SimplePixelShader* skyPS;

	SimplePixelShader* pixelShaderBlend;
	SimplePixelShader* pixelShaderNormalMapBlend;

	// Particle Shaders
	SimpleVertexShader* particleVS;
	SimplePixelShader* particlePS;


	// Buffers to hold actual geometry data
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;

	// The matrices to go from model space to screen space
	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix;

	// Render states
	ID3D11RasterizerState* defaultState;
	ID3D11RasterizerState* rsNoCull;
	ID3D11BlendState* bsAlphaBlend;
	
	// Helper to convert types from generic to platform specific
	Helpers* myHelper;
	
	// These may need to be moved
	//-----------------------------------
	ID3D11RenderTargetView* ppRTV;	
	ID3D11ShaderResourceView* ppSRV;
	//-----------------------------------
};