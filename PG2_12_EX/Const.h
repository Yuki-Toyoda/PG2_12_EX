#pragma once
#include <iostream>
#include <ctime>
/******** ウィンドウ名の指定 **********/
const char kWindowTitle[] = "Point Shooter";

/******** ウィンドウサイズの指定 **********/
const int kWindowWidth = 1920; //x
const int kWindowHeight = 1080; //y

/******** 発射できる弾の最大数 **********/
const static int kMaxShotBullet = 20;

/******** 弾の発射レート **********/
const static float kShotRate = 0.06f;

/******** スポーンできる敵の最大数 **********/
const static int kMaxSpawnEnemy = 30;
