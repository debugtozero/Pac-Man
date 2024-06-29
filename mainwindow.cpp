#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setFixedSize(800,800); //固定视口

    this->setWindowIcon(QIcon(":/Images/A.png")); //设置ico

    this->setWindowTitle("Pacman");//设置标题名

    MainSound=new QSound(":/Sound/Sounds/Main_sound.wav",this);
    MainSound->setLoops(QSound::Infinite); // 循环播放
    MainSound->play();

    Background=new QLabel(this);
    Background->setGeometry(0,0,800,800);//背景
    StarBackground=new QMovie(":/Images/StarBackground.gif",QByteArray(),this); //创建GIF
    Background->setMovie(StarBackground);
    StarBackground->start();//GIF需要用start()开始播放


    Background->lower();//将背景GIF图层置最底层

    ui->GameTitle->setPixmap(QPixmap(":/Images/Game_title.png").scaled(540,310,Qt::KeepAspectRatio));


    QMovie *Gif_1=new QMovie(this); //当前窗口作为父对象
    Gif_1->setFileName(":/Images/Ghost1_left.gif");//加载gif图
    Gif_1->setScaledSize(QSize(80,80));//设置gif图宽高为80
    ui->MainWindowGif1->setFixedSize(120,120); //修改控件宽高为120
    ui->MainWindowGif1->setMovie(Gif_1);//让其成为背景动画以便控制gif播放
    Gif_1->start();//gif图开始播放

    // 主页面背景gif下同

    QMovie *Gif_2=new QMovie(this);
    Gif_2->setFileName(":/Images/Ghost2_up.gif");
    Gif_2->setScaledSize(QSize(80,80));
    ui->MainWindowGif2->setFixedSize(120,120);
    ui->MainWindowGif2->setMovie(Gif_2);
    Gif_2->start();

    QMovie *Gif_3=new QMovie(this);
    Gif_3->setFileName(":/Images/Ghost3_right.gif");
    Gif_3->setScaledSize(QSize(80,80));
    ui->MainWindowGif3->setFixedSize(120,120);
    ui->MainWindowGif3->setMovie(Gif_3);
    Gif_3->start();

    // 按钮组件下同
    ui->Begin_button->setFixedSize(200,50);//组件大小固定
    ui->Begin_button->setStyleSheet("QPushButton{border-image: url(:/Images/Begin_text.png);}"
                                    "QPushButton:hover{border-image: url(:/Images/Begin_text_hover.png);}"
                                    "QPushButton:pressed{border-image: url(:/Images/Begin_text_press.png);}");//三种状态样式表背景编写

    ui->Rule_button->setFixedSize(200,50);
    ui->Rule_button->setStyleSheet("QPushButton{border-image: url(:/Images/Rules_text.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/Rules_text_hover.png);}"
                                   "QPushButton:pressed{border-image: url(:/Images/Rules_text_press.png);}");

    ui->Exit_button->setFixedSize(200,50);
    ui->Exit_button->setStyleSheet("QPushButton{border-image: url(:/Images/Exit_text.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/Exit_text_hover.png);}"
                                   "QPushButton:pressed{border-image: url(:/Images/Exit_text_press.png);}");


    Level_Page=new ChooseLevelScene(MainSound);
    ui->StackedWidget->addWidget(Level_Page);
    Rule_Page=new RuleWindow;
    ui->StackedWidget->addWidget(Rule_Page);    //插入新的widget    //Rule的所有权转移给StackedWidget
    //Rule->setFixedSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);    页面大小默认为StackedWidget大小，不需要设置



    QSound *ClickSound=new QSound(":/Sound/Sounds/TapButton.wav",this);

    connect(ui->Begin_button,&QPushButton::released,[=](){
        ClickSound->play();
        ui->StackedWidget->setCurrentWidget(Level_Page);
    });//信号连接，松开按钮时播放clicksound执行槽函数转到Level_page

    connect(Level_Page,&ChooseLevelScene::GameStart,this,&QWidget::hide);//响应选择关卡操作，点击关卡开始游戏，隐藏选择关卡的窗口

    connect(Level_Page,&ChooseLevelScene::GameEnd,this,[=]()
    {
       this->show();
    });//GameEnd发出信号显示选关窗口

    connect(Level_Page,&ChooseLevelScene::closeWindow,[=]()
    {
        ui->StackedWidget->setCurrentWidget(ui->Main_Page);
    });//选关窗口点击Back发出信号切换窗口进入主页面

    connect(ui->Rule_button,&QPushButton::released,[=](){
        ClickSound->play();
        ui->StackedWidget->setCurrentWidget(Rule_Page);
    });//当点击主界面游戏规则按钮，播放clicksound并跳转到规则页面

    connect(Rule_Page,&RuleWindow::closeWindow,[=]()
    {
       ui->StackedWidget->setCurrentWidget(ui->Main_Page);
    });//在规则界面点击Back，发出信号执行槽函数切换到主界面

    connect(ui->Exit_button,&QPushButton::released,[=]()
    {
        ClickSound->play();
        QTimer::singleShot(200,this,&QWidget::close);
    });
}

MainWindow::~MainWindow()
{
    MainSound->stop();
    delete ui;
    delete Level_Page;
}

