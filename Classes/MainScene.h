/*
 * Copyright (C) 2012 Soomla Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "cocosbuilder/CocosBuilder.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocosbuilder;

class Soomla : public Sprite {
public:
    CREATE_FUNC(Soomla);
};

class MainScene:
    public cocos2d::Layer,
    public CCBSelectorResolver,
    public CCBMemberVariableAssigner,
    public NodeLoaderListener {
private:
    Vec2 mOriginalPos;
private:
	Node* mBackgroundNode;
	Node* mMainNode;
	Node* mUnlockArea;
	Node* mUnlocker;
    EventListenerTouchOneByOne * listener;
public:
    CREATE_FUNC(MainScene);

    MainScene():
        mBackgroundNode(NULL)
        , mMainNode(NULL)
        , mUnlockArea(NULL)
        , mUnlocker(NULL)
    {}
    static cocos2d::Scene* getMainScene();

    virtual void onEnter();
    virtual void onExit();

    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Ref *pTarget, char const *pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Ref *pTarget, char const *pSelectorName);
    virtual bool onAssignCCBMemberVariable(Ref *pTarget, char const *pMemberVariableName, Node *pNode);
    virtual void onNodeLoaded(Node *pNode, NodeLoader *pNodeLoader);
    virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) override;
};

class MainSceneLoader: public LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainScene);
};


#endif // __MainScene_SCENE_H__
