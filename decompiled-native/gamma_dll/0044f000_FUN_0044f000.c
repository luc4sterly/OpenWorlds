// 0044f000 FUN_0044f000 [Global]
// programa: gamma.dll

int __fastcall FUN_0044f000(int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined1 auStack_60 [4];
  undefined1 local_5c;
  char local_5b;
  int local_5a;
  undefined1 *local_40;
  undefined **local_3c;
  undefined4 local_38 [2];
  undefined ***local_30;
  undefined4 *local_2c;
  undefined1 *local_14;
  
  local_14 = auStack_60;
  local_5c = 0;
  local_5b = 0;
  local_5a = param_1;
  bVar2 = FUN_00403760(*(int *)(param_1 + 4));
  if (bVar2) {
    iVar3 = FUN_0044f260(*(int *)(local_5a + 4));
    if (iVar3 != 0) {
      iVar3 = FUN_0044f260(*(int *)(local_5a + 4));
      FUN_0044f000(iVar3);
    }
    bVar2 = FUN_00403760(*(int *)(local_5a + 4));
    if (bVar2) {
      local_5c = 1;
    }
    else {
      FUN_004036b0(*(void **)(local_5a + 4),4);
    }
  }
  else {
    FUN_004036b0(*(void **)(local_5a + 4),4);
  }
  local_5b = '\x01';
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x24);
  if ((piVar1 != (int *)0x0) &&
     (local_40 = auStack_60, iVar3 = (**(code **)(*piVar1 + 0x14))(), iVar3 == -1)) {
    iVar3 = *(int *)(param_1 + 4);
    *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 1;
    if (*(int *)(iVar3 + 0x24) == 0) {
      *(byte *)(iVar3 + 0x32) = *(byte *)(iVar3 + 0x32) | 1;
    }
    if ((*(byte *)(iVar3 + 0x33) & *(byte *)(iVar3 + 0x32)) != 0) {
      local_30 = &local_3c;
      local_3c = &PTR_LAB_0046d4fc;
      local_2c = local_38;
      iVar3 = FUN_0044d690(s_ios_base_failure_in_clear_00480e90);
      iVar3 = FUN_00450b60(iVar3 + 1);
      FUN_00403d80(local_2c,iVar3);
      FUN_0044d6b0((char *)*local_2c,s_ios_base_failure_in_clear_00480e90);
      FUN_00451670();
    }
  }
  if ((((*(byte *)(*(int *)(local_5a + 4) + 0x32) & 5) == 0) &&
      ((*(ushort *)(*(int *)(local_5a + 4) + 0x30) & 0x2000) != 0)) && (local_5b == '\0')) {
    FUN_0044f000(local_5a);
  }
  return param_1;
}


