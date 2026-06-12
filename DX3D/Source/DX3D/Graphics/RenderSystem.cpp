#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG; //Что это значит вообще? Узнать что за оператор используется, а также узнать что значит тут _DEBUG
#endif

	DX3DGraphicsLogErrorAndThrow(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION,
		&m_d3Device, &featureLevel, &m_d3dContext), "Direct3D11 initialization failed.");

	//Проверка на объект, поддерживает ли он указанный интерфейс. Если да, то получить указатель на этот интерфейс
	DX3DGraphicsLogErrorAndThrow(m_d3Device->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),//Макрос, который безопасно получает указатель на интерфейс
		"QueryInterface failed to load");

	DX3DGraphicsLogErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"Failed to load IDXGIAdapter.");

	DX3DGraphicsLogErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"Failed to load IDXGIAdapter.");

	
}

dx3d::RenderSystem::~RenderSystem()
{
}
