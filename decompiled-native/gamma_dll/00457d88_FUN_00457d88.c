// 00457d88 FUN_00457d88 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_00457d88(undefined4 *param_1,undefined2 *param_2,int param_3,int param_4,int param_5,
            int *param_6)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  char cVar10;
  undefined2 extraout_CX;
  int iVar8;
  uint uVar9;
  undefined2 extraout_DX;
  uint uVar11;
  byte bVar13;
  byte *pbVar12;
  ushort *puVar14;
  undefined4 *puVar15;
  undefined2 *puVar16;
  undefined1 *puVar17;
  
  puVar17 = &stack0xfffffffc;
  _DAT_00482d00 = param_3;
  DAT_00482d04 = (undefined1)param_4;
  DAT_00482cfc = param_2;
  _DAT_00482d05 = param_5;
  iVar8 = param_5 + param_4 * -4;
  _DAT_00482d09 = param_5 + iVar8;
  puVar14 = (ushort *)param_6[1];
  DAT_00482cf0 = (byte *)param_6[2];
  DAT_00482cf4 = (byte *)param_6[3];
  DAT_00482cf8 = (undefined4 *)param_6[4];
  uVar11 = *(uint *)*param_6;
  DAT_00482cec = (uint *)*param_6 + 1;
  uVar11 = uVar11 << 0x10 | uVar11 >> 0x10;
  uVar9 = (uint)CONCAT11(DAT_00482d04,(char)iVar8);
LAB_00457e1a:
  do {
    uVar7 = (undefined2)uVar9;
    uVar3 = uVar11 * 2;
    if (CARRY4(uVar11,uVar11)) {
      uVar11 = uVar11 * 4;
      if (uVar11 == 0) {
        uVar11 = *DAT_00482cec;
        DAT_00482cec = DAT_00482cec + 1;
        uVar11 = uVar11 << 0x10 | uVar11 >> 0x10;
      }
      if (CARRY4(uVar3,uVar3)) {
        bVar13 = *DAT_00482cf4;
        DAT_00482cf4 = DAT_00482cf4 + 1;
        if (bVar13 == 0x24) {
          uVar2 = *DAT_00482cf8;
          *param_1 = uVar2;
          *(char *)param_2 = (char)((uint)uVar2 >> 0x18);
          uVar2 = DAT_00482cf8[1];
          puVar15 = (undefined4 *)((int)param_1 + _DAT_00482d05);
          *puVar15 = uVar2;
          param_1 = (undefined4 *)((int)puVar15 - _DAT_00482d05);
          *(char *)((int)param_2 + 1) = (char)((uint)uVar2 >> 0x18);
          DAT_00482cf8 = DAT_00482cf8 + 2;
        }
        else {
          if ((bVar13 & 7) == 0) {
            if (bVar13 == 0) {
              uVar6 = *(undefined2 *)DAT_00482cf8;
              DAT_00482cf8 = (undefined4 *)((int)DAT_00482cf8 + 2);
            }
            else {
              uVar1 = *(undefined1 *)DAT_00482cf8;
              DAT_00482cf8 = (undefined4 *)((int)DAT_00482cf8 + 1);
              uVar6 = CONCAT11(*(undefined1 *)(((bVar13 >> 3) - 3) + (int)param_2),uVar1);
            }
          }
          else {
            uVar1 = *(undefined1 *)(((bVar13 & 7) - 3) + (int)param_2);
            if (bVar13 >> 3 == 0) {
              uVar6 = CONCAT11(*(undefined1 *)DAT_00482cf8,uVar1);
              DAT_00482cf8 = (undefined4 *)((int)DAT_00482cf8 + 1);
            }
            else {
              uVar6 = CONCAT11(*(undefined1 *)(((bVar13 >> 3) - 3) + (int)param_2),uVar1);
            }
          }
          *param_2 = uVar6;
          bVar13 = *DAT_00482cf0;
          pbVar12 = DAT_00482cf0 + 1;
          DAT_00482cf0 = pbVar12;
          uVar6 = (*(code *)(&PTR_LAB_00483844)[bVar13])(uVar9,uVar11,puVar17);
          *(undefined2 *)param_1 = extraout_DX;
          *(undefined2 *)((int)param_1 + 2) = extraout_CX;
          puVar16 = (undefined2 *)((int)param_1 + _DAT_00482d05);
          *puVar16 = (short)pbVar12;
          puVar16[1] = uVar6;
          param_1 = (undefined4 *)((int)puVar16 - _DAT_00482d05);
        }
      }
      else {
        uVar5 = *puVar14;
        puVar14 = puVar14 + 1;
        bVar13 = (byte)(uVar5 >> 8);
        uVar7 = (undefined2)CONCAT31((int3)(uVar9 >> 8),bVar13);
        iVar8 = *(int *)(&DAT_00482d0d + (uVar5 & 0xff) * 4);
        *(undefined2 *)param_1 = *(undefined2 *)(iVar8 + (int)param_1);
        puVar16 = (undefined2 *)((int)param_1 + _DAT_00482d05);
        uVar6 = *(undefined2 *)(iVar8 + (int)puVar16);
        *puVar16 = uVar6;
        iVar4 = _DAT_00482d05;
        *(char *)param_2 = (char)((ushort)uVar6 >> 8);
        iVar8 = *(int *)(&DAT_00482d0d + (uint)bVar13 * 4);
        *(undefined2 *)((int)puVar16 + (2 - iVar4)) =
             *(undefined2 *)((int)puVar16 + ((iVar8 + 2) - iVar4));
        iVar4 = _DAT_00482d05 - iVar4;
        uVar6 = *(undefined2 *)((int)puVar16 + iVar8 + iVar4 + 2);
        *(undefined2 *)((int)puVar16 + iVar4 + 2) = uVar6;
        param_1 = (undefined4 *)((int)puVar16 + (iVar4 - _DAT_00482d05));
        *(char *)((int)param_2 + 1) = (char)((ushort)uVar6 >> 8);
      }
LAB_00457e10:
      param_1 = param_1 + 1;
      cVar10 = (char)((ushort)uVar7 >> 8) + -1;
      uVar9 = (uint)CONCAT11(cVar10,(char)uVar7);
      if (cVar10 != '\0') {
        param_2 = param_2 + 1;
        goto LAB_00457e1a;
      }
    }
    else {
      uVar5 = *puVar14;
      puVar14 = (ushort *)((int)puVar14 + 1);
      if ((byte)uVar5 == 0) {
        uVar11 = uVar11 << 2;
        if (uVar11 == 0) goto LAB_00457df8;
        goto LAB_00457e10;
      }
      iVar8 = *(int *)(&DAT_00482d0d + (uint)(byte)uVar5 * 4);
      uVar2 = *(undefined4 *)(iVar8 + (int)param_1);
      *param_1 = uVar2;
      *(char *)param_2 = (char)((uint)uVar2 >> 0x18);
      puVar15 = (undefined4 *)((int)param_1 + _DAT_00482d05);
      uVar2 = *(undefined4 *)((int)puVar15 + iVar8);
      *puVar15 = uVar2;
      param_1 = (undefined4 *)((int)puVar15 - _DAT_00482d05);
      *(char *)((int)param_2 + 1) = (char)((uint)uVar2 >> 0x18);
      uVar11 = uVar11 * 4;
      if (uVar11 == 0) {
LAB_00457df8:
        uVar11 = *DAT_00482cec;
        DAT_00482cec = DAT_00482cec + 1;
        uVar11 = uVar11 << 0x10 | uVar11 >> 0x10;
        goto LAB_00457e10;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      cVar10 = (char)(uVar9 >> 8) + -1;
      uVar9 = (uint)CONCAT11(cVar10,(char)uVar9);
      if (cVar10 != '\0') goto LAB_00457e1a;
    }
    uVar9 = (uint)CONCAT11(DAT_00482d04,(char)uVar9);
    param_1 = (undefined4 *)((int)param_1 + _DAT_00482d09);
    _DAT_00482d00 = _DAT_00482d00 + -1;
    param_2 = DAT_00482cfc;
    if (_DAT_00482d00 == 0) {
      return;
    }
  } while( true );
}


