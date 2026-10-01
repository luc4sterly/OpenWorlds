// 10042410 FUN_10042410 [Global]
// program: RWL21.DLL

int FUN_10042410(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = *(int *)(param_2 + 8);
  iVar4 = iVar7 + -8;
  iVar1 = *(int *)(param_1 + 8);
  if (iVar4 <= *(int *)(param_1 + 4) - iVar1) {
    puVar3 = (undefined4 *)(param_1 + 0xc + iVar1 * 0x74);
    puVar5 = (undefined4 *)(param_2 + 0x3ac);
    if (iVar4 != 0) {
      *(int *)(param_1 + 8) = iVar1 + iVar4;
      iVar7 = iVar7 + -9;
      do {
        *puVar3 = *puVar5;
        puVar3[1] = puVar5[1];
        puVar3[2] = puVar5[2];
        uVar2 = puVar5[0x1a];
        puVar3[0x19] = puVar5[0x19];
        puVar3[0x1a] = uVar2;
        *(undefined1 *)(puVar3 + 0x12) = *(undefined1 *)(puVar5 + 0x12);
        if ((*(byte *)(puVar5 + 0x12) & 0x40) != 0) {
          puVar3[0x13] = puVar5[0x13];
          puVar3[0x14] = puVar5[0x14];
          puVar3[0x15] = puVar5[0x15];
        }
        puVar3 = puVar3 + 0x1d;
        puVar5 = puVar5 + 0x1d;
        bVar8 = iVar7 != 0;
        iVar7 = iVar7 + -1;
      } while (bVar8);
      iVar7 = 8;
      pfVar6 = (float *)(param_2 + 0xc);
      do {
        FUN_100421e0(param_1,pfVar6);
        iVar7 = iVar7 + -1;
        pfVar6 = pfVar6 + 0x1d;
      } while (iVar7 != 0);
    }
    return iVar1 + -7;
  }
  return 0;
}


