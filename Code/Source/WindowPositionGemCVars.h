#pragma once

#include <IConsole.h>

namespace WindowPositionGem
{
    class WindowPositionGemCVars
    {
    public:
        void RegisterCVars();
        void UnregisterCVars();

        static void WindowX(IConsoleCmdArgs* args);
        static void WindowY(IConsoleCmdArgs* args);
        static void WindowXY(IConsoleCmdArgs* args);
    };
}
