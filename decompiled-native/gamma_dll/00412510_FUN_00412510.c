// 00412510 FUN_00412510 [Global]
// program: gamma.dll

int * __fastcall FUN_00412510(int *param_1)

{
  int *piVar1;
  
  *param_1 = DAT_0049ed10;
  param_1[1] = DAT_0049ed14;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if (*param_1 == 0) {
    piVar1 = (int *)FUN_004517c0();
    FUN_00411b30(param_1,piVar1);
  }
  return param_1;
}


