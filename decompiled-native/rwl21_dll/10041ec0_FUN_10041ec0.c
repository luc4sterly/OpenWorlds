// 10041ec0 FUN_10041ec0 [Global]
// programa: RWL21.DLL

void FUN_10041ec0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort uVar8;
  int *piVar9;
  int iVar10;
  float fVar11;
  uint uVar12;
  undefined4 *puVar13;
  float local_24;
  float local_20;
  
  if ((*(byte *)(param_1 + 0x48) & 0x20) == 0) {
    local_24 = 0.0;
    uVar8 = *(ushort *)(param_1 + 0x6c);
    local_20 = 0.0;
    if (uVar8 != 0) {
      fVar1 = 0.0;
      fVar2 = 0.0;
      fVar3 = 0.0;
      fVar4 = 0.0;
      puVar13 = *(undefined4 **)(param_1 + 0x70);
      uVar12 = (uint)uVar8;
      fVar5 = 0.0;
      fVar6 = 0.0;
      fVar7 = 0.0;
      do {
        piVar9 = (int *)*puVar13;
        puVar13 = puVar13 + 1;
        uVar12 = uVar12 - 1;
        iVar10 = *piVar9;
        fVar4 = *(float *)(iVar10 + 0xc) + fVar4;
        fVar3 = *(float *)(iVar10 + 0x10) + fVar3;
        local_24 = *(float *)(iVar10 + 0x14) + local_24;
        local_20 = *(float *)(iVar10 + 0x18) + local_20;
        fVar7 = fVar7 + *(float *)(iVar10 + 0x1c);
        fVar2 = *(float *)(iVar10 + 0x20) + fVar2;
        fVar6 = *(float *)(iVar10 + 0x24) + fVar6;
        fVar5 = *(float *)(iVar10 + 0x28) + fVar5;
        fVar1 = *(float *)(iVar10 + 0x2c) + fVar1;
      } while (uVar12 != 0);
      fVar11 = (float)uVar8;
      *(float *)(param_1 + 0x24) = fVar4 / fVar11;
      *(float *)(param_1 + 0x28) = fVar3 / fVar11;
      *(float *)(param_1 + 0x2c) = local_24 / fVar11;
      *(float *)(param_1 + 0x34) = fVar7 / fVar11;
      *(float *)(param_1 + 0x38) = fVar2 / fVar11;
      *(float *)(param_1 + 0x3c) = fVar6 / fVar11;
      *(float *)(param_1 + 0x40) = fVar5 / fVar11;
      *(float *)(param_1 + 0x44) = fVar1 / fVar11;
      *(float *)(param_1 + 0x30) = local_20 / fVar11;
      return;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  return;
}


