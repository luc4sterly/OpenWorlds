// 0041828d FUN_0041828d [Global]
// programa: sfmain.exe

void __fastcall FUN_0041828d(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (DAT_0043d51c != 0) {
    uVar2 = FUN_004176dc(param_1,param_2);
    uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
    if (DAT_0043d538 == 0) {
      uVar2 = FUN_004176a3(extraout_ECX,uVar1);
      DAT_0043d51c = 0;
      FUN_004152eb(extraout_ECX_00,(int)((ulonglong)uVar2 >> 0x20));
    }
    else {
      DAT_0043d544 = 1;
      FUN_004152eb(extraout_ECX,uVar1);
    }
  }
  return;
}


