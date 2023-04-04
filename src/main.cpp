#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <Geode/modify/AchievementNotifier.hpp>
#include <Geode/modify/CCDirector.hpp>
#include "ImGuiHook.hpp"
#include <imgui.h>
#include "ImGui.hpp"

using namespace geode::prelude;

void ImGuiHook::drawGUI() {
    ImGui::Begin("ImGui Hook!");
    ImGui::Text("Hello World!");
    char message[50];
    ImGui::InputText("lmao", message, IM_ARRAYSIZE(message));
    ImGui::End();
}

class $modify(CCKeyboardDispatcher) {
    bool dispatchKeyboardMSG(enumKeyCodes key, bool down) {
        if (down && key == KEY_Tab) {
            ImGuiHook::get()->toggle();
            return true;
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down);
    }
};

class $modify(CCDirector) {
    void drawScene() {
        ImGuiHook::get()->setup();

        CCDirector::drawScene();

        ImGuiHook::get()->render();
    }
};
