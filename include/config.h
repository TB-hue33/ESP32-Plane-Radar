#pragma once

// =============================================================================
// config.h
//
// THIS IS THE ONLY FILE MODIFIED FROM THE ORIGINAL REPO.
//
// Changes made:
//   1. Added kWifiSsid + kWifiPassword  — hardcoded WiFi credentials.
//   2. Set kDefaultRadarLat / kDefaultRadarLon to your fixed location.
//   3. kWifiPortalTimeoutSec = 0 so WiFiManager never blocks waiting for
//      a portal interaction (it connects immediately using saved credentials).
//
// The original source files (main.cpp, wifi_setup.cpp, adsb_client.cpp, etc.)
// are left completely unchanged.
// =============================================================================

namespace config {

// ---------------------------------------------------------------------------
// Hardcoded WiFi credentials
// wifi_setup.cpp will use these to pre-populate and auto-connect.
// ---------------------------------------------------------------------------
constexpr const char* kWifiSsid     = "ToroBravo";
constexpr const char* kWifiPassword = "Sneakerman33";

// ---------------------------------------------------------------------------
// Fixed radar location  (Garden City / Long Island, NY)
// radar_location.cpp uses these as the default when NVS has no saved position.
// After first boot they are stored in NVS and the portal is never needed.
// ---------------------------------------------------------------------------
constexpr double kDefaultRadarLat = 40.74543;
constexpr double kDefaultRadarLon = -73.64251;

// ---------------------------------------------------------------------------
// Portal / captive AP
// ---------------------------------------------------------------------------
constexpr const char* kPortalApName   = "PlaneRadar-Setup";
constexpr const char* kPortalIp       = "192.168.4.1";
constexpr const char* kPortalHostname = "plane-radar";
constexpr const char* kPortalHostUrl  = "http://plane-radar.local";

// ---------------------------------------------------------------------------
// WiFi timing
// Exact names required by wifi_setup.cpp (verified from compiler errors).
// kWifiPortalTimeoutSec = 0 means autoConnect() returns immediately
// when saved credentials work — the portal is never shown.
// ---------------------------------------------------------------------------
constexpr int kWifiPortalTimeoutSec  = 0;     // 0 = no portal timeout
constexpr int kWifiConnectAttemptMs  = 10000; // ms to wait for initial connect
constexpr int kWifiConnectingFrameMs = 100;   // ms per status-screen refresh

// ---------------------------------------------------------------------------
// BOOT button  (GPIO 9, active LOW)
// ---------------------------------------------------------------------------
constexpr int kBootPin         = 9;
constexpr int kBootResetHoldMs = 3000;
constexpr int kBootTapMinMs    = 50;

// ---------------------------------------------------------------------------
// Display  (GC9A01 SPI)
// Exact names required by lgfx_config.hpp (verified from compiler errors).
// ---------------------------------------------------------------------------
constexpr int  kDisplayPinRst     = 0;
constexpr int  kDisplayPinCs      = 1;
constexpr int  kDisplayPinDc      = 10;
constexpr int  kDisplayPinMosi    = 3;
constexpr int  kDisplayPinSclk    = 4;
constexpr bool kDisplayInvert     = true;
constexpr bool kDisplayRgbOrder   = false;    // false = BGR
constexpr int  kDisplaySpiWriteHz = 80000000;

// ---------------------------------------------------------------------------
// ADS-B
// Exact names required by adsb_client.cpp (verified from compiler errors).
// ---------------------------------------------------------------------------
constexpr int  kAdsbFetchIntervalMs    = 5000;  // 5 s poll
constexpr bool kAdsbShowGroundAircraft = false; // hide ground traffic

// ---------------------------------------------------------------------------
// NVS namespace
// ---------------------------------------------------------------------------
constexpr const char* kNvsNamespace = "planeradar";

} // namespace config
