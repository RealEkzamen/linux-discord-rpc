#include <Geode/Geode.hpp>
#include <managers/RPCManager.hpp>
#include <managers/Observer.hpp>

using namespace geode::prelude;

std::string getSysName() {
#if defined(GEODE_IS_WINDOWS) || defined(GEODE_WINDOWS)
    if (GetModuleHandleA("ntdll.dll") && GetProcAddress(GetModuleHandleA("ntdll.dll"), "wine_get_version")) {
        return "Linux";
    }
    return "Windows";
#elif defined(GEODE_IS_MACOS) || defined(GEODE_MACOS)
    return "macOS";
#elif defined(GEODE_IS_ANDROID) || defined(GEODE_ANDROID)
    return "Android";
#elif defined(GEODE_IS_IOS) || defined(GEODE_IOS)
    return "iOS";
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
