/*****************************************************
* TP IFT3100H24 - Knight Maker
 * by Team 12
 *****************************************************
 *
 * UserInterface class definition
 *
 *****************************************************/
#pragma once
#include <BaseNode.h>
#include <ofxImGui.h>


class UserInterface {

public:
    void setup();
    void draw();

    // Some useful definitions
    static const int        TOOLBAR_HEIGHT        = 60;
    static const int        STATUSBAR_HEIGHT      = 30;
    static const int        LEFTPANEL_WIDTH       = 256;
    static const int        TREEVIEW_HEIGHT       = 240;
    static constexpr float  CAMERA_ASPECT_RATIO   = 16.0f / 9.0f;

    std::string m_selectedWindow;
    int m_selectedNode = -1;
    std::string m_hoveredWindow;

    // Getters
    const std::string& getSelectedWindow() const {
        return m_selectedWindow;
    }

    const std::string& getHoveredWindow() const {
        return m_hoveredWindow;
    }

    bool onlyOneCamera() const { return m_onlyOneCamera; }


private:
    ofxImGui::Gui m_gui;

    ofTexture m_textureToolbarNewLevel;
    ofTexture m_textureToolbarLoadLevel;
    ofTexture m_textureToolbarSaveLevel;
    ofTexture m_textureToolbarGenerateAtlas;
    ofTexture m_textureToolbarToggleCameras;
    ofTexture m_textureToolbarToggleCamerasPressed;

    bool m_initialDraw = true;
    bool m_onlyOneCamera = false;


    // Draw functions

    void drawMenu();
    void drawToolbar();
    void drawTree();
    void drawTreeElement(BaseNode* node);
    void drawStatus();
    void drawProperties();
    void drawViewports();
    void drawViewport(const std::string& name, int index, const ImVec2& position, const ImVec2& size);

    // Callback functions

    void onAboutProgram();
    void onNewLevel();
    void onLoadLevel();
    void onSaveLevel();
    void onGenerateAtlas();
    void onHistoryUndo();
    void onHistoryRedo();
    void onToggleCameras();


};



