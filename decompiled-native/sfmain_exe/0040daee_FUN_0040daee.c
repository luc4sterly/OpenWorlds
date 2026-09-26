// 0040daee FUN_0040daee [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_0040daee(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  uint uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_10;
  
  FUN_0042c6a0(param_1,DAT_00445b20);
  uVar1 = FUN_0042be63(DAT_004393a4,0xc);
  if (uVar1 == 1) {
    *in_EAX = local_2c;
    *param_2 = local_28;
    uVar1 = FUN_0042be63(DAT_004393a4,(int)local_24);
    if (uVar1 == 1) {
      uVar1 = FUN_0042be63(DAT_004393a4,(int)local_22);
      if (uVar1 == 1) {
        uVar2 = FUN_0042c794(extraout_ECX,extraout_EDX);
        DAT_00445b20 = (int)uVar2;
        local_10 = 1;
      }
      else {
        local_10 = 0;
      }
    }
    else {
      local_10 = 0;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}


