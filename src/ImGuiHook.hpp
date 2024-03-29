#pragma once

#include <imgui.h>
#include <cocos2d.h>
#include <Geode/utils/cocos.hpp>
#include <unordered_map>

using namespace geode::prelude;

class ImGuiHook {
protected:
    bool m_visible = false;
    bool m_setup = false;
    ImFont* m_defaultFont  = nullptr;

    void setupFonts(const char* filepath, float size);
    void setupPlatform();

    void drawGUI();
    void draw();

    void newFrame();
    void renderDrawData(ImDrawData*);

public:
    bool isRendering = false;

    static ImGuiHook* get();

    void render();

    // setup ImGui
    void setup();

    void show(bool visible);
    void toggle();
};
