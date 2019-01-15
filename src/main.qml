/**
 * Copyright 2019 Hu Peng
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2
import QtQuick.VirtualKeyboard.Settings 2.2

Window {
    id: root
    width: 1280
    height: 440
    visible: true

    // TextField {
    //     anchors.top: parent.top
    //     anchors.horizontalCenter: parent.horizontalCenter
    //     onPressed: {
    //         inputPanel.visible = true; //当选择输入框的时候才显示键盘
    //     }
    // }

    InputPanel {
        id: inputPanel
        visible: true
        // active: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        // Connections {
        //     target: InputContext
        //     onPreeditTextChanged: if (InputContext.preeditText.length > 0) root.inputMethodResult(InputContext.preeditText)
        // }

        // onActiveChanged: {
        //     console.log(InputContext.inputEngine.inputMode)
        //     if(!active) { visible = false; }
        // }

        
        Component.onCompleted: {
            VirtualKeyboardSettings.activeLocales = ["en_GB", "zh_CN", "ja_JP", "fr_FR"]
            // VirtualKeyboardSettings.locale = "en_GB"
            // VirtualKeyboardSettings.fullScreenMode = true
            // VirtualKeyboardSettings.wordCandidateList.autoHideDelay = -1
            VirtualKeyboardSettings.wordCandidateList.alwaysVisible = true
            // VirtualKeyboardSettings.wordCandidateList.autoCommitWord = true
            // InputContext.previewVisible = true
            // InputContext.inputEngine.wordCandidateListVisibleHint = true
            // InputContext.inputEngine.inputMode = InputEngine.Pinyin
        }
        
    }

    
    Component.onCompleted: inputPanel.active = true
    

    // function inputMethodResult(text) {
    //     console.log(text)
    // }
}