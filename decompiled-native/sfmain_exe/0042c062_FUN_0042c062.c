// 0042c062 FUN_0042c062 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0042c062(int *param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  undefined4 *in_EAX;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *extraout_ECX;
  int extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  uint uVar6;
  undefined4 *puVar7;
  int extraout_ECX_02;
  int iVar8;
  uint extraout_ECX_03;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int unaff_EBX;
  undefined4 *puVar9;
  undefined8 uVar10;
  int iStack_14;
  uint uStack_10;
  
  (*(code *)PTR_FUN_0043e7f0)(param_2);
  if ((*(byte *)(extraout_ECX + 3) & 2) == 0) {
    FUN_0042d8ad(extraout_ECX,extraout_EDX);
    *(byte *)(extraout_ECX_00 + 0xc) = *(byte *)(extraout_ECX_00 + 0xc) | 0x20;
    (*(code *)PTR_FUN_0043e7f4)();
    uVar4 = 0;
  }
  else {
    uStack_10 = unaff_EBX * extraout_EDX;
    if (uStack_10 == 0) {
      (*(code *)PTR_FUN_0043e7f4)();
      uVar4 = 0;
    }
    else {
      puVar7 = extraout_ECX;
      if (extraout_ECX[2] == 0) {
        FUN_0042d8e0(extraout_ECX);
        puVar7 = extraout_ECX_01;
      }
      uVar2 = param_1[3];
      bVar1 = *(byte *)(param_1 + 3);
      iStack_14 = 0;
      *(byte *)(param_1 + 3) = bVar1 & 0xcf;
      if ((bVar1 & 0x40) == 0) {
        bVar3 = false;
        puVar7 = in_EAX;
        if ((*(byte *)((int)param_1 + 0xd) & 4) != 0) {
          bVar3 = true;
          *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfa | 1;
        }
        do {
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          FUN_0042bb35();
          iVar8 = extraout_ECX_02;
          if ((*(byte *)(param_1 + 3) & 0x30) != 0) break;
          iVar8 = iStack_14 + 1;
          iStack_14 = iVar8;
        } while (uStack_10 - iVar8 != 0);
        if (bVar3) {
          uVar5 = CONCAT22((short)((uint)extraout_EDX_00 >> 0x10),
                           CONCAT11(*(undefined1 *)((int)param_1 + 0xd),(char)extraout_EDX_00)) &
                  0xfffffaff;
          *(byte *)((int)param_1 + 0xd) = (byte)(uVar5 >> 8) | 4;
          FUN_0042d957(iVar8,uVar5);
        }
      }
      else {
        do {
          if ((param_1[1] == 0) && ((uint)param_1[5] <= uStack_10)) {
            uVar5 = FUN_0042e389(puVar7,in_EAX);
            if (uVar5 != 0xffffffff) {
              if (uVar5 != 0) goto LAB_0042c18e;
              uVar10 = (*(code *)PTR_FUN_0043e7ec)();
              uVar5 = (uint)((ulonglong)uVar10 >> 0x20);
              *(undefined4 *)((int)uVar10 + 4) = 0xc;
            }
            *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x20;
          }
          else {
            uVar5 = param_1[5] - param_1[1];
            if (uStack_10 < (uint)(param_1[5] - param_1[1])) {
              uVar5 = uStack_10;
            }
            puVar7 = in_EAX;
            puVar9 = (undefined4 *)*param_1;
            for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            }
            param_1[1] = param_1[1] + uVar5;
            *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x10;
            *param_1 = *param_1 + uVar5;
            if ((param_1[1] == param_1[5]) || ((*(byte *)((int)param_1 + 0xd) & 4) != 0)) {
              uVar10 = FUN_0042d957(0,uVar5);
              uVar5 = (uint)((ulonglong)uVar10 >> 0x20);
            }
          }
LAB_0042c18e:
          puVar7 = (undefined4 *)((int)in_EAX + uVar5);
          iStack_14 = iStack_14 + uVar5;
          uStack_10 = uStack_10 - uVar5;
        } while ((uStack_10 != 0) && (in_EAX = puVar7, (*(byte *)(param_1 + 3) & 0x20) == 0));
      }
      if ((*(byte *)(param_1 + 3) & 0x20) != 0) {
        iStack_14 = 0;
      }
      param_1[3] = param_1[3] | uVar2 & 0x30;
      (*(code *)PTR_FUN_0043e7f4)(param_2,puVar7);
      uVar4 = (undefined4)(CONCAT44(extraout_EDX_01,iStack_14) / (ulonglong)extraout_ECX_03);
    }
  }
  return uVar4;
}


