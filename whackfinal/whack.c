

#include "raylib.h"
#include "raymath.h"
#include "stdio.h"
//#include "emscripten.h"---emsc
#define MAX_INPUT_CHARS 6
#define NONEA 6

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

// define a timer

static int score = 0;
static int mscore = 0;

typedef struct
{
  float Lifetime;
} Timer;

// start or restart a timer with a specific lifetime
void StartTimer(Timer *timer, float lifetime)
{
  if (timer != 0)
    timer->Lifetime = lifetime;
}

// update a timer with the current frame time
void UpdateTimer(Timer *timer)
{
  // subtract this frame from the timer if it's not allready expired
  if (timer != 0 && timer->Lifetime > 0)
    timer->Lifetime -= GetFrameTime();
}

// check if a timer is done.
bool TimerDone(Timer *timer)
{
  if (timer != 0)
    return timer->Lifetime <= 0;

  return false;
}

// static int score=0;

int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 500;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
  InitAudioDevice();

  void dissa();
  Sound bonk = LoadSound("./whackso/bonk1.mp3");
  Sound gamemu = LoadSound("./whackso/gamemusic.mp3");
  Sound gamesound = LoadSound("./whackso/chik.mp3");
  int framecounter = 0;
  // input box//
  char name[MAX_INPUT_CHARS + 1] = "\0"; // NOTE: One extra space required for null terminator char '\0'
  int letterCount = 0;

  Rectangle textBox = {screenWidth / 2.0f - 100, 180, 225, 50};
  Rectangle dumbox = {screenWidth / 2.0f - 100, 170, 225, 50};

  bool mouseOnText = false;
  // input box//

  Texture2D back = LoadTexture("./whackso/moleback.png");
  Texture2D mole = LoadTexture("./whackso/mole.png");
  Texture2D molehi = LoadTexture("./whackso/molehit.png");
  Texture2D molere = LoadTexture("./whackso/mole.png");
  Texture2D hole = LoadTexture("./whackso/holeup.png");
  Texture2D holed = LoadTexture("./whackso/holedo.png");
  Texture2D hammer = LoadTexture("./whackso/hammer1.png");
  Texture2D hamme = LoadTexture("./whackso/hammer.png");
  Texture2D re = LoadTexture("./whackso/hammer1.png");

  Texture2D backx[3] = {LoadTexture("./whackso/title.png"), LoadTexture("./whackso/altbackx.png"), LoadTexture("./whackso/gameov.png")};
  Texture2D logo = (LoadTexture("./whackso/logo.png"));
  Texture2D logscr = LoadTexture("./whackso/wood1.png");
  Texture2D plbutton = LoadTexture("./whackso/BUTTON.png");
  Texture2D subutton = LoadTexture("./whackso/submit.png");
  Texture2D savebutton = LoadTexture("./whackso/savebutt.png");
  Texture2D endbutton = LoadTexture("./whackso/endbut.png");

  Rectangle molerec;
  Rectangle ceili;
  Rectangle ceil2;
  Rectangle ceil3;
  Rectangle ceil4;
  Rectangle ceil5;
  Rectangle ceil6;
  Rectangle ceil7;
  Rectangle ceil8;
  Rectangle ceil9;
  Rectangle ceil10;
  Rectangle ceil11;
  Rectangle ceil12;
  Rectangle ceil13;
  Rectangle plrect;
  Rectangle surct;
  Rectangle point;
  Rectangle svrect;
  Rectangle enrect;
  Rectangle elimin;

  Vector2 mousepos = {-100.0f, -100.0f};
  Vector2 molevec = {screenWidth / 4.5, screenHeight / 4.5};
  Vector2 molehivec = {300, 100};
  Vector2 hamvec = mousepos;
  Vector2 pattrn[14] = {{1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}, {1500, 0}};
  Texture2D temp;

  bool active[10] = {
      true,
      true,
      true,
      true,
      true,
      true,
      true,
      true,
  };
  bool collision;
  bool collisionh = false;
  bool collisionk = false;
  bool collisionq = false;
  bool collisionre[5] = {false, false, false, false, false};
  char none[NONEA] = "/0";
  const char *str;
  str = "/0";
  char tempx;
  // GetMousePosition();

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    molerec.width = mole.width;
    molerec.height = mole.height;
    molerec.x = molevec.x;
    molerec.y = molevec.y;
    mousepos = GetMousePosition();
    // pattern 1 rectangles
    ceili.width = 50;
    ceili.height = 10;
    ceili.y = 66; // 58
    ceili.x = screenWidth / 4;

    ceil2.width = 50;
    ceil2.height = 10;
    ceil2.y = 190;
    ceil2.x = screenWidth / 1.5;

    ceil3.width = 50;
    ceil3.height = 10;
    ceil3.y = 320;
    ceil3.x = screenWidth / 4;
    // end pattern 1//

    // pattern 2 rectangles//
    ceil4.width = 50;
    ceil4.height = 10;
    ceil4.y = 70;
    ceil4.x = ceili.x + 335;

    ceil5.width = 50;
    ceil5.height = 10;
    ceil5.y = 190;
    ceil5.x = ceili.x;

    ceil6.width = 50;
    ceil6.height = 10;
    ceil6.y = 320;
    ceil6.x = 530;
    // end pattern 2//

    // pattern3//
    ceil7.width = 50;
    ceil7.height = 10;
    ceil7.y = 50; // 50
    ceil7.x = ceili.x + 115;

    ceil8.width = 50;
    ceil8.height = 10;
    ceil8.y = 190; // 180
    ceil8.x = ceil5.x + 115;

    ceil9.width = 50;
    ceil9.height = 10;
    ceil9.y = 320; // 320
    ceil9.x = ceil6.x - 215;

    ceil10.width = 50;
    ceil10.height = 10;
    ceil10.y = 50;
    ceil10.x = ceil7.x + 115;

    ceil11.width = 50;
    ceil11.height = 10;
    ceil11.y = 190; // 180
    ceil11.x = ceil8.x + 115;

    ceil12.width = 50;
    ceil12.height = 10;
    ceil12.y = 320; // 320
    ceil12.x = ceil9.x + 115;

    // end pattern3//

    plrect.width = plbutton.width;
    plrect.height = plbutton.height;
    plrect.x = 500;
    plrect.y = 350;
    surct.width = subutton.width;
    surct.height = subutton.height;
    surct.x = 400;
    surct.y = 300;

    svrect.x = 635;
    svrect.y = 200;
    svrect.width = savebutton.width;
    svrect.height = savebutton.height;

    enrect.width = endbutton.width;
    enrect.height = endbutton.height;
    enrect.x = 635;
    enrect.y = 300;

    elimin.width = backx[1].width;
    elimin.height = backx[2].height;

    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_W))
    {
      molevec.y -= 10;
    }
    if (IsKeyDown(KEY_S))
    {
      molevec.y += 10;
    }
    if (IsKeyDown(KEY_A))
    {
      molevec.x -= 10;
    }
    if (IsKeyDown(KEY_D))
    {
      molevec.x += 10;
    }
    point.x = mousepos.x;
    point.y = mousepos.y;
    point.width = 10;
    point.height = 10;

    collisionre[0] = (CheckCollisionRecs(point, plrect));
    if (collisionre[0])
    {
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      {
        backx[0].height = 0;
        backx[0].width = 0;
        plbutton.height = 0;
        plbutton.width = 0;
      }
    }

    collision = CheckCollisionPointRec(mousepos, molerec);
    if (collision)
    {
      DrawText("hola", 0.0, 2.0f, 50, GREEN);
    }

    float molelife = 0.3; // GetRandomValue(3.0,50.0);
    Timer moletimer = {0};

    if ((molevec.x + mole.width) >= GetScreenWidth() - 250)
      molevec.x = GetScreenWidth() - 185 - mole.width;
    else if (molevec.x <= 0)
      molevec.x = 0;

    // input box//
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
      mouseOnText = true;
    else
      mouseOnText = false;

    if (mouseOnText)
    {
      // Set the window's cursor to the I-Beam
      SetMouseCursor(MOUSE_CURSOR_IBEAM);

      // Get char pressed (unicode character) on the queue
      int key = GetCharPressed();

      // Check if more characters have been pressed on the same frame
      while (key > 0)
      {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
        {
          name[letterCount] = (char)key;
          name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
          letterCount++;
        }

        key = GetCharPressed(); // Check next character in the queue
      }

      if (IsKeyPressed(KEY_BACKSPACE))
      {
        letterCount--;
        if (letterCount < 0)
          letterCount = 0;
        name[letterCount] = '\0';
      }
    }
    else
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    // save score and name in database//
    collisionre[2] = CheckCollisionRecs(point, svrect);
    if (collisionre[2])
    {
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      {
        DrawText("hello hari", 700, 300, 50, RED);
        score += 0;
        // if (IsKeyPressed(KEY_TAB))
        //{

         //   emscripten_run_script("dbs.call()");
        //}
      }
    }
    // save score in database//

    // end game//
    collisionre[3] = CheckCollisionRecs(point, enrect);
    if (collisionre[3])
    {
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      {
        // backx[1].width = 0;
        //  backx[1].height = 0;
        endbutton.width = 0;
        endbutton.height = 0;
        backx[0].width = 800;
        backx[0].height = 500;
        logscr.width = 800;
        logscr.height = 500;
        textBox.width = dumbox.width;
        textBox.height = dumbox.height;
        plbutton.width = 150;
        plbutton.height = 50;
        subutton.width = 150;
        subutton.height = 50;
      }
    }

    collisionre[4] = CheckCollisionRecs(point, elimin);
    if (collisionre[4])
    {
      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      {
        DrawText("hello hari", 700, 300, 50, RED);
        mscore += 1;
        // if (IsKeyPressed(KEY_TAB))
        {

          //  emscripten_run_script("dbs.call()");
        }
      }
    }
    // end game//

    //  if (mouseOnText) framecounter++;
    // else framecounter = 0;

    // inputbox//

    // if ((molevec.y + mole.height) >= GetScreenHeight())
    //  molevec.y = GetScreenHeight() - mole.height;
    // e///lse if (molevec.y <= 0)
    //  molevec.y = 0;

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    molehivec = molevec;

    // DrawTexture(backx[0],screenWidth / 265, screenHeight / 255,WHITE);
    // DrawTexture(backx[1],screenWidth / 265, screenHeight / 255,WHITE);
    // DrawTexture(backx[2],screenWidth / 265, screenHeight / 255,WHITE);

    // DrawTexture(back, screenWidth / 265, screenHeight / 255, WHITE);

    // molevec.x=molevec.x+1;

    molevec.y = molevec.y - 0.25;

    if (score > 200)
    {
      molevec.y = molevec.y - 0.3;
    }

    if (score > 300)
    {
      molevec.y = molevec.y - 0.5;
    }

    if (IsKeyDown(KEY_ENTER))
    {

      // backx[0].width = 0;
      // backx[0].height = 0;
      // plbutton.width = 0;
      // plbutton.height = 0;

      // temp=backx[0];
      // backx[0]=backx[1];
      // backx[1]=temp;
    }

    if (IsKeyPressed(KEY_Q) || mscore > 100) // q instead of backspace temp
    {

      backx[1].width = 0;
      backx[1].height = 0;
      hole.width = 0;
      hole.height = 0;
      mole.width = 0;
      mole.height = 0;
      holed.width = 0;
      holed.height = 0;
      ceili.width = 0;
      ceili.height = 0;

      ceili.width = 0;
      ceili.height = 0;
      ceil2.width = 0;
      ceil2.height = 0;
      ceil3.width = 0;
      ceil3.height = 0;
      ceil4.width = 0;
      ceil4.height = 0;
      ceil5.width = 0;
      ceil5.height = 0;
      ceil6.width = 0;
      ceil6.height = 0;
      ceil7.width = 0;
      ceil7.height = 0;
      ceil8.width = 0;
      ceil8.height = 0;
      ceil9.width = 0;
      ceil9.height = 0;
      ceil10.width = 0;
      ceil10.height = 0;
      ceil11.width = 0;
      ceil11.height = 0;
      ceil12.width = 0;
      ceil12.height = 0;
    }

    if (IsKeyDown(KEY_W))
    {
      PlaySound(gamesound);
      // StopMusicStream(gamesound);
    }
    
      if(IsKeyDown(KEY_H))
            {
             // emscripten_run_script(" hola.call()");
            }
    
    
    if(IsKeyPressed(KEY_TAB))
               {
           //     emscripten_run_script("dbs.call()");
               }

    if (IsKeyDown(KEY_RIGHT_SHIFT))
    {
      backx[0].width = 800;
      backx[0].height = 500;
      backx[1].width = 800;
      backx[1].height = 500;
      logo.width = 800;
      logo.height = 800;

      hole.width = 440;
      hole.height = 297;
      mole.width = 81;
      mole.height = 84;
      holed.width = 440;
      holed.height = 297;
    }
    collisionre[1] = CheckCollisionRecs(point, surct);
    if (collisionre[1])
    {
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      // if (IsKeyPressed(KEY_L))
      {
        logscr.width = 0;
        logscr.height = 0;
        textBox.width = 0;
        textBox.height = 0;
        dumbox.x = 403;
        dumbox.y = 1;
        subutton.width = 0;
        subutton.height = 0;
        endbutton.width = 150;
        endbutton.height = 50;
        // name[MAX_INPUT_CHARS] = none[NONEA];
        // none[NONEA] = tempx;
        DrawText("Enter your name", 280, 140, 30, BLANK);
        // TextReplace("name",name,none);
      }
    }

    DrawRectangleRec(molerec, BLANK);
    if (collision)
    {
      DrawText("hola", 0.0, 2.0f, 50, GREEN);

      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      {

        active[1] = true;
        ceil10.x = ceil7.x + 115;

        ceil11.width = 50;
        ceil11.height = 10;
        ceil11.y = 180;
        ceil11.x = ceil8.x + 115;
        PlaySound(bonk);
        score += 1;
        hammer = hamme;
        mole = molehi;
        ceil12.width = 50;
        // mole.height=10;
        // mole.width=10;
      }
      else
      {
        hammer = re;
        mole = molere;
      }
    }
    collisionh = CheckCollisionRecs(molerec, ceili);
    if (collisionh)
    {

      molevec.x = ceil8.x - 10; // 520
      molevec.y = ceil8.y + 15; // GetRandomValue(0,screenHeight-200);
      DrawText("chaslllllo", 0.0, 2.0f, 50, MAROON);
    }

    collisionh = CheckCollisionRecs(molerec, ceil2);
    if (collisionh)
    {
      molevec.x = ceili.x; // GetRandomValue(200,520);//200;
      molevec.y = ceili.y + 23;
      DrawText("bo", 0.0, 2.0f, 50, MAROON);
    }

    collisionh = CheckCollisionRecs(molerec, ceil3);
    if (collisionh)
    {
      molevec.x = ceil2.x + 20; // CEIL9.X
      molevec.y = ceil2.y + 15; // 340
      DrawText("to", 0.0, 2.0f, 50, MAROON);
    }

    collisionk = CheckCollisionRecs(molerec, ceil4);
    if (collisionk)
    {
      molevec.x = ceil11.x - 10;
      molevec.y = ceil11.y + 15; // GetRandomValue(0,screenHeight-200);
      DrawText("chaslllllo", 0.0, 2.0f, 50, MAROON);
    }

    collisionk = CheckCollisionRecs(molerec, ceil5);
    if (collisionk)
    {
      molevec.x = ceil4.x; // GetRandomValue(520,200);//520;
      molevec.y = ceil4.y + 15;
      DrawText("bo", 0.0, 2.0f, 50, MAROON);
    }

    collisionk = CheckCollisionRecs(molerec, ceil6);
    if (collisionk)
    {
      molevec.x = ceil5.x;      // ceil12.x
      molevec.y = ceil5.y + 15; // 340
      DrawText("to", 0.0, 2.0f, 50, MAROON);
    }

    collisionq = CheckCollisionRecs(molerec, ceil7);
    if (collisionq)
    {
      molevec.x = ceili.x; // ceil7.x+115;
      molevec.y = 70;      // GetRandomValue(0,screenHeight-200);
      DrawText("chaslllllo", 0.0, 2.0f, 50, GREEN);
    }

    collisionq = CheckCollisionRecs(molerec, ceil8); // middle first
    if (collisionq)
    {
      molevec.x = ceil6.x;      // GetRandomValue(520,200);//ceil5.x+115; //  //+115
      molevec.y = ceil6.y + 20; // 70
      DrawText("bo", 0.0, 2.0f, 50, MAROON);
    }

    collisionq = CheckCollisionRecs(molerec, ceil9);
    if (collisionq)
    {
      molevec.x = ceil8.x + 115; // 115
      molevec.y = ceil5.y;
      DrawText("to", 0.0, 2.0f, 50, MAROON);
    }
    collisionq = CheckCollisionRecs(molerec, ceil10);
    if (collisionq)
    {
      molevec.x = ceil4.x; // ceil3.x+115;
      molevec.y = 90;      // GetRandomValue(0,screenHeight-200);
      DrawText("chaslllllo", 0.0, 2.0f, 50, MAROON);
    }

    collisionq = CheckCollisionRecs(molerec, ceil11); // middle second
    if (collisionq)
    {
      molevec.x = ceil3.x; // GetRandomValue(540,250);//ceil7.x+115; //
      molevec.y = ceil3.y + 15;
      DrawText("bo", 0.0, 2.0f, 50, MAROON);
    }

    collisionq = CheckCollisionRecs(molerec, ceil12);
    if (collisionq)
    {
      molevec.x = ceil6.x + 220;
      molevec.y = 300;
      DrawText("to", 0.0, 2.0f, 50, MAROON);
    }

    StartTimer(&moletimer, molelife);

    UpdateTimer(&moletimer);

    if (!TimerDone(&moletimer))
    {
      // molevec.y-=1.5;
    }
    else if (TimerDone(&moletimer))
    {
      molevec.y += 5;
    }

    //  if(active[1])
    //   {
    //  DrawTextureV(molehi,molehivec,RED);
    // }

    // DrawTextureV(mole, molevec, WHITE);

    DrawTexture(backx[2], screenWidth / 265, screenHeight / 255, WHITE);

    DrawTexture(backx[1], screenWidth / 265, screenHeight / 255, WHITE);
    DrawRectangleRec(elimin, BLANK);
    DrawRectangleRec(ceili, GREEN);
    DrawRectangleRec(ceil2, ORANGE);
    DrawRectangleRec(ceil3, ORANGE);
    DrawRectangleRec(ceil4, BLUE);
    DrawRectangleRec(ceil5, BLUE);
    DrawRectangleRec(ceil6, BLUE);
    DrawRectangleRec(ceil7, YELLOW);
    DrawRectangleRec(ceil8, YELLOW);
    DrawRectangleRec(ceil9, YELLOW);
    DrawRectangleRec(ceil10, YELLOW);
    DrawRectangleRec(ceil11, YELLOW);
    DrawRectangleRec(ceil12, YELLOW);
    DrawTexture(endbutton, 635, 300, WHITE);
    DrawTexture(savebutton, 635, 200, WHITE);
    // DrawTexture(backx[2],screenWidth / 265, screenHeight / 255,WHITE);

    DrawTexture(hole, screenWidth / 4.3, 130, WHITE);
    DrawTextureV(mole, molevec, WHITE);
    DrawTexture(holed, screenWidth / 4.3, 130, WHITE);
    DrawTextureV(hammer, mousepos, WHITE);
    DrawText(TextFormat("%04i", score), 600, 10, 55, BLUE);
    DrawText(TextFormat("%04i", mscore), 100, 10, 55, RED);
    DrawTexture(logscr, screenWidth / 265, screenHeight / 255, WHITE);

    // input box//
    // DrawText("Enter your name", 280, 140, 30, GREEN);
    DrawRectangleRec(dumbox, BLANK);
    DrawRectangleRec(textBox, LIGHTGRAY);
    DrawTexture(subutton, 400, 300, WHITE);
    DrawRectangleRec(surct, BLANK);

    if (mouseOnText)
      DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
    else
      DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

    DrawText(name, (int)dumbox.x + 5, (int)dumbox.y + 8, 55, RED);

    // DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, GREEN);

    if (mouseOnText)
    {
      if (letterCount < MAX_INPUT_CHARS)
      {
        // Draw blinking underscore char
        if (((framecounter / 20) % 2) == 0)
          DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
      }
      else
        DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
    }
    // input box//

    DrawTexture(backx[0], screenWidth / 265, screenHeight / 255, WHITE);
    DrawTexture(plbutton, 500, 350, WHITE);
    DrawRectangleRec(plrect, BLANK);
    DrawTexture(logo, screenWidth / 365, screenHeight / 20, WHITE);

    framecounter++;

    if (framecounter > 100)
    {
      logo.height = 0;
      logo.width = 0;
    }

    // dissa()
    //  {
    ///  ceili.width=0;
    /// ceili.height=0;
    /// ceil2.width=0;
    // ceil2.height=0;
    // ceil3.width=0;
    ///// ceil3.height=0;
    // ceil4.width=0;
    //// ceil4.height=0;
    // ceil5.width=0;
    ///  ceil5.height=0;
    /// ceil6.width=0;
    /// ceil6.height=0;
    ////ceil7.width=0;
    /// ceil7.height=0;
    // ceil8.width=0;
    // ceil8.height=0;
    ///  ceil9.width=0;
    // ceil9.height=0;
    // ceil10.width=0;
    // ceil10.height=0;

    //}

    // DrawTexture(backx[2],screenWidth / 265, screenHeight / 255,WHITE);

    if (active[1] == true)
    {

      /// UnloadTexture(mole);
    }

    collision = CheckCollisionPointRec(mousepos, molerec);
    if (collision)
    {
      DrawText("hola", 0.0, 2.0f, 50, GREEN);
    }

    // DrawText(name, 400, 10, 55, RED);

    // ClearBackground(RAYWHITE);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
