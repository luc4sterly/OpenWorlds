// 1000c3c0 FUN_1000c3c0 [Global]
// programa: rwdlmd21.dll

int * FUN_1000c3c0(int *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  
  pbVar4 = (byte *)param_2[1];
  local_3c = pbVar4 + *param_2;
  if (param_2 != (int *)0x0) {
    local_38 = pbVar4;
    if (pbVar4 < local_3c) {
      do {
        uVar5 = (uint)*local_38;
        bVar1 = (&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + uVar5)];
        bVar2 = (&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + uVar5)];
        bVar3 = (&DAT_1008a210)[*(byte *)((int)&DAT_10089df0 + uVar5)];
        iVar10 = -1;
        local_34 = local_3c + -1;
        if (local_38 < local_34) {
          do {
            uVar5 = (uint)*local_34;
            local_40 = (uint)*(byte *)((int)&DAT_10089df0 + uVar5);
            sVar9 = (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_10089f00 + uVar5)] -
                    (ushort)bVar1;
            sVar11 = (ushort)(byte)(&DAT_1008a210)[*(byte *)((int)&DAT_1008a000 + uVar5)] -
                     (ushort)bVar2;
            iVar12 = (int)(short)((ushort)bVar1 +
                                 (ushort)(byte)(&DAT_1008a210)
                                               [*(byte *)((int)&DAT_10089f00 + uVar5)]);
            iVar6 = *param_1 * 2 - iVar12;
            sVar8 = (ushort)(byte)(&DAT_1008a210)[local_40] - (ushort)bVar3;
            iVar13 = (int)(short)((ushort)bVar2 +
                                 (ushort)(byte)(&DAT_1008a210)
                                               [*(byte *)((int)&DAT_1008a000 + uVar5)]);
            iVar12 = (param_1[1] * 2 + -2) - iVar12;
            iVar15 = param_1[2] * 2 - iVar13;
            iVar13 = (param_1[3] * 2 + -2) - iVar13;
            iVar10 = (int)(short)((ushort)bVar3 + (ushort)(byte)(&DAT_1008a210)[local_40]);
            iVar14 = param_1[4] * 2 - iVar10;
            iVar10 = (param_1[5] * 2 + -2) - iVar10;
            iVar7 = iVar12;
            if (sVar9 < 0) {
              iVar7 = iVar6;
              iVar6 = iVar12;
            }
            iVar12 = iVar13;
            if (sVar11 < 0) {
              iVar12 = iVar15;
              iVar15 = iVar13;
            }
            if (sVar8 < 0) {
              iVar10 = iVar10 * sVar8;
              iVar13 = iVar14 * sVar8;
            }
            else {
              iVar13 = iVar10 * sVar8;
              iVar10 = iVar14 * sVar8;
            }
            iVar10 = iVar6 * sVar9 + iVar15 * sVar11 + iVar10;
            if (-1 < iVar10) goto LAB_1000c5ed;
            if (iVar7 * sVar9 + iVar12 * sVar11 + iVar13 < 1) {
              local_3c = local_3c + -1;
              *local_34 = *local_3c;
            }
            local_34 = local_34 + -1;
          } while (local_38 < local_34);
        }
        if (iVar10 < 0) {
          local_38 = local_38 + 1;
        }
        else {
LAB_1000c5ed:
          local_3c = local_3c + -1;
          *local_38 = *local_3c;
        }
      } while (local_38 < local_3c);
    }
    iVar10 = (int)local_3c - (int)pbVar4;
    if (iVar10 < *param_2) {
      iVar15 = (**(code **)(DAT_10089de0 + 0x354))(pbVar4,iVar10);
      param_2[1] = iVar15;
      *param_2 = iVar10;
    }
  }
  return param_2;
}


