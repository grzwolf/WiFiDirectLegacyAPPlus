//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "stdafx.h"
#include "SimpleConsole.h"
#include "WlanHostedNetworkWinRT.h"

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

std::wstring s2ws(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

int _tmain(int argc, _TCHAR* argv[])
{
    // Initialize the Windows Runtime.
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize))
    {
        std::cout << "Failed to initialize Windows Runtime" << std::endl;
        return static_cast<HRESULT>(initialize);
    }

    SimpleConsole console;

    if (argc == 1) {
        // if there is no cmd line argument other than app's path+name, we start the AP with hard coded defaults
        std::string buf = "ssid testAP";
        console.ExecuteCommand(s2ws(buf));
        buf = "pass 12345678";
        console.ExecuteCommand(s2ws(buf));
        buf = "autoaccept 1";
        console.ExecuteCommand(s2ws(buf));
        buf = "start";
        console.ExecuteCommand(s2ws(buf));
    }
    else {
        // if there are two cmd line arguments other than the app's path+name, they are interpreted as ssid and pass 
        if (argc == 3) {
            TCHAR buf[100];
            _stprintf_s(buf, sizeof(buf) / sizeof(TCHAR), _T("ssid %s"), argv[1]);
            console.ExecuteCommand(buf);
            _stprintf_s(buf, sizeof(buf) / sizeof(TCHAR), _T("pass %s"), argv[2]);
            console.ExecuteCommand(buf);
            _stprintf_s(buf, sizeof(buf) / sizeof(TCHAR), _T("autoaccept 1"));
            console.ExecuteCommand(buf);
            _stprintf_s(buf, sizeof(buf) / sizeof(TCHAR), _T("start"));
            console.ExecuteCommand(buf);
        }
        else {
            // if there is one cmd line argument or more than 2, let's switch to interactive mode, just like the original app behaviour
        }
    }

    console.RunConsole();

    return 0;
}

