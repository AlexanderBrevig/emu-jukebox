//
// Created by robin on 11.01.19.
//

#ifndef EMU_JUKEBOX_FORMMANAGER_H
#define EMU_JUKEBOX_FORMMANAGER_H

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include "EventManager.h"
#include "../gui/forms/Form.h"

namespace ebox
{
    class FormManager
    {
        public:
            FormManager();
            void initialize(sf::RenderWindow *window, EventManager * events);

            void showImguiDemoWindow(bool showImguiDemoWindow);

            bool showImguiDemoWindow() const;

            void update();
            void draw();

        private:
            std::vector<ebox::Form *> m_forms;

            sf::RenderWindow *m_window;
            EventManager *m_events;
            bool m_showImguiDemoWindow;
            ImGuiStyle *m_style = nullptr;
            ImGuiIO *m_io = nullptr;
            sf::Clock m_deltaClock;
    };
}

#endif //EMU_JUKEBOX_FORMMANAGER_H