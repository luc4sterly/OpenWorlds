// 100394b0 RwCloseDisplayDevice [Global]
// program: RWL21.DLL

undefined4 RwCloseDisplayDevice(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x394b0  29  RwCloseDisplayDevice */
  if (DAT_1005b754 == 0) {
    FUN_1000cba0(0x55);
    uVar1 = 0;
  }
  else if (param_1 == 0) {
    FUN_1000cba0(1);
    uVar1 = 0;
  }
  else {
    (**(code **)(param_1 + 0x248))();
    if (DAT_1005e06c != (undefined4 *)0x0) {
      FUN_100446a0(DAT_1005e06c);
    }
    uVar1 = 1;
  }
  return uVar1;
}


