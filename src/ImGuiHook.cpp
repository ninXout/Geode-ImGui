
#include <imgui_internal.h>
#include "ImGuiHook.hpp"
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include "ImGui.hpp"

ImGuiHook* ImGuiHook::get() {
    static auto inst = new ImGuiHook;
    return inst;
}

void ImGuiHook::draw() {
    if (m_visible) {
        ImGui::PushFont(m_defaultFont);
        this->drawGUI();
        ImGui::PopFont();
    }
}

void ImGuiHook::setupFonts(const char* filepath, float size) {
    auto& io = ImGui::GetIO();
    ImFontConfig config;
    config.MergeMode = true;
    auto* result = io.Fonts->AddFontFromFileTTF(filepath, size);
    io.Fonts->Build();
    m_defaultFont = result;
}

void ImGuiHook::setup() {
    if (m_setup) return;
    m_setup = true;

    IMGUI_CHECKVERSION();
    
    auto ctx = ImGui::CreateContext();
        
    //this->setupFonts();
    this->setupPlatform();
}

void ImGuiHook::show(bool visible) {
    m_visible = visible;
    isRendering = visible;
}

void ImGuiHook::toggle() {
    this->show(!m_visible);
}