#include "StdAfx.h"
#include "WindowPositionGemCVars.h"
#include <windows.h>
#include <Winuser.h>
#include <ISystem.h>

using namespace WindowPositionGem;

void WindowPositionGemCVars::RegisterCVars()
{
    if (gEnv && !gEnv->IsEditor())
    {
        REGISTER_COMMAND("windowx", WindowX, 0,
            "set X position of the window");
        REGISTER_COMMAND("windowy", WindowY, 0,
            "set X position of the window");
        REGISTER_COMMAND("windowxy", WindowXY, 0,
            "set X and Y position of the window");
    }
}

void WindowPositionGemCVars::UnregisterCVars()
{
    if (gEnv && !gEnv->IsEditor())
    {
        UNREGISTER_CVAR("windowx");
        UNREGISTER_CVAR("windowy");
        UNREGISTER_CVAR("windowxy");
    }
}

void WindowPositionGemCVars::WindowX(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 1)
    {
        const auto x = atoi(args->GetArg(1));

        if (const auto windowHandle = GetActiveWindow())
        {
            WINDOWINFO windowInfo;
            windowInfo.cbSize = sizeof(WINDOWINFO);
            if (GetWindowInfo(windowHandle, &windowInfo))
                SetWindowPos(windowHandle, nullptr,
                    x,
                    windowInfo.rcWindow.top,
                    0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
        }
    }
}

void WindowPositionGemCVars::WindowY(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 1)
    {
        const auto y = atoi(args->GetArg(1));

        if (const auto windowHandle = GetActiveWindow())
        {
            WINDOWINFO windowInfo;
            windowInfo.cbSize = sizeof(WINDOWINFO);
            if (GetWindowInfo(windowHandle, &windowInfo))
                SetWindowPos(windowHandle, nullptr,
                    windowInfo.rcWindow.left,
                    y,
                    0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
        }
    }
}

void WindowPositionGemCVars::WindowXY(IConsoleCmdArgs* args)
{
    if (args->GetArgCount() > 2)
    {
        const auto x = atoi(args->GetArg(1));
        const auto y = atoi(args->GetArg(2));

        if (const auto windowHandle = GetActiveWindow())
            SetWindowPos(windowHandle, nullptr,
                x,
                y,
                0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE);
    }
}
