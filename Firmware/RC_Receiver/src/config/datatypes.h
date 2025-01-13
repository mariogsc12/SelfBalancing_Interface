// -------------------------------------------------- //
// ------------------- DATA TYPES ------------------- //
typedef enum
{
  MODE_IDLE,      // 0
  MODE_UP,        // 1
  MODE_MIDDLE,    // 2
  MODE_DOWN,      // 3
  MODE_ERROR      // 4
}SwitchMode;

typedef struct 
{
    const int id;
    int PwmMin;
    int PwmCenter;
    int PwmMax;
}RC_Signal;

