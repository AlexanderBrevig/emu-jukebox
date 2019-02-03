//
// Created by robin on 11.01.19.
//

#include "FormManager.h"

ebox::FormManager::FormManager()
{

}

void ebox::FormManager::initialize(sf::RenderWindow *window, EventManager * events)
{
    ImGui::CreateContext(); //IMGUI 1.60
    m_window = window;
    m_style = &ImGui::GetStyle();
    m_io = &ImGui::GetIO();
    m_events = events;

    ImGui::SFML::Init(*m_window);
    //Enable Ctrl+TAB (New in ImGui 1.63)
    m_io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    //Enable docking (New in ImGui 1.66 WIP) - Downloaded 14.10.2018
    m_io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    initializeForms();
}

void ebox::FormManager::initializeForms()
{
    m_forms.push_back(&m_filelistForm);
    m_forms.push_back(&m_playlistForm);
    m_forms.push_back(&m_audioTestForm);
}

void ebox::FormManager::update()
{
    for(sf::Event &event : m_events->getAllEvents())
    {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_window->close();
        }
    }
    ImGui::SFML::Update(*m_window, m_deltaClock.restart());
}

void ebox::FormManager::draw()
{
    if(m_showImguiDemoWindow)
        ImGui::ShowDemoWindow();

    for(auto const &item : m_forms)
        item->draw();

    SystemLog::get()->process();

    ImGui::SFML::Render(*m_window);
}

void ebox::FormManager::showImguiDemoWindow(bool showImguiDemoWindow)
{
    m_showImguiDemoWindow = showImguiDemoWindow;
}

bool ebox::FormManager::showImguiDemoWindow() const
{
    return m_showImguiDemoWindow;
}

void FormManager::handleEvents()
{
    m_audioTestForm.handleEvents();
}



