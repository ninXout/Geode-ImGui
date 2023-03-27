
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
        this->drawPages();
        ImGui::PopFont();
    }
}

void ImGuiHook::setupFonts() {
    
    static constexpr auto add_font = [](
        void* font, float size, const ImWchar* range
    ) {
        auto& io = ImGui::GetIO();
        ImFontConfig config;
        config.MergeMode = true;
        auto* result = io.Fonts->AddFontFromMemoryTTF(
            font, sizeof(font), size, nullptr, range
        );
        io.Fonts->Build();
        return result;
    };

    //m_defaultFont = add_font(Font_OpenSans, 18.f, def_ranges);
}

void ImGuiHook::setup() {
    if (m_setup) return;
    m_setup = true;

    IMGUI_CHECKVERSION();
    
    auto ctx = ImGui::CreateContext();
        
    this->setupFonts();
    this->setupPlatform();
}

void ImGuiHook::show(bool visible) {
    m_visible = visible;
    isRendering = visible;
}

void ImGuiHook::toggle() {
    this->show(!m_visible);
}