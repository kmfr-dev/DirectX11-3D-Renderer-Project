#include "Engine/Engine.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    if (!CEngine::GetInst()->Init(hInstance))
    {
        CEngine::DestroyInst();
        return 0;
    }	

    int Ret = CEngine::GetInst()->RunEngine();

    CEngine::DestroyInst();

    return Ret;
}