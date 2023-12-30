#pragma once
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_internal.h>

namespace eZe1
{
    char name_buf[64] = "";
    bool drawMenuBar()
    {

        return true;
    }

    void drawExplorerWindow()
    {
        if (ImGui::Begin("Explorer"))
        {

            // Splitting the window into 3 columns
            ImGui::Columns(3, "mycolumns", false); // 3 columns, with no borders

            // First column
            ImGui::Text("Column 1");
            ImGui::Button("Button 1");
            ImGui::NextColumn();

            // Second column
            ImGui::Text("Column 2");
            ImGui::Button("Button 2");
            ImGui::NextColumn();

            // Third column
            ImGui::Text("Column 3");
            ImGui::Button("Button 3");
            ImGui::Columns(1); // Reset to 1 column

            // Aligning widgets on the same line
            
            ImGui::Text("Name:");
            ImGui::SameLine();
            ImGui::InputText("##name", name_buf, IM_ARRAYSIZE(name_buf));

            // Adding some spacing
            ImGui::Spacing();

            // Custom indent
            ImGui::Indent(30.0f);
            ImGui::Text("Indented Text");
            ImGui::Unindent(30.0f);

        }
        ImGui::End();
    }

    void drawContentWindow()
    {
        if (ImGui::Begin("Content"))
        {
        }
        ImGui::End();
    }

    void drawEffectWindow()
    {
        if (ImGui::Begin("Effects"))
        {
            ImGui::Text("Hello, world!");
        }
        ImGui::End();
    }

    void drawUi()
    {
        static bool init = false;
        ImGuiID dockspace_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        drawMenuBar();
        drawExplorerWindow();
        drawContentWindow();
        drawEffectWindow();
        ImGui::ShowMetricsWindow();
        ImGui::ShowDemoWindow();

        if (!init)
        {

            // Begin DockBuilder context
            ImGui::DockBuilderRemoveNode(dockspace_id);                            // Clear any previous layout
            ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace); // Add the dockspace
            ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

            ImGuiID right_dock_id, left_dock_id, bottom_right_dock_id;
            // Split the dockspace to create a right dock for the explorer window
            ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Right, 0.3f, &right_dock_id, &left_dock_id);
            ImGui::DockBuilderSplitNode(left_dock_id, ImGuiDir_Down, 0.5f, &bottom_right_dock_id, nullptr);

            // Dock the explorer window into the right dock
            ImGui::SetNextWindowDockID(right_dock_id, ImGuiCond_FirstUseEver);
            ImGui::DockBuilderDockWindow("Explorer", right_dock_id);
            ImGui::DockBuilderDockWindow("Dear ImGui Demo", right_dock_id);

            ImGui::SetNextWindowDockID(left_dock_id, ImGuiCond_FirstUseEver);
            ImGui::DockBuilderDockWindow("Content", left_dock_id);
            ImGui::DockBuilderDockWindow("Effects", left_dock_id);

            ImGui::SetNextWindowDockID(bottom_right_dock_id, ImGuiCond_FirstUseEver);
            ImGui::DockBuilderDockWindow("Dear ImGui Metrics/Debugger", bottom_right_dock_id);

            // Finish the DockBuilder context
            ImGui::DockBuilderFinish(dockspace_id);

            init = true;
        }
    }
}
