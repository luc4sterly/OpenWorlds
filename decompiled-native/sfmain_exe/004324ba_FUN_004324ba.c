// 004324ba FUN_004324ba [Global]
// program: sfmain.exe

float10 __fastcall FUN_004324ba(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  
  iVar1 = (*(code *)PTR_thunk_FUN_00433814_0043eacc)(param_2);
  if (iVar1 == 0) {
    FUN_00432472(extraout_ECX,in_EAX[1]);
    if (*in_EAX == 1) {
      FUN_0042d8a8(extraout_ECX_00,extraout_EDX);
    }
    else {
      FUN_0042d8bb(extraout_ECX_00,extraout_EDX);
    }
  }
  return (float10)*(double *)(in_EAX + 6);
}


