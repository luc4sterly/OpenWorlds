// 00401779 FUN_00401779 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00401779(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined8 uVar1;
  undefined4 uStack_20;
  
  uVar1 = FUN_004026f4(param_1,param_2);
  if ((int)uVar1 == 0) {
    uStack_20 = 0;
  }
  else {
    uVar1 = FUN_0040186c(extraout_ECX,(int)((ulonglong)uVar1 >> 0x20));
    uStack_20 = (undefined4)uVar1;
  }
  return CONCAT44(param_2,uStack_20);
}


