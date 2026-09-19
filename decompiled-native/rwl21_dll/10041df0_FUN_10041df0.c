// 10041df0 FUN_10041df0 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10041df0(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  float10 fVar4;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(byte *)(param_1 + 0x48) & 0x60) == 0) {
    local_4 = 0.0;
    local_8 = 0.0;
    local_c = 0.0;
    if (*(ushort *)(param_1 + 0x6c) != 0) {
      uVar3 = (uint)*(ushort *)(param_1 + 0x6c);
      piVar2 = *(int **)(param_1 + 0x70);
      do {
        uVar3 = uVar3 - 1;
        local_c = *(float *)(*piVar2 + 0x10) + local_c;
        local_8 = *(float *)(*piVar2 + 0x14) + local_8;
        local_4 = *(float *)(*piVar2 + 0x18) + local_4;
        piVar2 = piVar2 + 1;
      } while (uVar3 != 0);
      fVar4 = rwLengthNormaliseVector(&local_c,&local_c);
      if (fVar4 <= (float10)_DAT_100522e8) {
        iVar1 = **(int **)(param_1 + 0x70);
        local_c = *(float *)(iVar1 + 0x10);
        local_8 = *(float *)(iVar1 + 0x14);
        local_4 = *(float *)(iVar1 + 0x18);
      }
    }
    *(float *)(param_1 + 0x4c) = local_c;
    *(float *)(param_1 + 0x50) = local_8;
    *(float *)(param_1 + 0x54) = local_4;
  }
  return;
}


