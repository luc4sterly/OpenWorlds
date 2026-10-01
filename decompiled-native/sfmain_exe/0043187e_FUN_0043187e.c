// 0043187e FUN_0043187e [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0043187e(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar1;
  
  _DAT_004e57c4 = 0;
  _DAT_004e57c8 = 0;
  GetStdHandle(0xfffffff6);
  FUN_0043173d(extraout_ECX,extraout_EDX);
  GetStdHandle(0xfffffff5);
  FUN_0043173d(extraout_ECX_00,extraout_EDX_00);
  GetStdHandle(0xfffffff4);
  uVar1 = FUN_0043173d(extraout_ECX_01,extraout_EDX_01);
  return CONCAT44(param_2,(int)uVar1);
}


