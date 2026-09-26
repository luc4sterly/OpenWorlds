// 00404fa9 FUN_00404fa9 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00404fa9(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar1;
  
  DAT_0040b474 = 0;
  DAT_0040b478 = 0;
  GetStdHandle(0xfffffff6);
  FUN_00404e68(extraout_ECX,extraout_EDX);
  GetStdHandle(0xfffffff5);
  FUN_00404e68(extraout_ECX_00,extraout_EDX_00);
  GetStdHandle(0xfffffff4);
  uVar1 = FUN_00404e68(extraout_ECX_01,extraout_EDX_01);
  return CONCAT44(param_2,(int)uVar1);
}


