// 0044aa60 FUN_0044aa60 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_0044aa60(void *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_004492f0(param_1,param_2);
  if (iVar1 == 0) {
    *(int *)((int)param_1 + 0xf8) = *(int *)((int)param_1 + 0xf8) + 1;
    return 0;
  }
  return 1;
}


