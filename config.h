#ifndef CONFIG_H
#define CONFIG_H

#define MAPLENGTH 19			// 逻辑地图大小
#define BRICK_SIZE 50           //砖块大小
#define HALF_BRICK_SIZE 25      //半个砖块大小
#define ENEMY_SIZE 40           //敌人大小
#define CRASH_DISTANCE 15       //玩家和敌人碰撞的判定距离

//////////////////////////////////////游戏进行常数////////////////////////////////////////
enum OBJECT_FLAG{ _PLAYER=65536, _ENEMY=65537, _SLOWVIRUS=65538, _SUPERBEAN=65539, _BEAN=4,};       //物品的类别标记
enum DIRECTION{DIR_LEFT=0,DIR_UP=1,DIR_RIGHT=2,DIR_DOWN=3};     //方向标记
const int DIR_VALUE[4][2]={{0,-1},{-1,0},{0,1},{1,0}};  //方向对应的移动指令
enum GAME_STATUS{GAME_READY=0,GAME_RUN=1,GAME_END=2};   //游戏当前状态标记

#define GAME_TIMER_SPEED 20   //游戏主控时钟的间隔，单位为毫秒
#define PROPS_ADD_INTERVAL 5000    //加入道具的间隔时间
#define SLOW_DOWN_TIME 3000        //总共减速时间
#define SLOW_DOWN_INTERVAL 30     //减速的时间间隔
#define SUPER_BEAN_TIME 5000       //超级豆总共时间
#define SUPER_BEAN_INTERVAL 50    //超级豆时钟的时间间隔
#define SUPER_BEAN_FREEZE 1000     //敌人冰冻的时间

//////////关卡锁////////////

extern bool passedLevelNum[4];  //对每个类引用config.cpp里的关卡锁变量


#include <QDebug>

#endif // CONFIG_H
