#pragma once

// =============================================================================
// config.h
//
// THIS IS THE ONLY FILE MODIFIED FROM THE ORIGINAL REPO.
//
// Changes made:
//   1. Added kWifiSsid + kWifiPassword  — hardcoded WiFi credentials.
//   2. Set kDefaultRadarLat / kDefaultRadarLon to your fixed location.
//   3. kWifiPortalTimeoutSec = 0 so WiFiManager never shows the portal.
//   4. Added all constants discovered via compiler errors across 4 build runs.
// =============================================================================

namespace config {

// ---------------------------------------------------------------------------
// Hardcoded WiFi credentials
// ---------------------------------------------------------------------------
constexpr const char* kWifiSsid     = "ToroBravo";
constexpr const char* kWifiPassword = "Sneakerman33";

// ---------------------------------------------------------------------------
// Fixed radar location  (Garden City / Long Island, NY)
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
// WiFi timing  (all names verified from wifi_setup.cpp + main.cpp errors)
// kWifiPortalTimeoutSec = 0 → autoConnect() never blocks on the portal
// ---------------------------------------------------------------------------
constexpr int kWifiPortalTimeoutSec    = 0;     // 0 = no portal timeout
constexpr int kWifiConnectAttemptMs    = 10000; // ms to wait per connect attempt
constexpr int kWifiConnectingFrameMs   = 100;   // ms per status-screen refresh tick
constexpr int kWifiConnectAttempts     = 3;     // retry count (wifi_setup.cpp)
constexpr int kWifiDownGraceMs         = 5000;  // ms WiFi can be down before reconnect
constexpr int kWifiReconnectIntervalMs = 30000; // ms between reconnect attempts

// ---------------------------------------------------------------------------
// BOOT button  (GPIO 9, active LOW)
// ---------------------------------------------------------------------------
constexpr int kBootPin         = 9;
constexpr int kBootResetHoldMs = 3000;
constexpr int kBootTapMinMs    = 50;

// ---------------------------------------------------------------------------
// Display  (GC9A01 round 240×240, SPI)
// Names verified from lgfx_config.hpp and status_screens.cpp errors.
// ---------------------------------------------------------------------------
constexpr int  kDisplayPinRst     = 0;
constexpr int  kDisplayPinCs      = 1;
constexpr int  kDisplayPinDc      = 10;
constexpr int  kDisplayPinMosi    = 3;
constexpr int  kDisplayPinSclk    = 4;
constexpr bool kDisplayInvert     = true;
constexpr bool kDisplayRgbOrder   = false;    // false = BGR
constexpr int  kDisplaySpiWriteHz = 80000000;
constexpr int  kDisplayWidth      = 240;
constexpr int  kDisplayHeight     = 240;

// Display colors (RGB565) — verified from status_screens.cpp errors
constexpr uint16_t kColorBlack   = 0x0000;
constexpr uint16_t kColorYellow  = 0xFFE0;
constexpr uint16_t kTextOnBlack  = 0xFFFF;  // white on black
constexpr uint16_t kTextOnYellow = 0x0000;  // black on yellow

// ---------------------------------------------------------------------------
// ADS-B  (names verified from adsb_client.cpp + main.cpp errors)
// ---------------------------------------------------------------------------
constexpr int  kAdsbFetchIntervalMs    = 5000;  // 5 s poll
constexpr bool kAdsbShowGroundAircraft = false; // hide ground traffic

// ---------------------------------------------------------------------------
// NVS namespace
// ---------------------------------------------------------------------------
constexpr const char* kNvsNamespace = "planeradar";

} // namespace config
