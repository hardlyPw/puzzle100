// puzzle12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Bangtal.h>
#include <stdio.h>
SceneID room1, room2, puzzle, ending;
ObjectID orange[9], flower[16], white, white2, start, next, end, end2, restart, picture, button_hint;
TimerID timer1;
int Hint = 0;

int X[3][3] = { //[y][x]
    { 375,525,675 },
    { 375,525,675 },
    { 375,525,675 }
};

int Y[3][3] = {
    { 450,450,450 }, //[0][0], [0][1], [0][2]
    { 310,310,310 },
    { 170,170,170 }
};

int XX[4][4] = {
    {320, 470, 620, 770},
    {320, 470, 620, 770},
    {320, 470, 620, 770},
    {320, 470, 620, 770}

};
int YY[4][4] = {
    {480,480,480,480},
    {330,330,330,330},
    {180,180,180,180},
    {30,30,30,30}
};

int alterX, alterY;
int alterXX, alterYY;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {

    ObjectID object = createObject(image);

    locateObject(object, scene, x, y);
    if (shown) {
        showObject(object);
    }
    return object;
}




void move(int x1, int x2, int y1, int y2, int name) {
    //오랜지 위치를 alter에 저장, orange -> 공백위치로 변경, 공백위치에 alter대입해서 교환 
    alterX = X[x1][x2];
    alterY = Y[y1][y2];
    X[x1][x2] = X[0][2];
    Y[y1][y2] = Y[0][2];
    X[0][2] = alterX;
    Y[0][2] = alterY;
    locateObject(orange[name], room1, X[x1][x2], Y[y1][y2]);
    locateObject(white, room1, X[0][2], Y[0][2]);
}

void move2(int x1, int x2, int y1, int y2, int name) {
    alterXX = XX[x1][x2];
    alterYY = YY[y1][y2];
    XX[x1][x2] = XX[0][0];
    YY[y1][y2] = YY[0][0];
    XX[0][0] = alterXX;
    YY[0][0] = alterYY;
    locateObject(flower[name], room2, XX[x1][x2], YY[y1][y2]);
    locateObject(white2, room2, XX[0][0], YY[0][0]);
}
void Starting() {
    int percent = rand() % 100;
    int percent2 = rand() % 5;
    if (percent <= 25) {
        for (int a = 0; a <= percent2; a++) {
            move(0, 1, 0, 1, 1);
            move(1, 1, 1, 1, 4);
            move(1, 0, 1, 0, 3);
            move(1, 2, 1, 2, 5);
            move(2, 0, 2, 0, 6);
            move(0, 0, 0, 0, 0);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
            move(2, 1, 2, 1, 7);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(3, 3, 3, 3, 15);
            move2(0, 3, 0, 3, 3);
            move2(2, 1, 2, 1, 9);
            move2(3, 2, 3, 2, 14);
            move2(1, 1, 1, 1, 5);
            move2(1, 0, 1, 0, 4);
            move2(1, 3, 1, 3, 7);
            move2(0, 2, 0, 2, 2);
            move2(1, 2, 1, 2, 6);
            move2(2, 0, 2, 0, 8);
            move2(3, 0, 3, 0, 12);
            move2(2, 2, 2, 2, 10);
            move2(2, 3, 2, 3, 11);
            move2(0, 1, 0, 1, 1);
            move2(3, 1, 3, 1, 13);
        }

    }
    else if (percent <= 50 and percent > 25) {
        for (int a = 0; a <= percent2; a++) {
            move(0, 0, 0, 0, 0);
            move(0, 1, 0, 1, 1);
            move(1, 0, 1, 0, 3);
            move(2, 1, 2, 1, 7);
            move(2, 0, 2, 0, 6);
            move(1, 0, 1, 0, 3);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
            move(1, 2, 1, 2, 5);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(0, 3, 0, 3, 3);
            move2(3, 2, 3, 2, 14);
            move2(1, 1, 1, 1, 5);
            move2(2, 0, 2, 0, 8);
            move2(1, 0, 1, 0, 4);
            move2(3, 0, 3, 0, 12);
            move2(2, 2, 2, 2, 10);
            move2(0, 2, 0, 2, 2);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }


    }
    else if (percent <= 75 and percent > 50) {
        for (int a = 0; a <= percent2; a++) {
            move(2, 1, 2, 1, 7);
            move(1, 2, 1, 2, 5);
            move(2, 0, 2, 0, 6);
            move(1, 0, 1, 0, 3);
            move(0, 1, 0, 1, 1);
            move(0, 0, 0, 0, 0);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(0, 2, 0, 2, 2);
            move2(3, 0, 3, 0, 12);
            move2(2, 0, 2, 0, 8);
            move2(1, 0, 1, 0, 4);
            move2(2, 2, 2, 2, 10);
            move2(0, 3, 0, 3, 3);
            move2(1, 1, 1, 1, 5);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(3, 2, 3, 2, 14);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }
    }
    else if (percent <= 100 and percent > 75) {
        for (int a = 0; a <= percent2; a++) {
            move(2, 1, 2, 1, 7);
            move(0, 0, 0, 0, 0);
            move(2, 2, 2, 2, 8);
            move(2, 0, 2, 0, 6);
            move(0, 1, 0, 1, 1);
            move(1, 2, 1, 2, 5);
            move(1, 0, 1, 0, 3);
            move(1, 1, 1, 1, 4);
            move(0, 1, 0, 1, 1);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(0, 2, 0, 2, 2);
            move2(2, 2, 2, 2, 10);
            move2(0, 3, 0, 3, 3);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(1, 0, 1, 0, 4);
            move2(3, 0, 3, 0, 12);
            move2(2, 0, 2, 0, 8);
            move2(1, 1, 1, 1, 5);
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(3, 2, 3, 2, 14);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }
    }
}

void retry() {
    enterScene(room1);
    hideObject(restart);
    setTimer(timer1, 600);
    startTimer(timer1);
    hideTimer();
    Hint = 0;
    hideObject(picture);
    srand((unsigned int)time(NULL));
    int percent = rand() % 100;
    int percent2 = rand() % 5;
    if (percent <= 25) {
        for (int a = 0; a <= percent2; a++) {
            move(0, 1, 0, 1, 1);
            move(1, 1, 1, 1, 4);
            move(1, 0, 1, 0, 3);
            move(1, 2, 1, 2, 5);
            move(2, 0, 2, 0, 6);
            move(0, 0, 0, 0, 0);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
            move(2, 1, 2, 1, 7);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(3, 3, 3, 3, 15);
            move2(0, 3, 0, 3, 3);
            move2(2, 1, 2, 1, 9);
            move2(3, 2, 3, 2, 14);
            move2(1, 1, 1, 1, 5);
            move2(1, 0, 1, 0, 4);
            move2(1, 3, 1, 3, 7);
            move2(0, 2, 0, 2, 2);
            move2(1, 2, 1, 2, 6);
            move2(2, 0, 2, 0, 8);
            move2(3, 0, 3, 0, 12);
            move2(2, 2, 2, 2, 10);
            move2(2, 3, 2, 3, 11);
            move2(0, 1, 0, 1, 1);
            move2(3, 1, 3, 1, 13);
        }

    }
    else if (percent <= 50 and percent > 25) {
        for (int a = 0; a <= percent2; a++) {
            move(0, 0, 0, 0, 0);
            move(0, 1, 0, 1, 1);
            move(1, 0, 1, 0, 3);
            move(2, 1, 2, 1, 7);
            move(2, 0, 2, 0, 6);
            move(1, 0, 1, 0, 3);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
            move(1, 2, 1, 2, 5);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(0, 3, 0, 3, 3);
            move2(3, 2, 3, 2, 14);
            move2(1, 1, 1, 1, 5);
            move2(2, 0, 2, 0, 8);
            move2(1, 0, 1, 0, 4);
            move2(3, 0, 3, 0, 12);
            move2(2, 2, 2, 2, 10);
            move2(0, 2, 0, 2, 2);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }


    }
    else if (percent <= 75 and percent > 50) {
        for (int a = 0; a <= percent2; a++) {
            move(2, 1, 2, 1, 7);
            move(1, 2, 1, 2, 5);
            move(2, 0, 2, 0, 6);
            move(1, 0, 1, 0, 3);
            move(0, 1, 0, 1, 1);
            move(0, 0, 0, 0, 0);
            move(1, 1, 1, 1, 4);
            move(2, 2, 2, 2, 8);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(0, 2, 0, 2, 2);
            move2(3, 0, 3, 0, 12);
            move2(2, 0, 2, 0, 8);
            move2(1, 0, 1, 0, 4);
            move2(2, 2, 2, 2, 10);
            move2(0, 3, 0, 3, 3);
            move2(1, 1, 1, 1, 5);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(3, 2, 3, 2, 14);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }
    }
    else if (percent <= 100 and percent > 75) {
        for (int a = 0; a <= percent2; a++) {
            move(2, 1, 2, 1, 7);
            move(0, 0, 0, 0, 0);
            move(2, 2, 2, 2, 8);
            move(2, 0, 2, 0, 6);
            move(0, 1, 0, 1, 1);
            move(1, 2, 1, 2, 5);
            move(1, 0, 1, 0, 3);
            move(1, 1, 1, 1, 4);
            move(0, 1, 0, 1, 1);
        }
        for (int a = 0; a <= percent2; a++) {
            move2(0, 2, 0, 2, 2);
            move2(2, 2, 2, 2, 10);
            move2(0, 3, 0, 3, 3);
            move2(0, 1, 0, 1, 1);
            move2(2, 3, 2, 3, 11);
            move2(1, 0, 1, 0, 4);
            move2(3, 0, 3, 0, 12);
            move2(2, 0, 2, 0, 8);
            move2(1, 1, 1, 1, 5);
            move2(1, 3, 1, 3, 7);
            move2(2, 1, 2, 1, 9);
            move2(1, 2, 1, 2, 6);
            move2(3, 2, 3, 2, 14);
            move2(3, 1, 3, 1, 13);
            move2(3, 3, 3, 3, 15);
        }
    }
    
}

void scale() {
    for (int i = 0; i <= 8; i++) {
        scaleObject(orange[i], 0.5f);
    }
}


void scale2() {
    for (int i = 0; i <= 15; i++) {
        scaleObject(flower[i], 0.5f);
    }
}

void act_hint() {
    Hint = Hint + 1;
    if (Hint > 99) {
        showObject(button_hint);
    }
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
 
    if (object == start) {
        Starting();
        scale();
        enterScene(room1);
        startTimer(timer1);
    }
    if (object == end) {
        endGame();
    }
    if (object == orange[0]) {       
        move(0, 0, 0, 0, 0);
        
    }
    else if (object == orange[1]) {
        move(0,1,0,1,1);
    }
    else if (object == orange[3]) {
        move(1,0,1,0, 3);
    }
    else if (object == orange[4]) {
        move(1, 1, 1, 1, 4);
    }
    else if (object == orange[5]) {
        move(1, 2, 1, 2, 5);
    }
    else if (object == orange[6]) {
        move(2, 0, 2, 0, 6);
    }
    else if (object == orange[7]) {
        move(2, 1, 2, 1, 7);
    }
    else if (object == orange[8]) {
        move(2, 2, 2, 2, 8);
    }    
    else if (object == flower[1]) {
        move2(0, 1, 0, 1, 1);
        act_hint();     
    }
    else if (object == flower[2]) {
        move2(0, 2, 0, 2, 2);
        act_hint();
    }
    else if (object == flower[3]) {
        act_hint();
        move2(0, 3, 0, 3, 3);
    }
    else if (object == flower[4]) {
        move2(1, 0, 1, 0, 4);
        act_hint();
    }
    else if (object == flower[5]) {
        move2(1, 1, 1, 1, 5);
        act_hint();
    }
    else if (object == flower[6]) {
        move2(1, 2, 1, 2, 6);
        act_hint();
    }
    else if (object == flower[7]) {
        move2(1, 3, 1, 3, 7);
        act_hint();
    }
    else if (object == flower[8]) {
        move2(2, 0, 2, 0, 8);
        act_hint();
    }
    else if (object == flower[9]) {
        move2(2, 1, 2, 1, 9);
        act_hint();
    }
    else if (object == flower[10]) {
        move2(2, 2, 2, 2, 10);
        act_hint();
    }
    else if (object == flower[11]) {
        move2(2, 3, 2, 3, 11);
        act_hint();
    }
    else if (object == flower[12]) {
        move2(3, 0, 3, 0, 12);
        act_hint();
    }
    else if (object == flower[13]) {
        move2(3, 1, 3, 1, 13);
        act_hint();
    }
    else if (object == flower[14]) {
        move2(3, 2, 3, 2, 14);
        act_hint();
    }
    else if (object == flower[15]) {
        move2(3, 3, 3, 3, 15);
        act_hint();
    }
    else if (object == button_hint) {
        showObject(picture);
        
    }


    else if (object == next) {
        if (X[0][0] == 375 && Y[0][0] == 450 && X[0][1] == 525 && Y[0][1] == 450 && X[0][2] == 675 && Y[0][2] == 450 && X[0][3] == 375 && Y[0][3] == 310) {
            if (X[0][4] == 525 && Y[0][4] == 310 && X[0][5] == 675 && Y[0][5] == 310 && X[0][6] == 375 && Y[0][6] == 170 && X[0][7] == 525 && Y[0][7] == 170 && X[0][8] == 675 && Y[0][8] == 170) {
                enterScene(room2);
                scale2();
            }
            else {
                showMessage("퍼즐이 완성되지 않았습니다");
            }
        }
        else {
            showMessage("퍼즐이 완성되지 않았습니다");
        }
    }
    else if (object == end2) {
        if (XX[0][0] == 320 && YY[0][0] == 480 && XX[0][1] == 470 && YY[0][1] == 480 && XX[0][2] == 620 && YY[0][2] == 480 && XX[0][3] == 770 && YY[0][3] == 480) {
            if (XX[1][0] == 320 && YY[1][0] == 330 && XX[1][1] == 470 && YY[1][1] == 330 && XX[1][2] == 620 && YY[1][2] == 330 && XX[1][3] == 770 && YY[1][3] == 330) {
                if (XX[2][0] == 320 && YY[2][0] == 180 && XX[2][1] == 470 && YY[2][1] == 180 && XX[2][2] == 620 && YY[2][2] == 180 && XX[2][3] == 770 && YY[2][3] == 180) {
                    if (XX[3][0] == 320 && YY[3][0] == 30 && XX[3][1] == 470 && YY[3][1] == 30 && XX[3][2] == 620 && YY[3][2] == 30 && XX[3][3] == 770 && YY[3][3] == 30) {
                        showTimer(timer1);
                        showMessage("걸린시간은 10분 - 남은 시간");
                        stopTimer(timer1);
                        showObject(restart);
                        enterScene(ending);
                        hideObject(button_hint);
                        
                    }
                    else {
                        showMessage("완성 안됨!");
                    }
                }
                else {
                    showMessage("완성 안됨!");
                }
            }
            else {
                showMessage("완성 안됨!");
            }
        }
        else {
            showMessage("완성 안됨!");
        }
    }
    else if (object == restart) {
    retry();
}
}
void timerCallback(TimerID timer) {
    if (timer == timer1) {
        showMessage("끝");
    }
}

int main()
{
    setTimerCallback(timerCallback);
    setMouseCallback(mouseCallback);


    room1 = createScene("퍼즐맞추기 1단계", "화면2.png");
    room2 = createScene("퍼즐맞추기 2단계", "화면2.png");
    puzzle = createScene("시작", "퍼즐.jpg");
    ending = createScene("끝", "엔딩.png");

    orange[0] = createObject("오렌지1.png", room1, X[0][0], Y[0][0], true);


    orange[1] = createObject("오렌지2.png", room1, X[0][1], Y[0][1], true);

    orange[2] = createObject("오렌지3.png", room1, X[0][2], Y[0][2], false);
    orange[3] = createObject("오렌지4.png", room1, X[1][0], Y[1][0], true);

    orange[4] = createObject("오렌지5.png", room1, X[1][1], Y[1][1], true);

    orange[5] = createObject("오렌지6.png", room1, X[1][2], Y[1][2], true);

    orange[6] = createObject("오렌지7.png", room1, X[2][0], Y[2][0], true);

    orange[7] = createObject("오렌지8.png", room1, X[2][1], Y[2][1], true);

    orange[8] = createObject("오렌지9.png", room1, X[2][2], Y[2][2], true);

    white = createObject("바탕.png", room1, X[0][2], Y[0][2], true);
    scaleObject(white, 0.5f); //675, 450

    start = createObject("start.png", puzzle, 375, 100, true);
    
    end = createObject("end.png", puzzle, 735, 100, true);
    
    next = createObject("next.png", room1, 525, 50, true);

    end2 = createObject("end.png", room2, 950, 50, true);

    restart = createObject("restart.png", ending, 750, 300, false);

    button_hint = createObject("힌트.png", room2, 1100, 50, false);

    picture = createObject("꽃.jpg", room2, 980, 200, false);
    scaleObject(picture, 0.3f);

    flower[0] = createObject("꽃1.jpg", room2, XX[0][0], YY[0][0], false);
    flower[1] = createObject("꽃2.jpg", room2, XX[0][1], YY[0][1], true);
    flower[2] = createObject("꽃3.jpg", room2, XX[0][2], YY[0][2], true);
    flower[3] = createObject("꽃4.jpg", room2, XX[0][3], YY[0][3], true);
    flower[4] = createObject("꽃5.jpg", room2, XX[1][0], YY[1][0], true);
    flower[5] = createObject("꽃6.jpg", room2, XX[1][1], YY[1][1], true);
    flower[6] = createObject("꽃7.jpg", room2, XX[1][2], YY[1][2], true);
    flower[7] = createObject("꽃8.jpg", room2, XX[1][3], YY[1][3], true);
    flower[8] = createObject("꽃9.jpg", room2, XX[2][0], YY[2][0], true);
    flower[9] = createObject("꽃10.jpg", room2, XX[2][1],YY[2][1], true);
    flower[10] = createObject("꽃11.jpg", room2, XX[2][2], YY[2][2], true);
    flower[11] = createObject("꽃12.jpg", room2, XX[2][3], YY[2][3], true);
    flower[12] = createObject("꽃13.jpg", room2, XX[3][0], YY[3][0], true);
    flower[13] = createObject("꽃14.jpg", room2, XX[3][1], YY[3][1], true);
    flower[14] = createObject("꽃15.jpg", room2, XX[3][2], YY[3][2], true);
    flower[15] = createObject("꽃16.jpg", room2, XX[3][3], YY[3][3], true);
    
    white2 = createObject("바탕.png", room2, XX[0][0], YY[0][0], true);

    scaleObject(white2, 0.5f);

    timer1 = createTimer(1200);

    startGame(puzzle);
    
}