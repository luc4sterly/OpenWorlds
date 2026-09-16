// 0043e0d0 FUN_0043e0d0 [Global]
// programa: gamma.dll

undefined4 FUN_0043e0d0(undefined4 *param_1)

{
  int *piVar1;
  
  param_1[6] = param_1[6] + -1;
  if (param_1[6] != 0) {
    return param_1[6];
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = &PTR_FUN_00477898;
    param_1[1] = &PTR_FUN_004778c4;
    param_1[2] = &PTR_FUN_00477908;
    param_1[3] = &PTR_FUN_0047794c;
    param_1[4] = &PTR_FUN_0047797c;
    param_1[5] = &PTR_FUN_004779cc;
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      param_1[9] = 0;
    }
    OleUninitialize();
    FUN_0044e100(param_1);
  }
  return 0;
}


