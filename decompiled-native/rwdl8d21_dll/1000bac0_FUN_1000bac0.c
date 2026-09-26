// 1000bac0 FUN_1000bac0 [Global]
// programa: RWDL8D21.DLL

int * FUN_1000bac0(int *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  
  pbVar4 = (byte *)param_2[1];
  local_3c = pbVar4 + *param_2;
  if (param_2 != (int *)0x0) {
    local_38 = pbVar4;
    if (pbVar4 < local_3c) {
      do {
        uVar6 = (uint)*local_38;
        bVar1 = (&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + uVar6)];
        bVar2 = (&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + uVar6)];
        iVar10 = -1;
        bVar3 = (&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + uVar6)];
        local_34 = local_3c + -1;
        if (local_38 < local_34) {
          do {
            uVar6 = (uint)*local_34;
            sVar9 = (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077ec0 + uVar6)] -
                    (ushort)bVar1;
            iVar14 = (int)(short)((ushort)(byte)(&DAT_100781d0)
                                                [*(byte *)((int)&DAT_10077ec0 + uVar6)] +
                                 (ushort)bVar1);
            iVar13 = (int)(short)((ushort)bVar3 +
                                 (ushort)(byte)(&DAT_100781d0)
                                               [*(byte *)((int)&DAT_10077fc0 + uVar6)]);
            sVar5 = (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077fc0 + uVar6)] -
                    (ushort)bVar3;
            iVar7 = *param_1 * 2 - iVar14;
            sVar11 = (ushort)(byte)(&DAT_100781d0)[*(byte *)((int)&DAT_10077db0 + uVar6)] -
                     (ushort)bVar2;
            iVar14 = (param_1[1] * 2 + -2) - iVar14;
            iVar15 = param_1[2] * 2 - iVar13;
            iVar13 = (param_1[3] * 2 + -2) - iVar13;
            iVar12 = (int)(short)((ushort)bVar2 +
                                 (ushort)(byte)(&DAT_100781d0)
                                               [*(byte *)((int)&DAT_10077db0 + uVar6)]);
            iVar10 = param_1[4] * 2 - iVar12;
            iVar12 = (param_1[5] * 2 + -2) - iVar12;
            iVar8 = iVar14;
            if (sVar9 < 0) {
              iVar8 = iVar7;
              iVar7 = iVar14;
            }
            iVar14 = iVar13;
            if (sVar5 < 0) {
              iVar14 = iVar15;
              iVar15 = iVar13;
            }
            iVar13 = iVar12;
            if (sVar11 < 0) {
              iVar13 = iVar10;
              iVar10 = iVar12;
            }
            iVar10 = iVar7 * sVar9 + iVar15 * sVar5 + iVar10 * sVar11;
            if (-1 < iVar10) goto LAB_1000bcd8;
            if (iVar8 * sVar9 + iVar14 * sVar5 + iVar13 * sVar11 < 1) {
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
LAB_1000bcd8:
          local_3c = local_3c + -1;
          *local_38 = *local_3c;
        }
      } while (local_38 < local_3c);
    }
    iVar10 = (int)local_3c - (int)pbVar4;
    if (iVar10 < *param_2) {
      iVar15 = (**(code **)(DAT_10077da8 + 0x354))(pbVar4,iVar10);
      param_2[1] = iVar15;
      *param_2 = iVar10;
    }
  }
  return param_2;
}


