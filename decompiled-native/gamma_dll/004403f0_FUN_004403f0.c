// 004403f0 FUN_004403f0 [Global]
// programa: gamma.dll

void __thiscall FUN_004403f0(void *param_1,LPCSTR param_2)

{
  int iVar1;
  
  if ((param_2 != (LPCSTR)0x0) && (*(int *)((int)param_1 + 0x34) != 0)) {
    iVar1 = FUN_00440770(param_1,param_2);
    if (-1 < iVar1) {
      iVar1 = FUN_00440900((int)param_1);
      if (-1 < iVar1) {
        *(undefined4 *)((int)param_1 + 8) = 1;
        *(undefined4 *)((int)param_1 + 0x38) = 1;
      }
    }
  }
  return;
}


