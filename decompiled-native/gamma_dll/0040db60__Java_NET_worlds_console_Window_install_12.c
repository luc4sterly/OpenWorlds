// 0040db60 _Java_NET_worlds_console_Window_install@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_install_12(int *param_1,undefined4 param_2,byte param_3)

{
  undefined4 uVar1;
  HWND pHVar2;
  uint *this;
  
                    /* 0xdb60  98  _Java_NET_worlds_console_Window_install@12 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891b0);
  pHVar2 = (HWND)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891b4);
  this = FUN_0044e010(0x30);
  if (this != (uint *)0x0) {
    FUN_0040f250(this,uVar1,pHVar2,(uint)param_3);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004891ac,this);
  if (DAT_004891c0 != (HWND)0x0) {
    SendMessageA(DAT_004891c0,0x8067,DAT_004891c8,0);
  }
  if ((param_3 != 0) && (DAT_00489274 != 0)) {
    DAT_00489274 = 0;
    SendMessageA((HWND)*this,0x8065,1,0);
    *(undefined1 *)(this + 9) = 1;
  }
  GetWindowLongA((HWND)*this,-6);
  return;
}


