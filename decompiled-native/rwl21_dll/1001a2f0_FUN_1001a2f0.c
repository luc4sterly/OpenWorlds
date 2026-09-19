// 1001a2f0 FUN_1001a2f0 [Global]
// programa: RWL21.DLL

void FUN_1001a2f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (((*(int *)(param_1 + 0x34) != 0) &&
      (*(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc0) = 0, *(int *)(param_1 + 0x2c) == param_1))
     && (*(char *)(param_1 + 0x3a) != '\0')) {
    piVar3 = (int *)(param_1 + 0x3c);
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar2 = iVar2 + 1;
      FUN_10041ec0(iVar1);
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x3a));
  }
  return;
}


