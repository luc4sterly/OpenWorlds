// 00407570 FUN_00407570 [Global]
// programa: gamma.dll

int * __fastcall FUN_00407570(int *param_1)

{
  int iVar1;
  uint *puVar2;
  undefined1 auStack_3c [20];
  undefined1 *local_28;
  undefined1 *local_10;
  
  *param_1 = 0;
  puVar2 = FUN_0044e010(0x28);
  *param_1 = (int)puVar2;
  local_28 = auStack_3c;
  local_10 = auStack_3c;
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = 3;
    *(undefined4 *)(iVar1 + 8) = 1;
    puVar2 = FUN_0044e010(*(int *)(iVar1 + 4) + 1);
    *(uint **)(iVar1 + 0xc) = puVar2;
    InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x10));
  }
  **(undefined1 **)(*param_1 + 0xc) = DAT_0046d930;
  *(undefined4 *)*param_1 = 0;
  return param_1;
}


