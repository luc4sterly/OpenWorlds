// 00418250 FUN_00418250 [Global]
// programa: gamma.dll

undefined4 __cdecl
FUN_00418250(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_30 [5];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  piVar3 = local_30;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  iVar1 = RwPickScene(param_1,param_3,param_4,param_2,local_30);
  iVar2 = 0;
  if ((iVar1 != 0) && (local_30[0] == 1)) {
    *param_5 = local_1c;
    param_5[1] = local_18;
    param_5[2] = local_14;
    iVar2 = local_30[1];
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar2;
}


