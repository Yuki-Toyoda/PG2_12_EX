#pragma once

/*********************************
    列挙子管理
*********************************/

/******** マウス入力検知 **********/
enum MouseButton
{
    LeftClick,
    RightClick,
    MiddleClick
};

/******** 入力状態検知 **********/
enum InputState
{
    Null,
    Trigger,
    Press,
    Release
};

/******** シーン遷移 **********/
enum Scene
{
    TITLE,
    GAME,
    RESULT
};

/******** マップチップ **********/
enum TitleInfo
{
    BG,
    LETTER,
    DOT,
    SQUARE
};

enum MapInfo
{
    NONE,
    BLOCK
};

/*================================
    列挙子管理
=================================*/
