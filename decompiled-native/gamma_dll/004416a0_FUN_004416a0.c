// 004416a0 FUN_004416a0 [Global]
// programa: gamma.dll

int * __thiscall FUN_004416a0(int *param_1,uint param_2)

{
  if (param_1 != (int *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = (int)&PTR_FUN_0047891c;
      param_1[3] = (int)&PTR_FUN_00478934;
      param_1[4] = (int)&PTR_FUN_00478978;
      param_1[0x2f] = (int)&PTR_FUN_00478a7c;
      param_1[0x30] = (int)&PTR_FUN_00478aa8;
      if ((HGDIOBJ)param_1[0x50] != (HGDIOBJ)0x0) {
        DeleteObject((HGDIOBJ)param_1[0x50]);
      }
      FUN_0044a000(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,&LAB_00440c80);
    }
  }
  return param_1;
}


