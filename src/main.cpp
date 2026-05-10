#include <Geode/Geode.hpp>
#include <managers/RPCManager.hpp>
#include <managers/Observer.hpp>

using namespace geode::prelude;

std::string getSysName() {
#ifdef _WIN32
    if (GetModuleHandleA("ntdll.dll") && GetProcAddress(GetModuleHandleA("ntdll.dll"), "wine_get_version")) {
        return "Linux";
    }
    return "Windows";
#elif defined(__APPLE__)
    return "macOS";
#elif defined(__ANDROID__)
    return "Android";
#else
    return "Linux";
#endif
}

$on_mod(Loaded) {
    auto& rpcManager = RPCManager::get();
    rpcManager.initRPC();
    rpcManager.defaultState = "Browsing menus";
    rpcManager.defaultLargeImage = "gd-large";
    rpcManager.defaultLargeImageText = fmt::format("Playing Geometry Dash on {}", getSysName());
    rpcManager.startTime = time(0);

    // start doing things
    Observer::get();
}
