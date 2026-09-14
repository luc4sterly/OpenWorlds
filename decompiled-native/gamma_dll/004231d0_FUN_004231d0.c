// 004231d0 FUN_004231d0 [Global]
// programa: gamma.dll

undefined4 * __fastcall FUN_004231d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00471860;
  *(undefined ***)param_1[1] = &PTR_LAB_0047186c;
  *(int *)(param_1[1] + 0x3c) = (int)param_1 + (0x40 - param_1[1]);
  param_1[3] = &PTR_LAB_00471824;
  if ((undefined4 *)param_1[0xf] != (undefined4 *)0x0) {
    FUN_0044e100((undefined4 *)param_1[0xf]);
  }
  param_1[3] = &PTR_LAB_0046f370;
  FUN_00404dc0(param_1 + 10);
  *param_1 = &PTR_LAB_0046f358;
  *(undefined ***)param_1[1] = &PTR_LAB_0046f364;
  *(int *)(param_1[1] + 0x3c) = (int)param_1 + (0xc - param_1[1]);
  return param_1;
}


