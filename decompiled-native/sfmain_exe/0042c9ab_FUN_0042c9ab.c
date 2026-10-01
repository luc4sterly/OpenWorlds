// 0042c9ab FUN_0042c9ab [Global]
// program: sfmain.exe

undefined4 * __fastcall FUN_0042c9ab(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar2;
  
  FUN_0042f85c(param_1,param_2);
  uVar1 = *in_EAX;
  FUN_0042fbc4(extraout_EDX,uVar1);
  uVar2 = FUN_0042fe62(extraout_ECX,extraout_EDX_00);
  if ((int)uVar2 != 0) {
    FUN_0042fbc4(param_2,uVar1);
  }
  return param_2;
}


