#include "propsobject.h"


PropsObject::PropsObject(short objectType): BaseObject(objectType)
{

}

SlowDownPacman::SlowDownPacman(int x, int y) : PropsObject(_SLOWVIRUS)
{
    //将道具类的绘制原点进行偏移，偏移量为半个图像的大小，这样道具类的实际位置刚好处于图像中央
    setOffset(-20/2,-20/2);

    //绘制道具
    setPixmap(QPixmap(":/Images/Virus.png").scaled(20, 20));

    X = x; Y = y;
    //设置道具类的初始位置
    setPos(Y*BRICK_SIZE+HALF_BRICK_SIZE,X*BRICK_SIZE+HALF_BRICK_SIZE);
}

SuperBean::SuperBean(int x, int y) : PropsObject(_SUPERBEAN)
{


    //将道具类的绘制原点进行偏移，偏移量为半个图像的大小，这样道具类的实际位置刚好处于图像中央
    setOffset(-20/2,-20/2);

    //绘制道具
    setPixmap(QPixmap(":/Images/Super_bean.png").scaled(20+6, 20+6));

    X = x; Y = y;
    //设置道具类的初始位置
    setPos(Y*BRICK_SIZE+HALF_BRICK_SIZE,X*BRICK_SIZE+HALF_BRICK_SIZE);
}
