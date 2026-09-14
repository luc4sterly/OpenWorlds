// 00443df0 FUN_00443df0 [Global]
// programa: gamma.dll

undefined4 FUN_00443df0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x34);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  if (puVar1 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  else {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00467068,param_1 + 0x40);
    if (-1 < iVar2) {
      (**(code **)(**(int **)(param_1 + 0x40) + 8))(*(int **)(param_1 + 0x40));
    }
  }
  if (*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) {
    FUN_00451780(*(undefined4 **)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = FUN_0044b350((int)param_3);
    uVar3 = FUN_00450b60((iVar2 + 1) * 2);
    *(undefined4 *)(param_1 + 0x38) = uVar3;
    if (*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) {
      FUN_0044df50(*(undefined4 **)(param_1 + 0x38),param_3,(iVar2 + 1) * 2);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


